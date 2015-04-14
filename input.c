/* input.c: i/o routines for files and pseudo-files (strings) */

#include "rc.h"

#include <errno.h>

#include "edit.h"
#include "input.h"
#include "jbwrap.h"

/* How many characters can we unget? */
enum { UNGETSIZE = 2 };

typedef enum inputtype {
	iFd, iString, iEdit
} inputtype;

typedef struct Input {
	bool saved;
	inputtype t;
	int fd, index, read, ungetcount, lineno, last;
	char *ibuf;
	void *cookie;
	int ungetbuf[UNGETSIZE];
	int (*gchar)(void);
} Input;

#define BUFSIZE ((size_t) 256)

static char *inbuf;
static size_t istacksize, chars_out, chars_in;
static bool save_lineno = TRUE;
static Input *istack, *itop;

int lastchar;

static char *prompt, *prompt2;

extern void ugchar(int c) {
	assert(istack->ungetcount < UNGETSIZE);
	istack->ungetbuf[istack->ungetcount++] = c;
}

extern int gchar() {
	int c;

	if (istack->ungetcount)
		return lastchar = istack->ungetbuf[--istack->ungetcount];

	while ((c = (*istack->gchar)()) == '\0')
		pr_error("warning: null character ignored", 0);

	return c;
}


/* get the next character from a string. */

static int stringgchar() {
	return lastchar = (inbuf[chars_out] == '\0' ? EOF : inbuf[chars_out++]);
}


/* write last command out to a file if interactive && $history is set */

static void history() {
	List *hist;
	size_t a;

	if (!interactive || (hist = varlookup("history")) == NULL)
		return;

	for (a = 0; a < chars_in; a++) {
		char c = inbuf[a];

		/* skip empty lines and comments */
		if (c == '#' || c == '\n')
			break;

		/* line matches [ \t]*[^#\n] so it's ok to write out */
		if (c != ' ' && c != '\t') {
			char *name = hist->w;
			int fd = rc_open(name, rAppend);
			if (fd < 0)
				uerror(name);
			else {
				writeall(fd, inbuf, chars_in);
				close(fd);
			}
			break;
		}
	}
}


/* read a character from a file descriptor */

static int fdgchar() {
	if (chars_out >= chars_in) { /* replenish empty buffer */
		ssize_t r;
		do {
			r = rc_read(istack->fd, inbuf, BUFSIZE);
			sigchk();
			if (r == -1)
				switch (errno) {
				case EAGAIN:
					if (!makeblocking(istack->fd))
						panic("not O_NONBLOCK");
					errno = EINTR;
					break;
				case EIO:
					if (makesamepgrp(istack->fd))
						errno = EINTR;
					else
						errno = EIO;
					break;
				}
		} while (r < 0 && errno == EINTR);
		if (r < 0) {
			uerror("read");
			rc_raise(eError);
		}
		chars_in = (size_t) r;
		if (chars_in == 0)
			return lastchar = EOF;
		chars_out = 0;
		if (dashvee)
			writeall(2, inbuf, chars_in);
		history();
	}

	return lastchar = inbuf[chars_out++];
}

/* read a character from a line-editing file descriptor */

static int editgchar() {
	if (chars_out >= chars_in) { /* replenish empty buffer */
		edit_free(istack->cookie);
		inbuf = edit_alloc(istack->cookie, &chars_in);
		if (inbuf == NULL) {
			chars_in = 0;
			fprint(2, "exit\n");
			return lastchar = EOF;
		}

		chars_out = 0;
		if (dashvee)
			writeall(2, inbuf, chars_in);
		history();
	}

	return lastchar = inbuf[chars_out++];
}

void termchange(void) {
	if (istack->t == iEdit)
		edit_reset(istack->cookie);
}


/* set up the input stack, and put a "dead" input at the bottom, so that yyparse will always read eof */

extern void initinput() {
	istack = itop = ealloc(istacksize = 256 * sizeof (Input));
	istack->ungetcount = 0;
	ugchar(EOF);
}

/* push an input source onto the stack. set up a new input buffer, and set gchar() */

static void pushcommon() {
	size_t idiff;
	istack->index = chars_out;
	istack->read = chars_in;
	istack->ibuf = inbuf;
	istack->lineno = lineno;
	istack->saved = save_lineno;
	istack->last = lastchar;
	istack++;
	idiff = istack - itop;
	if (idiff >= istacksize / sizeof (Input)) {
		itop = erealloc(itop, istacksize *= 2);
		istack = itop + idiff;
	}
	chars_out = 0;
	chars_in = 0;
	istack->ungetcount = 0;
}

extern void pushfd(int fd) {
	pushcommon();
	save_lineno = TRUE;
	istack->fd = fd;
	lineno = 1;
	if (editing && interactive && isatty(fd)) {
		istack->t = iEdit;
		istack->gchar = editgchar;
		istack->cookie = edit_begin(fd);
	} else {
		istack->t = iFd;
		istack->gchar = fdgchar;
		inbuf = ealloc(BUFSIZE);
	}
}

extern void pushstring(char **a, bool save) {
	pushcommon();
	istack->t = iString;
	save_lineno = save;
	inbuf = mprint("%A", a);
	istack->gchar = stringgchar;
	if (save_lineno)
		lineno = 1;
	else
		--lineno;
}


/* remove an input source from the stack. restore associated variables etc. */

extern void popinput() {
	if (istack->t == iEdit)
		edit_end(istack->cookie);
	if (istack->t == iFd || istack->t == iEdit)
		close(istack->fd);
	efree(inbuf);
	--istack;
	lastchar = istack->last;
	inbuf = istack->ibuf;
	chars_out = istack->index;
	chars_in = istack->read;
	if (save_lineno)
		lineno = istack->lineno;
	else
		lineno++;
	save_lineno = istack->saved;
}


/* flush input characters up to newline. Used by scanerror() */

extern void skiptonl() {
	int c;
	if (lastchar == '\n' || lastchar == EOF)
		return;
	while ((c = gchar()) != '\n' && c != EOF)
		; /* skip to newline */
	if (c == EOF)
		ugchar(c);
}


/* the wrapper loop in rc: prompt for commands until EOF, calling yyparse and walk() */

extern Node *doit(bool clobberexecit) {
	bool eof;
	bool execit;
	Jbwrap j;
	Estack e1;
	Edata jerror;

	if (dashen)
		clobberexecit = FALSE;
	execit = clobberexecit;
	sigsetjmp(j.j, 1);
	jerror.jb = &j;
	except(eError, jerror, &e1);
	for (eof = FALSE; !eof;) {
		Edata block;
		Estack e2;

		block.b = newblock();
		except(eArena, block, &e2);
		sigchk();

		if (interactive) {
			List *s;
			if (!dashen && fnlookup("prompt") != NULL) {
				static bool died = FALSE;
				static char *arglist[] = { "prompt", NULL };

				if (!died) {
					died = TRUE;
					funcall(arglist);
				}
				died = FALSE;
			}
			s = varlookup("prompt");
			if (s != NULL) {
				prompt = s->w;
				if (s->n != NULL)
					prompt2 = s->n->w;
				else
					prompt2 = "";
			} else {
				prompt = prompt2 = "";
			}
			if (istack->t == iFd)
				fprint(2, "%s", prompt);
			else if (istack->t == iEdit)
				edit_prompt(istack->cookie, prompt);
		}
		inityy();
		if (yyparse() == 1 && execit)
			rc_raise(eError);
		eof = (lastchar == EOF); /* "lastchar" can be clobbered during a walk() */
		if (parsetree != NULL) {
			if (execit)
				walk(parsetree, TRUE);
			else if (dashex && dashen)
				fprint(2, "%T\n", parsetree);
		}
		unexcept(); /* eArena */
	}
	popinput();
	unexcept(); /* eError */
	return parsetree;
}

/* parse a function imported from the environment */

extern Node *parseline(char *extdef) {
	bool i = interactive;
	char *in[2];
	Node *fun;
	in[0] = extdef;
	in[1] = NULL;
	interactive = FALSE;
	pushstring(in, TRUE);
	fun = doit(FALSE);
	interactive = i;
	return fun;
}

/* close file descriptors after a fork() */

extern void closefds() {
	Input *i;
	for (i = istack; i != itop; --i)	/* close open scripts */
		if (i->t == iFd && i->fd > 2) {
			close(i->fd);
			i->fd = -1;
		}
}

/* print (or set) prompt(2) */

extern void nextline() {
	lineno++;
	if (interactive) {
		if (istack->t == iFd)
			fprint(2, "%s", prompt2);
		else if (istack->t == iEdit)
			edit_prompt(istack->cookie, prompt2);
	}
}
