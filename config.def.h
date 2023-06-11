/* Define if you want rc to hand off exec errors to (e.g.) /bin/sh. */
#define DEFAULTINTERP "/bin/sh"

/* Define to the default path used if $PATH is empty when rc starts. */
#define DEFAULTPATH "/usr/local/bin","/usr/bin","/bin","."

/* Define if your kernel has SysV special SIGCLD semantics. */
#define HAVE_SYSV_SIGCLD 1

/* Define if you have /dev/fd. */
#define HAVE_DEV_FD 1

/* Define if you have /proc/self/fd. */
#define HAVE_PROC_SELF_FD 1

/* Define if you have named pipes. */
#define HAVE_FIFO 1

/* Define if quad_t is a native type. */
/* #undef HAVE_QUAD_T */

/* Define if you have rlim_t. */
#define HAVE_RLIM_T 1

/* Define if you have sigsetjmp(). */
#define HAVE_SIGSETJMP 1

/* Define if you have strerror(). */
#define HAVE_STRERROR 1

/* Define if you want rc to encode strange characters in the environment. */
#define PROTECT_ENV 1

/* Define if you want echo as a builtin. */
#define RC_ECHO 1

/* Define if you want rc to support broken apps, like a job control shell. */
#define RC_JOB 1

/* Define if rlim_t is quad_t. */
/* #undef RLIM_T_IS_QUAD_T */

/* Define to 1 if you have the `getgroups' function. */
#define HAVE_GETGROUPS 1

/* Define if you have POSIX getgroups(). */
#define HAVE_POSIX_GETGROUPS 1

/* Define to the type of elements in the array set by `getgroups'. Usually
   this is either `int' or `gid_t'. */
#define GETGROUPS_T gid_t

/* Define to 1 if you have the `lstat' function. */
#define HAVE_LSTAT 1

/* Define to 1 if you have the `mkfifo' function. */
/* #undef HAVE_MKFIFO */

/* Define to 1 if you have the `setpgrp' function. */
#define HAVE_SETPGRP 1

/* Define to 1 if the `setpgrp' function takes no argument. */
#define SETPGRP_VOID 1

/* Define to 1 if you have the `setrlimit' function. */
#define HAVE_SETRLIMIT 1

/* Define if RLIMIT_* macros need _KERNEL. */
/* #undef RLIMIT_NEEDS_KERNEL */

/* Define to 1 if you have the `sigaction' function. */
#define HAVE_SIGACTION 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'. */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'. */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
#define HAVE_SYS_WAIT_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

