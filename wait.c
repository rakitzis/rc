#include "rc.h"

#include <errno.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/wait.h>

#include "jbwrap.h"

bool forked = FALSE;

static pid_t rc_wait(int *);

typedef struct Pid Pid;

static struct Pid {
	pid_t pid;
	int stat;
	bool alive;
	Pid *n;
} *plist = NULL;

extern pid_t rc_fork() {
	Pid *new;
	pid_t pid = fork();
	switch (pid) {
	case -1:
		uerror("fork");
		rc_error(NULL);
		/* NOTREACHED */
	case 0:
		forked = TRUE;
		plist = 0;
		sigchk();
		return 0;
	default:
		new = enew(Pid);
		new->pid = pid;
		new->alive = TRUE;
		new->n = plist;
		plist = new;
		return pid;
	}
}

extern pid_t rc_wait4(pid_t pid, int *stat, bool nointr) {
	Pid *r, *prev;

	/* Find the child on the list. */
	for (r = plist, prev = NULL; r != NULL; prev = r, r = r->n)
		if (r->pid == pid)
			break;

	/* Uh-oh, not there. */
	if (r == NULL) {
		errno = ECHILD; /* no children */
		uerror("wait");
		*stat = 0x100; /* exit(1) */
		return -1;
	}

	/* If it's still alive, wait() for it. */
	while (r->alive) {
		int ret;
		Pid *q;

		ret = rc_wait(stat);

		if (ret < 0) {
			if (errno == ECHILD)
				panic("lost child");
			if (!nointr)
				return ret;
		}

		for (q = plist; q != NULL; q = q->n)
			if (q->pid == ret) {
				q->alive = FALSE;
				q->stat = *stat;
				break;
			}
	}
	*stat = r->stat;
	if (prev == NULL)
		plist = r->n; /* remove element from head of list */
	else
		prev->n = r->n;
	efree(r);
	return pid;
}

extern List *sgetapids() {
	List *r;
	Pid *p;
	for (r = NULL, p = plist; p != NULL; p = p->n) {
		List *q;
		if (!p->alive)
			continue;
		q = nnew(List);
		q->w = nprint("%d", p->pid);
		q->m = NULL;
		q->n = r;
		r = q;
	}
	return r;
}

extern void waitforall() {
	int stat;
	while (plist != NULL) {
		int pid = rc_wait4(plist->pid, &stat, FALSE);
		if (pid > 0)
			setstatus(pid, stat);
		else
			set(FALSE);
		sigchk();
	}
}

static int gotint;
void gotint_handler(int s) {
	gotint = 1;
	signal(s, gotint_handler);
}

/*
   rc_wait: a wait() wrapper that interfaces wait() w/rc signals.
   Note that the signal queue is not checked in this fn; someone
   may want to resume the wait() without delivering any signals.
*/

static int r;
static pid_t rc_wait(int *stat) {
	void (*old)(int);

	interrupt_happened = FALSE;
	r = -1;

	gotint = 0;
	old = signal(SIGINT, gotint_handler);
	if (!sigsetjmp(slowbuf.j, 1)) {
		slow = TRUE;
		if (!interrupt_happened)
			r = wait(stat);
	}
	slow = FALSE;
	signal(SIGINT, old);
	if (gotint && old != SIG_DFL && old != SIG_IGN)
		(*old)(SIGINT);

	return r;
}
