#ifndef STAT_H_INCLUDE
#define STAT_H_INCLUDE
#include <sys/stat.h>

#if HAVE_LSTAT
#else
#define lstat(name, buf) (stat((name), (buf)))
#endif
#endif
