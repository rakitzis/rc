/* signal.c: a Hugh-approved signal handler. */

#include <signal.h>
#include <setjmp.h>

#include "rc.h"
#include "sigmsgs.h"
#include "jbwrap.h"

#if HAVE_RESTARTABLE_SYSCALLS || READLINE
Jbwrap slowbuf;
volatile sig_atomic_t slow, interrupt_happened;
#endif

void (*sighandlers[NUMOFSIGNALS])(int);

static volatile sig_atomic_t sigcount, caught[NUMOFSIGNALS];

extern void catcher(int s) {
	if (caught[s] == 0) {
		sigcount++;
		caught[s] = 1;
	}
	signal(s, catcher);

#if READLINE
	if (in_readline) {
		in_readline = FALSE;
		switch (s) {
		extern int rl_pending_input;
		
		default:
			rl_clean_up_for_exit();
			rl_deprep_terminal();
			rl_clear_signals();
			rl_pending_input = 0;
			break;

/* These signals are already cleaned up by readline. */

		case SIGINT:
		case SIGALRM:
#ifdef SIGTSTP
		case SIGTSTP:
		case SIGTTOU:
		case SIGTTIN:
#endif
			break;
		}
	}
#endif /* READLINE */


#if HAVE_RESTARTABLE_SYSCALLS || READLINE
	interrupt_happened = TRUE;
	if (slow)
		siglongjmp(slowbuf.j, 1);
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
		signal(s, h);
		sighandlers[s] = h;
	} else {
		sighandlers[s] = h;
		signal(s, catcher);
	}
	return old;
}

extern void initsignal() {
	void (*h)(int);
	int i;
	for (i = 1; i < NUMOFSIGNALS; i++) {
		if ((h = signal(i, SIG_DFL)) != SIG_DFL)
			signal(i, h);
		sighandlers[i] = h;
	}

#if HAVE_SYSV_SIGCLD
	/* Ensure that SIGCLD is not SIG_IGN.  Solaris's rshd does this.  :-( */
	h = signal(SIGCLD, SIG_DFL);
	if (h != SIG_IGN)
		signal(SIGCLD, h);
#endif
}
