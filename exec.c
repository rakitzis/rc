/* exec.c */

#include "rc.h"

#include <errno.h>
#include <signal.h>

#include "wait.h"

#include "rc.h"
#include "wait.h"
/*
   Takes an argument list and does the appropriate thing (calls a
   builtin, calls a function, etc.)
*/

extern void exec(List *s, bool parent) {
	char **av, **ev = NULL;
	int stat;
	pid_t pid;
	builtin_t *b;
	char *path = NULL;
	bool didfork, returning, saw_exec, saw_builtin;
	av = list2array(s, dashex);
	saw_builtin = saw_exec = FALSE;
	do {
		if (*av == NULL	|| isabsolute(*av))
			b = NULL;
		else if (!saw_builtin && fnlookup(*av) != NULL)
			b = funcall;
		else
			b = isbuiltin(*av);

		/*
		   a builtin applies only to the immmediately following
		   command, e.g., builtin exec echo hi
		*/
		saw_builtin = FALSE;

		if (b == b_exec) {
			av++;
			saw_exec = TRUE;
			parent = FALSE;
		} else if (b == b_builtin) {
			av++;
			saw_builtin = TRUE;
		}
	} while (b == b_exec || b == b_builtin);
	if (*av == NULL && saw_exec) { /* do redirs and return on a null exec */
		doredirs();
		return;
	}
	/* force an exit on exec with any rc_error, but not for null commands as above */
	if (saw_exec)
		rc_pid = -1;
	if (b == NULL) {
		path = which(*av, TRUE);
		if (path == NULL && *av != NULL) { /* perform null commands for redirections */
			set(FALSE);
			redirq = NULL;
			if (parent)
				return;
			rc_exit(1);
		}
		ev = makeenv(); /* environment only needs to be built for execve() */
	}
	/*
	   If parent & the redirq is nonnull, builtin or not it has to fork.
	   If the fifoq is nonnull, then it must be emptied at the end so we
	   must fork no matter what.
	 */
	if ((parent && (b == NULL || redirq != NULL)) || outstanding_cmdarg()) {
		pid = rc_fork();
		didfork = TRUE;
	} else {
		pid = 0;
		didfork = FALSE;
	}
	returning = (!didfork && parent);
	switch (pid) {
	case -1:
		uerror("fork");
		rc_error(NULL);
		/* NOTREACHED */
	case 0:
		if (!returning)
			setsigdefaults(FALSE);
		pop_cmdarg(FALSE);
		doredirs();

		/* null commands performed for redirections */
		if (*av == NULL || b != NULL) {
			if (b != NULL)
				(*b)(av);
			if (returning)
				return;
			rc_exit(getstatus());
		}
		rc_execve(path, (char * const *) av, (char * const *) ev);

#ifdef DEFAULTINTERP
		if (errno == ENOEXEC) {
			*av = path;
			*--av = DEFAULTINTERP;
			execve(*av, (char * const *) av, (char * const *) ev);
		}
#endif

		uerror(*av);
		rc_exit(1);
		/* NOTREACHED */
	default:
		redirq = NULL;
		rc_wait4(pid, &stat, TRUE);
		setstatus(-1, stat);
		/*
		   There is a very good reason for having this weird
		   nl_on_intr variable: when rc and its child both
		   process a SIGINT, (i.e., the child has a SIGINT
		   catcher installed) then you don't want rc to print
		   a newline when the child finally exits. Here's an
		   example: ed, <type ^C>, <type "q">. rc does not
		   and should not print a newline before the next
		   prompt, even though there's a SIGINT in its signal
		   vector.
		*/
		if (WIFEXITED(stat))
			nl_on_intr = FALSE;
		sigchk();
		nl_on_intr = TRUE;
		pop_cmdarg(TRUE);
	}
}
