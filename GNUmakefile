# line editing library: null, edit, editline, readline, vrl
EDIT = null

# include extra builtins in addon.c
RC_ADDON = 0

# include parse tree dumper
RC_DEVELOP = 0

# if your kernel supports `#!' magic numbers
HASH_BANG = 1


srcdir = .
VPATH = $(srcdir)

VERSION := 1.7.4

PREFIX ?= /usr/local
MANPREFIX ?= $(PREFIX)/share/man

CFLAGS += -Wall
CPPFLAGS += -I. -I"$(srcdir)" -I$(PREFIX)/include -DRC_ADDON=$(RC_ADDON) \
	-DRC_DEVELOP=$(RC_DEVELOP)  -DHASH_BANG=$(HASH_BANG)
LDFLAGS += -L$(PREFIX)/lib

BINS := history mksignal mkstatval tripping
HEADERS := addon.h develop.h edit.h getgroups.h input.h jbwrap.h proto.h rc.h \
	rlimit.h stat.h wait.h
OBJS := builtins.o edit-$(EDIT).o except.o exec.o fn.o footobar.o getopt.o \
	glob.o glom.o hash.o heredoc.o input.o lex.o list.o main.o match.o \
	nalloc.o open.o parse.o print.o redir.o sigmsgs.o signal.o status.o \
	system.o tree.o utils.o var.o wait.o walk.o which.o

ifneq ($(EDIT),null)
	LDLIBS += -l$(EDIT)
endif

ifneq ($(RC_ADDON),0)
	OBJS += addon.o
endif

ifneq ($(RC_DEVELOP),0)
	OBJS += develop.o
endif

ifeq ($(HASH_BANG),0)
	OBJS += execve.o
endif

all: rc

.PHONY: all check clean distclean install trip
.SUFFIXES:
.SUFFIXES: .c .o .y
$(V).SILENT:

rc: $(OBJS)
	@echo "LINK $@"
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJS): GNUmakefile $(HDRS) config.h
system.o: system-bsd.c

.c.o:
	@echo "CC $@"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

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

$(BINS): GNUmakefile rc.h proto.h config.h

main.o: version.h

version.h: GNUmakefile .git/index
	@echo "GEN $@"
	v="$$(cd $(srcdir); git describe 2>/dev/null)"; \
	echo "#define VERSION \"$${v:-$(VERSION)}\"" >$@

.git/index:

.c:
	@echo "CC $@"
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<

check: trip

trip: rc tripping
	./rc -p <"$(srcdir)/trip.rc"

clean:
	rm -f *.o $(BINS) rc

distclean: clean
	rm -f config.h parse.[ch] sigmsgs.[ch] statval.h version.h

install: all
	@echo "INSTALL bin/rc"
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp rc $(DESTDIR)$(PREFIX)/bin/
	chmod 755 $(DESTDIR)$(PREFIX)/bin/rc
	@echo "INSTALL rc.1"
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp rc.1 $(DESTDIR)$(MANPREFIX)/man1/
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/rc.1
