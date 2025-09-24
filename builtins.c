/* builtins.c: the collection of rc's builtin commands */

/*
	NOTE: rc's builtins do not call "rc_error" because they are
	commands, and rc errors usually arise from syntax errors. e.g.,
	you probably don't want interpretation of a shell script to stop
	because of a bad umask.
*/

#include "rc.h"

#include <sys/ioctl.h>
#include <sys/stat.h>
#include <setjmp.h>
#include <errno.h>

#include "input.h"
#include "jbwrap.h"
#include "rlimit.h"
#include "sigmsgs.h"

#if RC_ADDON
#include "addon.c"
#endif

static void b_break(char **), b_cd(char **), b_continue(char **), b_eval(char **), b_flag(char **),
	b_exit(char **), b_newpgrp(char **), b_return(char **), b_shift(char **), b_umask(char **),
	b_wait(char **), b_whatis(char **);

#if HAVE_SETRLIMIT
static void b_limit(char **);
#endif

#if RC_ECHO
static void b_echo(char **);
#endif

static struct {
	builtin_t *p;
	char *name;
} builtins[] = {
	{ b_break,	"break" },
	{ b_builtin,	"builtin" },
	{ b_cd,		"cd" },
	{ b_continue,	"continue" },
#if RC_ECHO
	{ b_echo,	"echo" },
#endif
	{ b_eval,	"eval" },
	{ b_exec,	"exec" },
	{ b_exit,	"exit" },
	{ b_flag,	"flag" },
#if HAVE_SETRLIMIT
	{ b_limit,	"limit" },
#endif
	{ b_newpgrp,	"newpgrp" },
	{ b_return,	"return" },
	{ b_shift,	"shift" },
	{ b_umask,	"umask" },
	{ b_wait,	"wait" },
	{ b_whatis,	"whatis" },
	{ b_dot,	"." },
#ifdef ADDONS
	ADDONS
#endif
};

extern builtin_t *isbuiltin(char *s) {
    int i;
    for (i = 0; i < arraysize(builtins); i++)
	if (streq(builtins[i].name, s))
	    return builtins[i].p;
    return NULL;
}

/* funcall() is the wrapper used to invoke shell functions. pushes $*, and "return" returns here. */

extern void funcall(char **av) {
	Jbwrap j;
	Estack e1, e2;
	Edata jreturn, star;
	if (sigsetjmp(j.j, 1))
		return;
	starassign(*av, av+1, TRUE);
	jreturn.jb = &j;
	star.name = "*";
	except(eReturn, jreturn, &e1);
	except(eVarstack, star, &e2);
	walk(treecpy(fnlookup(*av), nalloc), TRUE);
	varrm("*", TRUE);
	unexcept(eVarstack);
	unexcept(eReturn);
}

static void arg_count(char *name) {
    fprint(2, RC "too many arguments to %s\n", name);
    set(FALSE);
}

static void badnum(char *num) {
    fprint(2, RC "`%s' is a bad number\n", num);
    set(FALSE);
}

/* a dummy command. (exec() performs "exec" simply by not forking) */

extern void b_exec(char **ignore) {
}

#if RC_ECHO
/* echo -n omits a newline. echo -- -n echos '-n' */

static void b_echo(char **av) {
    char *format = "%A\n";
    if (*++av != NULL) {
	if (streq(*av, "-n"))
	    format = "%A", av++;
	else if (streq(*av, "--"))
	    av++;
    }
    fprint(1, format, av);
    set(TRUE);
}
#endif

/* cd. traverse $cdpath if the directory given is not an absolute pathname */

static void b_cd(char **av) {
    List *s, nil;
    char *path = NULL;
    size_t t, pathlen = 0;
    if (*++av == NULL) {
	s = varlookup("home");
	*av = (s == NULL) ? "/" : s->w;
    } else if (av[1] != NULL) {
	arg_count("cd");
	return;
    }
    if (isabsolute(*av) || streq(*av, ".") || streq(*av, "..")) { /* absolute pathname? */
	if (chdir(*av) < 0) {
	    set(FALSE);
	    uerror(*av);
	} else
	    set(TRUE);
    } else {
	s = varlookup("cdpath");
	if (s == NULL) {
	    s = &nil;
	    nil.w = "";
	    nil.n = NULL;
	}
	do {
	    if (s != &nil && *s->w != '\0') {
		t = strlen(*av) + strlen(s->w) + 2;
		if (t > pathlen)
		    path = nalloc(pathlen = t);
		strcpy(path, s->w);
		if (!streq(s->w, "/")) /* "//" is special to POSIX */
		    strcat(path, "/");
		strcat(path, *av);
	    } else {
		pathlen = 0;
		path = *av;
	    }
	    if (chdir(path) >= 0) {
		set(TRUE);
		if (interactive && *s->w != '\0' && !streq(s->w, "."))
		    fprint(1, "%s\n", path);
		return;
	    }
	    s = s->n;
	} while (s != NULL);
	fprint(2, "couldn't cd to %s\n", *av);
	set(FALSE);
    }
}

static void b_umask(char **av) {
    int i;
    if (*++av == NULL) {
	set(TRUE);
	i = umask(0);
	umask(i);
	fprint(1, "0%o\n", i);
    } else if (av[1] == NULL) {
	i = o2u(*av);
	if ((unsigned int) i > 0777) {
	    fprint(2, "bad umask\n");
	    set(FALSE);
	} else {
	    umask(i);
	    set(TRUE);
	}
    } else {
	arg_count("umask");
	return;
    }
}

static void b_exit(char **av) {
	if (*++av != NULL)
		ssetstatus(av);
	rc_exit(getstatus());
}

static void b_flag(char **av) {
	bool *flagp = NULL;
	char f;
	int mode = 3; /* 0 = reset (-), 1 = set (+), 2 = test */
	const char *usage = "usage: flag f [ + | - ]\n";

	if (*++av == NULL) {
		fprint(2, RC "not enough arguments to flag\n");
		set(FALSE);
		return;
	}
	f = av[0][0];
	if (f == '\0' || av[0][1] != '\0') goto flag_usage;
	if (*++av == NULL) {
		mode = 2;
	} else if (av[0][0] == '+' && av[0][1] == '\0') {
		mode = 1;
	} else if (av[0][0] == '-' && av[0][1] == '\0') {
		mode = 0;
	}
	if (mode == 3) goto flag_usage;
	switch (f) {
		case 'c':
			if (mode != 2) goto flag_immutable;
			set(dashsee[0] != NULL);
			return;
		case 'd':
			if (mode != 2) goto flag_immutable;
			flagp = &dashdee; break;
		case 'e': flagp = &dashee; break;
		case 'i': flagp = &interactive; break;
		case 'l':
			  if (mode != 2) goto flag_immutable;
			  flagp = &dashell; break;
		case 'n': flagp = &dashen; break;
		case 'o':
			  if (mode != 2) goto flag_immutable;
			  flagp = &dashoh; break;
		case 'p':
			  if (mode != 2) goto flag_immutable;
			  flagp = &dashpee; break;
		case 's':
			  if (mode != 2) goto flag_immutable;
			  flagp = &dashess; break;
		case 'u': flagp = &dashewe; break;
		case 'v': flagp = &dashvee; break;
		case 'x': flagp = &dashex; break;
	}
	if (flagp != NULL) {
		if (mode == 2)
			set(*flagp);
		else {
			*flagp = mode;
			set(TRUE);
		}
	} else {
		fprint(2, RC "unknown flag");
		set(FALSE);
	}
	return;
flag_immutable:
	fprint(2, RC "flag immutable\n");
	set(FALSE);
	return;
flag_usage:
	fprint(2, usage);
	set(FALSE);
}

/* raise a "return" exception, i.e., return from a function. if an integer argument is present, set $status to it */

static void b_return(char **av) {
	if (*++av != NULL)
		ssetstatus(av);
	rc_raise(eReturn);
}

/* raise a "break" exception for breaking out of for and while loops */

static void b_break(char **av) {
	if (av[1] != NULL) {
		arg_count("break");
		return;
	}
	rc_raise(eBreak);
}

/* raise a "continue" exception to finish early an iteration of 'for' and 'while' loops */

static void b_continue(char **av) {
	if (av[1] != NULL) {
		arg_count("continue");
		return;
	}
	rc_raise(eContinue);
}

/* shift $* n places (default 1) */

static void b_shift(char **av) {
	int shift = (av[1] == NULL ? 1 : a2u(av[1]));
	List *s, *dollarzero;
	if (av[1] != NULL && av[2] != NULL) {
		arg_count("shift");
		return;
	}
	if (shift < 0) {
		badnum(av[1]);
		return;
	}
	s = varlookup("*")->n;
	dollarzero = varlookup("0");
	while (s != NULL && shift != 0) {
		s = s->n;
		--shift;
	}
	if (s == NULL && shift != 0) {
		fprint(2, "rc: cannot shift\n");
		set(FALSE);
	} else {
		varassign("*", append(dollarzero, s), FALSE);
		set(TRUE);
	}
}

/* dud function */

extern void b_builtin(char **ignore) {
}

/* wait for one or more processes, or all outstanding processes */

static void b_wait(char **av) {
	if (*++av == NULL)
		waitforall();
	else
		waitfor(av);
        sigchk();
}

/*
   whatis without arguments prints all variables and functions. Otherwise, check to see if a name
   is defined as a variable, function or pathname.
*/

#define not(b)	((b)^TRUE)
#define show(b)	(not(eff|vee|pee|bee|ess)|(b))

static bool issig(char *s) {
	int i;
	for (i = 0; i < NUMOFSIGNALS; i++)
		if (streq(s, signals[i].name))
			return TRUE;
	return FALSE;
}

static void b_whatis(char **av) {
	bool ess, eff, vee, pee, bee;
	bool f, found;
	int i, ac, c;
	List *s;
	Node *n;
	char *e;
	for (rc_optind = ac = 0; av[ac] != NULL; ac++)
		; /* count the arguments for getopt */
	ess = eff = vee = pee = bee = FALSE;
	while ((c = rc_getopt(ac, av, "sfvpb")) != -1)
		switch (c) {
		default: set(FALSE); return;
		case 's': ess = TRUE; break;
		case 'f': eff = TRUE; break;
		case 'v': vee = TRUE; break;
		case 'p': pee = TRUE; break;
		case 'b': bee = TRUE; break;
		}
	av += rc_optind;
	if (*av == NULL) {
		if (vee|eff)
			whatare_all_vars(eff, vee);
		if (ess)
			whatare_all_signals();
		if (bee)
			for (i = 0; i < arraysize(builtins); i++)
				fprint(1, "builtin %s\n", builtins[i].name);
		if (pee)
			fprint(2, "whatis -p: must specify argument\n");
		if (show(FALSE)) /* no options? */
			whatare_all_vars(TRUE, TRUE);
		set(TRUE);
		return;
	}
	found = TRUE;
	for (i = 0; av[i] != NULL; i++) {
		f = FALSE;
		errno = ENOENT;
		if (show(vee) && (s = varlookup(av[i])) != NULL) {
			f = TRUE;
			prettyprint_var(1, av[i], s);
		}
		if (((show(ess)&&issig(av[i])) || show(eff)) && (n = fnlookup(av[i])) != NULL) {
			f = TRUE;
			prettyprint_fn(1, av[i], n);
		} else if (show(bee) && isbuiltin(av[i]) != NULL) {
			f = TRUE;
			fprint(1, "builtin %s\n", av[i]);
		} else if (show(pee) && (e = which(av[i], FALSE)) != NULL) {
			f = TRUE;
			fprint(1, "%S\n", e);
		}
		if (!f) {
			found = FALSE;
			if (errno != ENOENT)
				uerror(av[i]);
			else
				fprint(2, "%s not found\n", av[i]);
		}
	}
	set(found);
}

/* push a string to be eval'ed onto the input stack. evaluate it */

static void b_eval(char **av) {
	bool i = interactive;
	if (av[1] == NULL)
		return;
	interactive = FALSE;
	pushstring(av + 1, i); /* don't reset line numbers on noninteractive eval */
	doit(TRUE);
	interactive = i;
}

/*
   push a file to be interpreted onto the input stack. with "-i" treat this as an interactive
   input source.
*/

extern void b_dot(char **av) {
	int fd;
	bool old_i = interactive, i = FALSE;
	Estack e;
	Edata star;
	av++;
	if (*av == NULL)
		return;
	if (streq(*av, "-i")) {
		av++;
		i = TRUE;
	}
	if (dasheye) { /* rc -i file has to do the right thing. reset the dasheye state to FALSE, though. */
		dasheye = FALSE;
		i = TRUE;
	}
	if (*av == NULL)
		return;
	fd = rc_open(*av, rFrom);
	if (fd < 0) {
		uerror(*av);
		set(FALSE);
		return;
	}
	starassign(*av, av+1, TRUE);
	interactive = i;
	pushfd(fd);
	star.name = "*";
	except(eVarstack, star, &e);
	doit(TRUE);
	varrm("*", TRUE);
	unexcept(eVarstack);
	interactive = old_i;
}

/* put rc into a new pgrp. Used on the NeXT where the Terminal program is broken (sigh) */

static void b_newpgrp(char **av) {
	if (av[1] != NULL) {
		arg_count("newpgrp");
		return;
	}
	setpgid(rc_pid, rc_pid); /* XXX check return value */
	tcsetpgrp(2, rc_pid); /* XXX check return value */
}

/* Berkeley limit support was cleaned up by Paul Haahr. */

#if HAVE_SETRLIMIT
static const struct Suffix
	kbsuf = { NULL, 1024, "k" },
	mbsuf = { &kbsuf, 1024*1024, "m" },
	gbsuf = { &mbsuf, 1024*1024*1024, "g" },
	stsuf = { NULL, 1, "s" },
	mtsuf = { &stsuf, 60, "m" },
	htsuf = { &mtsuf, 60*60, "h" };
#define	SIZESUF &gbsuf
#define	TIMESUF &htsuf
#define	NOSUF ((struct Suffix *) NULL)  /* for RLIMIT_NOFILE on SunOS 4.1 */

static const struct Limit limits[] = {
	{ "cputime",		RLIMIT_CPU,	TIMESUF },
	{ "filesize",		RLIMIT_FSIZE,	SIZESUF },
	{ "datasize",		RLIMIT_DATA,	SIZESUF },
	{ "stacksize",		RLIMIT_STACK,	SIZESUF },
	{ "coredumpsize",	RLIMIT_CORE,	SIZESUF },
#ifdef RLIMIT_NOFILE  /* SUSv2, but not universal */
	{ "descriptors",	RLIMIT_NOFILE,	NOSUF },
#endif
#ifdef RLIMIT_AS /* SUSv2, but not universal */
	{ "memoryuse",		RLIMIT_AS,	SIZESUF },
#endif
#if defined(RLIMIT_VMEM) && !defined(RLIMIT_AS) /* old name for AS */
	{ "memoryuse",		RLIMIT_VMEM,	SIZESUF },
#endif
#ifdef RLIMIT_RSS
	{ "memoryrss",		RLIMIT_RSS,	SIZESUF },
#endif
#ifdef RLIMIT_NPROC
	{ "maxproc",		RLIMIT_NPROC,	NOSUF },
#endif
#ifdef RLIMIT_MEMLOCK
	{ "memorylocked",	RLIMIT_MEMLOCK,	SIZESUF },
#endif
#ifdef RLIMIT_LOCKS
	{ "filelocks",		RLIMIT_LOCKS,	NOSUF },
#endif
	{ NULL, 0, NULL }
};

static void printlimit(const struct Limit *limit, bool hard) {
	struct rlimit rlim;
	rlim_t lim;
	getrlimit(limit->flag, &rlim);
	if (hard)
		lim = rlim.rlim_max;
	else
		lim = rlim.rlim_cur;
	if (lim == RLIM_INFINITY)
		fprint(1, "%s \tunlimited\n", limit->name);
	else {
		const struct Suffix *suf;
		for (suf = limit->suffix; suf != NULL; suf = suf->next)
			if (lim % suf->amount == 0 && (lim != 0 || suf->amount > 1)) {
				lim /= suf->amount;
				break;
			}
		fprint(1, RLIM_FMT, limit->name, (RLIM_CONV)lim, (suf == NULL || lim == 0) ? "" : suf->name);
	}
}

static bool parselimit(const struct Limit *resource, rlim_t *limit, char *s) {
	char *t;
	int len = strlen(s);
	const struct Suffix *suf = resource->suffix;

	*limit = 1;
	if (streq(s, "unlimited")) {
		*limit = RLIM_INFINITY;
		return TRUE;
	}
	if (suf == TIMESUF && (t = strchr(s, ':')) != NULL) {
		int min, sec;
		*t++ = '\0';
		min = a2u(s); sec = a2u(t);
		if (min == -1 || sec == -1) return FALSE;
		*limit = 60 * min + sec;
	} else {
		int n;
		for (; suf != NULL; suf = suf->next)
			if (streq(suf->name, s + len - strlen(suf->name))) {
				s[len - strlen(suf->name)] = '\0';
				*limit *= suf->amount;
				break;
			}
		n = a2u(s);
		if (n == -1) return FALSE;
		*limit *= n;
	}
	return TRUE;
}

static void b_limit(char **av) {
	const struct Limit *lp = limits;
	bool hard = FALSE;
	if (*++av != NULL && streq(*av, "-h")) {
		av++;
		hard = TRUE;
	}
	if (*av == NULL) {
		for (; lp->name != NULL; lp++)
			printlimit(lp, hard);
		return;
	}
	for (;; lp++) {
		if (lp->name == NULL) {
			fprint(2, "no such limit\n");
			set(FALSE);
			return;
		}
		if (streq(*av, lp->name))
			break;
	}
	if (*++av == NULL)
		printlimit(lp, hard);
	else {
		struct rlimit rlim;
		rlim_t pl;
		getrlimit(lp->flag, &rlim);
		if (!parselimit(lp, &pl, *av)) {
			fprint(2, "bad limit\n");
			set(FALSE);
			return;
		}
		if (hard)
			rlim.rlim_max = pl;
		else
			rlim.rlim_cur = pl;
		if (setrlimit(lp->flag, &rlim) == -1) {
			uerror("setrlimit");
			set(FALSE);
		} else
			set(TRUE);
	}
}
#endif

extern char *compl_builtin(const char *text, int state) {
	return compl_name(text, state, &builtins[0].name, arraysize(builtins), &builtins[1].name - &builtins[0].name);
}
