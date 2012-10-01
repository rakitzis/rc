#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv) {
	int i;
	signal(SIGCHLD, SIG_IGN);
	execvp(argv[1], &argv[1]);
}
