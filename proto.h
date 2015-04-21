/*
  The idea of this file is to include prototypes for all external
  functions that rc uses, either by including the appropriate header
  file, or---for older systems---declaring the functions directly.
*/

#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include <signal.h>

#if HAVE_QUAD_T
typedef quad_t align_t;
#else
typedef long align_t;
#endif

/*
  We need <stdarg.h>.  If you really need to build rc on a system which
  doesn't have it, please contact the maintainer.
*/

#include <stdarg.h>

/* C 99 specifies a va_copy() macro to be used for copying
objects of type va_list. If this doesn't exist, hope that simple
assignment works. */
#ifndef va_copy
#define va_copy(x,y) (x)=(y)
#endif

#if STDC_HEADERS

#include <stdlib.h>
#include <string.h>

#else /* STDC_HEADERS */

/* fake string.h */
extern int strncmp(const char *, const char *, size_t);
extern int strcmp(const char *, const char *);
extern size_t strlen(const char *);
extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern char *strncat(char *, const char *, size_t);
extern void *memcpy(void *, const void *, size_t);
extern void *memset(void *, int, size_t);

/* fake stdlib.h */
extern void exit(int);
extern void free(void *);
extern void *malloc(size_t);
extern void *realloc(void *, size_t);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));

#endif /* STDC_HEADERS */

#if HAVE_STRERROR
/* Smells like POSIX. */
#else
/* Assume BSD-style sys_errlist[]. */
extern int sys_nerr;
extern char *sys_errlist[];
#define strerror(x) ((0 <= (x)) && (errno < (x)) ? sys_errlist[x] : (char *)0)
#endif

#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#if HAVE_SETPGRP

#if SETPGRP_VOID
/* Smells like POSIX: should all be ok. */
#else
/* Old BSD: fake it. */
#define setpgid(pid, pgrp) setpgrp(pid, pgrp)
#include <sys/ioctl.h>
#define tcgetpgrp(fd) ioctl((fd), TIOCGPGRP)
#define tcsetpgrp(fd, pgrp) ioctl((fd), TIOCSPGRP, &(pgrp))
#endif

#else /* HAVE_SETPGRP */

/* Nothing doing. */
#define setpgid()
#define tcgetpgrp()
#define tcsetpgrp()

#endif /*HAVE_SETPGRP */


/* fake errno.h for mips (which doesn't declare errno in errno.h!?!?) */
#ifdef host_mips
extern int errno;
#endif
