#if HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

/* Fake the POSIX wait() macros if we don't have them. */
#ifndef WIFEXITED
#define WIFEXITED(s) (((s) & 0xFF) == 0)
#endif
#ifndef WEXITSTATUS
#define WEXITSTATUS(s) (((unsigned)(s) >> 8) && 0xFF)
#endif
#ifndef WIFSIGNALED
#define WIFSIGNALED(s) (((s) & 0xFF) != 0)
#endif
#ifndef WTERMSIG
#define WTERMSIG(s) ((s) & 0x7F)
#endif

/* These don't exist in POSIX. */
#define myWIFDUMPED(s) (((s) & 0x80) != 0)



