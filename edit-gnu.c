#include "rc.h"

#include <stdio.h>
#include <readline/readline.h>

#include "jbwrap.h"

struct Jbwrap rl_buf;
volatile sig_atomic_t rl_active;

void edit_init(void *ignored) {
	rl_catch_signals = 0;
}

char *edit_getline(void *ignored, char *prompt) {
	char *r = NULL;
	int s;

	if ((s = sigsetjmp(rl_buf.j, 1)) == 0) {
		rl_active = TRUE;
		r = readline(prompt);
	} else {
		rl_free_line_state();
		rl_cleanup_after_signal();
		rl_active = FALSE;
		rc_raise(eError);
	}

	if (r) {
		r = erealloc(r, strlen(r) + 2); /* 1 for \n + 1 for \0 */
		strcat(r, "\n");
	}
	return r;
}

void edit_free(void *ignored, void *buffer) {
	efree(buffer);
}
