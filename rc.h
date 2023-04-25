/*#define const   const*/
#undef NDEBUG
#include <stddef.h>
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

#ifdef __cplusplus
typedef enum Bool {
	FALSE, TRUE
} Bool;
#define new New
#else
typedef enum bool {
	FALSE, TRUE
} bool;
#endif

typedef enum redirtype {
	rFrom, rCreate, rAppend, rHeredoc, rHerestring
} redirtype;


typedef bool (*Conv)(Format *, int);
typedef void Sigfunc(int); /* See Advanced Programming in Unix Env - Stevens, section 10.3 */


union Edata {
	Jbwrap *jb;
	Block *b;
	const char *name;
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
	union NodeUnion {
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
	const char *w, *m;
	bool q;
};

struct Rq {
	const Node *r;
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
	const char *name;
	union {
		rc_Function *f;
		Variable *v;
	} u;
};

struct Format {
	/* for the formatting routines */
	va_list args;
	long flags, f1, f2;
	/* for the buffer maintenance routines */
	char *buf, *bufbegin;
	const char *bufend;
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
#ifndef NULL
#define NULL 0
#endif
#define a2u(x) n2u(x, 10)
#define o2u(x) n2u(x, 8)
#define arraysize(a) ((int)(sizeof(a)/sizeof((a)[0])))
#define memzero(s, n) memset(s, 0, n)
#define enew(T) ((T *) ealloc(sizeof(T)))
#define enew_arr(T,n) ((T *) ealloc((n)*sizeof(T)))
#define erenew_arr(T,oldp,n) ((T *) erealloc((oldp),(n)*sizeof(T)))
#define ecpy(s) (strcpy(enew_arr(char, (strlen(s) + 1)), s))
#define nnew(T) ((T *) nalloc(sizeof(T)))
#define nnew_arr(T,n) ((T *) nalloc((n)*sizeof(T)))
#define ncpy(s) (strcpy(nnew_arr(char, (strlen(s) + 1)), s))
#ifndef offsetof
#define offsetof(t, m) ((size_t) (((char *) &((t *) 0)->m) - (char *)0))
#endif
#define streq(x, y) (*(x) == *(y) && strcmp((x), (y)) == 0)
#define strcmp_fast(a, b) ( ((a)[0] != (b)[0]) ? ((((a)[0]) & 0xFF) - (((b)[0]) & 0xFF)) : strcmp((a), (b)) )
#define strncmp_fast(a, b, n) ( ((a)[0] != (b)[0]) ? ((((a)[0]) & 0xFF) - (((b)[0]) & 0xFF)) : strncmp((a), (b), (n)) )

#define conststrlen(x) (sizeof (x) - 1)

/* rc prototypes */

/* main.c */
extern Rq *redirq;
extern bool dashdee, dashee, dasheye, dashell, dashen;
extern bool dashpee, dashoh, dashess, dashvee, dashex;
extern bool interactive;
extern char *dashsee[];
extern pid_t rc_pid, rc_ppid;
extern int lineno;

/* builtins.c */
extern builtin_t *isbuiltin(const char *);
extern void b_exec(char **), funcall(char **), b_dot(char **), b_builtin(char **);
extern bool q_builtins_ordered(void);
extern int find_str(const char * const s, const char* const arr[], int sz);
extern char *compl_builtin(const char *, int);

/* except.c */
extern bool nl_on_intr;
extern bool outstanding_cmdarg(void);
extern void pop_cmdarg(bool);
extern void rc_raise(const ecodes);
extern void except(const ecodes, Edata, Estack *);
extern void unexcept(const ecodes);
extern void rc_error(const char *);
extern void sigint(int);

/* exec.c */
extern void exec(const List *, bool);

#if HASH_BANG
#define rc_execve execve
#else
/* execve.c */
extern int my_execve(char *, char **, char **);
#endif

/* footobar.c */
extern char **list2array(const List *, bool);
extern char *get_name(const char *);
extern List *parse_var(const char *);
extern Node *parse_fn(const char *);
extern void initprint(void);
extern void rc_exit(int); /* here for odd reasons; user-defined signal handlers are kept in fn.c */

/* getopt.c */
extern int rc_getopt(int, char * const *, const char *);

extern int rc_optind, rc_opterr, rc_optopt;
extern char *rc_optarg;

/* glob.c */
extern bool lmatch(const List *, const List *);
extern List *glob(List *);

/* glom.c */
extern void assign(const List *, List *, bool);
extern void qredir(const Node *);
extern List *append(List *, List*);
extern List *flatten(List *);
extern List *glom(const Node *);
extern List *concat(List *, List *);
extern List *word(char *, char *);

/* fn.c */
extern Node *fnlookup(const char *);
extern char *fnlookup_string(const char *);
extern void fnassign(const char *, const Node *);
extern void fnassign_string(const char *);
extern void fnrm(const char *);
extern void prettyprint_fn(int, const char *, const Node *);

/* var.c */
extern void starassign(char *, char **, bool);
extern List *varlookup(const char *);
extern bool varassign_string(const char *);
extern char *varlookup_string(const char *);
extern void varassign(const char *, const List *, bool);
extern void varrm(const char *, bool);
extern void prettyprint_var(int, const char *, const List *);

/* hash.c */
extern rc_Function *get_fn_place(const char *);
extern Variable *get_var_place(const char *, bool);
extern char **makeenv(void);
extern void alias(const char *, List *, bool);
extern void delete_fn(const char *);
extern void delete_var(const char *, bool);
extern void initenv(char **);
extern void inithash(void);
extern void set_exportable(const char *, bool);
extern void setsigdefaults(bool);
extern void inithandler(void);
extern void whatare_all_vars(bool, bool);
extern void whatare_all_signals(void);
extern rc_Function *lookup_fn(const char* s);
extern Variable * lookup_var(const char* s);
/*
extern void *lookup(const char *, Htab *);
*/
extern char *compl_name(const char *, int, const char* const *, size_t, ssize_t);
extern char *compl_fn(const char *, int);
extern char *compl_var(const char *, int);

/* heredoc.c */
extern int heredoc(int);
extern int qdoc(const Node *, Node *);
extern Hq *hq;

/* lex.c */
extern bool quotep(const char *, bool);
extern int yylex(void);
extern void inityy(void);
extern void yyerror(const char *);
extern const char nw[], dnw[];

/* list.c */
extern void listfree(List *);
extern List *listcpy(const List *, void *(*)(size_t));
extern size_t listlen(const List *);
extern int listnel(const List *);

/* match.c */
extern bool match(const char *, const char *, const char *);

/* alloc.c */
extern void *ealloc(size_t);
extern void *erealloc(void *, size_t);
extern void efree(void *);
extern Block *newblock(void);
extern void *nalloc(size_t);
extern void restoreblock(Block *);

/* open.c */
extern int rc_open(const char *, redirtype);
extern bool makeblocking(int);
extern bool makesamepgrp(int);

/* print.c */
/*
 * The following prototype should be:
 *      extern Conv fmtinstall(int, Conv);
 * but this freaks out SGI's compiler under IRIX3.3.2
 * extern bool (*fmtinstall(int, bool (*)(Format *, int)))(Format *, int);
*/
extern Conv fmtinstall(int, Conv);

extern int fmtprint(Format *, const char *,...);
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

#if 1
extern int yyparse(void);
#else
typedef int (*lexer_ptr)(void); /* or typedef int (*lexer_ptr)(YYSTYPE*); */
#define YYPARSE_PARAM_TYPE   lexer_ptr
#define YYPARSE_PARAM        yylex
/* #define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM */
extern int yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM);
#endif

extern void initparse(void);

/* readline */
extern volatile sig_atomic_t rl_active;
extern struct Jbwrap rl_buf;

/* redir.c */
extern void doredirs(void);


/* signal.c */
extern void initsignal(void);
extern void sigchk(void);
extern Sigfunc* rc_signal(int, Sigfunc*);
extern Sigfunc* sys_signal(int, Sigfunc*);
extern Sigfunc* sighandlers[];


/* status.c */
extern int istrue(void);
extern int getstatus(void);
extern void set(bool);
extern void setN(int code);
extern void setstatus(pid_t, int);
extern List *sgetstatus(void);
extern void setpipestatus(const int [], int);
extern void ssetstatus(char* const*);
extern char *strstatus(int s);


/* system.c or system-bsd.c */
extern void writeall(int, const char *, size_t);

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
extern Node *treecpy(const Node *, void *(*)(size_t));
extern void treefree(Node *);

/* utils.c */
extern bool isabsolute(const char *);
extern int n2u(const char *, unsigned int);
extern int mvfd(int, int);
extern int starstrcmp(const void *, const void *);
extern void pr_error(const char *, int);
extern void panic(const char *);
extern void uerror(const char *);

/* wait.c */
extern pid_t rc_fork(void);
extern pid_t rc_wait4(pid_t, int *, bool);
extern List *sgetapids(void);
extern void waitforall(void);
extern bool forked;

/* walk.c */
extern bool walk(const Node *, bool);
extern bool cond;

/* which.c */
extern bool rc_access(const char *, bool, struct stat *);
extern char *which(char *, bool);

