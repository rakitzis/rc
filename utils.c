/* utils.c: functions of general utility */

#include "rc.h"

#include <errno.h>

/* print error with line number on noninteractive shells (i.e., scripts) */

extern void pr_error(const char *s, int offset) {
	if (s != NULL) {
		if (interactive)
			fprint(2, RC "%s\n", s);
		else
			fprint(2, RC "line %d: %s\n", lineno + offset, s);
	}
}

/* our perror */

extern void uerror(const char *s) {
	const char *err;

	err = strerror(errno);
	if (!err) err = "unknown error";

	if (s)
		fprint(2, RC "%s: %s\n", s, err);
	else
		fprint(2, RC "%s\n", err);
}

/* Die horribly. This should never get called. Please let me know if it does. */

#define PANICMSG "rc panic: "

extern void panic(const char *s) {
	int ignore; /* All bets are off: cannot check write */
	ignore = write(2, PANICMSG, conststrlen(PANICMSG));
	ignore = write(2, s, strlen(s));
	ignore = write(2, "!\n", 2);
	(void) ignore;
	exit(1);
}

/* ascii -> unsigned conversion routines. -1 indicates conversion error. */

extern int n2u(const char *s, unsigned int base) {
	unsigned int i;
	for (i = 0; *s != '\0'; s++) {
		const unsigned int j = (unsigned int) *s - '0';
		if (j >= base) /* small hack with unsigned ints -- one compare for range test */
			return -1;
		i = i * base + j;
	}
	return (int) i;
}

/* The last word in portable ANSI: a strcmp wrapper for qsort */

extern int starstrcmp(const void *s1, const void *s2) {
	return strcmp_fast(*(char * const *)s1, *(char * const *)s2);
}

/* tests to see if pathname begins with "/", "./", or "../" */

extern bool isabsolute(const char *path) {
	return path[0] == '/' || (path[0] == '.' && (path[1] == '/' || (path[1] == '.' && path[2] == '/')));
}


/* duplicate a fd and close the old one only if necessary */

extern int mvfd(int i, int j) {
	if (i != j) {
		const int s = dup2(i, j);
		close(i);
		return s;
	}
	return 0;
}

int find_str(const char *const s, const char *const arr[], int sz)
{
	const char *const *pi = &arr[0], *const *pj = &arr[sz];

	while (pi < pj) {
		const char *const *const pm = pi + (pj - pi) / 2;
		const int c = strcmp_fast(*pm, s);
		if (c > 0) {
			pj = pm;
		} else if (c < 0) {
			pi = pm + 1;
		} else {
			return pm - arr;
		}
	}

	return -1;
}

