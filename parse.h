#ifndef YYTOKEN_IS_DECLARED
#define YYTOKEN_IS_DECLARED 1
typedef enum yytoken {
    ANDAND = 257,
    BACKBACK = 258,
    BANG = 259,
    CASE = 260,
    COUNT = 261,
    DUP = 262,
    ELSE = 263,
    END = 264,
    FLAT = 265,
    FN = 266,
    FOR = 267,
    IF = 268,
    IN = 269,
    OROR = 270,
    PIPE = 271,
    REDIR = 272,
    SREDIR = 273,
    SUB = 274,
    SUBSHELL = 275,
    SWITCH = 276,
    TWIDDLE = 277,
    WHILE = 278,
    WORD = 279,
    HUH = 280,
    PREDIR = 281
} yytoken;
#endif /* !YYTOKEN_IS_DECLARED */
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	struct Node *node;
	struct Redir redir;
	struct Pipe pipe;
	struct Dup dup;
	struct Word word;
	char *keyword;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
