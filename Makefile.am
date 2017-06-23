## Process this file with automake to produce Makefile.in

EDIT=@EDIT@

if AMC_HISTORY
man_MANS = rc.1 history.1
HISTORY = history
else
man_MANS = rc.1
endif

if AMC_NO_HASHBANG
EXECVE = execve.o
endif

if AMC_RESTART
SYSTEM = system-bsd.o
else
SYSTEM = system.o
endif

if AMC_DEVELOP
DEVELOP = develop.o
endif

bin_PROGRAMS = rc
noinst_PROGRAMS = mksignal mkstatval tripping $(HISTORY)

rc_SOURCES = builtins.c except.c exec.c fn.c footobar.c getopt.c glob.c glom.c hash.c heredoc.c input.c lex.c list.c main.c match.c nalloc.c open.c parse.y print.c redir.c signal.c status.c tree.c utils.c var.c wait.c walk.c which.c

EXTRA_rc_SOURCES = addon.c edit-edit.c edit-editline.c edit-null.c edit-readline.c edit-vrl.c execve.c system.c system-bsd.c

rc_DEPENDENCIES = sigmsgs.o $(ADDON) $(DEVELOP) $(EDIT) $(EXECVE) $(SYSTEM)
rc_LDADD = sigmsgs.o $(ADDON) $(DEVELOP) $(EDIT) $(EXECVE) $(SYSTEM)

noinst_HEADERS = edit.h getgroups.h input.h jbwrap.h parse.h proto.h rc.h rlimit.h stat.h wait.h

BUILT_SOURCES = parse.h sigmsgs.c

EXTRA_DIST = EXAMPLES addon.c addon.h history.1 rc.1 trip.rc

AM_YFLAGS = -d

sigmsgs.c sigmsgs.h: mksignal
	./mksignal

# Newer automake's buildtime dependency tracking can't seem to figure
# this one out.
status.o: statval.h

statval.h: mkstatval
	./mkstatval > statval.h

DISTCLEANFILES = parse.c parse.h sigmsgs.c sigmsgs.h statval.h

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
