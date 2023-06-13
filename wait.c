#include "rc.h"

#include <errno.h>

#include "wait.h"

bool forked = FALSE;

typedef struct Pid Pid;

static struct Pid {
	pid_t pid;
	int stat;
	bool alive;
	bool waiting;
	Pid *n;
} *plist = NULL;

extern pid_t rc_fork(void) {
	Pid *new;
	struct Pid *p, *q;
	pid_t pid = fork();

	switch (pid) {
	case -1:
		uerror("fork");
		rc_error(NULL);
		/* NOTREACHED */
		/* FALLTHRU */
	case 0:
		forked = TRUE;
		sigchk();
		clearflow();
		p = plist; q = 0;
		while (p) {
			if (q) efree(q);
			q = p;
			p = p->n;
		}
		if (q) efree(q);
		plist = 0;
		return 0;
	default:
		new = enew(Pid);
		new->pid = pid;
		new->alive = TRUE;
		new->waiting = FALSE;
		new->n = plist;
		plist = new;
		return pid;
	}
}

static int markwaiting(pid_t pid, bool clear) {
	Pid *p;
	int n = 0;
	for (p = plist; p != NULL; p = p->n)
		if (pid == -1 || p->pid == pid) {
			p->waiting = TRUE;
			n++;
		} else if (clear)
			p->waiting = FALSE;
	return n;
}

static pid_t dowait(int *stat, bool nointr) {
	Pid **p, *q;
	pid_t pid;
	for (;;) {
		for (p = &plist; *p != NULL; p = &(*p)->n) {
			q = *p;
			if (q->waiting && !q->alive) {
				pid = q->pid;
				*stat = q->stat;
				*p = q->n; /* remove element from list */
				efree(q);
				return pid;
			}
		}
		pid = rc_wait(stat);
		if (pid < 0) {
			if (errno == ECHILD)
				panic("lost child");
			if (nointr)
				continue;
			else
				return pid;
		}
		for (q = plist; q != NULL; q = q->n)
			if (q->pid == pid) {
				q->alive = FALSE;
				q->stat = *stat;
				break;
			}
	}
	/* never reached */
	return -1;
}

extern pid_t rc_wait4(pid_t pid, int *stat, bool nointr) {
	if (markwaiting(pid, TRUE) == 0) {
		/* Uh-oh, not there. */
		errno = ECHILD; /* no children */
		uerror("wait");
		*stat = 0x100; /* exit(1) */
		return -1;
	}
	return dowait(stat, nointr);
}

extern List *sgetapids(void) {
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

extern void waitforall(void) {
	int stat;
	markwaiting(-1, TRUE);
	while (plist != NULL) {
		pid_t pid = dowait(&stat, FALSE);
		if (pid > 0) {
			setstatus(pid, stat);
			if (WIFEXITED(stat))
			    fprint(2, "%ld: exited (%d)\n", pid, WEXITSTATUS(stat));
		} else {
			set(FALSE);
			if (errno == EINTR)
				return;
		}
		sigchk();
	}
}

extern void waitfor(char **av) {
	int alive, count, i, stat;
	pid_t pid;
	for (i = 0; av[i] != NULL; i++)
		if ((pid = a2u(av[i])) < 0) {
			fprint(2, RC "`%s' is a bad number\n", av[i]);
			set(FALSE);
			return;
		} else if (markwaiting(pid, i == 0) == 0) {
			fprint(2, RC "`%s' is not a child\n", av[i]);
			set(FALSE);
			return;
		}
	alive = count = i;
	if (count >= MAX_PIPELINE) {
		fprint(2, RC "too many arguments to wait\n");
		set(FALSE);
		return;
	}
	setpipestatuslength(count);
	while (alive > 0) {
		pid = dowait(&stat, FALSE);
		if (pid > 0) {
			alive--;
			for (i = 0; av[i] != NULL; i++)
				if (a2u(av[i]) == pid) {
					setpipestatus(count - i - 1, pid, stat);
					break;
				}
		} else if (errno == EINTR) {
			set(FALSE);
			return;
		}
		sigchk();
	}
}

