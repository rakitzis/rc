/* signal-safe read and write (for BSD slow devices). writeall() also
allows partial writes */

#include <errno.h>

#include "rc.h"
#include "jbwrap.h"
#include "wait.h"

Jbwrap slowbuf;
volatile sig_atomic_t slow;

static char *safe_buf;
static size_t safe_remain;

extern void writeall(int fd, char *buf, size_t remain) {
	int i;

	safe_buf = buf;
	safe_remain = remain;
	for (i = 0; safe_remain > 0; buf += i, safe_remain -= i) {
		if (sigsetjmp(slowbuf.j, 1) == 0) {
			slow = TRUE;
			if ((i = write(fd, safe_buf, safe_remain)) <= 0)
				break; /* abort silently on errors in write() */
		} else
			break;
	}
	slow = FALSE;
	sigchk();
}

extern int rc_read(int fd, char *buf, size_t n) {
	ssize_t r;

	if (sigsetjmp(slowbuf.j, 1) == 0) {
		slow = TRUE;
		r = read(fd, buf, n);
	} else {
		errno = EINTR;
		r = -1;
	}
	slow = FALSE;

	return r;
}

static int r = -1;
extern pid_t rc_wait(int *stat) {
	if (sigsetjmp(slowbuf.j, 1) == 0) {
		slow = TRUE;
		r = wait(stat);
	} else {
		errno = EINTR;
		r = -1;
	}
	slow = FALSE;

	return r;
}
