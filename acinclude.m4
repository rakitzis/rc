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


dnl Check for va_copy() in <stdarg.h>.  This is new in C 9x.
AC_DEFUN(RC_HAVE_VA_COPY, [
	AC_CACHE_CHECK(for va_copy(), rc_cv_have_va_copy, AC_EGREP_CPP(yes, [
#include <stdarg.h>
#ifdef va_copy
yes
#endif
], rc_cv_have_va_copy=yes, rc_cv_have_va_copy=no))
	case "$rc_cv_have_va_copy" in
	yes) AC_DEFINE(HAVE_VA_COPY) ;;
	esac
])
