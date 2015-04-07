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

/* teach readline how to quote a filename in rc */
static char *quote(char *text, int type, char *qp) {
	char *p, *r;

	/* worst case: string is entirely quote characters each of which will
	 * be doubled, plus space for initial and final quotes and \0 */
	p = r = malloc(strlen(text) * 2 + 3);
	if (!r) return 0;
	/* supply opening quote unless already there */
	if (*qp != '\'')
		*p++ = '\'';
	while (*text) {
		if (*text == '\'')
			*p++ = '\''; /* double existing quote */
		*p++ = *text++;
	}
	if (type == SINGLE_MATCH)
		*p++ = '\'';
	*p = '\0';
	return r;
}

char *unquote(char *text, int unused) {
	char *p, *r;

	p = r = malloc(strlen(text) + 1);
	if (!r) return 0;
	while (*text) {
		*p++ = *text++;
		if (*(text - 1) == '\'' && *text == '\'') ++text;
	}
	*p = '\0';
	return r;
}
static char **complete(const char *text, int start, int end) {
	//fprintf(stderr, "completer called on %s with %d and %d", text, start, end);
	/* we can look at rl_line_buffer to see whether to complete as a
	 * command or a filename (should we do variables too?). for now, assume
	 * it's a filename */
	/* it's a filename: let readline do it's default thing */
	return 0;
}

void *edit_begin(int fd) {
	List *hist;
	struct cookie *c;

	rl_catch_signals = 0;
	rl_completer_quote_characters = "'";
	rl_basic_word_break_characters = " \t\n`@$><=;|&{(";
	rl_basic_quote_characters = "";
	rl_filename_quote_characters = "\t\n !#$&'()*;<=>?@[\\]^`{|}~";
	rl_filename_quoting_function = quote;
	rl_filename_dequoting_function = unquote;
	rl_attempted_completion_function = complete;

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
