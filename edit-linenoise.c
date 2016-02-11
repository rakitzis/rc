#include "rc.h"

#include <errno.h>
#include <sys/types.h>

#include "linenoise.h"

bool editing = 1;

struct cookie {
  char *buffer;
};

static char *prompt;

void *edit_begin(int fd) {
  struct cookie *c;
  List *hist = varlookup("history");
  if ( NULL != hist ) {
    if ( (linenoiseHistoryLoad(hist->w) != 0) && errno != ENOENT ) {
      uerror(hist->w);
    }
  }
  c = ealloc(sizeof *c);
  c->buffer = NULL;
  return c;
}

char *edit_alloc(void *cookie, size_t *count) {
  struct cookie *c = cookie;
  c->buffer = linenoise(prompt);
  if (c->buffer) {
    *count = strlen(c->buffer);
    if (*count) {
      linenoiseHistoryAdd(c->buffer);
      c->buffer[*count]='\n';
      ++*count;
    }
  }
  return c->buffer;
}

void edit_prompt(void *cookie, char *pr) {
  prompt = pr;
}

void edit_free(void *cookie) {
  struct cookie *c = cookie;

  efree(c->buffer);
  c->buffer = NULL; /* allow "overfrees" */
}

void edit_end(void *cookie) {
  struct cookie *c = cookie;
  efree(c);
}

void edit_reset(void *cookie) {
  // do nothing
}
