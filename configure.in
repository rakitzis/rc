AC_INIT(rc.h)

AC_CONFIG_HEADER(config.h)

AC_PROG_CC
case "x$GCC" in
xyes)
	CFLAGS="-Wall $CFLAGS"
	;;
esac

AC_PROG_INSTALL
AC_PROG_YACC
AC_CHECK_PROGS(LN, ln cp)

AC_CHECK_HEADERS(sys/resource.h sys/time.h sys/types.h unistd.h)
AC_HEADER_DIRENT
AC_HEADER_STDC

dnl Linux puts real signal names in /usr/include/asm/signal.h.
AC_CACHE_CHECK(for signal names in <sys/signal.h>, rc_cv_sys_signal_h,
	if grep SIGINT /usr/include/sys/signal.h >/dev/null 2>&1; then
		rc_cv_sys_signal_h=yes
	else
		rc_cv_sys_signal_h=no
	fi)

case "x$rc_cv_sys_signal_h" in
xyes)
	SIGNAL_H=/usr/include/sys/signal.h
	;;
xno)
	AC_CACHE_CHECK(for signal names in <asm/signal.h>, rc_cv_asm_signal_h,
		if grep SIGINT /usr/include/asm/signal.h >/dev/null 2>&1; then
			rc_cv_asm_signal_h=yes
		else
			rc_cv_asm_signal_h=no
		fi)

	case "x$rc_cv_asm_signal_h" in
	xyes)
		SIGNAL_H=/usr/include/asm/signal.h
		;;
	xno)
		AC_MSG_ERROR(Can't find signal names in <sys/signal.h> or <asm/signal.h>)
		;;
	esac
	;;
esac
AC_SUBST(SIGNAL_H)

AC_TYPE_GETGROUPS
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UID_T

AC_CHECK_FUNCS(getgroups setpgrp setrlimit)

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
case "x$rc_cv_kernel_rlimit" in
xyes)
	AC_DEFINE(RLIMIT_NEEDS_KERNEL)
	;;
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

case "x$rc_cv_have_rlim_t" in
xyes)
	AC_DEFINE(HAVE_RLIM_T)
	;;
xno)
	AC_CACHE_CHECK(for native quad_t, rc_cv_have_quad_t,
		AC_TRY_RUN([
#include <sys/types.h>
main() {
	quad_t q;
	q = 0;
	exit((int) q);
}
		], rc_cv_have_quad_t=yes, rc_cv_have_quad_t=no))

	case "x$rc_cv_have_quad_t" in
	xyes)
		AC_DEFINE(HAVE_QUAD_T)

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

		case "x$rc_cv_rlim_t_is_quad_t" in
		xyes)
			AC_DEFINE(RLIM_T_IS_QUAD_T)
			;;
		esac
		;;
	esac
	;;
esac

AC_SYS_RESTARTABLE_SYSCALLS

dnl Does the kernel handle `#! /interpreter'?
AC_SYS_INTERPRETER
case "x$ac_cv_sys_interpreter" in
xyes)
	AC_DEFINE(HASH_BANG)
	EXECVE=''
	;;
xno)
	EXECVE=execve.o
esac
AC_SUBST(EXECVE)

AC_CACHE_CHECK(for /dev/fd, rc_cv_sys_dev_fd,
	if test -d /dev/fd && test -r /dev/fd/0; then
		rc_cv_sys_dev_fd=yes
	elif test -d /proc/self/fd && test -r /proc/self/fd/0; then
		rc_cv_sys_dev_fd=odd
	else
		rc_cv_sys_dev_fd=no
	fi)
	
case "x$rc_cv_sys_dev_fd" in
xyes)
	AC_DEFINE(HAVE_DEV_FD)
	;;
xodd)
	AC_DEFINE(HAVE_PROC_SELF_FD)
	;;
xno)
	AC_CACHE_CHECK(for named pipes, rc_cv_sys_fifo,
		AC_DEFINE_UNQUOTED(TMPNAM, "/tmp/rc$$.0")
		AC_TRY_RUN([
#include <sys/types.h>
#include <sys/stat.h>

main() {
	exit(mknod(TMPNAM, S_IFIFO | 0666, 0) != 0);
}
		], rc_cv_sys_fifo=yes, rc_cv_sys_fifo=no, rc_cv_sys_fifo=no))
	case "x$rc_cv_sys_fifo" in
	xyes)
		AC_DEFINE(HAVE_FIFO)
		;;
	esac
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
	case "x$enableval" in
	xno)
		;;
	xyes)
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
	case "x$enableval" in
	xno|xyes)
		;;
	*)
		AC_DEFINE_UNQUOTED(DEFAULTPATH, $enableval)
	esac
],
	enable_def_path=yes)

case "x$enable_def_path" in
xyes)
	AC_CACHE_CHECK(extant directories for default path, rc_cv_def_path,[
		rc_cv_def_path=''
		for i in /usr/local/bin /usr/bin /usr/ucb /bin .; do
			if test -d $i; then
				case "x$rc_cv_def_path" in
				x)
					rc_cv_def_path=\"$i\"
					;;
				*)
					rc_cv_def_path=$rc_cv_def_path,\"$i\"
					;;
				esac
			fi
		done
		AC_DEFINE_UNQUOTED(DEFAULTPATH, $rc_cv_def_path)
	])
	;;
esac
	
AC_ARG_ENABLE(history, [  --enable-history        Build history subprograms],
	test "x$enableval" != "xno" && rc_history=yes,
	rc_history=no)
case "x$rc_history" in
xyes)
	HISTORY=history/history
	;;
esac
AC_SUBST(HISTORY)

AC_ARG_WITH(addon, [  --with-addon            Extra builtins, from addon.c ],[
	case "x$withval" in
	xyes)
		ADDON=addon.o
		;;
	xno)
		ADDON=''
		;;
	*)	
		ADDON=$withval
		;;
	esac
	])
AC_SUBST(ADDON)

AC_ARG_WITH(editline, [  --with-editline         Simmule Turner's line editing],
	AC_CHECK_LIB(edit, readline,
		AC_DEFINE(READLINE) LIBS="$LIBS -ledit",
		AC_MSG_WARN(editline library not found)))

AC_ARG_WITH(readline, [  --with-readline         Bloated GNU line editing],
	AC_CHECK_LIB(readline, readline,
		AC_DEFINE(READLINE) LIBS="$LIBS -lreadline -ltermcap",
		AC_MSG_WARN(readline library not found)))

AC_OUTPUT(Makefile)
