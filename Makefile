PACKAGE = rc
VERSION = 1.7.4
DESCRIPTION = $$(cd "$(srcdir)"; git describe --always)

srcdir = .
VPATH = $(srcdir)

PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

CC = cc
DEF_CFLAGS = -Wall
DEF_CPPFLAGS = -I$(PREFIX)/include
DEF_LDFLAGS = -L$(PREFIX)/lib
YACC = byacc

# line editing library: null/edit/editline/readline/vrl
EDIT = readline

# if your kernel supports `#!' magic numbers
HASH_BANG = 1

# if system calls automatically restart after interruption by signal
HAVE_RESTARTABLE_SYSCALLS = 0

# include extra builtins in addon.c
RC_ADDON = 0

# include parse tree dumper
RC_DEVELOP = 0

ALL_CFLAGS = $(DEF_CFLAGS) $(CFLAGS)
REQ_CPPFLAGS = -I. -I"$(srcdir)" \
  -DPACKAGE=\"$(PACKAGE)\" -DVERSION=\"$(VERSION)\" \
  -DDESCRIPTION=\"$(DESCRIPTION)\" -DHASH_BANG=$(HASH_BANG) \
  -DHAVE_RESTARTABLE_SYSCALLS=$(HAVE_RESTARTABLE_SYSCALLS) \
  -DRC_ADDON=$(RC_ADDON) -DRC_DEVELOP=$(RC_DEVELOP)
ALL_CPPFLAGS = $(REQ_CPPFLAGS) $(DEF_CPPFLAGS) $(CPPFLAGS)
ALL_LDFLAGS = $(DEF_LDFLAGS) $(LDFLAGS)

LIB_EDIT_null =
LIB_EDIT_edit = -ledit
LIB_EDIT_editline = -leditline
LIB_EDIT_readline = -lreadline
LIB_EDIT_vrl = -lvrl
LDLIBS = $(LIB_EDIT_$(EDIT))

OBJ_ADDON_0 =
OBJ_ADDON_1 = addon.o
OBJ_DEVELOP_0 =
OBJ_DEVELOP_1 = develop.o
OBJ_EXECVE_0 = execve.o
OBJ_EXECVE_1 =
OBJ_SYSTEM_0 = system.o
OBJ_SYSTEM_1 = system-bsd.o
OBJS = $(OBJ_ADDON_$(RC_ADDON)) $(OBJ_DEVELOP_$(RC_DEVELOP)) builtins.o \
  edit-$(EDIT).o except.o exec.o $(OBJ_EXECVE_$(HASH_BANG)) fn.o footobar.o \
  getopt.o glob.o glom.o hash.o heredoc.o input.o lex.o list.o main.o match.o \
  nalloc.o open.o parse.o print.o redir.o sigmsgs.o signal.o status.o \
  $(OBJ_SYSTEM_$(HAVE_RESTARTABLE_SYSCALLS)) tree.o utils.o var.o wait.o \
  walk.o which.o
HDRS = addon.h develop.h edit.h getgroups.h input.h jbwrap.h proto.h rc.h \
  rlimit.h stat.h wait.h
BINS = history mksignal mkstatval tripping

all: rc

.PHONY: all check clean distclean install trip
.SUFFIXES:
.SUFFIXES: .c .o .y
$(V).SILENT:

rc: $(OBJS)
	@echo "LINK $@"
	$(CC) $(ALL_LDFLAGS) $(ALL_CFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJS): Makefile $(HDRS) config.h

.c.o:
	@echo "CC $@"
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS) -c -o $@ $<

config.h:
	@echo "GEN $@"
	cp "$(srcdir)/config.def.h" $@

lex.o parse.o: parse.c

.y.c:
	@echo "GEN $@"
	$(YACC) -b $* -d $<
	mv $*.tab.c $*.c
	mv $*.tab.h $*.h

builtins.o fn.o hash.o sigmsgs.o signal.o status.o: sigmsgs.c

sigmsgs.c: mksignal
	@echo "GEN $@"
	./mksignal

status.o: statval.h

statval.h: mkstatval
	@echo "GEN $@"
	./mkstatval >$@

$(BINS): Makefile rc.h proto.h config.h

.c:
	@echo "CC $@"
	$(CC) $(ALL_CPPFLAGS) $(ALL_CFLAGS) -o $@ $<

check: trip

trip: rc tripping
	./rc -p <"$(srcdir)/trip.rc"

clean:
	rm -f *.o $(BINS) rc

distclean: clean
	rm -f config.h parse.[ch] sigmsgs.[ch] statval.h

install: all
	@echo "INSTALL bin/rc"
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp rc $(DESTDIR)$(PREFIX)/bin/
	chmod 755 $(DESTDIR)$(PREFIX)/bin/rc
	@echo "INSTALL rc.1"
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp rc.1 $(DESTDIR)$(MANPREFIX)/man1/
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/rc.1

