/*
   This file is NOT BUILT by default.  Together with addon.c, it
   provides an example of how to add new builtins to rc.

   To define a new builtin, it must appear in the macro ADDONS, which
   is a comma-separated list of pairs of function pointers (the
   implementation of the new builtin) and string literals (the name of
   the new builtin).

   Any new builtin functions must also have proper prototypes in this
   file.  This is always of the same form.

	void b_NAME(char **av);

   The first argument, av[0], is the name of the builtin.  The last
   argument is followed by a NULL pointer.

   Builtins report their exit status using set(TRUE) or set(FALSE).

*/

#if RC_ADDON

#define ADDONS \
	{ b_sum,	"+" }, \
	{ b_prod, "x" },

extern void b_sum(char **av);
extern void b_prod(char **av);

#endif
