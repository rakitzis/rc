/* signal.c: a Hugh-approved signal handler. */

#include "rc.h"

#include <signal.h>
#include <setjmp.h>

#include "sigmsgs.h"
#include "jbwrap.h"

#if HAVE_SA_INTERRUPT
static void (*sys_signal(int signum, void (*handler)(int)))(int) {
	struct sigaction new, old;

	new.sa_handler = handler;
	new.sa_flags = SA_INTERRUPT;
	sigaction(signum, &new, &old);
	return old.sa_handler;
}
#else
#define sys_signal signal
#endif

void (*sighandlers[NUMOFSIGNALS])(int);

static volatile sig_atomic_t sigcount, caught[NUMOFSIGNALS];

extern void catcher(int s) {
	if (caught[s] == 0) {
		sigcount++;
		caught[s] = 1;
	}
	sys_signal(s, catcher);

#if READLINE
	if (rl_active)
		siglongjmp(rl_buf.j, s);
#endif /* READLINE */

#if HAVE_RESTARTABLE_SYSCALLS
	if (slow) {
		siglongjmp(slowbuf.j, s);
}
#endif
}

extern void sigchk() {
	void (*h)(int);
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

extern void (*rc_signal(int s, void (*h)(int)))(int) {
	void (*old)(int);
	sigchk();
	old = sighandlers[s];
	if (h == SIG_DFL || h == SIG_IGN) {
		sighandlers[s] = h;
		sys_signal(s, h);
	} else {
		sighandlers[s] = h;
		sys_signal(s, catcher);
	}
	return old;
}

extern void initsignal() {
	void (*h)(int);
	int i;

#if HAVE_SYSV_SIGCLD
	/* Ensure that SIGCLD is not SIG_IGN.  Solaris's rshd does this.  :-( */
	h = sys_signal(SIGCLD, SIG_IGN);
	if (h != SIG_IGN && h != SIG_ERR)
		sys_signal(SIGCLD, h);
	else
		sys_signal(SIGCLD, SIG_DFL);
#endif

	for (i = 1; i < NUMOFSIGNALS; i++) {
		h = sys_signal(i, SIG_IGN);
		if (h != SIG_IGN && h != SIG_ERR)
			sys_signal(i, h);
		sighandlers[i] = h;
	}
}
