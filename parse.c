/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20190617

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 8 "parse.y"
/* note that this actually needs to appear before any system header
   files are included; byacc likes to throw in <stdlib.h> first. */
#include "rc.h"

static Node *star, *nolist;
Node *parsetree;	/* not using yylval because bison declares it as an auto */
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 31 "parse.y"
typedef union YYSTYPE {
	struct Node *node;
	struct Redir redir;
	struct Pipe pipe;
	struct Dup dup;
	struct Word word;
	const char *keyword;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 44 "parse.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   25,   25,    8,    8,   13,   13,    3,    3,
    9,    9,    4,   15,    2,   11,   11,   16,   16,   16,
    5,    5,    6,    6,    6,   19,   24,   24,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,   26,   26,   18,   18,
   23,   23,   22,   22,   12,   12,   17,   17,   20,   20,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,   21,   21,   14,   14,   14,   27,
   27,
};
static const YYINT yylen[] = {                            2,
    2,    2,    1,    1,    2,    2,    1,    2,    1,    2,
    1,    2,    3,    3,    5,    0,    2,    1,    2,    2,
    3,    3,    1,    2,    2,    2,    0,    3,    0,    1,
    2,    4,    8,    6,    4,    8,    4,    4,    4,    4,
    2,    2,    3,    3,    3,    2,    0,    1,    1,    2,
    1,    2,    1,    1,    1,    3,    1,    1,    1,    3,
    2,    5,    2,    2,    2,    2,    2,    3,    3,    3,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    0,    2,    0,    2,    2,    0,
    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   18,    0,   85,    0,    0,    0,
    0,    0,    0,    0,    0,   72,    0,    0,   87,    0,
    0,    0,    0,    0,    0,   55,    0,    0,    0,   30,
    3,    4,    2,   82,   80,   79,   78,   73,   76,   74,
    0,   83,   77,   81,   75,   84,   58,   57,   59,    0,
   48,    0,   63,   64,    0,    0,    0,   90,   71,    0,
    0,    0,    0,    0,   90,   67,    0,    0,    0,   11,
    0,    0,   66,   65,    0,    0,   31,    0,   90,   90,
   90,    5,    6,    8,    0,   54,    0,   51,    0,    0,
    1,   41,    0,   68,   69,    0,   45,    0,    0,    0,
    0,    0,    0,    0,    0,   85,   13,   12,   10,   70,
   88,    0,   17,    0,    0,    0,   56,   52,    0,   60,
   85,   90,   14,   91,    0,   32,   90,    0,    0,    0,
    0,    0,   40,    0,    0,    0,   90,   26,    0,   62,
    0,   90,    0,    0,    0,    0,    0,   85,    0,    0,
    0,    0,    0,    0,   24,   36,   25,   22,   21,
};
static const YYINT yydgoto[] = {                         21,
   47,   22,   68,   23,  149,  150,   69,   70,   71,   48,
   77,   27,   28,   72,   58,   29,   49,   30,  126,   98,
   55,   88,   89,  138,   33,   52,  101,
};
static const YYINT yysindex[] = {                       847,
   24,  933,  -80,  933,    0,  933,    0,   -1,    2,  821,
  933,  -80,    3,  -80,    2,    0,  821, 1094,    0,  821,
    0, 1094, -251,  -30, 1094,    0,  773,   24, 1094,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -79,    0,    0,    0,    0,    0,    0,    0,    0,  795,
    0, 1094,    0,    0,  821,  933, 1094,    0,    0,  -49,
  -49, 1094,  933,  933,    0,    0, -228,  -67,  154,    0,
 1094,  402,    0,    0, -208,  933,    0, -251,    0,    0,
    0,    0,    0,    0, 1118,    0,  -49,    0,  636,    4,
    0,    0,  933,    0,    0, -208,    0,  -49,  -38,   23,
  468, -208,  -32,  -49,  468,    0,    0,    0,    0,    0,
    0,  -49,    0,  468,  468,  468,    0,    0,  -80,    0,
    0,    0,    0,    0, -210,    0,    0,  933, -234,  884,
 -208, -208,    0,  933,  910,  468,    0,    0,   -9,    0,
  -49,    0, -234,  468,  969,  468, -234,    0,  969,  -59,
  154,  969, -234,  424,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                       134,
    0,    0,  110,    0,    0,    0,    0,    0,    0,    0,
    0,  110,    0, 1071,    0,    0,    0,  550,    0,    0,
    0,  187,  485,   30,  134,    0,  511,    0,  187,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  187,    0,    0,  515,    0,  143,    0,    0,   14,
   38,  187,    0,    0,    0,    0,  -10,    0,  -36,    0,
  481,    0,    0,    0,  678,    0,    0,  485,    0,    0,
    0,    0,    0,    0,    8,    0,   62,    0,  541,    0,
    0,    0,    0,    0,    0,  721,    0,   86,    0,    0,
  -34,  729,    0,  356,  -34,    0,    0,    0,    0,    0,
    0,  446,    0,  -34,  -34,  -34,    0,    0, 1071,    0,
    0,    0,    0,    0,   95,    0,    0,  570,  139,    0,
  751,  755,    0,    0,    0,  -34,    0,    0,    0,    0,
  380,    0,  145,  -34,  550,  -34,  759,    0,  550,    0,
  -58,  550,  763,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -44,  118,    0, -111, 1392,   10, -133, 1380,
   -8,    0,   46,    0,   65,  -21,  442,    0,    0, 1193,
  -89,  -12,    0,    0,   53,    6,  436,
};
#define YYTABLESIZE 1544
static const YYINT yytable[] = {                         61,
  124,   78,  122,   29,    9,   86,   29,   83,  127,   25,
    5,  152,  100,   51,  128,  152,  130,   62,  152,   64,
   76,   11,   79,   19,   29,   61,  109,   61,   82,   61,
   61,  135,   90,   32,   25,   80,   81,  155,   56,    7,
  157,   57,   63,   18,   93,  106,   79,   20,   61,   19,
   61,   19,  137,   19,   19,   93,   78,  107,  154,   80,
   81,   93,   81,  123,  119,  156,   23,   86,   48,  113,
   84,   53,   19,   20,   19,   20,  118,   20,   20,   65,
   91,    0,    0,   61,    0,   61,    0,    0,    9,    0,
   29,    0,    0,    0,    0,   86,   20,   53,   20,   53,
    0,   53,   53,    0,   27,    0,    0,    0,    0,   19,
    0,    0,   61,  145,   61,    0,    0,    0,    0,   47,
   53,   86,   53,   86,  134,   86,   86,   59,    0,    0,
    0,    0,   27,   20,   66,   27,   19,   73,   19,    0,
    0,    0,    0,   29,   86,   47,   86,   47,   35,   47,
   47,    0,   29,   27,   34,    0,    0,   53,   59,    0,
   20,    0,   20,  108,    0,    0,    0,   94,   47,    0,
    0,   29,   97,    0,    0,    0,   35,    0,    0,   35,
   29,   86,   34,   29,    0,   34,   53,    0,    0,    0,
    0,   83,   29,    0,    0,    0,   29,   35,    0,    0,
    0,   29,    0,   34,    0,   47,    0,    0,   86,    0,
   86,    0,   82,    0,    0,    0,    0,    0,    0,   27,
    0,    0,   29,    0,   29,    0,   79,   29,   29,   29,
  121,    0,   47,    0,   47,   29,   29,    0,    0,   80,
   81,    0,    0,    0,    0,   29,   61,   61,   61,   61,
   61,   61,   61,   61,   61,   61,   61,   61,   61,   61,
   61,   61,   61,   35,   61,   61,   61,   61,   61,   34,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   31,   19,   19,
   19,   19,   19,    7,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   29,   20,   20,   20,   20,   20,    0,   53,   53,
   53,   53,   53,   53,   53,   53,   53,   53,   53,   53,
   53,   53,   53,   53,   53,    0,   53,   53,   53,   53,
   53,    0,   86,   86,   86,   86,   86,    0,   86,   86,
   86,   86,   86,   86,   86,   86,   86,   86,   27,    0,
   86,   86,   86,   86,   86,   85,   47,   47,   47,    0,
   47,   47,   47,   47,   47,   47,   47,   47,    0,   47,
   47,   47,   47,    0,   47,   47,   47,   47,   47,   15,
   29,   85,    0,   85,    0,   85,   85,   29,    0,   29,
    0,   35,   35,   29,   29,    0,    0,   34,   34,    0,
   79,  111,   29,   29,   85,   15,   85,   15,    0,   15,
   15,    0,    0,   80,   81,    0,    0,    0,    0,    0,
    0,    0,    0,  158,    0,    0,    0,   17,   15,    0,
    0,   19,  110,   29,    0,   53,    0,   54,    0,   29,
   29,   85,    0,    0,    0,   89,   29,   29,   67,   17,
    0,   74,   46,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,    0,  124,    0,    0,
   85,   89,  159,    0,   46,   89,   89,    0,    0,    0,
   29,   95,    0,    0,   16,    0,    0,   20,    0,    0,
  105,    0,   15,   17,   15,    0,   89,   19,    0,    0,
    0,    0,    0,    0,  114,  115,  116,    0,   29,   20,
   49,   29,   16,    0,   46,   16,  117,    0,    0,    0,
    0,    0,    0,    0,  120,    0,    0,    0,    0,   29,
    0,   89,    0,   16,    0,    0,    0,    0,   49,    0,
   50,   49,   46,    0,    0,   46,    0,  136,    0,   29,
    0,    0,  139,   20,    0,    0,    0,    0,    0,   49,
    0,   47,  144,   46,    0,    0,    0,  146,   50,   37,
    0,   50,    0,    0,    0,    0,    0,   29,    0,    0,
   18,    0,    0,    0,    0,    0,    0,    0,    0,   50,
    0,    0,    0,    0,    0,   29,    0,   37,   29,   16,
   37,    0,   85,   85,   85,   85,   85,    0,   85,   85,
   85,   85,   85,   85,   85,   85,   85,   85,   37,    0,
   85,   85,   85,   85,   85,   49,   15,   15,   15,   46,
   15,   15,   15,   15,   15,   15,   15,   15,    0,   15,
   15,   15,   15,    0,   15,   15,   15,   15,   15,    2,
   34,   35,    4,    0,   36,   50,    6,   37,   38,   39,
   40,   17,    0,   41,   29,   19,   42,   43,   44,   45,
   16,    2,   34,   35,    4,    0,   36,   42,    6,   37,
   38,   39,   40,    0,   37,   41,   46,    0,   42,   43,
   44,   45,   16,   89,   89,   89,   89,    0,   89,    0,
   89,   89,   89,   89,   89,   42,    0,   89,   42,    0,
   89,   89,   89,   89,   89,    2,    3,    0,    4,    5,
   43,   20,    6,    7,    8,    9,   42,   29,   44,   10,
   11,   16,   12,   13,   14,   15,   16,   16,   16,    0,
   29,   29,    0,    0,   16,   16,    0,    0,   43,    0,
   38,   43,    0,    0,   39,    0,   44,   49,   28,   44,
    0,   46,   33,    0,   49,    0,    0,    0,   46,   43,
   49,   49,    0,    0,   46,   46,    0,   44,   38,    0,
    0,   38,   39,    0,    0,   39,   28,   50,    0,   28,
   33,    0,   42,   33,   50,    0,   29,    0,   17,   38,
   50,   50,   19,   39,    0,    0,    0,   28,    0,   29,
   29,   33,    0,    0,    0,    0,   37,    0,    0,    0,
   17,    0,    0,   37,   19,    0,    0,    0,    0,   37,
   37,    0,    0,    0,    0,   43,    0,    0,    0,    0,
    0,    0,    0,   44,    0,   46,   17,    0,    0,    0,
   19,    0,    0,    0,    0,    0,   85,    0,   20,    0,
    0,    0,    0,    0,    0,   38,    0,    0,    0,   39,
    0,   46,   17,   28,    0,    0,   19,   33,   93,    0,
   20,    0,    0,    2,   34,   35,    4,    5,   36,    0,
    6,   37,   38,   39,   40,    0,    0,   10,   11,    0,
   42,   43,   44,   45,   16,    0,   20,   18,    0,   17,
    0,    0,    0,   19,  140,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   42,    0,    0,    0,    0,    0,
   42,   42,   20,   18,   46,   17,    0,   42,    0,   19,
  142,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   17,   18,
   46,    0,   19,    0,    0,    0,    0,   43,    0,   20,
    0,    0,    0,   43,   43,   44,    0,    0,    0,    0,
   43,   44,   44,   46,    0,    0,    0,    0,   44,    0,
    0,    0,    0,    0,   17,   20,    0,   38,   19,    0,
    0,   39,    0,   38,   38,    0,    0,   39,   39,    0,
   38,   28,   28,    0,   39,   33,   33,    0,   20,    0,
    2,   34,   35,    4,    5,   36,    0,    6,   37,   38,
   39,   40,    0,    0,   10,   11,    0,   42,   43,   44,
   45,   16,    2,   34,   35,    4,    0,   36,    0,    6,
   37,   38,   39,   40,   20,    0,   41,    0,    0,   42,
   43,   44,   45,   16,    0,    0,    0,    0,    2,   34,
   35,    4,    0,   36,    0,    6,   37,   38,   39,   40,
    0,   18,   41,    0,    0,   42,   43,   44,   45,   16,
    0,    0,    1,    0,    2,    3,   47,    4,    5,    0,
   47,    6,    7,    8,    9,    0,    0,    0,   10,   11,
    0,   12,   13,   14,   15,   16,    0,    0,    0,   17,
    0,   47,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    2,   34,   35,    4,    0,   36,    0,    6,   37,
   38,   39,   40,   17,    0,   41,    0,   19,   42,   43,
   44,   45,   16,    0,    0,    0,   47,    2,   34,   35,
    4,    0,   36,    0,    6,   37,   38,   39,   40,    0,
    0,   41,    0,    0,   42,   43,   44,   45,   16,   20,
    2,   34,   35,    4,   50,   36,    0,    6,   37,   38,
   39,   40,   60,   61,   41,    0,    0,   42,   43,   44,
   45,   16,    0,   20,    0,    0,   18,    0,    0,   87,
    0,    0,    0,    0,    0,    0,    2,    3,  148,    4,
    5,    0,    0,    6,    7,    8,    9,    0,    0,    0,
   10,   11,    0,   12,   13,   14,   15,   16,   99,    0,
    0,    0,    0,    0,    0,  103,  104,    0,    0,    0,
    0,    0,    0,    0,  112,    0,    0,    0,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  141,    0,   47,   47,
   47,   47,    0,   47,    0,   47,   47,   47,   47,   47,
    0,    0,   47,    0,    0,   47,   47,   47,   47,   47,
    0,    2,    3,    0,    4,    5,    0,    0,    6,    7,
    8,    9,    0,    0,    0,   10,   11,    0,   12,   13,
   14,   15,   16,    0,    0,    2,   34,   35,    4,   26,
   36,    0,    6,   37,   38,   39,   40,    0,    0,   41,
    0,   24,   42,   43,   44,   45,   16,   26,    0,    0,
    0,   26,    0,    0,   26,    0,    0,    0,   26,    0,
    0,    0,    0,   75,    0,    0,   24,    0,    0,    0,
   92,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   26,    0,    0,    0,    0,   26,    0,    0,    0,
    0,   26,    0,   96,    0,    0,    0,    0,    0,    0,
   26,    0,    0,  102,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   26,    0,    0,    0,   26,    0,    0,    0,    0,    0,
    0,    0,  125,   26,   26,   26,  129,    0,    0,    0,
    0,    0,    0,    0,    0,  131,  132,  133,    0,    0,
    0,    0,    0,    0,    0,   26,    0,    0,    0,    0,
    0,    0,    0,   26,   26,   26,    0,  143,   26,    0,
    0,   26,    0,    0,    0,  147,  151,  153,    0,    0,
  151,    0,    0,  151,
};
static const YYINT yycheck[] = {                         10,
   10,   23,   41,   38,   41,   27,   41,   38,   41,    0,
  262,  145,   57,   94,  104,  149,  106,   12,  152,   14,
  272,  273,  257,   10,   59,   36,   71,   38,   59,   40,
   41,  121,   27,   10,   25,  270,  271,  149,   40,   10,
  152,   40,   40,  123,   94,  274,  257,   10,   59,   36,
   61,   38,  263,   40,   41,   94,   78,  125,  148,  270,
  271,   94,  271,   41,   61,  125,  125,   89,   61,   78,
   25,   10,   59,   36,   61,   38,   89,   40,   41,   15,
   28,   -1,   -1,   94,   -1,   96,   -1,   -1,  125,   -1,
  125,   -1,   -1,   -1,   -1,   10,   59,   36,   61,   38,
   -1,   40,   41,   -1,   10,   -1,   -1,   -1,   -1,   96,
   -1,   -1,  123,  123,  125,   -1,   -1,   -1,   -1,   10,
   59,   36,   61,   38,  119,   40,   41,   10,   -1,   -1,
   -1,   -1,   38,   96,   17,   41,  123,   20,  125,   -1,
   -1,   -1,   -1,   10,   59,   36,   61,   38,   10,   40,
   41,   -1,   10,   59,   10,   -1,   -1,   96,   41,   -1,
  123,   -1,  125,   10,   -1,   -1,   -1,   50,   59,   -1,
   -1,   38,   55,   -1,   -1,   -1,   38,   -1,   -1,   41,
   38,   96,   38,   41,   -1,   41,  125,   -1,   -1,   -1,
   -1,   38,   59,   -1,   -1,   -1,   10,   59,   -1,   -1,
   -1,   59,   -1,   59,   -1,   96,   -1,   -1,  123,   -1,
  125,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,  125,
   -1,   -1,  257,   -1,   38,   -1,  257,   41,  263,  264,
  269,   -1,  123,   -1,  125,  270,  271,   -1,   -1,  270,
  271,   -1,   -1,   -1,   -1,   59,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  125,  275,  276,  277,  278,  279,  125,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  264,  275,  276,
  277,  278,  279,  264,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  125,  275,  276,  277,  278,  279,   -1,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,   -1,  275,  276,  277,  278,
  279,   -1,  257,  258,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  264,   -1,
  275,  276,  277,  278,  279,   10,  257,  258,  259,   -1,
  261,  262,  263,  264,  265,  266,  267,  268,   -1,  270,
  271,  272,  273,   -1,  275,  276,  277,  278,  279,   10,
  257,   36,   -1,   38,   -1,   40,   41,  264,   -1,  257,
   -1,  263,  264,  270,  271,   -1,   -1,  263,  264,   -1,
  257,   10,  270,  271,   59,   36,   61,   38,   -1,   40,
   41,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   10,   -1,   -1,   -1,   36,   59,   -1,
   -1,   40,   41,  257,   -1,    4,   -1,    6,   -1,  263,
  264,   96,   -1,   -1,   -1,   10,  270,  271,   17,   36,
   -1,   20,   61,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   96,   -1,   10,   -1,   -1,
  125,   36,   59,   -1,   61,   40,   41,   -1,   -1,   -1,
   10,   50,   -1,   -1,   10,   -1,   -1,   96,   -1,   -1,
   65,   -1,  123,   36,  125,   -1,   61,   40,   -1,   -1,
   -1,   -1,   -1,   -1,   79,   80,   81,   -1,   38,   96,
   10,   41,   38,   -1,   10,   41,   85,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   59,
   -1,   96,   -1,   59,   -1,   -1,   -1,   -1,   38,   -1,
   10,   41,   38,   -1,   -1,   41,   -1,  122,   -1,   10,
   -1,   -1,  127,   96,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   61,  137,   59,   -1,   -1,   -1,  142,   38,   10,
   -1,   41,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,
  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   38,   59,  125,
   41,   -1,  257,  258,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,   59,   -1,
  275,  276,  277,  278,  279,  125,  257,  258,  259,  125,
  261,  262,  263,  264,  265,  266,  267,  268,   -1,  270,
  271,  272,  273,   -1,  275,  276,  277,  278,  279,  258,
  259,  260,  261,   -1,  263,  125,  265,  266,  267,  268,
  269,   36,   -1,  272,  125,   40,  275,  276,  277,  278,
  279,  258,  259,  260,  261,   -1,  263,   10,  265,  266,
  267,  268,  269,   -1,  125,  272,   61,   -1,  275,  276,
  277,  278,  279,  258,  259,  260,  261,   -1,  263,   -1,
  265,  266,  267,  268,  269,   38,   -1,  272,   41,   -1,
  275,  276,  277,  278,  279,  258,  259,   -1,  261,  262,
   10,   96,  265,  266,  267,  268,   59,  257,   10,  272,
  273,  257,  275,  276,  277,  278,  279,  263,  264,   -1,
  270,  271,   -1,   -1,  270,  271,   -1,   -1,   38,   -1,
   10,   41,   -1,   -1,   10,   -1,   38,  257,   10,   41,
   -1,  257,   10,   -1,  264,   -1,   -1,   -1,  264,   59,
  270,  271,   -1,   -1,  270,  271,   -1,   59,   38,   -1,
   -1,   41,   38,   -1,   -1,   41,   38,  257,   -1,   41,
   38,   -1,  125,   41,  264,   -1,  257,   -1,   36,   59,
  270,  271,   40,   59,   -1,   -1,   -1,   59,   -1,  270,
  271,   59,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,
   36,   -1,   -1,  264,   40,   -1,   -1,   -1,   -1,  270,
  271,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  125,   -1,   61,   36,   -1,   -1,   -1,
   40,   -1,   -1,   -1,   -1,   -1,   94,   -1,   96,   -1,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,  125,
   -1,   61,   36,  125,   -1,   -1,   40,  125,   94,   -1,
   96,   -1,   -1,  258,  259,  260,  261,  262,  263,   -1,
  265,  266,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,  279,   -1,   96,  123,   -1,   36,
   -1,   -1,   -1,   40,   41,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   -1,   -1,
  263,  264,   96,  123,   61,   36,   -1,  270,   -1,   40,
   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,  123,
   61,   -1,   40,   -1,   -1,   -1,   -1,  257,   -1,   96,
   -1,   -1,   -1,  263,  264,  257,   -1,   -1,   -1,   -1,
  270,  263,  264,   61,   -1,   -1,   -1,   -1,  270,   -1,
   -1,   -1,   -1,   -1,   36,   96,   -1,  257,   40,   -1,
   -1,  257,   -1,  263,  264,   -1,   -1,  263,  264,   -1,
  270,  263,  264,   -1,  270,  263,  264,   -1,   96,   -1,
  258,  259,  260,  261,  262,  263,   -1,  265,  266,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,  279,  258,  259,  260,  261,   -1,  263,   -1,  265,
  266,  267,  268,  269,   96,   -1,  272,   -1,   -1,  275,
  276,  277,  278,  279,   -1,   -1,   -1,   -1,  258,  259,
  260,  261,   -1,  263,   -1,  265,  266,  267,  268,  269,
   -1,  123,  272,   -1,   -1,  275,  276,  277,  278,  279,
   -1,   -1,  256,   -1,  258,  259,   36,  261,  262,   -1,
   40,  265,  266,  267,  268,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,  279,   -1,   -1,   -1,   36,
   -1,   61,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,  260,  261,   -1,  263,   -1,  265,  266,
  267,  268,  269,   36,   -1,  272,   -1,   40,  275,  276,
  277,  278,  279,   -1,   -1,   -1,   96,  258,  259,  260,
  261,   -1,  263,   -1,  265,  266,  267,  268,  269,   -1,
   -1,  272,   -1,   -1,  275,  276,  277,  278,  279,   96,
  258,  259,  260,  261,    2,  263,   -1,  265,  266,  267,
  268,  269,   10,   11,  272,   -1,   -1,  275,  276,  277,
  278,  279,   -1,   96,   -1,   -1,  123,   -1,   -1,   27,
   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,  261,
  262,   -1,   -1,  265,  266,  267,  268,   -1,   -1,   -1,
  272,  273,   -1,  275,  276,  277,  278,  279,   56,   -1,
   -1,   -1,   -1,   -1,   -1,   63,   64,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   72,   -1,   -1,   -1,   76,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   89,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  134,   -1,  258,  259,
  260,  261,   -1,  263,   -1,  265,  266,  267,  268,  269,
   -1,   -1,  272,   -1,   -1,  275,  276,  277,  278,  279,
   -1,  258,  259,   -1,  261,  262,   -1,   -1,  265,  266,
  267,  268,   -1,   -1,   -1,  272,  273,   -1,  275,  276,
  277,  278,  279,   -1,   -1,  258,  259,  260,  261,    0,
  263,   -1,  265,  266,  267,  268,  269,   -1,   -1,  272,
   -1,    0,  275,  276,  277,  278,  279,   18,   -1,   -1,
   -1,   22,   -1,   -1,   25,   -1,   -1,   -1,   29,   -1,
   -1,   -1,   -1,   22,   -1,   -1,   25,   -1,   -1,   -1,
   29,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   52,   -1,   -1,   -1,   -1,   57,   -1,   -1,   -1,
   -1,   62,   -1,   52,   -1,   -1,   -1,   -1,   -1,   -1,
   71,   -1,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  101,   -1,   -1,   -1,  105,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  101,  114,  115,  116,  105,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  114,  115,  116,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  136,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  144,  145,  146,   -1,  136,  149,   -1,
   -1,  152,   -1,   -1,   -1,  144,  145,  146,   -1,   -1,
  149,   -1,   -1,  152,
};
#define YYFINAL 21
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'$'",0,"'&'",0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,
"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",0,
"'`'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"ANDAND","BACKBACK","BANG","CASE","COUNT","DUP","ELSE","END",
"FLAT","FN","FOR","IF","IN","OROR","PIPE","REDIR","SREDIR","SUB","SUBSHELL",
"SWITCH","TWIDDLE","WHILE","WORD","HUH","PREDIR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : rc",
"rc : line end",
"rc : error end",
"end : END",
"end : '\\n'",
"cmdsa : cmd ';'",
"cmdsa : cmd '&'",
"line : cmd",
"line : cmdsa line",
"body : cmd",
"body : cmdsan body",
"cmdsan : cmdsa",
"cmdsan : cmd '\\n'",
"brace : '{' body '}'",
"paren : '(' body ')'",
"assign : first optcaret '=' optcaret word",
"epilog :",
"epilog : redir epilog",
"redir : DUP",
"redir : REDIR word",
"redir : SREDIR word",
"case : CASE words ';'",
"case : CASE words '\\n'",
"cbody : cmd",
"cbody : case cbody",
"cbody : cmdsan cbody",
"iftail : cmd else",
"else :",
"else : ELSE optnl cmd",
"cmd :",
"cmd : simple",
"cmd : brace epilog",
"cmd : IF paren optnl iftail",
"cmd : FOR '(' word IN words ')' optnl cmd",
"cmd : FOR '(' word ')' optnl cmd",
"cmd : WHILE paren optnl cmd",
"cmd : SWITCH '(' word ')' optnl '{' cbody '}'",
"cmd : TWIDDLE optcaret word words",
"cmd : cmd ANDAND optnl cmd",
"cmd : cmd OROR optnl cmd",
"cmd : cmd PIPE optnl cmd",
"cmd : redir cmd",
"cmd : assign cmd",
"cmd : BANG optcaret cmd",
"cmd : SUBSHELL optcaret cmd",
"cmd : FN words brace",
"cmd : FN words",
"optcaret :",
"optcaret : '^'",
"simple : first",
"simple : first args",
"args : arg",
"args : args arg",
"arg : word",
"arg : redir",
"first : comword",
"first : first '^' sword",
"sword : comword",
"sword : keyword",
"word : sword",
"word : word '^' sword",
"comword : '$' sword",
"comword : '$' sword SUB words ')'",
"comword : COUNT sword",
"comword : FLAT sword",
"comword : '`' sword",
"comword : '`' brace",
"comword : '$' brace",
"comword : BACKBACK word brace",
"comword : BACKBACK word sword",
"comword : '(' nlwords ')'",
"comword : REDIR brace",
"comword : WORD",
"keyword : FOR",
"keyword : IN",
"keyword : WHILE",
"keyword : IF",
"keyword : SWITCH",
"keyword : FN",
"keyword : ELSE",
"keyword : CASE",
"keyword : TWIDDLE",
"keyword : BANG",
"keyword : SUBSHELL",
"keyword : '='",
"words :",
"words : words word",
"nlwords :",
"nlwords : nlwords '\\n'",
"nlwords : nlwords word",
"optnl :",
"optnl : optnl '\\n'",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 182 "parse.y"

void initparse(void) {
	star = treecpy(mk(nVar, mk(nWord,"*", NULL, FALSE)), ealloc);
	nolist = treecpy(mk(nVar, mk(nWord,"ifs", NULL, FALSE)), ealloc);
}

#line 677 "parse.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM)
        goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0)
        goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0)
            yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL)
                yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
            goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)
            --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0)
        goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                    goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base)
                    goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF)
            goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL)
                yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 53 "parse.y"
	{ parsetree = yystack.l_mark[-1].node; YYACCEPT; }
break;
case 2:
#line 54 "parse.y"
	{ yyerrok; parsetree = NULL; YYABORT; }
break;
case 3:
#line 57 "parse.y"
	{ if (!heredoc(1)) YYABORT; }
break;
case 4:
#line 58 "parse.y"
	{ if (!heredoc(0)) YYABORT; }
break;
case 6:
#line 62 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nNowait,yystack.l_mark[-1].node) : yystack.l_mark[-1].node); }
break;
case 8:
#line 66 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[0].node); }
break;
case 10:
#line 70 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node == NULL ? yystack.l_mark[0].node : yystack.l_mark[0].node == NULL ? yystack.l_mark[-1].node : mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node)); }
break;
case 12:
#line 73 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; if (!heredoc(0)) YYABORT; }
break;
case 13:
#line 75 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 14:
#line 77 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 15:
#line 79 "parse.y"
	{ yyval.node = mk(nAssign,yystack.l_mark[-4].node,yystack.l_mark[0].node); }
break;
case 16:
#line 81 "parse.y"
	{ yyval.node = NULL; }
break;
case 17:
#line 82 "parse.y"
	{ yyval.node = mk(nEpilog,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 18:
#line 85 "parse.y"
	{ yyval.node = mk(nDup,yystack.l_mark[0].dup.type,yystack.l_mark[0].dup.left,yystack.l_mark[0].dup.right); }
break;
case 19:
#line 86 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 20:
#line 89 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 21:
#line 93 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 22:
#line 94 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 23:
#line 96 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[0].node, NULL); }
break;
case 24:
#line 97 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 25:
#line 98 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 26:
#line 100 "parse.y"
	{ yyval.node = yystack.l_mark[0].node != NULL ? mk(nElse, yystack.l_mark[-1].node, yystack.l_mark[0].node) : yystack.l_mark[-1].node; }
break;
case 27:
#line 102 "parse.y"
	{ yyval.node = NULL; }
break;
case 28:
#line 103 "parse.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 29:
#line 105 "parse.y"
	{ yyval.node = NULL; }
break;
case 31:
#line 107 "parse.y"
	{ yyval.node = mk(nBrace,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 32:
#line 108 "parse.y"
	{ yyval.node = mk(nIf,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 33:
#line 109 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-5].node,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 34:
#line 110 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-3].node,star,yystack.l_mark[0].node); }
break;
case 35:
#line 111 "parse.y"
	{ yyval.node = mk(nWhile,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 36:
#line 112 "parse.y"
	{ yyval.node = mk(nSwitch,yystack.l_mark[-5].node,yystack.l_mark[-1].node); }
break;
case 37:
#line 113 "parse.y"
	{ yyval.node = mk(nMatch,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 38:
#line 114 "parse.y"
	{ yyval.node = mk(nAndalso,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 39:
#line 115 "parse.y"
	{ yyval.node = mk(nOrelse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 40:
#line 116 "parse.y"
	{ yyval.node = mk(nPipe,yystack.l_mark[-2].pipe.left,yystack.l_mark[-2].pipe.right,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 41:
#line 117 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 42:
#line 118 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 43:
#line 119 "parse.y"
	{ yyval.node = mk(nBang,yystack.l_mark[0].node); }
break;
case 44:
#line 120 "parse.y"
	{ yyval.node = mk(nSubshell,yystack.l_mark[0].node); }
break;
case 45:
#line 121 "parse.y"
	{ yyval.node = mk(nNewfn,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 46:
#line 122 "parse.y"
	{ yyval.node = mk(nRmfn,yystack.l_mark[0].node); }
break;
case 50:
#line 128 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 52:
#line 131 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 56:
#line 137 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 58:
#line 140 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].keyword, NULL, FALSE); }
break;
case 60:
#line 143 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 61:
#line 145 "parse.y"
	{ yyval.node = mk(nVar,yystack.l_mark[0].node); }
break;
case 62:
#line 146 "parse.y"
	{ yyval.node = mk(nVarsub,yystack.l_mark[-3].node,yystack.l_mark[-1].node); }
break;
case 63:
#line 147 "parse.y"
	{ yyval.node = mk(nCount,yystack.l_mark[0].node); }
break;
case 64:
#line 148 "parse.y"
	{ yyval.node = mk(nFlat, yystack.l_mark[0].node); }
break;
case 65:
#line 149 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 66:
#line 150 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 67:
#line 151 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 68:
#line 152 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 69:
#line 153 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 70:
#line 154 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 71:
#line 155 "parse.y"
	{ yyval.node = mk(nNmpipe,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node); }
break;
case 72:
#line 156 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].word.w, yystack.l_mark[0].word.m, yystack.l_mark[0].word.q); }
break;
case 73:
#line 158 "parse.y"
	{ yyval.keyword = "for"; }
break;
case 74:
#line 159 "parse.y"
	{ yyval.keyword = "in"; }
break;
case 75:
#line 160 "parse.y"
	{ yyval.keyword = "while"; }
break;
case 76:
#line 161 "parse.y"
	{ yyval.keyword = "if"; }
break;
case 77:
#line 162 "parse.y"
	{ yyval.keyword = "switch"; }
break;
case 78:
#line 163 "parse.y"
	{ yyval.keyword = "fn"; }
break;
case 79:
#line 164 "parse.y"
	{ yyval.keyword = "else"; }
break;
case 80:
#line 165 "parse.y"
	{ yyval.keyword = "case"; }
break;
case 81:
#line 166 "parse.y"
	{ yyval.keyword = "~"; }
break;
case 82:
#line 167 "parse.y"
	{ yyval.keyword = "!"; }
break;
case 83:
#line 168 "parse.y"
	{ yyval.keyword = "@"; }
break;
case 84:
#line 169 "parse.y"
	{ yyval.keyword = "="; }
break;
case 85:
#line 171 "parse.y"
	{ yyval.node = NULL; }
break;
case 86:
#line 172 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
case 87:
#line 174 "parse.y"
	{ yyval.node = NULL; }
break;
case 89:
#line 176 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
#line 1187 "parse.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0)
                yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL)
                    yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF)
            goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
