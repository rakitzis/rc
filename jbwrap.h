#include <setjmp.h>

/* If we have POSIX sigjmp_buf and friends, use them.  If we don't, just
use a jmp_buf.  This probably fails on a traditional SysV machine, where
jmp_bufs don't preserve signal masks.  I'm not worrying about this till
someone reports it as a bug :-). */

#if HAVE_SIGSETJMP
#else
#define sigjmp_buf jmp_buf
#define sigsetjmp(x,y) setjmp(x)
#define siglongjmp longjmp
#endif /* HAVE_SIGSETJMP */


/* Certain braindamaged environments don't define jmp_buf as an array,
so wrap it in a structure.  Potentially, we could use configure to do
this only where it needs to be done, but the effort is probably not
worth it. */

struct Jbwrap {
	sigjmp_buf j;
};
