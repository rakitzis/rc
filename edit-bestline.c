#include "rc.h"

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <bestline.h>

#include "edit.h"

bool editing = 1;

struct cookie {
	char *buffer;
};

/* Join two strings with a "/" between them, into a malloc string */
static char *dir_join(const char *a, const char *b) {
	size_t l;
	if (!a) a = "";
	if (!b) b = "";
	l = strlen(a);
	return mprint("%s%s%s", a, l && a[l-1] != '/' ? "/" : "", b);
}

static char *quote(char *str) {
	size_t quotecount = 0;
	for (char *p = str; *p; p++)
		if (*p == '\'') quotecount++;
	size_t newlen = strlen(str) + quotecount + 2;
	char *quoted = ealloc(newlen + 1);
	quoted[0] = '\'';
	char *q = quoted + 1;
	for (char *p = str; *p; p++, q++) {
		*q = *p;
		if (*p == '\'')
			*(++q) = '\'';
	}
	*q = '\'';
	*(q+1) = '\0';
	return quoted;
}

static void strip_quotes(char *str) {
	bool quoted = 0;
	for (char *p = str; *p; p++) {
		if (*p == '\'') {
			if (p[1] == '\'') {
				if (quoted) {
					// unescape single quote
					memmove(p, p+1, strlen(p+1) + 1);
					// don't decrement p -> step over the remaining quote
				} else {
					// ignore empty string
					memmove(p, p+2, strlen(p+2) + 1);
					p--;
				}
			} else {
				// strip single quote (opening or closing)
				memmove(p, p+1, strlen(p+1) + 1);
				p--;
				quoted = !quoted;
			}
		}
	}
}

/* Decide if this directory entry is a completion candidate, either executable
 * or a directory. "dname" is the absolute path of the directory, "name" is the
 * current entry. "subdirs" is the name being completed up to and including the
 * last slash (or NULL if there is no slash), "prefix" is the remainder of the
 * name being completed, "len" is the length of "prefix".
 */
static char *entry(char *dname, char *name, char *subdirs,
			char *prefix, size_t len) {
	char *full;
	struct stat st;

	if (strncmp(name, prefix, len) != 0)
		return NULL;
	if (streq(name, ".") || streq(name, ".."))
		return NULL;
	full = dir_join(dname, name);
	int exe = rc_access(full, FALSE, &st);
	efree(full);
	if (exe || S_ISDIR(st.st_mode))
		return dir_join(subdirs, name);
	return NULL;
}

/* Split a string "text" after the last "/" into "pre" and "post". If there is
 * no "/", "pre" will be NULL. */
static void split_last_slash(const char *text, char **pre, char **post) {
	char *last_slash = strrchr(text, '/');
	if (last_slash) {
		size_t l = last_slash + 1 - text;
		*pre = ealloc(l + 1);
		memcpy(*pre, text, l);
		(*pre)[l] = '\0';
		*post = last_slash + 1;
	} else {
		*pre = NULL;
		*post = (char *)text;
	}
}

static char *compl_extcmd(const char *text, int state) {
	static char *dname, *prefix, *subdirs;
	static DIR *d;
	static List nil, *path;
	static size_t len;

	if (!state) {
		split_last_slash(text, &subdirs, &prefix);
		d = NULL;
		if (subdirs && isabsolute(subdirs))
			path = &nil;
		else
			path = varlookup("path");
		len = strlen(prefix);
	}
	while (d || path) {
		if (!d) {
			dname = dir_join(path->w, subdirs);
			d = opendir(dname);
			path = path->n;
			if (!d) efree(dname);
		} else {
			struct dirent *e;
			while ((e = readdir(d))) {
				char *x;
				x = entry(dname, e->d_name, subdirs,
						prefix, len);
				if (x) return x;
			}
			closedir(d);
			efree(dname);
			d = NULL;
		}
	}
	efree(subdirs);
	return NULL;
}

static char *compl_filename(const char *text, int state) {
	static char *textnoquotes, *dname, *prefix, *subdirs;
	static DIR *d;
	static size_t len;
	if (!state) {
		textnoquotes = strdup(text);
		strip_quotes(textnoquotes);
		text = textnoquotes;
		split_last_slash(text, &subdirs, &prefix);
		len = strlen(prefix);
		d = opendir(subdirs ? subdirs : ".");
		if (!d) {
			efree(subdirs);
			efree(textnoquotes);
			return NULL;
		}
	}
	struct dirent *e;
	while ((e = readdir(d))) {
		if (streq(e->d_name, ".") || streq(e->d_name, ".."))
			continue;
		dname = NULL;
		if (strncmp(e->d_name, prefix, len) == 0) {
			dname = subdirs ? dir_join(subdirs, e->d_name) : strdup(e->d_name);
			if (strstr(dname, " ")) {
				char *quoted = quote(dname);
				efree(dname);
				dname = quoted;
			}
			return dname;
		}
	}
	closedir(d);
	d = NULL;
	efree(subdirs);
	efree(dname);
	efree(textnoquotes);
	return NULL;
}

static char compl_prefix(const char *buf, int index) {
	while (index-- > 0) {
		char c = buf[index];
		if (c != ' ' && c != '\t')
			return c;
	}
	return ';';
}

static int findbeginningoftoken(const char *buf, int cursorpos) {
	bool quoted = 0;
	int beginning = 0;
	for (const char *p = buf; *p && p < buf + cursorpos; p++) {
		if (*p == '\'') {
			quoted = !quoted;
		} else if (!quoted && (*p == ' ' || *p == ';' || *p == '$')) {
			beginning = p - buf + 1;
		}
	}
	return beginning;
}

static int quotedstrcmp(const void *s1, const void *s2) {
	char *c1 = *(char**)s1;
	char *c2 = *(char**)s2;
	for (; *c1 && *c2; c1++, c2++) {
		while (*c1 == '\'') c1++;
		while (*c2 == '\'') c2++;
		if (*c1 != *c2) break;
	}
	return (int)(*c1 - *c2);
}

static void add_completions(const char *buf, int start, int end,
		char* (*compl_func)(const char*, int), bestlineCompletions *lc) {
	char *token = strndup(buf + start, end - start);
	char *match = compl_func(token, 0);
	while (match) {
		size_t len = strlen(buf) - (end - start) + strlen(match) + 1;
		char *completion = (char*)ealloc(len);
		snprintf(completion, len, "%.*s%s%s", start, buf, match, &buf[end]);
		bool duplicate = 0;
		if (strcmp(buf, completion) == 0) {
			duplicate = 1;
		} else for (int i = 0; i < lc->len; ++i) {
			if (strcmp(lc->cvec[i], completion) == 0
					|| strcmp(buf, completion) == 0) {
				duplicate = 1;
				break;
			}
		}
		if (!duplicate) {
			bestlineAddCompletion(lc, completion);
		}
		efree(completion);
		match = compl_func(token, 1);
	}
	efree(token);
	if (lc->len > 1)
		qsort(lc->cvec, lc->len, sizeof(char*), quotedstrcmp);
}

static void completion(const char *buf, int pos, bestlineCompletions *lc) {
	int startindex = findbeginningoftoken(buf, pos);
	char prefix = compl_prefix(buf, startindex);
	switch (prefix) {
		case '`': case '@': case '|': case '&':
		case '(': case ')': case '{': case ';':
			add_completions(buf, startindex, pos, &compl_builtin, lc);
			add_completions(buf, startindex, pos, &compl_fn, lc);
			add_completions(buf, startindex, pos, &compl_extcmd, lc);
			return;
		case '$':
			add_completions(buf, startindex, pos, &compl_var, lc);
			return;
	}
	// replace ~/ with $HOME/
	char *expandedbuf = NULL;
	if (buf[startindex] == '~' && buf[startindex + 1] == '/') {
		const char* home = getenv("HOME");
		if (home) {
			size_t homelen = strlen(home);
			expandedbuf = ealloc(strlen(buf) + homelen);
			sprintf(expandedbuf, "%.*s%s%s", startindex, buf, home, buf + startindex + 1);
			buf = expandedbuf;
			pos += homelen - 1;
		}
	}
	add_completions(buf, startindex, pos, &compl_filename, lc);
	efree(expandedbuf);
}

void *edit_begin(int fd) {
	List *hist;
	struct cookie *c;

	bestlineSetCompletionCallback(completion);

	hist = varlookup("history");
	if (hist != NULL)
		if (bestlineHistoryLoad(hist->w) != 0 &&
				errno != ENOENT) /* ignore if missing */
			uerror(hist->w);

	c = ealloc(sizeof *c);
	c->buffer = NULL;
	return c;
}

static char *prompt;

char *edit_alloc(void *cookie, size_t *count) {
	struct cookie *c = cookie;
	c->buffer = bestline(prompt);
	if (c->buffer) {
		*count = strlen(c->buffer);
		if (*count)
			bestlineHistoryAdd(c->buffer);
		c->buffer[*count] = '\n';
		++*count; /* include the \n */
	}
	return c->buffer;
}

void edit_prompt(void *cookie, char *pr) {
	prompt = pr;
}

void edit_free(void *cookie) {
	struct cookie *c = cookie;
	efree(c->buffer);
	c->buffer = NULL; /* allow "overfrees" */
}

void edit_end(void *cookie) {
	struct cookie *c = cookie;
	efree(c);
}

void edit_reset(void *cookie) {
	// do nothing
}
