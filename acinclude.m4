dnl This macro sets HAVE_POSIX_GETGROUPS if the
dnl getgroups() function accepts a zero first argument.
AC_DEFUN(RC_FUNC_GETGROUPS, [
	AC_CACHE_CHECK(for POSIX getgroups, rc_cv_func_posix_getgroups, AC_TRY_RUN([
#include <sys/types.h>
#include <unistd.h>
int main(void) {
	return getgroups(0, (void *)0) == -1;
}
	], rc_cv_func_posix_getgroups=yes, rc_cv_func_posix_getgroups=no, rc_cv_func_posix_getgroups=yes))
	case "$rc_cv_func_posix_getgroups" in
	yes) AC_DEFINE(HAVE_POSIX_GETGROUPS) ;;
	esac
])


dnl The AC_FUNC_SETPGRP macro doesn't
dnl #include <unistd.h>, so it fails on OSF-1, where setpgrp
dnl will happily accept arguments, but the protoype doesn't
dnl have them.

AC_DEFUN(RC_FUNC_SETPGRP, [
	AC_CACHE_CHECK(for setpgrp that takes no arguments, ac_cv_func_setpgrp_void, AC_TRY_RUN([
#include <unistd.h>
/* If setpgrp() takes no arguments, this may fail to compile, but
if it compiles the call should succeed.  Note that the assignments
to ac_cv_func_setpgrp_void are the other way round from what you
would expect. */
int main(void) {
	return setpgrp(1,1) != -1;
}
	], ac_cv_func_setpgrp_void=no, ac_cv_func_setpgrp_void=yes, ac_cv_func_setpgrp_void=yes))
	case "$ac_cv_func_setpgrp_void" in
	yes) AC_DEFINE(SETPGRP_VOID) ;;
	esac
])

dnl Check for va_copy() in <stdarg.h>.  This is new in C 9x.
AC_DEFUN(RC_HAVE_VA_COPY, [
	AC_CACHE_CHECK(for va_copy(), rc_cv_have_va_copy, AC_EGREP_CPP(yes, [
#ifdef va_copy
yes
#endif
], rc_cv_have_va_copy=yes, rc_cv_have_va_copy=no))
	case "$rc_cv_have_va_copy" in
	yes) AC_DEFINE(HAVE_VA_COPY) ;;
	esac
])
