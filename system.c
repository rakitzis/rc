#include "rc.h"

#if HAVE_RESTARTABLE_SYSCALLS

#include "system-bsd.c"

#else

extern void writeall(int fd, char *buf, size_t remain) {
	int i;

	for (i = 0; remain > 0; buf += i, remain -= i)
		if ((i = write(fd, buf, remain)) <= 0)
			break; /* abort silently on errors in write() */
	sigchk();
}

#endif
