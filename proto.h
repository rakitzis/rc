#if HAVE_QUAD_T
typedef quad_t align_t;
#else
typedef long align_t;
#endif

/* If you need to change this, please let the maintainer know. */
#ifndef SIG_ATOMIC_T
typedef int SIG_ATOMIC_T;
#endif

#if STDC_HEADERS
#include <stdlib.h>
#else
/* fake stdlib.h */
extern void exit(int);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
#endif

#if STDC_HEADERS
#include <string.h>
#else
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
#endif

/* fake errno.h for mips (which doesn't declare errno in errno.h!?!?) */
#ifdef host_mips
extern int errno;
#endif
