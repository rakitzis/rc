/* signal.c: a Hugh-approved signal handler. */

#include "rc.h"

#include <signal.h>
#include <setjmp.h>
#include <errno.h>

#include "sigmsgs.h"
#include "jbwrap.h"


Sigfunc* sys_signal(int signum, Sigfunc* handler)
#if HAVE_SIGACTION
{
	struct sigaction new, old;

	new.sa_handler = handler;
	new.sa_flags = 0; /* clear SA_RESTART */
	sigfillset(&new.sa_mask);
	if (sigaction(signum, &new, &old) == 0)
		return old.sa_handler;
	return SIG_DFL;
}
#else
{
	return signal(signum, handler);
}
#endif

Sigfunc* sighandlers[NUMOFSIGNALS];

static volatile sig_atomic_t sigcount, caught[NUMOFSIGNALS];

static void catcher(int s) {
	if (caught[s] == 0) {
		sigcount++;
		caught[s] = 1;
	}
	sys_signal(s, catcher);

#if HAVE_RESTARTABLE_SYSCALLS
	if (slow) {
		siglongjmp(slowbuf.j, s);
	}
#endif
}

extern void sigchk(void) {
	Sigfunc* h;
	int s, i;

	if (sigcount == 0)
		return; /* ho hum; life as usual */
	if (forked)
		exit(1); /* exit unconditionally on a signal in a child process */
	for (i = 0, s = -1; i < NUMOFSIGNALS; i++)
		if (caught[i] != 0) {
			s = i;
			--sigcount;
			caught[s] = 0;
			break;
		}
	if (s == -1)
		panic("all-zero sig vector with nonzero sigcount");
	if ((h = sighandlers[s]) == SIG_DFL)
		panic("caught signal set to SIG_DFL");
	if (h == SIG_IGN)
		panic("caught signal set to SIG_IGN");
	(*h)(s);
}

extern Sigfunc* rc_signal(int s, Sigfunc* h)
{
	Sigfunc* old;
	sigchk();
	old = sighandlers[s];
	sighandlers[s] = h;
	if (h == SIG_DFL || h == SIG_IGN)
		sys_signal(s, h);
	else
		sys_signal(s, catcher);
	return old;
}

extern void initsignal(void) {
	Sigfunc* h;
	int i;

	/* Ensure that SIGCHLD is not SIG_IGN.  Solaris's rshd does this.  :-( */
	h = sys_signal(SIGCHLD, SIG_IGN);
	if (h != SIG_IGN && h != SIG_ERR)
		sys_signal(SIGCHLD, h);
	else
		sys_signal(SIGCHLD, SIG_DFL);

	for (i = 1; i < NUMOFSIGNALS; i++) {
#ifdef SIGKILL
		if (i == SIGKILL) continue;
#endif
#ifdef SIGSTOP
		if (i == SIGSTOP) continue;
#endif
		h = sys_signal(i, SIG_IGN);
		if (h != SIG_IGN && h != SIG_ERR)
			sys_signal(i, h);
		sighandlers[i] = h;
	}
}
