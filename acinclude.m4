dnl The AC_FUNC_SETPGRP macro doesn't
dnl #include <unistd.h>, so it fails on OSF-1, where setpgrp
dnl will happily accept arguments, but the protoype doesn't
dnl have them.

AC_DEFUN(RC_FUNC_SETPGRP, [
	AC_CACHE_CHECK(for setpgrp that takes no arguments, ac_cv_func_setpgrp_void, AC_TRY_RUN([
#include <unistd.h>
/* If setpgrp() takes no arguments, this may fail to compile, but
if it compiles the call should succeed.  */
int main(void) {
	return setpgrp(1,1) != -1;
}
	], ac_cv_func_setpgrp_void=no, ac_cv_func_setpgrp_void=yes, ac_cv_func_setpgrp_void=yes))
	case "$ac_cv_func_setpgrp_void" in
	yes) AC_DEFINE(SETPGRP_VOID) ;;
	esac
])
