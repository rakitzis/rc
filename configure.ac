dnl Get things going...
AC_INIT(rc.h)

RELDATE=`cat $srcdir/RELDATE`
AC_DEFINE_UNQUOTED(RELDATE, "$RELDATE")

dnl Automake stuff.
dnl Use this one for snapshots...
dnl AM_INIT_AUTOMAKE(rc, 1.6s`echo $RELDATE |sed 's/-//g'`)
dnl ...and this one for releases
AM_INIT_AUTOMAKE(rc, 1.6c5)

AM_CONFIG_HEADER(config.h)

dnl Find a standard C compiler
AC_PROG_CC
AM_PROG_CC_STDC

dnl If we're using gcc, specify `-Wall'.  I've also checked the code
dnl with `-pedantic -W -Wall -Wpointer-arith -Wstrict-prototypes
dnl -Wmissing-prototypes', and checked that all the warnings generated
dnl are harmless.
case "$GCC" in
yes) CFLAGS="-Wall $CFLAGS" ;;
esac

AC_SYS_LARGEFILE

AC_PROG_CPP
AC_CHECK_PROGS(LN, ln cp)

AC_CHECK_HEADERS(sys/resource.h sys/time.h sys/types.h unistd.h)
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT

AC_TYPE_GETGROUPS
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_UID_T
AC_CHECK_TYPE(ssize_t, long)

AC_CHECK_FUNCS(getgroups setpgrp setrlimit)
RC_FUNC_GETGROUPS

RC_FUNC_SIGSETJMP

AC_FUNC_SETPGRP

RC_FUNC_STRERROR

RC_NEED_KERNEL

RC_TYPE_RLIM_T

RC_TYPE_SIG_ATOMIC_T

dnl We prefer system calls that don't restart.  If we have sigaction()
dnl and SA_INTERRUPT, we'll use 'em.  Otherwise, we check whether good
dnl ol' signal() produces interruptible system calls.
RC_FUNC_SIGACTION
case "$rc_cv_sa_int" in
yes)	AC_DEFINE(HAVE_SA_INTERRUPT) ;;
no) AC_SYS_RESTARTABLE_SYSCALLS ;;
esac
AM_CONDITIONAL(AMC_RESTART, test "$ac_cv_sys_restartable_syscalls" = yes)

RC_SYS_V_SIGCLD

dnl Does the kernel handle `#! /interpreter'?
AC_SYS_INTERPRETER
case "$ac_cv_sys_interpreter" in
yes)  AC_DEFINE(HASH_BANG) ;;
esac
AM_CONDITIONAL(AMC_NO_HASHBANG, test "$ac_cv_sys_interpreter" = no)


dnl What do we do for command arguments?  We want /dev/fd or Linux's
dnl /proc/self/fd.  Failing that, we'll try for POSIX mkfifo(), or a
dnl mknod() that makes FIFOs.
RC_SYS_DEV_FD
case "$rc_cv_sys_dev_fd" in
yes)	AC_DEFINE(HAVE_DEV_FD) ;;
odd)	AC_DEFINE(HAVE_PROC_SELF_FD) ;;
no)	AC_CHECK_FUNCS(mkfifo) ;;
esac

case "$ac_cv_func_mkfifo" in
yes)	AC_DEFINE(HAVE_FIFO) ;;
no)	RC_SYS_MKNOD_FIFO ;;
esac

dnl Now handle arguments.
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
                          (/usr/local/bin /usr/bin /usr/bsd /usr/ucb /bin .)]],
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
		for i in /usr/local/bin /usr/bin /usr/bsd /usr/ucb /bin .; do
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

if test "${with_vrl+set}" = set -o "${with_readline+set}" = set; then
	RC_LIB_TGETENT
fi

AC_ARG_WITH(vrl, [  --with-vrl              Gert-Jan Vons's line editing],
	AC_CHECK_LIB(vrl, readline,
		AC_DEFINE(EDITLINE) LIBS="$LIBS -lvrl $rc_lib_tgetent",
		AC_MSG_ERROR(vrl library not found), $rc_lib_tgetent))

dnl There are (at least) two incompatible versions of readline, and we
dnl need to know which one we are using.  We don't support readline 2.0.
AC_ARG_WITH(readline, [  --with-readline         Bloated GNU line editing], [
	AC_CHECK_LIB(readline, readline, [
		AC_DEFINE(READLINE)
		LIBS="$LIBS -lreadline $rc_lib_tgetent"
		AC_CHECK_LIB(readline, _rl_clean_up_for_exit, , AC_DEFINE(READLINE_OLD), $rc_lib_tgetent)
	], AC_MSG_ERROR(readline library not found), $rc_lib_tgetent)
])
AM_CONDITIONAL(AMC_READLINE, test "${with_readline+set}" = set)

dnl For some reason CPPFLAGS doesn't get propagated.
AC_SUBST(CPPFLAGS)

AC_OUTPUT(Makefile)
