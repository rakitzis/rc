#include "rc.h"

#include <errno.h>

#include <sys/types.h>

#include "edit.h"

bool editing = 0;

void *edit_begin(int fd) {
	assert(0); /* should never be called */
	return NULL;
}

char *edit_alloc(void *cookie, size_t *count) {
	assert(0); /* should never be called */
	return NULL;
}

void edit_prompt(void *cookie, char *prompt) {
	assert(0); /* should never be called */
}

void edit_free(void *buffer) {
	assert(0); /* should never be called */
}

void edit_end(void *cookie) {
	assert(0); /* should never be called */
}

void edit_reset(void *cookie) {
	assert(0); /* should never be called */
}
