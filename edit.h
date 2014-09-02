extern bool editing;

extern void *edit_begin(int fd);

extern char *edit_alloc(void *, size_t *);
extern void edit_free(void *);

extern void edit_prompt(void *, char *);

extern void edit_end(void *);

extern void edit_reset(void *);
