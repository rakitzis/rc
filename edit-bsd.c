#include "rc.h"

#include <stdio.h>

#include <histedit.h>

#include "edit.h"

bool editing = 1;

struct cookie {
	EditLine *el;
	History *hist;
};

static char *prompt;

void *edit_begin(int fd) {
	FILE *f;
	HistEvent he;
	struct cookie *c;

	c = ealloc(sizeof *c);
	if (fd == 0)
		f = stdin;
	else
		f = fdopen(fd, "r");
	c->el = el_init("rc", f, stdout, stderr);
	el_set(c->el, EL_SIGNAL, 0);
	el_source(c->el, NULL);

	c->hist = history_init();
	history(c->hist, &he, H_SETSIZE, 20);
	el_set(c->el, EL_HIST, history, c->hist);

	return c;
}


static void edit_catcher(int sig) {
	write(2, "\n", 1);
	rc_raise(eError);
}

char *edit_alloc(void *cookie, size_t *count) {
	const char *r;
	HistEvent he;
	struct cookie *c = cookie;
	void (*oldint)(int), (*oldquit)(int);

	oldint = sys_signal(SIGINT, edit_catcher);
	oldquit = sys_signal(SIGQUIT, edit_catcher);

	r = el_gets(c->el, count);

	sys_signal(SIGINT, oldint);
	sys_signal(SIGQUIT, oldquit);

	if (r)
		history(c->hist, &he, H_ENTER, r);
	return (char *)r; /* cast to avoid gcc warning */
}

static char *edit_prompter(EditLine *e) {
	return prompt;
}

void edit_prompt(void *cookie, char *pr) {
	struct cookie *c = cookie;

	prompt = pr;
	el_set(c->el, EL_PROMPT, edit_prompter);
}

void edit_free(void *cookie) {
	/* this function deliberately left blank */
}

void edit_end(void *cookie) {
	struct cookie *c = cookie;

	el_end(c->el);
	history_end(c->hist);
	efree(c);
}

void edit_reset(void *cookie) {
	struct cookie *c = cookie;

	el_set(c->el, EL_TERMINAL, NULL);
}
