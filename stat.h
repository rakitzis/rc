#include <sys/stat.h>

#if HAVE_LSTAT
#else
#define lstat(name, buf) (stat((name), (buf)))
#endif
