AC_INIT(rc.h)

dnl Automake stuff.
AM_INIT_AUTOMAKE(rc, 1.5b3)
AM_CONFIG_HEADER(config.h)

AC_ARG_PROGRAM

AC_DEFINE(RELDATE, "1998-07-16")

dnl If we're using gcc, specify `-Wall'.  I've also checked the code
dnl with `-pedantic -W -Wall -Wpointer-arith -Wstrict-prototypes
dnl -Wmissing-prototypes', and checked that all the warnings generated
dnl are harmless.
AC_PROG_CC
case "$GCC" in
yes) CFLAGS="-Wall $CFLAGS" ;;
esac

AC_PROG_CPP
AC_PROG_INSTALL
AC_CHECK_PROGS(LN, ln cp)

dnl Don't bother looking for `yacc'.  
dnl AC_PROG_YACC

AC_CHECK_HEADERS(sys/resource.h sys/time.h sys/types.h unistd.h)
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

AC_TYPE_GETGROUPS
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UID_T
AC_CHECK_TYPE(ssize_t, long)

dnl Check type of sig_atomic_t.
AC_CACHE_CHECK(for sig_atomic_t, rc_cv_sig_atomic_t,
	AC_EGREP_HEADER(sig_atomic_t, signal.h,
		rc_cv_sig_atomic_t=yes, rc_cv_sig_atomic_t=no))
case "$rc_cv_sig_atomic_t" in
no)	AC_DEFINE(sig_atomic_t, int) ;;
esac

AC_CHECK_FUNCS(getgroups setpgrp setrlimit)


dnl sigsetjmp() isn't a real function in some places.
AC_CACHE_CHECK(for sigsetjmp, rc_cv_sigsetjmp,
	AC_TRY_LINK([
#include <setjmp.h>
	], [
sigjmp_buf e;
sigsetjmp(e, 1);
	], rc_cv_sigsetjmp=yes, rc_cv_sigsetjmp=no))
case "$rc_cv_sigsetjmp" in
yes)	AC_DEFINE(HAVE_SIGSETJMP) ;;
esac


AC_FUNC_SETPGRP


dnl HPUX needs _KERNEL defined to pick up RLIMIT_foo defines.  (Why?)
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
yes)	AC_DEFINE(RLIMIT_NEEDS_KERNEL) ;;
esac


dnl Look for rlim_t in sys/types.h and sys/resource.h
AC_CACHE_CHECK(for rlim_t, rc_cv_have_rlim_t,
	AC_EGREP_CPP(rlim_t, [
#include <sys/types.h>
#if RLIMIT_NEEDS_KERNEL
#define _KERNEL
#endif
#include <sys/resource.h>
	], rc_cv_have_rlim_t=yes, rc_cv_have_rlim_t=no))

case "$rc_cv_have_rlim_t" in
yes)	AC_DEFINE(HAVE_RLIM_T) ;;
no)	AC_CACHE_CHECK(for native quad_t, rc_cv_have_quad_t,
		AC_TRY_COMPILE([
#include <sys/types.h>
		], [
typedef quad_t align_t;
align_t a;
a = (quad_t)0;
		], rc_cv_have_quad_t=yes, rc_cv_have_quad_t=no))

	case "$rc_cv_have_quad_t" in
	yes)	AC_DEFINE(HAVE_QUAD_T)
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
		yes)	AC_DEFINE(RLIM_T_IS_QUAD_T) ;;
		esac
		;;
	esac
	;;
esac

AC_SYS_RESTARTABLE_SYSCALLS
AM_CONDITIONAL(AMC_RESTART, test "$ac_cv_sys_restartable_syscalls" = yes)

dnl Do we have SysV SIGCLD semantics?  In other words, if we set the
dnl action for SIGCLD to SIG_IGN does wait() always say ECHILD?
AC_CACHE_CHECK(for SysV SIGCLD semantics, rc_cv_sysv_sigcld,
	AC_TRY_RUN([
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
		if (wait(&i) == -1 && errno == ECHILD) return 0;
		else return 1;
	}
}
	], rc_cv_sysv_sigcld=yes, rc_cv_sysv_sigcld=no, rc_cv_sysv_sigcld=yes))
case "$rc_cv_sysv_sigcld" in
yes)	AC_DEFINE(HAVE_SYSV_SIGCLD) ;;
esac


dnl Does the kernel handle `#! /interpreter'?
AC_SYS_INTERPRETER
case "$ac_cv_sys_interpreter" in
yes)  AC_DEFINE(HASH_BANG) ;;
esac
AM_CONDITIONAL(AMC_NO_HASHBANG, test "$ac_cv_sys_interpreter" = no)


dnl What do we do for command arguments?  We want /dev/fd or Linux's
dnl /proc/self/fd.  Failing that, we'll try for POSIX mkfifo(), or a
dnl mknod() that makes FIFOs.
AC_CACHE_CHECK(for /dev/fd, rc_cv_sys_dev_fd,
	if test -d /dev/fd && test -r /dev/fd/0; then
		rc_cv_sys_dev_fd=yes
	elif test -d /proc/self/fd && test -r /proc/self/fd/0; then
		rc_cv_sys_dev_fd=odd
	else
		rc_cv_sys_dev_fd=no
	fi)
	
case "$rc_cv_sys_dev_fd" in
yes)	AC_DEFINE(HAVE_DEV_FD) ;;
odd)	AC_DEFINE(HAVE_PROC_SELF_FD) ;;
no)	AC_CHECK_FUNCS(mkfifo) ;;
esac

case "$ac_cv_func_mkfifo" in
yes)	AC_DEFINE(HAVE_FIFO) ;;
no)	AC_CACHE_CHECK(for mknod FIFOs, rc_cv_sys_fifo,
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
	;;
esac

AC_ARG_ENABLE(builtin-echo, [  --disable-builtin-echo  Don't include \`echo' as a builtin],
	test "x$enableval" != "xno" && AC_DEFINE(RC_ECHO),
	AC_DEFINE(RC_ECHO))

AC_ARG_ENABLE(job, [  --disable-job           Don't do job-control-style backgrounding],
	test "x$enableval" != "xno" && AC_DEFINE(RC_JOB),
	AC_DEFINE(RC_JOB))

AC_ARG_ENABLE(protect-env, [  --disable-protect-env   Don't protect environment names],
	test "x$enableval" != "xno" && AC_DEFINE(PROTECT_ENV),
	AC_DEFINE(PROTECT_ENV))

AC_ARG_ENABLE(def-interp,
[  --enable-def-interp=/bin/foo
                          Use /bin/foo as default interpreter [/bin/sh]],
[
	case "$enableval" in
	no)
		;;
	yes)
		AC_DEFINE(DEFAULTINTERP, "/bin/sh")
		;;
	*)
		AC_DEFINE_UNQUOTED(DEFAULTINTERP, "$enableval")
	esac
],
	AC_DEFINE(DEFAULTINTERP, "/bin/sh"))

AC_ARG_ENABLE(def-path,
[  --enable-def-path=\"/usr/local/bin/\",\"/usr/bin\"
                          Default path [All of these that exist
                          (/usr/local/bin /usr/bin /usr/ucb /bin .)]],
[
	case "$enableval" in
	no|yes)	;;
	*)	AC_DEFINE_UNQUOTED(DEFAULTPATH, $enableval) ;;
	esac
],
	enable_def_path=yes)

case "$enable_def_path" in
yes)	AC_CACHE_CHECK(extant directories for default path, rc_cv_def_path,[
		rc_cv_def_path=''
		for i in /usr/local/bin /usr/bin /usr/ucb /bin .; do
			if test -d $i; then
				case "$rc_cv_def_path" in
				'')	rc_cv_def_path=\"$i\" ;;
				*)	rc_cv_def_path=$rc_cv_def_path,\"$i\" ;;
				esac
			fi
		done
	])
	AC_DEFINE_UNQUOTED(DEFAULTPATH, $rc_cv_def_path)
	;;
esac

AC_ARG_WITH(history,
	[  --with-history          Build history subprograms],[
	case "$withval" in
        yes) rc_history=yes ;;
        *) rc_history=no ;;
        esac
	], rc_history=no)
AM_CONDITIONAL(AMC_HISTORY, test "$rc_history" = yes)


AC_ARG_WITH(addon, [  --with-addon[=foo.c]    Extra builtins, from addon.c by default ],[
	case "$withval" in
	yes)	ADDON=addon.o ;;
	no)	ADDON='' ;;
	*)	ADDON=`echo $withval |sed 's/\.c$/\.o/'` ;;
	esac
])
AM_CONDITIONAL(AMC_ADDON, test "$ADDON" != "")
case "$ADDON" in
?*) AC_DEFINE(RC_ADDON) ;;
esac
AC_SUBST(ADDON)


AC_ARG_WITH(editline, [  --with-editline         Simmule Turner's line editing],
	AC_CHECK_LIB(edit, readline,
		AC_DEFINE(EDITLINE) LIBS="$LIBS -ledit",
		AC_MSG_ERROR(editline library not found)))

AC_ARG_WITH(vrl, [  --with-vrl              Gert-Jan Vons's line editing],
	AC_CHECK_LIB(readline, readline,
		AC_DEFINE(EDITLINE) LIBS="$LIBS -lreadline -ltermcap",
		AC_MSG_ERROR(vrl library not found), -ltermcap))

dnl There are (at least) two incompatible versions of readline, and we
dnl need to know which one we are using.  We don't support readline 2.0.
AC_ARG_WITH(readline, [  --with-readline         Bloated GNU line editing], [
	AC_CHECK_LIB(readline, readline, [
		AC_DEFINE(READLINE)
		LIBS="$LIBS -lreadline -ltermcap"
		AC_CHECK_LIB(readline, _rl_clean_up_for_exit, , AC_DEFINE(READLINE_OLD), -ltermcap)
	], AC_MSG_ERROR(readline library not found), -ltermcap)
])
AM_CONDITIONAL(AMC_READLINE, test "${with_readline+set}" = set)

dnl For some reason CPPFLAGS doesn't get propagated.
AC_SUBST(CPPFLAGS)

AC_OUTPUT(Makefile)
