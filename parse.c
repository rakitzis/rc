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
#line 30 "parse.y"
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
    REDIR_PREC = 273,
    SREDIR = 274,
    SUB = 275,
    SUBSHELL = 276,
    SWITCH = 277,
    TWIDDLE = 278,
    WHILE = 279,
    WORD = 280,
    HUH = 281
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
    1,   40,    0,   67,   68,    0,   44,    0,    0,    0,
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
static const YYINT yysindex[] = {                       938,
   -1,  967,  -82,  967,    0,  967,    0,  -27,   -4,  860,
  967,  -82,    5,  -82,   -4,    0,  860, 1117,    0,  860,
    0, 1117, -240,  -32, 1117,    0,  692,   -1, 1117,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -84,    0,    0,    0,    0,    0,    0,    0,    0,  811,
    0, 1117,    0,    0,  860,  967, 1117,    0,    0,  -54,
  -54, 1117,  967,  967,    0,    0, -234,  -79,  160,    0,
 1117,  410,    0,    0, -218,  967,    0, -240,    0,    0,
    0,    0,    0,    0, 1094,    0,  -54,    0,  834,    2,
    0,    0,  967,    0,    0, -218,    0,  -54,  -38,   19,
  480, -218,  -33,  -54,  480,    0,    0,    0,    0,    0,
    0,  -54,    0,  480,  480,  480,    0,    0,  -82,    0,
    0,    0,    0,    0, -205, -228,    0,    0,  967, -228,
  883, -218, -218,    0,  967,  906,  480,    0,   -9,    0,
  -54,    0, -228,  480, 1008,  480, -228,    0, 1008,  -63,
  160, 1008, -228,  433,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                       142,
    0,    0,  362,    0,    0,    0,    0,    0,    0,    0,
    0,  362,    0, 1141,    0,    0,    0,  492,    0,    0,
    0,  530,  547,    1,  142,    0,  521,    0,  530,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  530,    0,    0,  555,    0,  158,    0,    0,   14,
   38,  530,    0,    0,    0,    0,  -10,    0,  -36,    0,
  162,    0,    0,    0,  734,    0,    0,  547,    0,    0,
    0,    0,    0,    0,    3,    0,   62,    0,  559,    0,
    0,    0,    0,    0,    0,  769,    0,   86,    0,    0,
  -34,  786,    0,  110,  -34,    0,    0,    0,    0,    0,
    0,  457,    0,  -34,  -34,  -34,    0,    0, 1141,    0,
    0,    0,    0,    0,  547,   49,    0,    0,  730,   95,
    0,  795,  803,    0,    0,    0,  -34,    0,    0,    0,
  386,    0,   97,  -34,  492,  -34,  119,    0,  492,    0,
  -59,  492,  397,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -55,   27,    0, -135, 1422,   10,  -57, 1405,
   -7,    0,   55,    0,   68,   -8,  391,    0,    0,  478,
  -83,    4,    0,   57,    6,   51,
};
#define YYTABLESIZE 1574
static const YYINT yytable[] = {                         60,
  124,  100,  122,   28,    9,   83,   28,  128,   32,   25,
    7,   51,   56,  155,   78,  109,  157,   62,   86,   64,
  129,    5,  131,   19,   28,   60,   82,   60,   79,   60,
   60,   76,   90,   11,   25,   57,   59,  136,   18,   93,
  106,   80,   81,   66,   63,  107,   73,   20,   60,   19,
   60,   19,   81,   19,   19,   93,    5,  138,   26,  123,
   93,  156,  119,   47,  154,   23,   76,   59,   11,   78,
  113,   52,   19,   20,   19,   20,   94,   20,   20,   84,
   86,   97,   65,   60,   91,   60,   26,  152,    9,   26,
   28,  152,  118,    0,  152,   85,   20,   52,   20,   52,
    0,   52,   52,    0,   34,    0,   33,   26,    0,   19,
    0,    0,   60,  145,   60,  105,   78,    0,    0,   84,
   52,   85,   52,   85,  135,   85,   85,  125,   27,  114,
  115,  116,   34,   20,   33,   34,   19,   33,   19,    0,
    0,    0,    0,    0,   85,   84,   85,   84,    0,   84,
   84,   28,    0,   34,    0,   33,   27,   52,    0,   27,
   20,    0,   20,    0,    0,    0,    0,   28,   84,  108,
   84,   28,  137,   26,    0,    0,    0,   27,  139,   28,
    0,   85,    0,    0,    0,    0,   52,    0,  144,    0,
    0,    0,  146,    0,    0,   28,    0,   83,   28,   28,
   28,    0,   28,    0,    0,   84,    0,    0,   85,    0,
   85,    0,    0,    0,    0,    0,   28,    0,   82,   34,
   28,   33,   28,    0,   79,    0,    0,    0,    0,   28,
  121,    0,    0,    0,   84,   28,   28,   80,   81,    0,
    0,    0,    0,   27,    0,    0,   60,   60,   60,   60,
   60,   60,   60,   60,   60,   60,   60,   60,   60,   60,
   60,   60,   31,   60,    7,   60,   60,   60,   60,   60,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   28,   19,    0,   19,
   19,   19,   19,   19,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
    0,   20,   26,   20,   20,   20,   20,   20,   52,   52,
   52,   52,   52,   52,   52,   52,   52,   52,   52,   52,
   52,   52,   52,   52,    0,   52,    0,   52,   52,   52,
   52,   52,   85,   85,   85,   85,   85,    0,   85,   85,
   85,   85,   85,   85,   85,   85,   85,   85,   34,    0,
   33,   85,   85,   85,   85,   85,   84,   84,   84,   84,
   84,   46,   84,   84,   84,   84,   84,   84,   84,   84,
   84,   84,   27,    0,    0,   84,   84,   84,   84,   84,
    0,    0,    0,    0,   53,   15,   54,   46,   28,   46,
    0,   46,   46,    0,    0,   28,   32,   67,    0,    0,
   74,   28,   28,    0,   28,    0,   79,    0,   28,  111,
   46,   15,    0,   15,    0,   15,   15,   28,   28,   80,
   81,   28,   28,    0,   32,    0,    0,   32,    0,    0,
   95,    0,  158,    0,   15,   17,    0,    0,    0,   19,
  110,    0,    0,    0,    0,   32,    0,   46,    0,    0,
    0,    0,    0,    0,    0,    0,   88,    0,   17,    0,
   46,    0,   19,    0,    0,  117,    0,    0,    0,   50,
    0,   15,    0,  120,   46,    0,   46,   60,   61,  124,
    0,  159,   88,   46,    0,    0,   88,   88,    0,    0,
    0,   28,    0,    0,   87,   20,    0,    0,   15,    0,
   15,    0,    0,    0,    0,   17,    0,   88,    0,   19,
    0,   32,    0,    0,    0,    0,    0,    0,   20,   28,
   48,    0,    0,   99,    0,    0,    0,    0,    0,   28,
  103,  104,    0,    0,    0,    0,    0,    0,    0,  112,
   28,    0,   88,   60,    0,    0,   16,    0,   48,    0,
    0,   48,    0,    0,   45,    0,   87,   28,   49,    0,
   28,    0,    0,    0,    0,   20,    0,    0,    0,   48,
    0,   46,    0,    0,   16,    0,    0,   16,   28,    0,
    0,    0,   45,    0,    0,   45,   49,    0,    0,   49,
    0,    0,   18,    0,    0,   16,    0,    0,    0,    0,
    0,    0,  141,   45,    0,    0,   28,   49,   46,   46,
   46,    0,   46,   46,    0,   46,   46,   46,   46,   46,
    0,   46,   46,   46,    0,   46,    0,   46,   46,   46,
   46,   46,   15,   15,   15,   48,   15,   15,    0,   15,
   15,   15,   15,   15,   28,   15,   15,   15,    0,   15,
   32,   15,   15,   15,   15,   15,    0,    2,   34,   35,
    4,   16,   36,    0,    6,   37,   38,   39,   40,   45,
    0,   41,    0,   49,    0,   42,   43,   44,   45,   16,
    2,   34,   35,    4,    0,   36,    0,    6,   37,   38,
   39,   40,    0,    0,   41,    0,    0,    0,   42,   43,
   44,   45,   16,    0,   88,   88,   88,   88,    0,   88,
    0,   88,   88,   88,   88,   88,    0,   17,   88,    0,
    0,   19,   88,   88,   88,   88,   88,    2,    3,   36,
    4,    5,    0,   41,    6,    7,    8,    9,   28,    0,
    0,   10,    0,   11,    0,   12,   13,   14,   15,   16,
    0,   28,   28,    0,    0,    0,    0,   36,    0,    0,
   36,   41,    0,    0,   41,    0,    0,   48,   42,    0,
    0,    0,    0,    0,   48,   85,   28,   20,   36,    0,
   48,   48,   41,   28,    0,   43,    0,    0,    0,   28,
   28,    0,    0,   16,   37,    0,   42,    0,    0,   42,
   16,   45,   38,    0,    0,   49,   16,   16,   45,    0,
    0,    0,   49,   43,   45,   45,   43,   42,   49,   49,
    0,    0,   37,    0,    0,   37,    0,    0,    0,    0,
   38,    0,    0,   38,   43,    0,   17,    0,    0,    0,
   19,    0,    0,   37,   36,    0,    0,    0,   41,    0,
    0,   38,    0,    0,    0,    0,    0,    0,    0,   17,
    0,   46,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   42,   46,   17,    0,    0,    0,   19,
    0,    0,    0,    0,   93,    0,   20,    0,    0,    0,
   43,    0,    0,    0,    0,    0,    0,    0,   17,   37,
   46,    0,   19,  140,    0,    0,    0,   38,    0,   20,
    0,    0,    0,   18,    0,    0,    0,    0,    0,    0,
    0,   17,    0,   46,    0,   19,  142,    0,    0,    2,
   34,   35,    4,    5,   36,   20,    6,   37,   38,   39,
   40,    0,    0,   10,    0,   11,   46,   42,   43,   44,
   45,   16,    0,   17,    0,    0,    0,   19,   20,    0,
    0,    0,   18,    0,    0,    0,   36,    0,    0,    0,
   41,    0,    0,   36,    0,    0,    0,   41,    0,   36,
   36,   20,   17,   41,    0,    0,   19,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,    0,   46,    0,    0,
    0,    0,   42,   20,    0,    0,    0,    0,   42,    0,
    0,    0,   43,   17,    0,    0,    0,   19,    0,   43,
    0,   37,    0,    0,    0,   43,    0,    0,   37,   38,
   18,    0,   20,    0,   37,    0,   38,    0,    2,   34,
   35,    4,   38,   36,    0,    6,   37,   38,   39,   40,
    0,    0,   41,    0,    0,    0,   42,   43,   44,   45,
   16,    2,   34,   35,    4,    5,   36,    0,    6,   37,
   38,   39,   40,   20,    0,   10,    0,   11,    0,   42,
   43,   44,   45,   16,    0,    0,    0,    2,   34,   35,
    4,    0,   36,    0,    6,   37,   38,   39,   40,   17,
   18,   41,    0,   19,    0,   42,   43,   44,   45,   16,
    2,   34,   35,    4,    0,   36,    0,    6,   37,   38,
   39,   40,   17,    0,   41,    0,   19,    0,   42,   43,
   44,   45,   16,    2,   34,   35,    4,    0,   36,    0,
    6,   37,   38,   39,   40,    0,   46,   41,    0,    0,
   46,   42,   43,   44,   45,   16,    0,    0,    0,   20,
    0,    0,    0,    1,    0,    2,    3,    0,    4,    5,
    0,   46,    6,    7,    8,    9,    0,    0,    0,   10,
    0,   11,   20,   12,   13,   14,   15,   16,    0,    0,
    0,    0,    0,    0,    2,   34,   35,    4,    0,   36,
    0,    6,   37,   38,   39,   40,   46,    0,   41,   18,
    0,    0,   42,   43,   44,   45,   16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,  148,    4,    5,
    0,    0,    6,    7,    8,    9,    0,    0,    0,   10,
    0,   11,    0,   12,   13,   14,   15,   16,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,   34,   35,    4,    0,   36,    0,    6,   37,
   38,   39,   40,    0,    0,   41,    0,    0,    0,   42,
   43,   44,   45,   16,    2,    3,    0,    4,    5,    0,
    0,    6,    7,    8,    9,    0,    0,    0,   10,    0,
   11,    0,   12,   13,   14,   15,   16,    0,   46,   46,
   46,   46,    0,   46,   26,   46,   46,   46,   46,   46,
    0,    0,   46,    0,    0,    0,   46,   46,   46,   46,
   46,   24,   26,    0,    0,    0,   26,    0,    0,   26,
    0,    0,    0,   26,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   75,    0,    0,   24,    0,    0,    0,
   92,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,   26,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    0,    0,   96,    0,   26,    0,    0,    0,    0,
    0,    0,    0,  102,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   26,    0,    0,    0,   26,
    0,    0,    0,    0,    0,    0,    0,    0,   26,   26,
   26,    0,  126,    0,    0,    0,  130,    0,    0,    0,
    0,    0,    0,    0,    0,  132,  133,  134,    0,    0,
    0,   26,    0,    0,    0,    0,    0,    0,   26,   26,
   26,    0,    0,   26,    0,    0,   26,    0,  143,    0,
    0,    0,    0,    0,    0,  147,  151,  153,    0,    0,
  151,    0,    0,  151,
};
static const YYINT yycheck[] = {                         10,
   10,   57,   41,   38,   41,   38,   41,   41,   10,    0,
   10,   94,   40,  149,   23,   71,  152,   12,   27,   14,
  104,  262,  106,   10,   59,   36,   59,   38,  257,   40,
   41,  272,   27,  274,   25,   40,   10,  121,  123,   94,
  275,  270,  271,   17,   40,  125,   20,   10,   59,   36,
   61,   38,  271,   40,   41,   94,  262,  263,   10,   41,
   94,  125,   61,   61,  148,  125,  272,   41,  274,   78,
   78,   10,   59,   36,   61,   38,   50,   40,   41,   25,
   89,   55,   15,   94,   28,   96,   38,  145,  125,   41,
  125,  149,   89,   -1,  152,   10,   59,   36,   61,   38,
   -1,   40,   41,   -1,   10,   -1,   10,   59,   -1,   96,
   -1,   -1,  123,  123,  125,   65,  125,   -1,   -1,   10,
   59,   36,   61,   38,  119,   40,   41,  101,   10,   79,
   80,   81,   38,   96,   38,   41,  123,   41,  125,   -1,
   -1,   -1,   -1,   -1,   59,   36,   61,   38,   -1,   40,
   41,   10,   -1,   59,   -1,   59,   38,   96,   -1,   41,
  123,   -1,  125,   -1,   -1,   -1,   -1,   10,   59,   10,
   61,   10,  122,  125,   -1,   -1,   -1,   59,  128,   38,
   -1,   96,   -1,   -1,   -1,   -1,  125,   -1,  138,   -1,
   -1,   -1,  142,   -1,   -1,   38,   -1,   38,   41,   38,
   59,   -1,   41,   -1,   -1,   96,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   59,   -1,   59,  125,
   59,  125,  257,   -1,  257,   -1,   -1,   -1,   -1,  264,
  269,   -1,   -1,   -1,  125,  270,  271,  270,  271,   -1,
   -1,   -1,   -1,  125,   -1,   -1,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  264,  274,  264,  276,  277,  278,  279,  280,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  125,  274,   -1,  276,
  277,  278,  279,  280,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
   -1,  274,  264,  276,  277,  278,  279,  280,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,   -1,  274,   -1,  276,  277,  278,
  279,  280,  257,  258,  259,  260,  261,   -1,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  264,   -1,
  264,  276,  277,  278,  279,  280,  257,  258,  259,  260,
  261,   10,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  264,   -1,   -1,  276,  277,  278,  279,  280,
   -1,   -1,   -1,   -1,    4,   10,    6,   36,  257,   38,
   -1,   40,   41,   -1,   -1,  264,   10,   17,   -1,   -1,
   20,  270,  271,   -1,  257,   -1,  257,   -1,  257,   10,
   59,   36,   -1,   38,   -1,   40,   41,  270,  271,  270,
  271,  270,  271,   -1,   38,   -1,   -1,   41,   -1,   -1,
   50,   -1,   10,   -1,   59,   36,   -1,   -1,   -1,   40,
   41,   -1,   -1,   -1,   -1,   59,   -1,   96,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   36,   -1,
   61,   -1,   40,   -1,   -1,   85,   -1,   -1,   -1,    2,
   -1,   96,   -1,   93,  123,   -1,  125,   10,   11,   10,
   -1,   59,   36,   61,   -1,   -1,   40,   41,   -1,   -1,
   -1,   10,   -1,   -1,   27,   96,   -1,   -1,  123,   -1,
  125,   -1,   -1,   -1,   -1,   36,   -1,   61,   -1,   40,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   96,   38,
   10,   -1,   -1,   56,   -1,   -1,   -1,   -1,   -1,   10,
   63,   64,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   72,
   59,   -1,   96,   76,   -1,   -1,   10,   -1,   38,   -1,
   -1,   41,   -1,   -1,   10,   -1,   89,   38,   10,   -1,
   41,   -1,   -1,   -1,   -1,   96,   -1,   -1,   -1,   59,
   -1,   61,   -1,   -1,   38,   -1,   -1,   41,   59,   -1,
   -1,   -1,   38,   -1,   -1,   41,   38,   -1,   -1,   41,
   -1,   -1,  123,   -1,   -1,   59,   -1,   -1,   -1,   -1,
   -1,   -1,  135,   59,   -1,   -1,  125,   59,  257,  258,
  259,   -1,  261,  262,   -1,  264,  265,  266,  267,  268,
   -1,  270,  271,  272,   -1,  274,   -1,  276,  277,  278,
  279,  280,  257,  258,  259,  125,  261,  262,   -1,  264,
  265,  266,  267,  268,  125,  270,  271,  272,   -1,  274,
  264,  276,  277,  278,  279,  280,   -1,  258,  259,  260,
  261,  125,  263,   -1,  265,  266,  267,  268,  269,  125,
   -1,  272,   -1,  125,   -1,  276,  277,  278,  279,  280,
  258,  259,  260,  261,   -1,  263,   -1,  265,  266,  267,
  268,  269,   -1,   -1,  272,   -1,   -1,   -1,  276,  277,
  278,  279,  280,   -1,  258,  259,  260,  261,   -1,  263,
   -1,  265,  266,  267,  268,  269,   -1,   36,  272,   -1,
   -1,   40,  276,  277,  278,  279,  280,  258,  259,   10,
  261,  262,   -1,   10,  265,  266,  267,  268,  257,   -1,
   -1,  272,   -1,  274,   -1,  276,  277,  278,  279,  280,
   -1,  270,  271,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   38,   -1,   -1,   41,   -1,   -1,  257,   10,   -1,
   -1,   -1,   -1,   -1,  264,   94,  257,   96,   59,   -1,
  270,  271,   59,  264,   -1,   10,   -1,   -1,   -1,  270,
  271,   -1,   -1,  257,   10,   -1,   38,   -1,   -1,   41,
  264,  257,   10,   -1,   -1,  257,  270,  271,  264,   -1,
   -1,   -1,  264,   38,  270,  271,   41,   59,  270,  271,
   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,   59,   -1,   36,   -1,   -1,   -1,
   40,   -1,   -1,   59,  125,   -1,   -1,   -1,  125,   -1,
   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,
   -1,   61,   -1,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  125,   61,   36,   -1,   -1,   -1,   40,
   -1,   -1,   -1,   -1,   94,   -1,   96,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,  125,
   61,   -1,   40,   41,   -1,   -1,   -1,  125,   -1,   96,
   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   36,   -1,   61,   -1,   40,   41,   -1,   -1,  258,
  259,  260,  261,  262,  263,   96,  265,  266,  267,  268,
  269,   -1,   -1,  272,   -1,  274,   61,  276,  277,  278,
  279,  280,   -1,   36,   -1,   -1,   -1,   40,   96,   -1,
   -1,   -1,  123,   -1,   -1,   -1,  257,   -1,   -1,   -1,
  257,   -1,   -1,  264,   -1,   -1,   -1,  264,   -1,  270,
  271,   96,   36,  270,   -1,   -1,   40,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   61,   -1,   -1,
   -1,   -1,  264,   96,   -1,   -1,   -1,   -1,  270,   -1,
   -1,   -1,  257,   36,   -1,   -1,   -1,   40,   -1,  264,
   -1,  257,   -1,   -1,   -1,  270,   -1,   -1,  264,  257,
  123,   -1,   96,   -1,  270,   -1,  264,   -1,  258,  259,
  260,  261,  270,  263,   -1,  265,  266,  267,  268,  269,
   -1,   -1,  272,   -1,   -1,   -1,  276,  277,  278,  279,
  280,  258,  259,  260,  261,  262,  263,   -1,  265,  266,
  267,  268,  269,   96,   -1,  272,   -1,  274,   -1,  276,
  277,  278,  279,  280,   -1,   -1,   -1,  258,  259,  260,
  261,   -1,  263,   -1,  265,  266,  267,  268,  269,   36,
  123,  272,   -1,   40,   -1,  276,  277,  278,  279,  280,
  258,  259,  260,  261,   -1,  263,   -1,  265,  266,  267,
  268,  269,   36,   -1,  272,   -1,   40,   -1,  276,  277,
  278,  279,  280,  258,  259,  260,  261,   -1,  263,   -1,
  265,  266,  267,  268,  269,   -1,   36,  272,   -1,   -1,
   40,  276,  277,  278,  279,  280,   -1,   -1,   -1,   96,
   -1,   -1,   -1,  256,   -1,  258,  259,   -1,  261,  262,
   -1,   61,  265,  266,  267,  268,   -1,   -1,   -1,  272,
   -1,  274,   96,  276,  277,  278,  279,  280,   -1,   -1,
   -1,   -1,   -1,   -1,  258,  259,  260,  261,   -1,  263,
   -1,  265,  266,  267,  268,  269,   96,   -1,  272,  123,
   -1,   -1,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  258,  259,  260,  261,  262,
   -1,   -1,  265,  266,  267,  268,   -1,   -1,   -1,  272,
   -1,  274,   -1,  276,  277,  278,  279,  280,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,  260,  261,   -1,  263,   -1,  265,  266,
  267,  268,  269,   -1,   -1,  272,   -1,   -1,   -1,  276,
  277,  278,  279,  280,  258,  259,   -1,  261,  262,   -1,
   -1,  265,  266,  267,  268,   -1,   -1,   -1,  272,   -1,
  274,   -1,  276,  277,  278,  279,  280,   -1,  258,  259,
  260,  261,   -1,  263,    0,  265,  266,  267,  268,  269,
   -1,   -1,  272,   -1,   -1,   -1,  276,  277,  278,  279,
  280,    0,   18,   -1,   -1,   -1,   22,   -1,   -1,   25,
   -1,   -1,   -1,   29,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   22,   -1,   -1,   25,   -1,   -1,   -1,
   29,   -1,   -1,   -1,   -1,   -1,   52,   -1,   -1,   -1,
   -1,   57,   -1,   -1,   -1,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   52,   -1,   71,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  101,   -1,   -1,   -1,  105,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  114,  115,
  116,   -1,  101,   -1,   -1,   -1,  105,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  114,  115,  116,   -1,   -1,
   -1,  137,   -1,   -1,   -1,   -1,   -1,   -1,  144,  145,
  146,   -1,   -1,  149,   -1,   -1,  152,   -1,  137,   -1,
   -1,   -1,   -1,   -1,   -1,  144,  145,  146,   -1,   -1,
  149,   -1,   -1,  152,
};
#define YYFINAL 21
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 310
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
"FLAT","FN","FOR","IF","IN","OROR","PIPE","REDIR","REDIR_PREC","SREDIR","SUB",
"SUBSHELL","SWITCH","TWIDDLE","WHILE","WORD","HUH",0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
#line 179 "parse.y"

void initparse() {
	star = treecpy(mk(nVar, mk(nWord,"*", NULL, FALSE)), ealloc);
	nolist = treecpy(mk(nVar, mk(nWord,"ifs", NULL, FALSE)), ealloc);
}

#line 674 "parse.c"

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
#line 52 "parse.y"
	{ parsetree = yystack.l_mark[-1].node; YYACCEPT; }
break;
case 2:
#line 53 "parse.y"
	{ yyerrok; parsetree = NULL; YYABORT; }
break;
case 3:
#line 56 "parse.y"
	{ if (!heredoc(1)) YYABORT; }
break;
case 4:
#line 57 "parse.y"
	{ if (!heredoc(0)) YYABORT; }
break;
case 6:
#line 61 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nNowait,yystack.l_mark[-1].node) : yystack.l_mark[-1].node); }
break;
case 8:
#line 65 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[0].node); }
break;
case 10:
#line 69 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node == NULL ? yystack.l_mark[0].node : yystack.l_mark[0].node == NULL ? yystack.l_mark[-1].node : mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node)); }
break;
case 12:
#line 72 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; if (!heredoc(0)) YYABORT; }
break;
case 13:
#line 74 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 14:
#line 76 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 15:
#line 78 "parse.y"
	{ yyval.node = mk(nAssign,yystack.l_mark[-4].node,yystack.l_mark[0].node); }
break;
case 16:
#line 80 "parse.y"
	{ yyval.node = NULL; }
break;
case 17:
#line 81 "parse.y"
	{ yyval.node = mk(nEpilog,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 18:
#line 84 "parse.y"
	{ yyval.node = mk(nDup,yystack.l_mark[0].dup.type,yystack.l_mark[0].dup.left,yystack.l_mark[0].dup.right); }
break;
case 19:
#line 85 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 20:
#line 88 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 21:
#line 92 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 22:
#line 93 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 23:
#line 95 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[0].node, NULL); }
break;
case 24:
#line 96 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 25:
#line 97 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 27:
#line 100 "parse.y"
	{ yyval.node = mk(nElse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 28:
#line 102 "parse.y"
	{ yyval.node = NULL; }
break;
case 30:
#line 104 "parse.y"
	{ yyval.node = mk(nBrace,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 31:
#line 105 "parse.y"
	{ yyval.node = mk(nIf,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 32:
#line 106 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-5].node,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 33:
#line 107 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-3].node,star,yystack.l_mark[0].node); }
break;
case 34:
#line 108 "parse.y"
	{ yyval.node = mk(nWhile,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 35:
#line 109 "parse.y"
	{ yyval.node = mk(nSwitch,yystack.l_mark[-5].node,yystack.l_mark[-1].node); }
break;
case 36:
#line 110 "parse.y"
	{ yyval.node = mk(nMatch,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 37:
#line 111 "parse.y"
	{ yyval.node = mk(nAndalso,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 38:
#line 112 "parse.y"
	{ yyval.node = mk(nOrelse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 39:
#line 113 "parse.y"
	{ yyval.node = mk(nPipe,yystack.l_mark[-2].pipe.left,yystack.l_mark[-2].pipe.right,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 40:
#line 114 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 41:
#line 115 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 42:
#line 116 "parse.y"
	{ yyval.node = mk(nBang,yystack.l_mark[0].node); }
break;
case 43:
#line 117 "parse.y"
	{ yyval.node = mk(nSubshell,yystack.l_mark[0].node); }
break;
case 44:
#line 118 "parse.y"
	{ yyval.node = mk(nNewfn,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 45:
#line 119 "parse.y"
	{ yyval.node = mk(nRmfn,yystack.l_mark[0].node); }
break;
case 49:
#line 125 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 51:
#line 128 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 55:
#line 134 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 57:
#line 137 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].keyword, NULL, FALSE); }
break;
case 59:
#line 140 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 60:
#line 142 "parse.y"
	{ yyval.node = mk(nVar,yystack.l_mark[0].node); }
break;
case 61:
#line 143 "parse.y"
	{ yyval.node = mk(nVarsub,yystack.l_mark[-3].node,yystack.l_mark[-1].node); }
break;
case 62:
#line 144 "parse.y"
	{ yyval.node = mk(nCount,yystack.l_mark[0].node); }
break;
case 63:
#line 145 "parse.y"
	{ yyval.node = mk(nFlat, yystack.l_mark[0].node); }
break;
case 64:
#line 146 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 65:
#line 147 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 66:
#line 148 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 67:
#line 149 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 68:
#line 150 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 69:
#line 151 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 70:
#line 152 "parse.y"
	{ yyval.node = mk(nNmpipe,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node); }
break;
case 71:
#line 153 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].word.w, yystack.l_mark[0].word.m, yystack.l_mark[0].word.q); }
break;
case 72:
#line 155 "parse.y"
	{ yyval.keyword = "for"; }
break;
case 73:
#line 156 "parse.y"
	{ yyval.keyword = "in"; }
break;
case 74:
#line 157 "parse.y"
	{ yyval.keyword = "while"; }
break;
case 75:
#line 158 "parse.y"
	{ yyval.keyword = "if"; }
break;
case 76:
#line 159 "parse.y"
	{ yyval.keyword = "switch"; }
break;
case 77:
#line 160 "parse.y"
	{ yyval.keyword = "fn"; }
break;
case 78:
#line 161 "parse.y"
	{ yyval.keyword = "else"; }
break;
case 79:
#line 162 "parse.y"
	{ yyval.keyword = "case"; }
break;
case 80:
#line 163 "parse.y"
	{ yyval.keyword = "~"; }
break;
case 81:
#line 164 "parse.y"
	{ yyval.keyword = "!"; }
break;
case 82:
#line 165 "parse.y"
	{ yyval.keyword = "@"; }
break;
case 83:
#line 166 "parse.y"
	{ yyval.keyword = "="; }
break;
case 84:
#line 168 "parse.y"
	{ yyval.node = NULL; }
break;
case 85:
#line 169 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
case 86:
#line 171 "parse.y"
	{ yyval.node = NULL; }
break;
case 88:
#line 173 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
#line 1176 "parse.c"
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
