#include "rc.h"

<<<<<<< HEAD
extern void writeall(int fd, const char *buf, size_t remain) {
=======
extern void writeall(int fd, CONST char *buf, size_t remain) {
>>>>>>> const_ptr_only
	int i;

	for (i = 0; remain > 0; buf += i, remain -= i)
		if ((i = write(fd, buf, remain)) <= 0)
			break; /* abort silently on errors in write() */
	sigchk();
}
