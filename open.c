/* open.c: to insulate <fcntl.h> from the rest of rc. */

#include "rc.h"
#include <fcntl.h>

/*
   Opens a file with the necessary flags. Assumes the following
   declaration for redirtype:

	enum redirtype {
		rFrom, rCreate, rAppend, rHeredoc, rHerestring
	};
*/

static const int mode_masks[] = {
	/* rFrom */	O_RDONLY,
	/* rCreate */	O_TRUNC | O_CREAT | O_WRONLY,
	/* rAppend */	O_APPEND | O_CREAT | O_WRONLY
};

extern int rc_open(const char *name, redirtype m) {
	if ((unsigned) m >= arraysize(mode_masks))
		panic("bad mode passed to rc_open");
	return open(name, mode_masks[m], 0666);
}

/* make a file descriptor blocking. return value indicates whether
the desciptor was previously set to non-blocking. */

extern bool makeblocking(int fd) {
	int flags;

	if ((flags = fcntl(fd, F_GETFL)) == -1) {
		uerror("fcntl");
		rc_error(NULL);
	}
	if (! (flags & O_NONBLOCK))
		return FALSE;
	flags &= ~O_NONBLOCK;
	if (fcntl(fd, F_SETFL, (long) flags) == -1) {
		uerror("fcntl");
		rc_error(NULL);
	}
	return TRUE;
}

/* make a file descriptor the same pgrp as us.  Returns TRUE if
it changes anything. */

extern bool makesamepgrp(int fd) {
	pid_t grp;

	grp = getpgrp();

	if (tcgetpgrp(fd) == grp)
		return FALSE;

	if (tcsetpgrp(fd, grp) < 0) {
		uerror("tcsetgrp");
		return FALSE;
	}
	return TRUE;
}
