## Process this file with automake to produce Makefile.in

if HISTORY
HISTBIN = history
HISTMAN = history.1
else
HISTBIN =
HISTMAN =
endif

if H_R_S
RDWR = rdwr-bsd.c
else
RDWR = rdwr.c
endif

if N_H_B
EXECVE = execve.c
endif

bin_PROGRAMS = rc
noinst_PROGRAMS = $(HISTBIN)

rc_SOURCES = @ADDON@ builtins.c except.c exec.c fn.c footobar.c getopt.c glob.c glom.c hash.c heredoc.c input.c lex.c list.c main.c match.c nalloc.c open.c print.c redir.c sigmsgs.c signal.c status.c tree.c utils.c var.c wait.c walk.c which.c y.tab.c $(RDWR) $(EXECVE)

EXTRA_rc_SOURCES = execve.c rdwr.c rdwr-bsd.c

history_SOURCES = history.c

noinst_HEADERS = group.h jbwrap.h proto.h rc.h rlimit.h y.tab.h

BUILT_SOURCES = sigmsgs.c y.tab.c

man_MANS = rc.1 $(HISTMAN)

EXTRA_DIST = addon.c addon.h EXAMPLES history.1 mksignal parse.y rc.1 trip.rc

sigmsgs.c sigmsgs.h: $(srcdir)/mksignal
	sh $(srcdir)/mksignal @SIGNAL_H@

y.tab.c: $(srcdir)/parse.y
	$(YACC) -d $(srcdir)/parse.y

trip: rc
	./rc -p < $(srcdir)/trip.rc

install-exec-hook:
if HISTORY
	$(LN) $(HISTORY) - ;\
	$(INSTALL_PROGRAM) - $(bindir) ;\
	-rm -f $(bindir)/--;  $(LN) $(bindir)/- $(bindir)/-- ;\
	-rm -f $(bindir)/-p;  $(LN) $(bindir)/- $(bindir)/-p ;\
	-rm -f $(bindir)/--p; $(LN) $(bindir)/- $(bindir)/--p
endif
