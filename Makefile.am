## Process this file with automake to produce Makefile.in

if AMC_ADDON
ADDON = @ADDON@
endif

if AMC_HISTORY
man_MANS = rc.1 history.1
HISTORY = history
else
man_MANS = rc.1
endif

if AMC_NO_HASHBANG
EXECVE = execve.o
endif

if AMC_READLINE
READLINE = readline.o
endif

if AMC_RESTART
SYSTEM = system-bsd.o
else
SYSTEM = system.o
endif

bin_PROGRAMS = rc
noinst_PROGRAMS = mksignal mkstatval tripping $(HISTORY)

rc_SOURCES = builtins.c except.c exec.c fn.c footobar.c getopt.c glob.c glom.c hash.c heredoc.c input.c lex.c list.c main.c match.c nalloc.c open.c parse.c print.c redir.c signal.c status.c tree.c utils.c var.c wait.c walk.c which.c

EXTRA_rc_SOURCES = addon.c execve.c readline.c system.c system-bsd.c

rc_DEPENDENCIES = sigmsgs.o $(ADDON) $(EXECVE) $(READLINE) $(SYSTEM)
rc_LDADD = sigmsgs.o $(ADDON) $(EXECVE) $(READLINE) $(SYSTEM)

noinst_HEADERS = getgroups.h jbwrap.h parse.h proto.h rc.h rlimit.h wait.h

BUILT_SOURCES = sigmsgs.c

EXTRA_DIST = EXAMPLES RELDATE addon.c addon.h history.1 parse.y rc.1 trip.rc

sigmsgs.c sigmsgs.h: mksignal
	./mksignal

statval.h: mkstatval
	./mkstatval > statval.h

CONFIGURE_DEPENDENCIES = RELDATE

DISTCLEANFILES = sigmsgs.c sigmsgs.h statval.h

# Of course, parse.c and parse.h depend on parse.y.  However, unless
# you're hacking on rc's grammar, it's not useful to have this
# dependency expressed, since the distributed parse.[ch] (generated with
# byacc, and lightly edited to remove a couple of gcc warnings) are
# portable (I hope).
#parse.c parse.h: $(srcdir)/parse.y
#	$(YACC) -d $(srcdir)/parse.y
#     mv y.tab.c parse.c
#     mv y.tab.h parse.h

check: trip

trip: rc tripping
	./rc -p < $(srcdir)/trip.rc

install-exec-hook:
if AMC_HISTORY
	$(INSTALL_PROGRAM) history $(bindir)/- ;\
	rm -f $(bindir)/--;  $(LN) $(bindir)/- $(bindir)/-- ;\
	rm -f $(bindir)/-p;  $(LN) $(bindir)/- $(bindir)/-p ;\
	rm -f $(bindir)/--p; $(LN) $(bindir)/- $(bindir)/--p
endif
