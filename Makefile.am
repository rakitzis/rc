## Process this file with automake to produce Makefile.in

bin_PROGRAMS = rc @HISTORY@

EXTRA_PROGRAMS = history

rc_SOURCES = @ADDON@ builtins.c except.c exec.c execve.c fn.c footobar.c getopt.c glob.c glom.c hash.c heredoc.c input.c lex.c list.c main.c match.c nalloc.c open.c print.c redir.c sigmsgs.c signal.c status.c tree.c utils.c var.c version.c wait.c walk.c which.c y.tab.c

noinst_HEADERS = addon.h group.h jbwrap.h proto.h rc.h rlimit.h y.tab.h

noinst_DATA = EXAMPLES mksignal parse.y trip.rc

BUILT_SOURCES = sigmsgs.c sigmsgs.h y.tab.c y.tab.h

sigmsgs.c sigmsgs.h: $(srcdir)/mksignal
	sh $(srcdir)/mksignal @SIGNAL_H@

y.tab.c: $(srcdir)/parse.y
	$(YACC) -d $(srcdir)/parse.y

trip: rc
	./rc -p < $(srcdir)/trip.rc
