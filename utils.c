/* utils.c: functions of general utility */

#include "rc.h"

#include <errno.h>
#include <setjmp.h>

#include "jbwrap.h"

/* print error with line number on noninteractive shells (i.e., scripts) */

<<<<<<< HEAD
extern void pr_error(const char *s, int offset) {
=======
extern void pr_error(CONST char *s, int offset) {
>>>>>>> const_ptr_only
	if (s != NULL) {
		if (interactive)
			fprint(2, RC "%s\n", s);
		else
			fprint(2, RC "line %d: %s\n", lineno + offset, s);
	}
}

/* our perror */

<<<<<<< HEAD
extern void uerror(const char *s) {
	const char *err;
=======
extern void uerror(CONST char *s) {
	char *err;
>>>>>>> const_ptr_only

	err = strerror(errno);
	if (!err) err = "unknown error";

	if (s)
		fprint(2, RC "%s: %s\n", s, err);
	else
		fprint(2, RC "%s\n", err);
}

/* Die horribly. This should never get called. Please let me know if it does. */

#define PANICMSG "rc panic: "

<<<<<<< HEAD
extern void panic(const char *s) {
=======
extern void panic(CONST char *s) {
>>>>>>> const_ptr_only
	write(2, PANICMSG, conststrlen(PANICMSG));
	write(2, s, strlen(s));
	write(2, "!\n", 2);
	exit(1);
}

/* ascii -> unsigned conversion routines. -1 indicates conversion error. */

<<<<<<< HEAD
extern int n2u(const char *s, unsigned int base) {
=======
extern int n2u(CONST char *s, unsigned int base) {
>>>>>>> const_ptr_only
	unsigned int i;
	for (i = 0; *s != '\0'; s++) {
		unsigned int j = (unsigned int) *s - '0';
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
		int s = dup2(i, j);
		close(i);
		return s;
	}
	return 0;
}
