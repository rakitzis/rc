/*
   This file is NOT BUILT by default.  Together with addon.h, it
   provides an example of how to add new builtins to rc.
*/

#include "rc.h"
#include "addon.h"

void b_sum(char **av) {
	long sum = 0;

	while (*++av)
		sum += atol(*av);
	fprint(1, "%ld\n", sum);
	set(TRUE);
}

void b_prod(char **av) {
	long sum = 1;

	while (*++av)
		sum *= atol(*av);
	fprint(1, "%ld\n", sum);
	set(TRUE);
}
