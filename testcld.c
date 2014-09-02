#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
        int i;
        sigset(SIGCLD, SIG_IGN);
        switch (fork()) {
        case -1:
                return 1;
        case 0:
                return 0;
        default:
		sleep(1);
                if (wait(&i) == -1 && errno == ECHILD) return 0;
                else return 1;
        }
}
