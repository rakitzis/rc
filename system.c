#include "rc.h"

extern void writeall(int fd, char *buf, size_t remain) {
	int i;

	for (i = 0; remain > 0; buf += i, remain -= i)
		if ((i = write(fd, buf, remain)) <= 0)
			break; /* abort silently on errors in write() */
	sigchk();
}

extern int rc_read(int fd, char *buf, size_t n) {
	return read(fd, buf, n);
}

#if READLINE
extern char *rc_readline(char *prompt) {
	return readline(prompt);
}
#endif
