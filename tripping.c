/* This is an auxiliary test program for rc.  */

#include <fcntl.h>
#include <stdio.h>

void out0(void) {
	putchar('t'); putchar('r');
	putchar('\0');
	putchar('u'); putchar('e');
	putchar('\n');
}

void makenonblock(void) {
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
	case 'n':
		makenonblock();
		break;
	}
	return 0;
}
