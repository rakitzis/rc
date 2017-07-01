#include "rc.h"

extern void writeall(int fd, const char *buf, size_t remain) {
	int i = 0;

	for (; remain > 0; buf += i, remain -= i)
		if ((i = write(fd, buf, remain)) <= 0)
			break; /* abort silently on errors in write() */
	sigchk();
}
