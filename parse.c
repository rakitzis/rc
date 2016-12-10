/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20161202

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
#line 29 "parse.y"
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
} yytoken;
#endif /* !YYTOKEN_IS_DECLARED */
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   24,   24,    8,    8,   13,   13,    3,    3,
    9,    9,    4,   15,    2,   11,   11,   16,   16,   16,
    5,    5,    6,    6,    6,   19,   19,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,   25,   25,   18,   18,   23,
   23,   22,   22,   12,   12,   17,   17,   20,   20,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,   21,   21,   14,   14,   14,   26,   26,
};
static const YYINT yylen[] = {                            2,
    2,    2,    1,    1,    2,    2,    1,    2,    1,    2,
    1,    2,    3,    3,    5,    0,    2,    1,    2,    2,
    3,    3,    1,    2,    2,    1,    4,    0,    1,    2,
    4,    8,    6,    4,    8,    4,    4,    4,    4,    2,
    2,    3,    3,    3,    2,    0,    1,    1,    2,    1,
    2,    1,    1,    1,    3,    1,    1,    1,    3,    2,
    5,    2,    2,    2,    2,    2,    3,    3,    3,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    0,    2,    0,    2,    2,    0,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   18,    0,   84,    0,    0,    0,
    0,    0,    0,    0,    0,   71,    0,    0,   86,    0,
    0,    0,    0,    0,    0,   54,    0,    0,    0,   29,
    3,    4,    2,   81,   79,   78,   77,   72,   75,   73,
    0,   82,   76,   80,   74,   83,   57,   56,   58,    0,
   47,    0,   62,   63,    0,    0,    0,   89,   70,    0,
    0,    0,    0,    0,   89,   66,    0,    0,    0,   11,
    0,    0,   65,   64,    0,    0,   30,    0,   89,   89,
   89,    5,    6,    8,    0,   53,    0,   50,    0,    0,
    1,    0,    0,   67,   68,    0,   44,    0,    0,    0,
    0,    0,    0,    0,    0,   84,   13,   12,   10,   69,
   87,    0,   17,    0,    0,    0,   55,   51,    0,   59,
   84,   89,   14,   90,    0,    0,   31,   89,    0,    0,
    0,    0,    0,   39,    0,    0,    0,   89,    0,   61,
    0,   89,    0,    0,    0,    0,    0,   84,    0,    0,
    0,    0,    0,    0,   24,   35,   25,   22,   21,
};
static const YYINT yydgoto[] = {                         21,
   47,   22,   68,   23,  149,  150,   69,   70,   71,   48,
   77,   27,   28,   72,   58,   29,   49,   30,  127,   98,
   55,   88,   89,   33,   52,  101,
};
static const YYINT yysindex[] = {                       937,
   24, 1030,  -83, 1030,    0, 1030,    0,  -27,   -7,  862,
 1030,  -83,   -3,  -83,   -7,    0,  862, 1128,    0,  862,
    0, 1128, -185,  -30, 1128,    0,  796,   24, 1128,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -101,    0,    0,    0,    0,    0,    0,    0,    0,  818,
    0, 1128,    0,    0,  862, 1030, 1128,    0,    0,  -56,
  -56, 1128, 1030, 1030,    0,    0, -233,  -82,  154,    0,
 1128,  402,    0,    0, -229, 1030,    0, -185,    0,    0,
    0,    0,    0,    0, 1008,    0,  -56,    0,  840,   -4,
    0, -229, 1030,    0,    0, -229,    0,  -56,  -38,   18,
  468, -229,  -36,  -56,  468,    0,    0,    0,    0,    0,
    0,  -56,    0,  468,  468,  468,    0,    0,  -83,    0,
    0,    0,    0,    0, -154, -225,    0,    0, 1030, -225,
  884, -229, -229,    0, 1030,  913,  468,    0,   -9,    0,
  -56,    0, -225,  468, 1052,  468, -225,    0, 1052,  -65,
  154, 1052, -225,  424,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                       134,
    0,    0,  356,    0,    0,    0,    0,    0,    0,    0,
    0,  356,    0, 1074,    0,    0,    0,  491,    0,    0,
    0,  187,  500,   54,  134,    0,  485,    0,  187,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  187,    0,    0,  511,    0,  143,    0,    0,   14,
   38,  187,    0,    0,    0,    0,  -10,    0,  -35,    0,
  481,    0,    0,    0,  678,    0,    0,  500,    0,    0,
    0,    0,    0,    0,    5,    0,   62,    0,  515,    0,
    0,  749,    0,    0,    0,  750,    0,   86,    0,    0,
  -34,  759,    0,  110,  -34,    0,    0,    0,    0,    0,
    0,  446,    0,  -34,  -34,  -34,    0,    0, 1074,    0,
    0,    0,    0,    0,  500,    6,    0,    0,  541,   30,
    0,  779,  783,    0,    0,    0,  -34,    0,    0,    0,
  380,    0,   95,  -34,  491,  -34,  119,    0,  491,    0,
  -64,  491,  139,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -18,   75,    0, -140, 1336,    2, -135, 1356,
  -15,    0,   42,    0,   65,   -8,  442,    0,    0,  833,
  -86,  -20,    0,   55,    9,  352,
};
#define YYTABLESIZE 1508
static const YYINT yytable[] = {                         60,
  124,   25,  122,   28,  128,    9,   28,   83,  155,  152,
   51,  157,   56,  152,   78,   26,  152,  129,   86,  131,
   62,   18,   64,   19,   28,   60,   25,   60,   82,   60,
   60,   79,   57,   32,  136,   90,   63,   93,  100,   34,
  106,   81,  107,   26,   80,   81,   26,   20,   60,   19,
   60,   19,  109,   19,   19,   93,  119,   93,  123,  156,
   23,  154,  113,    7,   26,   47,   84,   34,  118,   78,
   34,   52,   19,   20,   19,   20,    5,   20,   20,   65,
   86,    0,   91,   60,   59,   60,   76,   11,   34,    9,
   28,   66,    0,    0,   73,   85,   20,   52,   20,   52,
    0,   52,   52,    0,   33,    0,    0,    5,  138,   19,
    0,    0,   60,  145,   60,   59,   78,   76,   11,   84,
   52,   85,   52,   85,   94,   85,   85,  135,   27,   97,
   26,    0,   33,   20,    0,   33,   19,    0,   19,    0,
    0,    0,    0,   28,   85,   84,   85,   84,   32,   84,
   84,    0,   28,   33,   34,    0,   27,   52,    0,   27,
   20,    0,   20,  108,    0,    0,    0,    0,   84,    0,
   84,   28,    0,    0,    0,  125,   32,   27,    0,   32,
   28,   85,    0,   28,    0,    0,   52,    0,    0,    0,
    0,   83,   28,    0,    0,    0,   28,   32,    0,    0,
    0,   28,    0,    0,    0,   84,    0,    0,   85,    0,
   85,    0,   82,    0,    0,    0,    0,    0,    0,   33,
    0,    0,   28,    0,   28,    0,   79,   28,    0,   28,
  121,    0,    0,    0,   84,   28,   28,    0,    0,   80,
   81,    0,    0,   27,    0,   28,   60,   60,   60,   60,
   60,   60,   60,   60,   60,   60,   60,   60,   60,   60,
   60,   60,   60,   32,   60,   60,   60,   60,   60,   26,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   31,   19,   19,
   19,   19,   19,   34,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   28,   20,   20,   20,   20,   20,    7,   52,   52,
   52,   52,   52,   52,   52,   52,   52,   52,   52,   52,
   52,   52,   52,   52,   52,    0,   52,   52,   52,   52,
   52,    0,   85,   85,   85,   85,   85,    0,   85,   85,
   85,   85,   85,   85,   85,   85,   85,   85,   33,    0,
   85,   85,   85,   85,   85,   46,   84,   84,   84,   84,
   84,    0,   84,   84,   84,   84,   84,   84,   84,   84,
   84,   84,   27,    0,   84,   84,   84,   84,   84,   15,
   28,   46,    0,   46,    0,   46,   46,   28,    0,   28,
    0,    0,   32,   28,   28,    0,    0,    0,    0,    0,
   79,  111,   28,   28,   46,   15,  105,   15,    0,   15,
   15,    0,    0,   80,   81,    0,    0,    0,    0,    0,
  114,  115,  116,  158,    0,    0,    0,   17,   15,    0,
    0,   19,  110,   28,    0,   53,    0,   54,    0,    0,
   28,   46,    0,    0,    0,   88,   28,   28,   67,   17,
    0,   74,   46,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  137,    0,   15,    0,  124,   46,  139,
   46,   88,  159,    0,   46,   88,   88,    0,    0,  144,
   28,   95,    0,  146,   48,    0,    0,   20,    0,    0,
   28,    0,   15,   17,   15,    0,   88,   19,    0,   16,
    0,    0,    0,    0,    0,    0,    0,    0,   28,   20,
   45,   28,   48,    0,   49,   48,  117,    0,   28,    0,
    0,    0,    0,    0,  120,    0,    0,   16,    0,   28,
   16,   88,    0,   48,    0,   46,    0,    0,   45,   28,
   36,   45,   49,    0,    0,   49,    0,    0,   16,    0,
    0,    0,    0,   20,    0,    0,    0,    0,    0,   45,
    0,    0,    0,   49,    0,    0,    0,    0,   36,    0,
    0,   36,    0,    0,    0,    0,    0,    0,    0,    0,
   18,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,    0,    0,    0,   28,    0,    0,    0,   48,
    0,    0,   46,   46,   46,   28,   46,   46,    0,   46,
   46,   46,   46,   46,   16,   46,   46,   46,   46,    0,
   46,   46,   46,   46,   46,   45,   15,   15,   15,   49,
   15,   15,    0,   15,   15,   15,   15,   15,    0,   15,
   15,   15,   15,    0,   15,   15,   15,   15,   15,    2,
   34,   35,    4,    0,   36,   36,    6,   37,   38,   39,
   40,    0,    0,   41,    0,    0,   42,   43,   44,   45,
   16,    2,   34,   35,    4,    0,   36,   41,    6,   37,
   38,   39,   40,    0,    0,   41,    0,    0,   42,   43,
   44,   45,   16,   88,   88,   88,   88,    0,   88,    0,
   88,   88,   88,   88,   88,   41,    0,   88,   41,    0,
   88,   88,   88,   88,   88,    2,    3,    0,    4,    5,
    0,    0,    6,    7,    8,    9,   41,   28,    0,   10,
   11,   48,   12,   13,   14,   15,   16,   28,   48,    0,
   28,   28,    0,    0,   48,   48,   16,    0,   40,   42,
   28,   28,    0,   16,    0,    0,    0,   45,   43,   16,
   16,   49,    0,    0,   45,    0,    0,    0,   49,    0,
   45,   45,    0,    0,   49,   49,   40,   42,   37,   40,
   42,    0,   38,    0,    0,    0,   43,   36,    0,   43,
    0,    0,   41,    0,   36,    0,    0,   40,   42,    0,
   36,   36,    0,    0,    0,    0,   37,   43,    0,   37,
   38,    0,    0,   38,    0,    0,    0,    0,    0,    0,
    0,   17,    0,    0,   50,   19,    0,   37,    0,    0,
    0,   38,   60,   61,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,    0,    0,   19,    0,   87,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   40,   42,   17,    0,    0,   46,   19,
    0,    0,    0,   43,    0,    0,    0,    0,   99,   85,
    0,   20,    0,    0,    0,  103,  104,   17,    0,    0,
   46,   19,    0,   37,  112,    0,    0,   38,   60,    0,
    0,   93,    0,   20,    0,    0,    0,    0,    0,   17,
    0,   87,   46,   19,  140,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   41,   20,    0,    0,    0,    0,
   18,   41,    0,    0,   46,    0,    0,   41,   17,    0,
    0,    0,   19,  142,    0,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  141,    0,    0,
    0,    0,   17,   46,    0,    0,   19,    0,    0,   20,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,   42,    0,   20,    0,
    0,    0,   40,   42,    0,   43,    0,    0,   40,   42,
    0,    0,   43,    0,    0,    0,    0,    0,   43,    0,
    0,    0,   20,    0,    0,   37,    0,    0,    0,   38,
    0,    0,   37,   17,    0,    0,   38,   19,   37,    0,
    0,    0,   38,    2,   34,   35,    4,    5,   36,   18,
    6,   37,   38,   39,   40,   17,    0,   10,   11,   19,
   42,   43,   44,   45,   16,    2,   34,   35,    4,    0,
   36,    0,    6,   37,   38,   39,   40,   17,    0,   41,
   46,   19,   42,   43,   44,   45,   16,    2,   34,   35,
    4,    5,   36,   20,    6,   37,   38,   39,   40,   46,
    0,   10,   11,   46,   42,   43,   44,   45,   16,    2,
   34,   35,    4,    0,   36,   20,    6,   37,   38,   39,
   40,    0,    0,   41,   46,    0,   42,   43,   44,   45,
   16,    2,   34,   35,    4,    0,   36,   20,    6,   37,
   38,   39,   40,    0,    0,   41,    0,    0,   42,   43,
   44,   45,   16,   17,    0,    0,    0,   19,    0,   46,
    2,   34,   35,    4,   18,   36,    0,    6,   37,   38,
   39,   40,    0,    0,   41,    0,    0,   42,   43,   44,
   45,   16,    1,    0,    2,    3,    0,    4,    5,    0,
    0,    6,    7,    8,    9,    0,    0,    0,   10,   11,
    0,   12,   13,   14,   15,   16,    0,    0,    0,    0,
    0,    0,    0,   20,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   18,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,   34,   35,    4,    0,
   36,    0,    6,   37,   38,   39,   40,    0,    0,   41,
    0,    0,   42,   43,   44,   45,   16,    2,   34,   35,
    4,    0,   36,    0,    6,   37,   38,   39,   40,    0,
    0,   41,    0,    0,   42,   43,   44,   45,   16,    2,
    3,  148,    4,    5,    0,    0,    6,    7,    8,    9,
    0,    0,    0,   10,   11,    0,   12,   13,   14,   15,
   16,   46,   46,   46,   46,   24,   46,    0,   46,   46,
   46,   46,   46,    0,    0,   46,    0,    0,   46,   46,
   46,   46,   46,    0,    0,   26,    0,   75,    0,    0,
   24,    0,    0,    0,   92,    0,    0,    0,    0,    0,
    0,    0,    0,   26,    0,    0,    0,   26,    0,    0,
   26,    0,    0,    0,   26,    2,    3,   96,    4,    5,
    0,    0,    6,    7,    8,    9,    0,  102,    0,   10,
   11,    0,   12,   13,   14,   15,   16,   26,    0,    0,
    0,    0,   26,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  126,    0,    0,    0,
  130,    0,    0,    0,    0,    0,    0,    0,    0,  132,
  133,  134,    0,    0,    0,    0,   26,    0,    0,    0,
   26,    0,    0,    0,    0,    0,    0,    0,    0,   26,
   26,   26,  143,    0,    0,    0,    0,    0,    0,  147,
  151,  153,    0,    0,  151,    0,    0,  151,    0,    0,
    0,    0,   26,    0,    0,    0,    0,    0,    0,   26,
   26,   26,    0,    0,   26,    0,    0,   26,
};
static const YYINT yycheck[] = {                         10,
   10,    0,   41,   38,   41,   41,   41,   38,  149,  145,
   94,  152,   40,  149,   23,   10,  152,  104,   27,  106,
   12,  123,   14,   10,   59,   36,   25,   38,   59,   40,
   41,  257,   40,   10,  121,   27,   40,   94,   57,   10,
  274,  271,  125,   38,  270,  271,   41,   10,   59,   36,
   61,   38,   71,   40,   41,   94,   61,   94,   41,  125,
  125,  148,   78,   10,   59,   61,   25,   38,   89,   78,
   41,   10,   59,   36,   61,   38,  262,   40,   41,   15,
   89,   -1,   28,   94,   10,   96,  272,  273,   59,  125,
  125,   17,   -1,   -1,   20,   10,   59,   36,   61,   38,
   -1,   40,   41,   -1,   10,   -1,   -1,  262,  263,   96,
   -1,   -1,  123,  123,  125,   41,  125,  272,  273,   10,
   59,   36,   61,   38,   50,   40,   41,  119,   10,   55,
  125,   -1,   38,   96,   -1,   41,  123,   -1,  125,   -1,
   -1,   -1,   -1,   10,   59,   36,   61,   38,   10,   40,
   41,   -1,   10,   59,  125,   -1,   38,   96,   -1,   41,
  123,   -1,  125,   10,   -1,   -1,   -1,   -1,   59,   -1,
   61,   38,   -1,   -1,   -1,  101,   38,   59,   -1,   41,
   38,   96,   -1,   41,   -1,   -1,  125,   -1,   -1,   -1,
   -1,   38,   59,   -1,   -1,   -1,   10,   59,   -1,   -1,
   -1,   59,   -1,   -1,   -1,   96,   -1,   -1,  123,   -1,
  125,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,  125,
   -1,   -1,  257,   -1,   38,   -1,  257,   41,   -1,  264,
  269,   -1,   -1,   -1,  125,  270,  271,   -1,   -1,  270,
  271,   -1,   -1,  125,   -1,   59,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  125,  275,  276,  277,  278,  279,  264,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  264,  275,  276,
  277,  278,  279,  264,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  125,  275,  276,  277,  278,  279,  264,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,   -1,  275,  276,  277,  278,
  279,   -1,  257,  258,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  264,   -1,
  275,  276,  277,  278,  279,   10,  257,  258,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  264,   -1,  275,  276,  277,  278,  279,   10,
  257,   36,   -1,   38,   -1,   40,   41,  264,   -1,  257,
   -1,   -1,  264,  270,  271,   -1,   -1,   -1,   -1,   -1,
  257,   10,  270,  271,   59,   36,   65,   38,   -1,   40,
   41,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,
   79,   80,   81,   10,   -1,   -1,   -1,   36,   59,   -1,
   -1,   40,   41,  257,   -1,    4,   -1,    6,   -1,   -1,
  264,   96,   -1,   -1,   -1,   10,  270,  271,   17,   36,
   -1,   20,   61,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  122,   -1,   96,   -1,   10,  123,  128,
  125,   36,   59,   -1,   61,   40,   41,   -1,   -1,  138,
   10,   50,   -1,  142,   10,   -1,   -1,   96,   -1,   -1,
   10,   -1,  123,   36,  125,   -1,   61,   40,   -1,   10,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,   96,
   10,   41,   38,   -1,   10,   41,   85,   -1,   38,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   38,   -1,   59,
   41,   96,   -1,   59,   -1,   61,   -1,   -1,   38,   59,
   10,   41,   38,   -1,   -1,   41,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   96,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   38,   -1,
   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,  125,
   -1,   -1,  257,  258,  259,  125,  261,  262,   -1,  264,
  265,  266,  267,  268,  125,  270,  271,  272,  273,   -1,
  275,  276,  277,  278,  279,  125,  257,  258,  259,  125,
  261,  262,   -1,  264,  265,  266,  267,  268,   -1,  270,
  271,  272,  273,   -1,  275,  276,  277,  278,  279,  258,
  259,  260,  261,   -1,  263,  125,  265,  266,  267,  268,
  269,   -1,   -1,  272,   -1,   -1,  275,  276,  277,  278,
  279,  258,  259,  260,  261,   -1,  263,   10,  265,  266,
  267,  268,  269,   -1,   -1,  272,   -1,   -1,  275,  276,
  277,  278,  279,  258,  259,  260,  261,   -1,  263,   -1,
  265,  266,  267,  268,  269,   38,   -1,  272,   41,   -1,
  275,  276,  277,  278,  279,  258,  259,   -1,  261,  262,
   -1,   -1,  265,  266,  267,  268,   59,  257,   -1,  272,
  273,  257,  275,  276,  277,  278,  279,  257,  264,   -1,
  270,  271,   -1,   -1,  270,  271,  257,   -1,   10,   10,
  270,  271,   -1,  264,   -1,   -1,   -1,  257,   10,  270,
  271,  257,   -1,   -1,  264,   -1,   -1,   -1,  264,   -1,
  270,  271,   -1,   -1,  270,  271,   38,   38,   10,   41,
   41,   -1,   10,   -1,   -1,   -1,   38,  257,   -1,   41,
   -1,   -1,  125,   -1,  264,   -1,   -1,   59,   59,   -1,
  270,  271,   -1,   -1,   -1,   -1,   38,   59,   -1,   41,
   38,   -1,   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   36,   -1,   -1,    2,   40,   -1,   59,   -1,   -1,
   -1,   59,   10,   11,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   36,   -1,   -1,   -1,   40,   -1,   27,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  125,  125,   36,   -1,   -1,   61,   40,
   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   56,   94,
   -1,   96,   -1,   -1,   -1,   63,   64,   36,   -1,   -1,
   61,   40,   -1,  125,   72,   -1,   -1,  125,   76,   -1,
   -1,   94,   -1,   96,   -1,   -1,   -1,   -1,   -1,   36,
   -1,   89,   61,   40,   41,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,   96,   -1,   -1,   -1,   -1,
  123,  264,   -1,   -1,   61,   -1,   -1,  270,   36,   -1,
   -1,   -1,   40,   41,   -1,   -1,   -1,   96,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  135,   -1,   -1,
   -1,   -1,   36,   61,   -1,   -1,   40,   -1,   -1,   96,
   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  257,   -1,   96,   -1,
   -1,   -1,  264,  264,   -1,  257,   -1,   -1,  270,  270,
   -1,   -1,  264,   -1,   -1,   -1,   -1,   -1,  270,   -1,
   -1,   -1,   96,   -1,   -1,  257,   -1,   -1,   -1,  257,
   -1,   -1,  264,   36,   -1,   -1,  264,   40,  270,   -1,
   -1,   -1,  270,  258,  259,  260,  261,  262,  263,  123,
  265,  266,  267,  268,  269,   36,   -1,  272,  273,   40,
  275,  276,  277,  278,  279,  258,  259,  260,  261,   -1,
  263,   -1,  265,  266,  267,  268,  269,   36,   -1,  272,
   61,   40,  275,  276,  277,  278,  279,  258,  259,  260,
  261,  262,  263,   96,  265,  266,  267,  268,  269,   36,
   -1,  272,  273,   40,  275,  276,  277,  278,  279,  258,
  259,  260,  261,   -1,  263,   96,  265,  266,  267,  268,
  269,   -1,   -1,  272,   61,   -1,  275,  276,  277,  278,
  279,  258,  259,  260,  261,   -1,  263,   96,  265,  266,
  267,  268,  269,   -1,   -1,  272,   -1,   -1,  275,  276,
  277,  278,  279,   36,   -1,   -1,   -1,   40,   -1,   96,
  258,  259,  260,  261,  123,  263,   -1,  265,  266,  267,
  268,  269,   -1,   -1,  272,   -1,   -1,  275,  276,  277,
  278,  279,  256,   -1,  258,  259,   -1,  261,  262,   -1,
   -1,  265,  266,  267,  268,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   96,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  123,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  258,  259,  260,  261,   -1,
  263,   -1,  265,  266,  267,  268,  269,   -1,   -1,  272,
   -1,   -1,  275,  276,  277,  278,  279,  258,  259,  260,
  261,   -1,  263,   -1,  265,  266,  267,  268,  269,   -1,
   -1,  272,   -1,   -1,  275,  276,  277,  278,  279,  258,
  259,  260,  261,  262,   -1,   -1,  265,  266,  267,  268,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
  279,  258,  259,  260,  261,    0,  263,   -1,  265,  266,
  267,  268,  269,   -1,   -1,  272,   -1,   -1,  275,  276,
  277,  278,  279,   -1,   -1,    0,   -1,   22,   -1,   -1,
   25,   -1,   -1,   -1,   29,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   18,   -1,   -1,   -1,   22,   -1,   -1,
   25,   -1,   -1,   -1,   29,  258,  259,   52,  261,  262,
   -1,   -1,  265,  266,  267,  268,   -1,   62,   -1,  272,
  273,   -1,  275,  276,  277,  278,  279,   52,   -1,   -1,
   -1,   -1,   57,   -1,   -1,   -1,   -1,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   71,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  101,   -1,   -1,   -1,
  105,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  114,
  115,  116,   -1,   -1,   -1,   -1,  101,   -1,   -1,   -1,
  105,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  114,
  115,  116,  137,   -1,   -1,   -1,   -1,   -1,   -1,  144,
  145,  146,   -1,   -1,  149,   -1,   -1,  152,   -1,   -1,
   -1,   -1,  137,   -1,   -1,   -1,   -1,   -1,   -1,  144,
  145,  146,   -1,   -1,  149,   -1,   -1,  152,
};
#define YYFINAL 21
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 309
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
"SWITCH","TWIDDLE","WHILE","WORD","HUH",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
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
"iftail : cmd",
"iftail : brace ELSE optnl cmd",
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

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

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
#line 178 "parse.y"

void initparse() {
	star = treecpy(mk(nVar, mk(nWord,"*", NULL, FALSE)), ealloc);
	nolist = treecpy(mk(nVar, mk(nWord,"ifs", NULL, FALSE)), ealloc);
}

#line 659 "parse.c"

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
#line 51 "parse.y"
	{ parsetree = yystack.l_mark[-1].node; YYACCEPT; }
break;
case 2:
#line 52 "parse.y"
	{ yyerrok; parsetree = NULL; YYABORT; }
break;
case 3:
#line 55 "parse.y"
	{ if (!heredoc(1)) YYABORT; }
break;
case 4:
#line 56 "parse.y"
	{ if (!heredoc(0)) YYABORT; }
break;
case 6:
#line 60 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nNowait,yystack.l_mark[-1].node) : yystack.l_mark[-1].node); }
break;
case 8:
#line 64 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[0].node); }
break;
case 10:
#line 68 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node == NULL ? yystack.l_mark[0].node : yystack.l_mark[0].node == NULL ? yystack.l_mark[-1].node : mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node)); }
break;
case 12:
#line 71 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; if (!heredoc(0)) YYABORT; }
break;
case 13:
#line 73 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 14:
#line 75 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 15:
#line 77 "parse.y"
	{ yyval.node = mk(nAssign,yystack.l_mark[-4].node,yystack.l_mark[0].node); }
break;
case 16:
#line 79 "parse.y"
	{ yyval.node = NULL; }
break;
case 17:
#line 80 "parse.y"
	{ yyval.node = mk(nEpilog,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 18:
#line 83 "parse.y"
	{ yyval.node = mk(nDup,yystack.l_mark[0].dup.type,yystack.l_mark[0].dup.left,yystack.l_mark[0].dup.right); }
break;
case 19:
#line 84 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 20:
#line 87 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 21:
#line 91 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 22:
#line 92 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 23:
#line 94 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[0].node, NULL); }
break;
case 24:
#line 95 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 25:
#line 96 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 27:
#line 99 "parse.y"
	{ yyval.node = mk(nElse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 28:
#line 101 "parse.y"
	{ yyval.node = NULL; }
break;
case 30:
#line 103 "parse.y"
	{ yyval.node = mk(nBrace,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 31:
#line 104 "parse.y"
	{ yyval.node = mk(nIf,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 32:
#line 105 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-5].node,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 33:
#line 106 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-3].node,star,yystack.l_mark[0].node); }
break;
case 34:
#line 107 "parse.y"
	{ yyval.node = mk(nWhile,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 35:
#line 108 "parse.y"
	{ yyval.node = mk(nSwitch,yystack.l_mark[-5].node,yystack.l_mark[-1].node); }
break;
case 36:
#line 109 "parse.y"
	{ yyval.node = mk(nMatch,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 37:
#line 110 "parse.y"
	{ yyval.node = mk(nAndalso,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 38:
#line 111 "parse.y"
	{ yyval.node = mk(nOrelse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 39:
#line 112 "parse.y"
	{ yyval.node = mk(nPipe,yystack.l_mark[-2].pipe.left,yystack.l_mark[-2].pipe.right,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 40:
#line 113 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 41:
#line 114 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 42:
#line 115 "parse.y"
	{ yyval.node = mk(nBang,yystack.l_mark[0].node); }
break;
case 43:
#line 116 "parse.y"
	{ yyval.node = mk(nSubshell,yystack.l_mark[0].node); }
break;
case 44:
#line 117 "parse.y"
	{ yyval.node = mk(nNewfn,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 45:
#line 118 "parse.y"
	{ yyval.node = mk(nRmfn,yystack.l_mark[0].node); }
break;
case 49:
#line 124 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 51:
#line 127 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 55:
#line 133 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 57:
#line 136 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].keyword, NULL, FALSE); }
break;
case 59:
#line 139 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 60:
#line 141 "parse.y"
	{ yyval.node = mk(nVar,yystack.l_mark[0].node); }
break;
case 61:
#line 142 "parse.y"
	{ yyval.node = mk(nVarsub,yystack.l_mark[-3].node,yystack.l_mark[-1].node); }
break;
case 62:
#line 143 "parse.y"
	{ yyval.node = mk(nCount,yystack.l_mark[0].node); }
break;
case 63:
#line 144 "parse.y"
	{ yyval.node = mk(nFlat, yystack.l_mark[0].node); }
break;
case 64:
#line 145 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 65:
#line 146 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 66:
#line 147 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 67:
#line 148 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 68:
#line 149 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 69:
#line 150 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 70:
#line 151 "parse.y"
	{ yyval.node = mk(nNmpipe,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node); }
break;
case 71:
#line 152 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].word.w, yystack.l_mark[0].word.m, yystack.l_mark[0].word.q); }
break;
case 72:
#line 154 "parse.y"
	{ yyval.keyword = "for"; }
break;
case 73:
#line 155 "parse.y"
	{ yyval.keyword = "in"; }
break;
case 74:
#line 156 "parse.y"
	{ yyval.keyword = "while"; }
break;
case 75:
#line 157 "parse.y"
	{ yyval.keyword = "if"; }
break;
case 76:
#line 158 "parse.y"
	{ yyval.keyword = "switch"; }
break;
case 77:
#line 159 "parse.y"
	{ yyval.keyword = "fn"; }
break;
case 78:
#line 160 "parse.y"
	{ yyval.keyword = "else"; }
break;
case 79:
#line 161 "parse.y"
	{ yyval.keyword = "case"; }
break;
case 80:
#line 162 "parse.y"
	{ yyval.keyword = "~"; }
break;
case 81:
#line 163 "parse.y"
	{ yyval.keyword = "!"; }
break;
case 82:
#line 164 "parse.y"
	{ yyval.keyword = "@"; }
break;
case 83:
#line 165 "parse.y"
	{ yyval.keyword = "="; }
break;
case 84:
#line 167 "parse.y"
	{ yyval.node = NULL; }
break;
case 85:
#line 168 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
case 86:
#line 170 "parse.y"
	{ yyval.node = NULL; }
break;
case 88:
#line 172 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
#line 1161 "parse.c"
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
