#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
	int cstatus, pstatus;
	pid_t pid;
	
	for (cstatus = 0; cstatus < 2; ++cstatus) {
		switch (pid = fork()) {
		case -1:
			perror("fork");
			return 1;
		case 0:
			_exit(cstatus);
		default:
			if (wait(&pstatus) != pid) {
				perror("wait");
				return 1;
			}
			printf("#define STATUS%d %d\n", cstatus, pstatus);
		}
	}
	return 0;
}
