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
	yes) AC_DEFINE(HAVE_POSIX_GETGROUPS, 1, [Define to 1 if you have the `getgroups' function with POSIX semantics.]) ;;
	esac
])


dnl We can't use AC_CHECK_FUNCS for sigsetjmp(), since it's a macro in
dnl some places.
AC_DEFUN(RC_FUNC_SIGSETJMP, [
	AC_CACHE_CHECK(for sigsetjmp, rc_cv_sigsetjmp,
		AC_TRY_LINK([
#include <setjmp.h>
		], [
sigjmp_buf e;
sigsetjmp(e, 1);
		], rc_cv_sigsetjmp=yes, rc_cv_sigsetjmp=no))
	case "$rc_cv_sigsetjmp" in
	yes)	AC_DEFINE(HAVE_SIGSETJMP, 1, [Define to 1 if you have the `sigsetjmp' function or macro.]) ;;
	esac
])

dnl Similarly, AC_CHECK_FUNCS doesn't find strerror() on NetBSD.
AC_DEFUN(RC_FUNC_STRERROR, [
	AC_CACHE_CHECK(for strerror, rc_cv_strerror,
		AC_TRY_LINK([
#include <string.h>
		], [
strerror(0);
		], rc_cv_strerror=yes, rc_cv_strerror=no))
	case "$rc_cv_strerror" in
	yes)	AC_DEFINE(HAVE_STRERROR, 1, [Define to 1 if you have the `strerror' function or macro.]) ;;
	esac
])

dnl HPUX needs _KERNEL defined to pick up RLIMIT_foo defines.  (Why?)
AC_DEFUN(RC_NEED_KERNEL, [
	AC_CACHE_CHECK(if _KERNEL is required for RLIMIT defines, rc_cv_kernel_rlimit,
		AC_TRY_COMPILE([
#include <sys/types.h>
#include <sys/resource.h>
		], [
int f;
f = RLIMIT_DATA;
		], rc_cv_kernel_rlimit=no, [ AC_TRY_COMPILE([
#include <sys/types.h>
#define _KERNEL
#include <sys/resource.h>
#undef _KERNEL
			], [
int f;
f = RLIMIT_DATA;
			], rc_cv_kernel_rlimit=yes, rc_cv_kernel_rlimit=no)]))
	case "$rc_cv_kernel_rlimit" in
	yes)	AC_DEFINE(RLIMIT_NEEDS_KERNEL, 1, [Define to 1 if `_KERNEL' must be defined for `RLIMIT_*' macros.]) ;;
	esac
])

dnl Look for rlim_t in sys/types.h and sys/resource.h
AC_DEFUN(RC_TYPE_RLIM_T, [
	AC_CACHE_CHECK(for rlim_t, rc_cv_have_rlim_t,
		AC_EGREP_CPP(rlim_t, [
#include <sys/types.h>
#if RLIMIT_NEEDS_KERNEL
#define _KERNEL
#endif
#include <sys/resource.h>
		], rc_cv_have_rlim_t=yes, rc_cv_have_rlim_t=no))

	case "$rc_cv_have_rlim_t" in
	yes)	AC_DEFINE(HAVE_RLIM_T, 1, [Define to 1 if you have the `rlim_t' type.]) ;;
	no)	AC_CACHE_CHECK(for native quad_t, rc_cv_have_quad_t,
			AC_TRY_COMPILE([
#include <sys/types.h>
			], [
typedef quad_t align_t;
align_t a;
a = (quad_t)0;
			], rc_cv_have_quad_t=yes, rc_cv_have_quad_t=no))

		case "$rc_cv_have_quad_t" in
		yes)	AC_DEFINE(HAVE_QUAD_T, 1, [Define to 1 if you have the `quad_t' type.])
			AC_CACHE_CHECK(if rlimit values are quad_t, rc_cv_rlim_t_is_quad_t,
				AC_TRY_RUN([
#include <sys/types.h>
#include <sys/time.h>
#include <sys/types.h>
#if RLIMIT_NEEDS_KERNEL
#define _KERNEL
#endif
#include <sys/resource.h>
#if RLIMIT_NEEDS_KERNEL
#undef _KERNEL
#endif
main(){
	struct rlimit rl;
	exit(sizeof rl.rlim_cur != sizeof(quad_t));
}
				], rc_cv_rlim_t_is_quad_t=yes, rc_cv_rlim_t_is_quad_t=no, $ac_cv_type_quad_t))

			case "$rc_cv_rlim_t_is_quad_t" in
			yes)	AC_DEFINE(RLIM_T_IS_QUAD_T, 1, [Define to 1 if `rlim_t' is `quad_t'.]) ;;
			esac
			;;
		esac
		;;
	esac
])


dnl Check type of sig_atomic_t.
AC_DEFUN(RC_TYPE_SIG_ATOMIC_T, [
	AC_CACHE_CHECK(for sig_atomic_t, rc_cv_sig_atomic_t,
		AC_EGREP_HEADER(sig_atomic_t, signal.h,
			rc_cv_sig_atomic_t=yes, rc_cv_sig_atomic_t=no))
	case "$rc_cv_sig_atomic_t" in
	no)	AC_DEFINE(sig_atomic_t, int, [Define to 1 if you have the `sig_atomic_t' type.]) ;;
	esac
])


dnl Do we have SysV SIGCLD semantics?  In other words, if we set the
dnl action for SIGCLD to SIG_IGN does wait() always say ECHILD?  Linux,
dnl of course, is bizarre here.  It basically implements the SysV
dnl semantics, but if the parent calls wait() before the child calls
dnl exit(), wait() returns with the PID of the child as normal.  (Real
dnl SysV waits for all children to exit, then returns with ECHILD.)
dnl Anyway, this is why the `sleep(1)' is there.
AC_DEFUN(RC_SYS_V_SIGCLD, [
	AC_CACHE_CHECK(for SysV SIGCLD semantics, rc_cv_sysv_sigcld,
		AC_TRY_RUN([
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
	int i;
	signal(SIGCLD, SIG_IGN);
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
		], rc_cv_sysv_sigcld=yes, rc_cv_sysv_sigcld=no, rc_cv_sysv_sigcld=yes))
	case "$rc_cv_sysv_sigcld" in
	yes)	AC_DEFINE(HAVE_SYSV_SIGCLD, 1, [Has SysV SIGCLD]) ;;
	esac
])


dnl Do we have /dev/fd or /proc/self/fd?
AC_DEFUN(RC_SYS_DEV_FD, [
	AC_CACHE_CHECK(for /dev/fd, rc_cv_sys_dev_fd,
		if test -d /dev/fd && test -r /dev/fd/0; then
			rc_cv_sys_dev_fd=yes
		elif test -d /proc/self/fd && test -r /proc/self/fd/0; then
			rc_cv_sys_dev_fd=odd
		else
			rc_cv_sys_dev_fd=no
		fi
	)
])


dnl Can mknod make FIFOs?
AC_DEFUN(RC_SYS_MKNOD_FIFO, [
	AC_CACHE_CHECK(for mknod FIFOs, rc_cv_sys_fifo,
		AC_TRY_RUN([
#include <sys/types.h>
#include <sys/stat.h>

main() {
	exit(mknod("/tmp/rc$$.0", S_IFIFO | 0666, 0) != 0);
}
		], rc_cv_sys_fifo=yes, rc_cv_sys_fifo=no, rc_cv_sys_fifo=no))
	rm -f /tmp/rc$$.0
	case "$rc_cv_sys_fifo" in
	yes)	AC_DEFINE(HAVE_FIFO) ;;
	esac
])

dnl Where is tgetent()?
AC_DEFUN(RC_LIB_TGETENT, [
	AC_CHECK_LIB(termcap, tgetent,
		rc_lib_tgetent=-ltermcap,
		AC_CHECK_LIB(ncurses, tgetent,
			rc_lib_tgetent=-lncurses,
			AC_MSG_ERROR(tgetent not found)
		)
	)
])
