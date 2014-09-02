/* initialize the input stack */
extern void initinput(void);

/* push an input onto the stack */
extern void pushfd(int);
/* the Boolean argument affects line number reporting */
extern void pushstring(char **, bool);

/* pop the stack */
extern void popinput(void);

/* get / unget the next character */
extern int gchar(void);
extern void ugchar(int);

/* $TERM or $TERMCAP has changed */
extern void termchange(void);

/* parse a function from the environment */
extern Node *parseline(char *);

/* main parsing loop; Boolean says whether to exec also */
extern Node *doit(bool);

/* error recovery: skip to the next newline */
extern void skiptonl(void);

/* prepare for next line of input */
extern void nextline(void);

/* close all file descriptors on the stack */
extern void closefds(void);

/* the last character read */
extern int lastchar;
