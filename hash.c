/* hash.c: hash table support for functions and variables. */

/*
   Functions and variables are cached in both internal and external
   form for performance. Thus a variable which is never "dereferenced"
   with a $ is passed on to rc's children untouched. This is not so
   important for variables, but is a big win for functions, where a call
   to yyparse() is involved.
*/

#include "rc.h"
#include "sigmsgs.h"

static bool var_exportable(const char *);
static bool fn_exportable(const char *);
static int hash(const char *, int);
static int find(const char *, Htab *, int);
static void free_fn(rc_Function *);

static Htab *fp;
static Htab *vp;
static int fused, fsize, vused, vsize;
static char **env;
static int bozosize;
static int envsize;
static bool env_dirty = TRUE;
static char * const dead = "";

#define HASHSIZE 64 /* rc was debugged with HASHSIZE == 2; 64 is about right for normal use */

extern void inithash(void) {
	Htab *fpp, *vpp;
	int i;
	fp = enew_arr(Htab, HASHSIZE);
	vp = enew_arr(Htab, HASHSIZE);
	fused = vused = 0;
	fsize = vsize = HASHSIZE;
	for (vpp = vp, fpp = fp, i = 0; i < HASHSIZE; i++, vpp++, fpp++)
		vpp->name = fpp->name = NULL;
}

#define ADV()   {if ((c = (*s++) & 0xff) == '\0') break;}

/* hash function courtesy of paul haahr */

static int hash(const char *s, int size) {
	unsigned int c;
	int n = 0;
	while (1) {
		ADV();
		n += (c << 17u) ^ (c << 11u) ^ (c << 5u) ^ (c >> 1u);
		ADV();
		n ^= (c << 14u) + (c << 7u) + (c << 4u) + c;
		ADV();
		n ^= (~c << 11u) | ((c << 3u) ^ (c >> 1u));
		ADV();
		n -= (c << 16u) | (c << 9u) | (c << 2u) | (c & 3u);
	}
	if (n < 0)
		n = ~n;
	return n & (size - 1); /* need power of 2 size */
}

static bool rehash(Htab *ht) {
	int i, size;
	int newsize, newused;
	Htab *newhtab;
	if (ht == fp) {
		if (fsize > 2 * fused)
			return FALSE;
		size = fsize;
	} else {
		if (vsize > 2 * vused)
			return FALSE;
		size = vsize;
	}
	newsize = 2 * size;
	newhtab = enew_arr(Htab, newsize);
	for (i = 0; i < newsize; i++)
		newhtab[i].name = NULL;
	for (i = newused = 0; i < size; i++)
		if (ht[i].name != NULL && ht[i].name != dead) {
			int j;
			newused++;
			j = hash(ht[i].name, newsize);
			while (newhtab[j].name != NULL) {
				j++;
				j &= (newsize - 1);
			}
			newhtab[j].name = ht[i].name;
			newhtab[j].u = ht[i].u;
		}
	if (ht == fp) {
		fused = newused;
		fp = newhtab;
		fsize = newsize;
	} else {
		vused = newused;
		vp = newhtab;
		vsize = newsize;
	}
	efree(ht);
	return TRUE;
}

#define varfind(s) find(s, vp, vsize)
#define fnfind(s) find(s, fp, fsize)

static int find(const char *s, Htab *ht, int size) {
	int h = hash(s, size);
	while (ht[h].name != NULL && !streq(ht[h].name, s)) {
		h++;
		h &= size - 1;
	}
	return h;
}

extern rc_Function *lookup_fn(const char *s) {
	const int h = find(s, fp, fsize);
	return (fp[h].name == NULL) ? NULL : fp[h].u.f;
}

extern Variable *lookup_var(const char *s) {
	const int h = find(s, vp, vsize);
	return (vp[h].name == NULL) ? NULL : vp[h].u.v;
}

extern rc_Function *get_fn_place(const char *s) {
	int h = fnfind(s);
	env_dirty = TRUE;
	if (fp[h].name == NULL) {
		if (rehash(fp))
			h = fnfind(s);
		fused++;
		fp[h].name = ecpy(s);
		fp[h].u.f = enew(rc_Function);
	} else
		free_fn(fp[h].u.f);
	return fp[h].u.f;
}

extern Variable *get_var_place(const char *s, bool stack) {
	int h = varfind(s);

	env_dirty = TRUE;

	if (vp[h].name == NULL) {
		if (rehash(vp))
			h = varfind(s);
		vused++;
		vp[h].name = ecpy(s);
		vp[h].u.v = enew(Variable);
		vp[h].u.v->n = NULL;
		return vp[h].u.v;
	} else {
		Variable *new;
		if (stack) {	/* increase the stack by 1 */
			new = enew(Variable);
			new->n = vp[h].u.v;
			return vp[h].u.v = new;
		} else {	/* trample the top of the stack */
			new = vp[h].u.v;
			efree(new->extdef);
			listfree(new->def);
			return new;
		}
	}
}

extern void delete_fn(const char *s) {
	const int h = fnfind(s);
	if (fp[h].name == NULL)
		return; /* not found */
	env_dirty = TRUE;
	free_fn(fp[h].u.f);
	efree(fp[h].u.f);
	efree((char*)fp[h].name);
	if (fp[(h+1)&(fsize-1)].name == NULL) {
		--fused;
		fp[h].name = NULL;
	} else {
		fp[h].name = dead;
	}
}

extern void delete_var(const char *s, bool stack) {
	const int h = varfind(s);
	Variable *v;
	if (vp[h].name == NULL)
		return; /* not found */
	env_dirty = TRUE;
	v = vp[h].u.v;
	efree(v->extdef);
	listfree(v->def);
	if (v->n != NULL) { /* This is the top of a stack */
		if (stack) { /* pop */
			vp[h].u.v = v->n;
			efree(v);
		} else { /* else just empty */
			v->extdef = NULL;
			v->def = NULL;
		}
	} else { /* needs to be removed from the hash table */
		efree(v);
		vp[h].u.v = NULL; /* vp[hp].u.v == v */
		efree((char*)vp[h].name);
		if (vp[(h+1)&(vsize-1)].name == NULL) {
			--vused;
			vp[h].name = NULL;
		} else {
			vp[h].name = dead;
		}
	}
}

static void free_fn(rc_Function *f) {
	treefree(f->def);
	efree(f->extdef);
}

extern void initenv(char **envp) {
	int n;
	for (n = 0; envp[n] != NULL; n++)
		;
	n++; /* one for the null terminator */
	if (n < HASHSIZE)
		n = HASHSIZE;
	env = enew_arr(char *, (envsize = 2 * n));

	for (; *envp != NULL; envp++)
		if (strncmp_fast(*envp, "fn_", conststrlen("fn_")) == 0) {
			if (!dashpee)
				fnassign_string(*envp);
		} else {
			if (!varassign_string(*envp)) /* add to bozo env */
				env[bozosize++] = *envp;
		}
}

static const char * const neverexport[] = {
	"apid", "apids", "bqstatus", "cdpath", "home",
	"ifs", "path", "pid", "ppid", "pwd", "random", "status", "*"
};

/* for a few variables that have default values, we export them only
if they've been explicitly set; maybeexport[n].flag is TRUE if this
has occurred. */
struct nameflag {
	const char *name;
	bool flag;
};
static struct nameflag maybeexport[] = {
	{ "prompt", FALSE },
	{ "version", FALSE }
};

void set_exportable(const char *s, bool b) {
	int i;
	for (i = 0; i < arraysize(maybeexport); ++i)
		if (maybeexport[i].flag != b && streq(s, maybeexport[i].name))
			maybeexport[i].flag = b;
}

static bool var_exportable(const char *s) {
	int i;
	for (i = 0; i < arraysize(neverexport); i++)
		if (streq(s, neverexport[i]))
			return FALSE;
	for (i = 0; i < arraysize(maybeexport); i++)
		if (maybeexport[i].flag == FALSE && streq(s, maybeexport[i].name))
			return FALSE;
	return TRUE;
}

static bool fn_exportable(const char *s) {
	int i;
	if (strncmp_fast(s, "sig", conststrlen("sig")) == 0) { /* small speed hack */
		for (i = 0; i < NUMOFSIGNALS; i++)
			if (streq(s, signals[i].name))
				return FALSE;
		if (streq(s, "sigexit"))
			return FALSE;
	}
	return TRUE;
}

extern char **makeenv(void) {
	int ep, i;
	if (!env_dirty)
		return env;
	env_dirty = FALSE;
	ep = bozosize;
	if (vsize + fsize + 1 + bozosize > envsize) {
		envsize = 2 * (bozosize + vsize + fsize + 1);
		env = erenew_arr(char*, env, envsize);
	}
	for (i = 0; i < vsize; i++) {
		char *v;
		if (vp[i].name == NULL || vp[i].name == dead || !var_exportable(vp[i].name))
			continue;
		v = varlookup_string(vp[i].name);
		if (v != NULL)
			env[ep++] = v;
	}
	for (i = 0; i < fsize; i++) {
		if (fp[i].name == NULL || fp[i].name == dead || !fn_exportable(fp[i].name))
			continue;
		env[ep++] = fnlookup_string(fp[i].name);
	}
	env[ep] = NULL;
	qsort(env, (size_t) ep, sizeof(char *), starstrcmp);
	return env;
}

extern void whatare_all_vars(bool showfn, bool showvar) {
	int i;
	List *s;
	if (showvar)
		for (i = 0; i < vsize; i++)
			if (vp[i].name != NULL && (s = varlookup(vp[i].name)) != NULL)
				prettyprint_var(1, vp[i].name, s);
	if (showfn)
		for (i = 0; i < fsize; i++)
			if (fp[i].name != NULL && fp[i].name != dead)
				prettyprint_fn(1, fp[i].name, fnlookup(fp[i].name));
}

extern char *compl_name(const char *text, int state, const char * const *p, size_t count, ssize_t inc) {
	static const char * const *n;
	static size_t i, len;
	char *name;

	if (!state) {
		n = p;
		i = 0;
		len = strlen(text);
	}
	for (name = NULL; name == NULL && i < count; i++, n += inc)
		if (*n != NULL && strncmp(*n, text, len) == 0)
			name = strdup(*n);
	return name;
}

extern char *compl_fn(const char *text, int state) {
	return compl_name(text, state, &fp[0].name, fsize, &fp[1].name - &fp[0].name);
}

extern char *compl_var(const char *text, int state) {
	return compl_name(text, state, &vp[0].name, vsize, &vp[1].name - &vp[0].name);
}
