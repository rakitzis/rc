/* This is an auxiliary test program for rc.  */

#include "config.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static void out0(void) {
	putchar('t'); putchar('r');
	putchar('\0');
	putchar('u'); putchar('e');
	putchar('\n');
}

static void ctrl_a(void) {
	puts("a\001ab\002b");
}

static void makenonblock(void) {
	int flags;

	if ((flags = fcntl(0, F_GETFL)) == -1)
		perror("fcntl 1");
	flags |= O_NONBLOCK;
	if (fcntl(0, F_SETFL, (long) flags) == -1)
		perror("fcntl 2");
}

int main(int argc, char **argv) {
	switch(argv[1][0]) {
	case '0':
		out0();
		break;
	case 'a':
		ctrl_a();
		break;
	case 'n':
		makenonblock();
		break;
	}
	return 0;
}
