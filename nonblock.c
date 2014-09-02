/* Set stdin to nonblocking. */
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main(void) {
	int flags;
	flags = fcntl(0, F_GETFL);
	flags |= O_NONBLOCK;
	fcntl(0, F_SETFL, (long) flags);
	flags = read(0, &flags, 1);
	printf("read returns %d, errno == %d\n", flags, errno);
	return 0;
}
