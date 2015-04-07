#include "rc.h"

#include <errno.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <readline/rltypedefs.h>

#include "edit.h"

bool editing = 1;

struct cookie {
	char *buffer;
};

void *edit_begin(int fd) {
	List *hist;
	struct cookie *c;

	rl_catch_signals = 0;
	rl_completer_quote_characters = "'";
	rl_filename_quote_characters = "\t\n !#$&'()*;<=>?@[\\]^`{|}~";

	hist = varlookup("history");
	if (hist != NULL)
		if (read_history(hist->w) != 0 && errno != ENOENT) /* ignore if missing */
			uerror(hist->w);

	c = ealloc(sizeof *c);
	c->buffer = NULL;
	return c;
}

static void edit_catcher(int sig) {
	write(2, "\n", 1);
	rc_raise(eError);
}

static char *prompt;

char *edit_alloc(void *cookie, size_t *count) {
	struct cookie *c = cookie;
	void (*oldint)(int), (*oldquit)(int);

	oldint = sys_signal(SIGINT, edit_catcher);
	oldquit = sys_signal(SIGQUIT, edit_catcher);

	c->buffer = readline(prompt);

	sys_signal(SIGINT, oldint);
	sys_signal(SIGQUIT, oldquit);

	if (c->buffer) {
		*count = strlen(c->buffer);
		if (*count)
			add_history(c->buffer);
		c->buffer[*count] = '\n';
		++*count; /* include the \n */
	}
	return c->buffer;
}

void edit_prompt(void *cookie, char *pr) {
	prompt = pr;
}

void edit_free(void *cookie) {
	struct cookie *c = cookie;

	efree(c->buffer);
	/* Set c->buffer to NULL, allowing us to "overfree" it.  This
	   is a bit of a kludge, but it's otherwise hard to deal with
	   the case where a signal causes an early return from
	   readline. */
	c->buffer = NULL;
}

void edit_end(void *cookie) {
	struct cookie *c = cookie;

	efree(c);
}

void edit_reset(void *cookie) {
	rl_reset_terminal(NULL);
}
