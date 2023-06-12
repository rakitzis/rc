/*
   This file is NOT BUILT by default.  It provides an example of how
   to add new builtins to rc.

   To define a new builtin, it must appear in the macro ADDONS, which
   is a comma-separated list of pairs of function pointers (the
   implementation of the new builtin) and string literals (the name of
   the new builtin).

   Any new builtin functions must have prototypes of the same form:

	void b_NAME(char **av);

   The first argument, av[0], is the name of the builtin.  The last
   argument is followed by a NULL pointer.

   Builtins report their exit status using set(TRUE) or set(FALSE).

*/

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

#define ADDONS \
	{ b_sum, "+" }, \
	{ b_prod, "x" },
