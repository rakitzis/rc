#include "rc.h"

#include <errno.h>

#include "wait.h"

bool forked = FALSE;

typedef struct Pid Pid;

static struct Pid {
	pid_t pid;
	int stat;
	bool alive;
	Pid *n;
} *plist = NULL;

extern pid_t rc_fork() {
	Pid *new;
	struct Pid *p, *q;
	pid_t pid = fork();

	switch (pid) {
	case -1:
		uerror("fork");
		rc_error(NULL);
		/* NOTREACHED */
	case 0:
		forked = TRUE;
		sigchk();
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
		new->n = plist;
		plist = new;
		return pid;
	}
}

extern pid_t rc_wait4(pid_t pid, int *stat, bool nointr) {
	Pid **p, *r;

	/* Find the child on the list. */
	for (p = &plist; *p; p = &(*p)->n)
		if ((*p)->pid == pid || (pid == -1 && !(*p)->alive))
			break;

	/* Uh-oh, not there. */
	if (pid != -1 && *p == NULL) {
		errno = ECHILD; /* no children */
		uerror("wait");
		*stat = 0x100; /* exit(1) */
		return -1;
	}

	/* If it's still alive, wait() for it. */
	while (*p == NULL || (*p)->alive) {
		int ret;
		Pid **q;

		ret = rc_wait(stat);

		if (ret < 0) {
			if (errno == ECHILD)
				panic("lost child");
			if (nointr)
				continue;
			else
				return ret;
		}

		for (q = &plist; *q; q = &(*q)->n)
			if ((*q)->pid == ret) {
				if (pid == -1)
					p = q;
				(*q)->alive = FALSE;
				(*q)->stat = *stat;
				break;
			}
	}
	r = *p;
	pid = r->pid;
	*stat = r->stat;
	*p = r->n; /* remove element from list */
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
		pid_t pid = rc_wait4(-1, &stat, FALSE);
		if (pid > 0)
			setstatus(pid, stat);
		else {
			set(FALSE);
			if (errno == EINTR)
				return;
		}
		sigchk();
	}
}
