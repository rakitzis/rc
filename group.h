/* Solaris / `gcc -ansi' only defines NGROUPS_MAX in <limits.h> if
_POSIX_C_SOURCE is defined. */
#define _POSIX_C_SOURCE 1
#include <limits.h>
#undef _POSIX_C_SOURCE

#if defined(NGROUPS) && !defined(NGROUPS_MAX)
#define NGROUPS_MAX NGROUPS
#endif
