#include "rc.h"

#include <errno.h>

#include <sys/types.h>

#include "edit.h"

bool editing = 0;

void *edit_init(int fd) {
	/* this function deliberately left blank */
	return NULL;
}

char *edit_alloc(void *cookie, int *count) {
	char *buf;
	int size, used;
	ssize_t r;

	used = 0;
	size = 1;
	buf = ealloc(size + 1); /* leave room for terminating \0 */
	do {
		if (used >= size) { /* >= leaves room for terminating \0 */
			size = size * 2;
			buf = erealloc(buf, size);
		}
		do {
			r = rc_read(0, buf + used, size - used);
			sigchk();
			if (r == -1)
				switch (errno) {
				case EAGAIN:
					if (!makeblocking(0))
						panic("not O_NONBLOCK");
					errno = EINTR;
					break;
				case EIO:
					if (makesamepgrp(0))
						errno = EINTR;
					else
						errno = EIO;
					break;
				}
		} while (r < 0 && errno == EINTR);

		if (r == 0)
			return NULL;

		used += r;
		buf[used] = '\0';
	} while (strchr(buf, '\n') == NULL);

	*count = used;
	if (used)
		return buf;
	else
		return NULL;
}

void edit_prompt(void *cookie, char *prompt) {
	fprint(2, "%s", prompt);
}

void edit_free(void *buffer) {
	efree(buffer);
}

void edit_end(void *cookie) {
	/* this function deliberately left blank */
}
