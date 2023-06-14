/* What a mess.  This file attempts to straighten everything out. */

#if HAVE_SETRLIMIT

#if HAVE_SYS_RESOURCE_H
#include <sys/time.h>
#if RLIMIT_NEEDS_KERNEL
#define _KERNEL
#endif
#include <sys/resource.h>
#if RLIMIT_NEEDS_KERNEL
#undef _KERNEL
#endif
#else
#include <sys/times.h>
#endif

#if HAVE_LIMITS_H
#include <limits.h>
#endif

#ifndef HAVE_RLIM_T
#if RLIM_T_IS_QUAD_T
typedef quad_t rlim_t;
#else
typedef long rlim_t;
#endif
#endif

#if HAVE_QUAD_T
#define RLIM_CONV quad_t
#define RLIM_FMT "%s \t%qd%s\n"
#else
#define RLIM_CONV long
#define RLIM_FMT "%s \t%ld%s\n"
#endif

#if defined(RLIMIT_OFILE) && !defined (RLIMIT_NOFILE)
#define RLIMIT_NOFILE RLIMIT_OFILE
#endif

struct Suffix {
	const struct Suffix *next;
	long amount;
	char *name;
};

struct Limit {
	char *name;
	int flag;
	const struct Suffix *suffix;
};
#endif /* HAVE_SETRLIMIT */
