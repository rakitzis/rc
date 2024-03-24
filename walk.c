/* walk.c: walks the parse tree. */

#include "rc.h"
#include "wait.h"

#include <signal.h>
#include <setjmp.h>
#include <termios.h>
#include <unistd.h>

#include "jbwrap.h"

/*
   global which indicates whether rc is executing a test;
   used by rc -e so that if (false) does not exit.
*/
bool cond = FALSE;

static bool haspreredir(Node *);
static bool isallpre(Node *);
static bool dofork(bool);
static void dopipe(Node *);
static void loop_body(Node* n);

/* Tail-recursive version of walk() */

#define WALK(x, y) { n = x; parent = y; goto top; }

/* walk the parse-tree. "obvious". */

extern bool walk(Node *nd, bool parent) {
	Node *volatile n = nd;
top:	sigchk();
	if (n == NULL) {
		if (!parent)
			exit(0);
		set(TRUE);
		return TRUE;
	}
	switch (n->type) {
	case nArgs: case nBackq: case nConcat: case nCount:
	case nFlat: case nLappend: case nRedir: case nVar:
	case nVarsub: case nWord:
		exec(glob(glom(n)), parent);	/* simple command */
		break;
	case nBody:
		walk(n->u[0].p, TRUE);
		WALK(n->u[1].p, parent);
		/* WALK doesn't fall through */
	case nNowait: {
		int pid;
		if ((pid = rc_fork()) == 0) {
#if defined(RC_JOB) && defined(SIGTTOU) && defined(SIGTTIN) && defined(SIGTSTP)
			setsigdefaults(FALSE);
			rc_signal(SIGTTOU, SIG_IGN);	/* Berkeleyized version: put it in a new pgroup. */
			rc_signal(SIGTTIN, SIG_IGN);
			rc_signal(SIGTSTP, SIG_IGN);
			setpgid(0, getpid());
#else
			setsigdefaults(TRUE);		/* ignore SIGINT, SIGQUIT, SIGTERM */
#endif
			mvfd(rc_open("/dev/null", rFrom), 0);
			walk(n->u[0].p, FALSE);
			exit(getstatus());
		}
		if (interactive)
			fprint(2, "%d\n", pid);
		varassign("apid", word(nprint("%d", pid), NULL), FALSE);
		redirq = NULL; /* kill pre-redir queue */
		break;
	}
	case nAndalso: {
		const bool oldcond = cond;
		cond = TRUE;
		if (walk(n->u[0].p, TRUE)) {
			cond = oldcond;
			WALK(n->u[1].p, parent);
		} else
			cond = oldcond;
		break;
	}
	case nOrelse: {
		const bool oldcond = cond;
		cond = TRUE;
		if (!walk(n->u[0].p, TRUE)) {
			cond = oldcond;
			WALK(n->u[1].p, parent);
		} else
			cond = oldcond;
		break;
	}
	case nBang:
		set(!walk(n->u[0].p, TRUE));
		break;
	case nIf: {
		const bool oldcond = cond;
		Node *true_cmd = n->u[1].p, *false_cmd = NULL;
		if (true_cmd != NULL && true_cmd->type == nElse) {
			false_cmd = true_cmd->u[1].p;
			true_cmd = true_cmd->u[0].p;
		}
		cond = TRUE;
		if (!walk(n->u[0].p, TRUE))
			true_cmd = false_cmd; /* run the else clause */
		cond = oldcond;
		WALK(true_cmd, parent);
		break;
	}
	case nWhile: {
		Jbwrap break_jb;
		Edata  break_data;
		Estack break_stack;
		bool testtrue;
		const bool oldcond = cond;
		cond = TRUE;
		if (!walk(n->u[0].p, TRUE)) { /* prevent spurious breaks inside test */
			cond = oldcond;
			break;
		}
		cond = oldcond;
		if (sigsetjmp(break_jb.j, 1))
			break;
		break_data.jb = &break_jb;
		except(eBreak, break_data, &break_stack);

		cond = oldcond;
		do {
			Edata  iter_data;
			Estack iter_stack;
			iter_data.b = newblock();
			except(eArena, iter_data, &iter_stack);
			loop_body(n->u[1].p);
			cond = TRUE;
			testtrue = walk(n->u[0].p, TRUE);
			cond = oldcond;
			unexcept(eArena);
		} while (testtrue);
		cond = oldcond;
		unexcept(eBreak);
		break;
	}
	case nForin: {
		List *volatile l;
		List *var = glom(n->u[0].p);
		Jbwrap break_jb;
		Edata  break_data;
		Estack break_stack;
		if (sigsetjmp(break_jb.j, 1))
			break;
		break_data.jb = &break_jb;
		except(eBreak, break_data, &break_stack);

		for (l = listcpy(glob(glom(n->u[1].p)), nalloc); l != NULL; l = l->n) {
			Edata  iter_data;
			Estack iter_stack;
			assign(var, word(l->w, NULL), FALSE);
			iter_data.b = newblock();
			except(eArena, iter_data, &iter_stack);
			loop_body(n->u[2].p);
			unexcept(eArena);
		}
		unexcept(eBreak);
		break;
	}
	case nSubshell:
		if (dofork(TRUE)) {
			setsigdefaults(FALSE);
			walk(n->u[0].p, FALSE);
			rc_exit(getstatus());
		}
		break;
	case nAssign:
		if (n->u[0].p == NULL)
			rc_error("null variable name");
		assign(glom(n->u[0].p), glob(glom(n->u[1].p)), FALSE);
		break;
	case nPipe:
		dopipe(n);
		break;
	case nNewfn: {
		List *l = glom(n->u[0].p);
		if (l == NULL)
			rc_error("null function name");
		while (l != NULL) {
			if (dashex)
				prettyprint_fn(2, l->w, n->u[1].p);
			fnassign(l->w, n->u[1].p);
			l = l->n;
		}
		set(TRUE);
		break;
	}
	case nRmfn: {
		List *l = glom(n->u[0].p);
		while (l != NULL) {
			if (dashex)
				fprint(2, "fn %S\n", l->w);
			fnrm(l->w);
			l = l->n;
		}
		set(TRUE);
		break;
	}
	case nDup:
		redirq = NULL;
		break; /* Null command */
	case nMatch: {
		List *a = glob(glom(n->u[0].p)), *b = glom(n->u[1].p);
		if (dashex)
			fprint(2, (a != NULL && a->n != NULL) ? "~ (%L) %L\n" : "~ %L %L\n", a, " ", b, " ");
		set(lmatch(a, b));
		break;
	}
	case nSwitch: {
		List *v = glom(n->u[0].p);
		while (1) {
			do {
				n = n->u[1].p;
				if (n == NULL)
					return istrue();
			} while (n->u[0].p == NULL || n->u[0].p->type != nCase);
			if (lmatch(v, glom(n->u[0].p->u[0].p))) {
				for (n = n->u[1].p; n != NULL && (n->u[0].p == NULL || n->u[0].p->type != nCase); n = n->u[1].p)
					walk(n->u[0].p, TRUE);
				break;
			}
		}
		break;
	}
	case nPre: {
		List *v;
		if (n->u[0].p->type == nRedir || n->u[0].p->type == nDup) {
			if (redirq == NULL && !dofork(parent)) /* subshell on first preredir */
				break;
			setsigdefaults(FALSE);
			qredir(n->u[0].p);
			if (!haspreredir(n->u[1].p))
				doredirs(); /* no more preredirs, empty queue */
			walk(n->u[1].p, FALSE);
			rc_exit(getstatus());
			/* NOTREACHED */
		} else if (n->u[0].p->type == nAssign) {
			if (isallpre(n->u[1].p)) {
				walk(n->u[0].p, TRUE);
				WALK(n->u[1].p, parent);
			} else {
				Estack e;
				Edata var;
				v = glom(n->u[0].p->u[0].p);
				assign(v, glob(glom(n->u[0].p->u[1].p)), TRUE);
				var.name = v->w;
				except(eVarstack, var, &e);
				walk(n->u[1].p, parent);
				varrm(v->w, TRUE);
				unexcept(eVarstack);
			}
		} else
			panic("unexpected node in preredir section of walk");
		break;
	}
	case nBrace:
		if (n->u[1].p == NULL) {
			WALK(n->u[0].p, parent);
		} else if (dofork(parent)) {
			setsigdefaults(FALSE);
			walk(n->u[1].p, TRUE); /* Do redirections */
			doredirs();
			redirq = NULL;   /* Reset redirection queue */
			walk(n->u[0].p, FALSE); /* Do commands */
			rc_exit(getstatus());
			/* NOTREACHED */
		}
		break;
	case nEpilog:
		if (n->u[0].p != NULL) {
			WALK(n->u[0].p, parent); /* Do more redirections. */
		}
		qredir(n->u[1].p);
		break;
	case nNmpipe:
		rc_error("named pipes cannot be executed as commands");
		/* NOTREACHED */
	default:
		panic("unknown node in walk");
		/* NOTREACHED */
	}
	return istrue();
}

/* checks to see whether there are any pre-redirections left in the tree */

static bool haspreredir(Node *n) {
	while (n != NULL && n->type == nPre) {
		if (n->u[0].p->type == nDup || n->u[0].p->type == nRedir)
			return TRUE;
		n = n->u[1].p;
	}
	return FALSE;
}

/* checks to see whether a subtree is all pre-command directives, i.e., assignments and redirs only */

static bool isallpre(Node *n) {
	while (n != NULL && n->type == nPre)
		n = n->u[1].p;
	return n == NULL || n->type == nRedir || n->type == nAssign || n->type == nDup;
}

/*
   A code-saver. Forks, child returns (for further processing in walk()), and the parent
   waits for the child to finish, setting $status appropriately.
*/

static bool dofork(bool parent) {
	int pid, sp;
	struct termios t;

	if (interactive)
		tcgetattr(0, &t);
	if (!parent || (pid = rc_fork()) == 0)
		return TRUE;
	redirq = NULL; /* clear out the pre-redirection queue in the parent */
	rc_wait4(pid, &sp, TRUE);
	if (interactive && WIFSIGNALED(sp))
		tcsetattr(0, TCSANOW, &t);
	setstatus(-1, sp);
	sigchk();
	return FALSE;
}

static void dopipe(Node *n) {
	int i, j, sp, pid, fd_prev, fd_out, pids[MAX_PIPELINE], p[2];
	bool intr;
	Node *r;
	struct termios t;

	if (interactive)
		tcgetattr(0, &t);
	fd_prev = fd_out = 1;
	for (r = n, i = 0; r != NULL && r->type == nPipe; r = r->u[2].p, i++) {
		if (i + 1 >= MAX_PIPELINE)
			rc_error("pipe too long");
		if (pipe(p) < 0) {
			uerror("pipe");
			rc_error(NULL);
		}
		if ((pid = rc_fork()) == 0) {
			setsigdefaults(FALSE);
			redirq = NULL; /* clear preredir queue */
			mvfd(p[0], r->u[1].i);
			if (fd_prev != 1)
				mvfd(fd_prev, fd_out);
			close(p[1]);
			walk(r->u[3].p, FALSE);
			exit(getstatus());
		}
		if (fd_prev != 1)
			close(fd_prev); /* parent must close all pipe fd's */
		pids[i] = pid;
		fd_prev = p[1];
		fd_out = r->u[0].i;
		close(p[0]);
	}
	if ((pid = rc_fork()) == 0) {
		setsigdefaults(FALSE);
		mvfd(fd_prev, fd_out);
		walk(r, FALSE);
		exit(getstatus());
		/* NOTREACHED */
	}
	redirq = NULL; /* clear preredir queue */
	close(fd_prev);
	pids[i++] = pid;

	/* collect statuses */

	intr = FALSE;
	setpipestatuslength(i);
	for (j = 0; j < i; j++) {
		rc_wait4(pids[j], &sp, TRUE);
		setpipestatus(j, -1, sp);
		intr |= WIFSIGNALED(sp);
	}
	if (interactive && intr)
		tcsetattr(0, TCSANOW, &t);
	sigchk();
}

/* From http://en.cppreference.com/w/c/program/setjmp
 * According to the C standard setjmp() must appear only in the following 4 constructs:
 *   1. switch (setjmp(args)) {statements}
 *   2. if (setjmp(args) == Const) {statements} with any of
 *             operators: ==, !=, <, >, <=, >=
 *   3. while (! setjmp(args)) {statements}
 *   4. setjmp(args);
*/
static void loop_body(Node *nd) {
	Node *volatile n = nd;
	Jbwrap cont_jb;
	Edata  cont_data;
	Estack cont_stack;

	if (sigsetjmp(cont_jb.j, 1) == 0) {
		cont_data.jb = &cont_jb;
		except(eContinue, cont_data, &cont_stack);
		walk(n, TRUE);
		unexcept(eContinue);
	}
}
