#undef NDEBUG
#include "config.h"
#include "proto.h"

#include <assert.h>

/* for struct stat */
#include <sys/stat.h>

#define RC "rc: "

/* datatypes */

#define ENV_SEP '\001'
#define ENV_ESC '\002'

/* braindamaged IBM header files #define true and false */
#undef FALSE
#undef TRUE

typedef void builtin_t(char **);
typedef struct Block Block;
typedef struct Dup Dup;
typedef struct Estack Estack;
typedef struct rc_Function rc_Function;
typedef struct Hq Hq;
typedef struct Htab Htab;
typedef struct Jbwrap Jbwrap;
typedef struct List List;
typedef struct Node Node;
typedef struct Pipe Pipe;
typedef struct Redir Redir;
typedef struct Rq Rq;
typedef struct Variable Variable;
typedef struct Word Word;
typedef struct Format Format;
typedef union Edata Edata;

typedef enum nodetype {
	nAndalso, nAssign, nBackq, nBang, nBody, nCbody, nNowait, nBrace,
	nConcat, nCount, nElse, nFlat, nDup, nEpilog, nNewfn, nForin, nIf,
	nOrelse, nPipe, nPre, nRedir, nRmfn, nArgs, nSubshell, nCase,
	nSwitch, nMatch, nVar, nVarsub, nWhile, nWord, nLappend, nNmpipe
} nodetype;

typedef enum ecodes {
	eError, eBreak, eReturn, eVarstack, eArena, eFifo, eFd, eContinue
} ecodes;

typedef enum bool {
	FALSE, TRUE
} bool;

typedef enum redirtype {
	rFrom, rCreate, rAppend, rHeredoc, rHerestring
} redirtype;

typedef bool (*Conv)(Format *, int);

union Edata {
	Jbwrap *jb;
	Block *b;
	char *name;
	int fd;
};

struct Estack {
	ecodes e;
	bool interactive;
	Edata data;
	Estack *prev;
};

struct List {
	char *w, *m;
	List *n;
};

struct Node {
	nodetype type;
	union {
		char *s;
		int i;
		Node *p;
	} u[4];
};

struct Pipe {
	int left, right;
};

struct Dup {
	redirtype type;
	int left, right;
};

struct Redir {
	redirtype type;
	int fd;
};

struct Word {
	char *w, *m;
	bool q;
};

struct Rq {
	Node *r;
	struct Rq *n;
};

struct rc_Function {
	Node *def;
	char *extdef;
};

struct Variable {
	List *def;
	char *extdef;
	Variable *n;
};

struct Htab {
	char *name;
	void *p;
};

struct Format {
	/* for the formatting routines */
	va_list args;
	long flags, f1, f2;
	/* for the buffer maintenance routines */
	char *buf, *bufbegin, *bufend;
	int flushed;
	void (*grow)(Format *, size_t);
	union { int n; void *p; } u;
};

/* Format->flags values */
enum {
	FMT_quad	= 1,		/* %q */
	FMT_long	= 2,		/* %l */
	FMT_unsigned	= 8,		/* %u */
	FMT_zeropad	= 16,		/* %0 */
	FMT_leftside	= 32,		/* %- */
	FMT_altform	= 64,		/* %# */
	FMT_f1set	= 128,		/* %<n> */
	FMT_f2set	= 256		/* %.<n> */
};

/* macros */
#define EOF (-1)
#define MAX_PIPELINE 512
#ifndef NULL
#define NULL 0
#endif
#define a2u(x) n2u(x, 10)
#define o2u(x) n2u(x, 8)
#define arraysize(a) ((int)(sizeof(a)/sizeof(*a)))
#define memzero(s, n) memset(s, 0, n)
#define enew(x) ((x *) ealloc(sizeof(x)))
#define ecpy(x) strcpy((char *) ealloc(strlen(x) + 1), x)
#define lookup_fn(s) ((rc_Function *) lookup(s, fp))
#define lookup_var(s) ((Variable *) lookup(s, vp))
#define nnew(x) ((x *) nalloc(sizeof(x)))
#define ncpy(x) (strcpy((char *) nalloc(strlen(x) + 1), x))
#ifndef offsetof
#define offsetof(t, m) ((size_t) (((char *) &((t *) 0)->m) - (char *)0))
#endif
#define streq(x, y) (*(x) == *(y) && strcmp(x, y) == 0)
#define conststrlen(x) (sizeof (x) - 1)

/* rc prototypes */

/* main.c */
extern Rq *redirq;
extern bool dashdee, dashee, dasheye, dashell, dashen;
extern bool dashpee, dashoh, dashess, dashvee, dashewe, dashex;
extern bool interactive;
extern char *dashsee[];
extern pid_t rc_pid;
extern int lineno;

/* builtins.c */
extern builtin_t *isbuiltin(char *);
extern void b_exec(char **), funcall(char **), b_dot(char **), b_builtin(char **);
extern char *compl_builtin(const char *, int);

/* except.c */
extern bool nl_on_intr;
extern bool outstanding_cmdarg(void);
extern void pop_cmdarg(bool);
extern void rc_raise(ecodes);
extern void except(ecodes, Edata, Estack *);
extern void unexcept(ecodes);
extern void clearflow(void);
extern void rc_error(char *);
extern void sigint(int);

/* exec.c */
extern void exec(List *, bool);

#if HASH_BANG
#define rc_execve execve
#else
/* execve.c */
extern int rc_execve(char *, char **, char **);
#endif

/* footobar.c */
extern char **list2array(List *, bool);
extern char *get_name(char *);
extern List *parse_var(char *);
extern Node *parse_fn(char *);
extern void initprint(void);
extern void rc_exit(int); /* here for odd reasons; user-defined signal handlers are kept in fn.c */

/* getopt.c */
extern int rc_getopt(int, char **, char *);

extern int rc_optind, rc_opterr, rc_optopt;
extern char *rc_optarg;

/* glob.c */
extern bool lmatch(List *, List *);
extern List *glob(List *);

/* glom.c */
extern void assign(List *, List *, bool);
extern void qredir(Node *);
extern List *append(List *, List*);
extern List *flatten(List *);
extern List *glom(Node *);
extern List *concat(List *, List *);
extern List *varsub(List *, List *);
extern List *word(char *, char *);

/* hash.c */
extern Htab *fp, *vp;
extern void *lookup(char *, Htab *);
extern rc_Function *get_fn_place(char *);
extern List *varlookup(char *);
extern List *varlookupNonStrict(char *);
extern Node *fnlookup(char *);
extern Variable *get_var_place(char *, bool);
extern bool varassign_string(char *);
extern char **makeenv(void);
extern char *fnlookup_string(char *);
extern char *varlookup_string(char *);
extern void alias(char *, List *, bool);
extern void starassign(char *, char **, bool);
extern void delete_fn(char *);
extern void delete_var(char *, bool);
extern void fnassign(char *, Node *);
extern void fnassign_string(char *);
extern void fnrm(char *);
extern void initenv(char **);
extern void inithash(void);
extern void set_exportable(char *, bool);
extern void setsigdefaults(bool);
extern void inithandler(void);
extern void varassign(char *, List *, bool);
extern void varrm(char *, bool);
extern void whatare_all_vars(bool, bool);
extern void whatare_all_signals(void);
extern void prettyprint_var(int, char *, List *);
extern void prettyprint_fn(int, char *, Node *);
extern char *compl_name(const char *, int, char **, size_t, ssize_t);
extern char *compl_fn(const char *, int);
extern char *compl_var(const char *, int);

/* heredoc.c */
extern int heredoc(int);
extern int qdoc(Node *, Node *);
extern Hq *hq;

/* lex.c */
extern bool quotep(char *, bool);
extern int yylex(void);
extern void inityy(void);
extern void yyerror(const char *);
extern void scanerror(char *);
extern const char nw[], dnw[];

/* list.c */
extern void listfree(List *);
extern List *listcpy(List *, void *(*)(size_t));
extern size_t listlen(List *);
extern int listnel(List *);

/* match.c */
extern bool match(char *, char *, char *);

/* alloc.c */
extern void *ealloc(size_t);
extern void *erealloc(void *, size_t);
extern void efree(void *);
extern Block *newblock(void);
extern void *nalloc(size_t);
extern void nfree(void);
extern void restoreblock(Block *);

/* open.c */
extern int rc_open(const char *, redirtype);
extern bool makeblocking(int);
extern bool makesamepgrp(int);

/* print.c */
/*
   The following prototype should be:
extern Conv fmtinstall(int, Conv);
   but this freaks out SGI's compiler under IRIX3.3.2
*/
extern bool (*fmtinstall(int, bool (*)(Format *, int)))(Format *, int);
extern int printfmt(Format *, const char *);
extern int fmtprint(Format *, const char *,...);
extern void fmtappend(Format *, const char *, size_t);
extern void fmtcat(Format *, const char *);
extern int fprint(int fd, const char *fmt,...);
extern char *mprint(const char *fmt,...);
extern char *nprint(const char *fmt,...);
/*
   the following macro should by rights be coded as an expression, not
   a statement, but certain compilers (notably DEC) have trouble with
   void expressions inside the ?: operator. (sheesh, give me a break!)
*/
#define	fmtputc(f, c) {\
	if ((f)->buf >= (f)->bufend)\
		(*(f)->grow)((f), (size_t)1);\
	*(f)->buf++ = (c);\
}

/* parse.c (parse.y) */
extern Node *parsetree;
extern int yyparse(void);
extern void initparse(void);

/* readline */
extern volatile sig_atomic_t rl_active;
extern struct Jbwrap rl_buf;

/* redir.c */
extern void doredirs(void);


/* signal.c */
extern void initsignal(void);
extern void catcher(int);
extern void sigchk(void);
extern void (*rc_signal(int, void (*)(int)))(int);
extern void (*sys_signal(int, void (*)(int)))(int);
extern void (*sighandlers[])(int);


/* status.c */
extern int istrue(void);
extern int getstatus(void);
extern void set(bool);
extern void setstatus(pid_t, int);
extern void setpipestatuslength(int);
extern void setpipestatus(int, pid_t, int);
extern List *sgetstatus(void);
extern void ssetstatus(char **);
extern char *strstatus(int s);


/* system.c or system-bsd.c */
extern void writeall(int, char *, size_t);

#if HAVE_RESTARTABLE_SYSCALLS
extern int rc_read(int, char *, size_t);
extern pid_t rc_wait(int *);
extern Jbwrap slowbuf;
extern volatile sig_atomic_t slow;

#else /* HAVE_RESTARTABLE_SYSCALLS */

#define rc_read read
#define rc_wait wait
#endif /* HAVE_RESTARTABLE_SYSCALLS */


/* tree.c */
extern Node *mk(enum nodetype, ...);
extern Node *treecpy(Node *, void *(*)(size_t));
extern void treefree(Node *);

/* utils.c */
extern bool isabsolute(char *);
extern int n2u(char *, unsigned int);
extern int mvfd(int, int);
extern int starstrcmp(const void *, const void *);
extern void pr_error(char *, int);
extern void panic(char *);
extern void uerror(char *);

/* wait.c */
extern pid_t rc_fork(void);
extern pid_t rc_wait4(pid_t, int *, bool);
extern List *sgetapids(void);
extern void waitforall(void);
extern void waitfor(char **);
extern bool forked;

/* walk.c */
extern bool walk(Node *, bool);
extern bool cond;

/* which.c */
extern bool rc_access(char *, bool, struct stat *);
extern char *which(char *, bool);
