#if HAVE_GETGROUPS
#if HAVE_POSIX_GETGROUPS
/* We love POSIX. */
#else
/* OK, so you've got getgroups, but you don't have the POSIX semantics
of a zero first argument.  The conclusion is that you're on a reasonably
pure BSD system, and we can include <sys/param.h> for NGROUPS. */
#include <sys/param.h>
#endif
#endif
