## Process this file with automake to produce Makefile.in

if HISTORY
man_MANS = rc.1 history.1
HIST = history
else
man_MANS = rc.1
endif

if H_R_S
SYSTEM = system-bsd.o
else
SYSTEM = system.o
endif

if N_H_B
EXECVE = execve.o
endif

if READLINE
RLO = readline.o
endif

bin_PROGRAMS = rc
noinst_PROGRAMS = mksignal $(HIST)

rc_SOURCES = @ADDON@ builtins.c except.c exec.c fn.c footobar.c getopt.c glob.c glom.c hash.c heredoc.c input.c lex.c list.c main.c match.c nalloc.c open.c print.c redir.c sigmsgs.c signal.c status.c tree.c utils.c var.c wait.c walk.c which.c y.tab.c

EXTRA_rc_SOURCES = execve.c readline.c system.c system-bsd.c

rc_DEPENDENCIES = $(SYSTEM) $(EXECVE) $(RLO)
rc_LDADD = $(SYSTEM) $(EXECVE) $(RLO)

mksignal_SOURCES = mksignal.c

noinst_HEADERS = group.h jbwrap.h proto.h rc.h rlimit.h y.tab.h

BUILT_SOURCES = sigmsgs.c y.tab.c


EXTRA_DIST = addon.c addon.h EXAMPLES history.1 parse.y rc.1 trip.rc

sigmsgs.c sigmsgs.h: ./mksignal
	./mksignal

y.tab.c: $(srcdir)/parse.y
	$(YACC) -d $(srcdir)/parse.y

trip: rc
	./rc -p < $(srcdir)/trip.rc

install-exec-hook:
if HISTORY
	$(LN) history - ;\
	$(INSTALL_PROGRAM) - $(bindir) ;\
	rm -f $(bindir)/--;  $(LN) $(bindir)/- $(bindir)/-- ;\
	rm -f $(bindir)/-p;  $(LN) $(bindir)/- $(bindir)/-p ;\
	rm -f $(bindir)/--p; $(LN) $(bindir)/- $(bindir)/--p
endif
