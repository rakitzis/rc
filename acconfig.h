/* Define to a suitable ssize_t. */
#undef ssize_t

/* Define to a suitable sig_atomic_t. */
#undef sig_atomic_t

/* Define if you want rc to hand off exec errors to (e.g.) /bin/sh. */
#undef DEFAULTINTERP

/* Define to the default path used if $PATH is empty when rc starts. */
#undef DEFAULTPATH

/* Define if your kernel has SysV special SIGCLD semantics. */
#undef HAVE_SYSV_SIGCLD

/* Define if your kernel supports `#!' magic numbers. */
#undef HASH_BANG

/* Define if you have /dev/fd. */
#undef HAVE_DEV_FD

/* Define if you have /proc/self/fd. */
#undef HAVE_PROC_SELF_FD

/* Define if you have named pipes. */
#undef HAVE_FIFO

/* Define if quad_t is a native type. */
#undef HAVE_QUAD_T

/* Define if you have rlim_t. */
#undef HAVE_RLIM_T

/* Define if you have sigsetjmp(). */
#undef HAVE_SIGSETJMP

/* Define if you want rc to encode strange characters in the environment. */
#undef PROTECT_ENV

/* Define if you have extra builtins. */
#undef RC_ADDON

/* Define if you want echo as a builtin. */
#undef RC_ECHO

/* Define if you want rc to support broken apps, like a job control shell. */
#undef RC_JOB

/* Define if you want to use editline. */
#undef EDITLINE

/* Define if you want to use GNU readline. */
#undef READLINE

/* Define if you have the older readline, with rl_deprep_terminal. */
#undef READLINE_OLD

/* Define if RLIMIT_foo defines need _KERNEL. */
#undef RLIMIT_NEEDS_KERNEL

/* Define if rlim_t is quad_t. */
#undef RLIM_T_IS_QUAD_T

/* Define to package name. */
#undef PACKAGE

/* Define to version. */
#undef VERSION

/* Define to release date. */
#undef RELDATE

/* Define if you have SA_INTERRUPT (and sigaction()). */
#undef HAVE_SA_INTERRUPT

/* Define if you have POSIX getgroups(). */
#undef HAVE_POSIX_GETGROUPS

/* Define if you have va_copy(). */
#undef HAVE_VA_COPY
