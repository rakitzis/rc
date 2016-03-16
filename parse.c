/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20141128

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
#line 28 "parse.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct Node *node;
	struct Redir redir;
	struct Pipe pipe;
	struct Dup dup;
	struct Word word;
	CONST char *keyword;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 44 "parse.tab.c"

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

#define ANDAND 257
#define BACKBACK 258
#define BANG 259
#define CASE 260
#define COUNT 261
#define DUP 262
#define ELSE 263
#define END 264
#define FLAT 265
#define FN 266
#define FOR 267
#define IF 268
#define IN 269
#define OROR 270
#define PIPE 271
#define REDIR 272
#define SREDIR 273
#define SUB 274
#define SUBSHELL 275
#define SWITCH 276
#define TWIDDLE 277
#define WHILE 278
#define WORD 279
#define HUH 280
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   22,   22,    8,    8,   13,   13,    3,    3,
    9,    9,    4,   15,    2,   11,   11,   16,   16,   16,
    5,    5,    6,    6,    6,   19,   19,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,   24,   24,   18,   18,   18,
   12,   12,   17,   17,   20,   20,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,   21,
   21,   14,   14,   14,   23,   23,
};
static const YYINT yylen[] = {                            2,
    2,    2,    1,    1,    2,    2,    1,    2,    1,    2,
    1,    2,    3,    3,    3,    0,    2,    1,    2,    2,
    3,    3,    1,    2,    2,    1,    4,    0,    1,    2,
    4,    8,    6,    4,    8,    4,    4,    4,    4,    2,
    2,    3,    3,    3,    2,    0,    1,    1,    2,    2,
    1,    3,    1,    1,    1,    3,    2,    5,    2,    2,
    2,    2,    2,    3,    3,    3,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,
    2,    0,    2,    2,    0,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,   18,    0,   80,    0,    0,    0,
    0,    0,    0,    0,    0,   68,    0,    0,   82,    0,
    0,    0,    0,    0,    0,   51,    0,    0,    0,    0,
    3,    4,    2,   78,   76,   75,   74,   69,   72,   70,
    0,   79,   73,   77,   71,   54,   53,   55,    0,   47,
    0,   59,   60,    0,    0,    0,   85,   67,    0,    0,
    0,    0,    0,   85,   63,    0,    0,    0,   11,    0,
    0,   62,   61,    0,    0,   30,    0,   85,   85,   85,
    5,    6,    8,    0,    0,    1,    0,   50,    0,    0,
   64,   65,    0,   44,    0,    0,    0,    0,    0,    0,
    0,    0,   80,   13,   12,   10,   66,   83,    0,   17,
    0,    0,    0,    0,   52,   56,   80,   85,   14,   86,
    0,    0,   31,   85,    0,    0,    0,    0,    0,   39,
    0,    0,   85,    0,   58,   85,    0,    0,    0,    0,
    0,   80,    0,    0,    0,    0,    0,    0,   24,   35,
   25,   22,   21,
};
static const YYINT yydgoto[] = {                         21,
   46,   22,   67,   23,  143,  144,   68,   69,   70,   47,
   76,   27,   28,   71,   57,   29,   48,   30,  123,   95,
   54,   33,   98,   51,
};
static const YYINT yysindex[] = {                       874,
   24, 1001,  -80, 1001,    0, 1001,    0,  -21,  -13,  900,
 1001,  -80,   -2,  -80,  -13,    0,  900, 1134,    0,  900,
    0, 1134, -185,  -30, 1134,    0,  -24,   24, 1134,  826,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -100,    0,    0,    0,    0,    0,    0,    0,  849,    0,
 1134,    0,    0,  900, 1001, 1134,    0,    0,  -62,  -62,
 1134, 1001, 1001,    0,    0, -235,  -68,  154,    0, 1134,
  426,    0,    0, -208, 1001,    0, -185,    0,    0,    0,
    0,    0,    0, 1001, 1001,    0, -208,    0,  -62, 1001,
    0,    0, -208,    0,  -62,  -38,   28,  502, -208,  -36,
  -62,  502,    0,    0,    0,    0,    0,    0,  -62,    0,
  502,  502,  502,  -62,    0,    0,    0,    0,    0,    0,
 -155, -204,    0,    0, 1001, -204,  922, -208, -208,    0,
  944,  502,    0,   -9,    0,    0, -204,  502,  967,  502,
 -204,    0,  967,  -50,  154,  967, -204,  448,    0,    0,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                       134,
    0,    0,  356,    0,    0,    0,    0,    0,    0,    0,
    0,  356,    0, 1024,    0,    0,    0,  571,    0,    0,
    0,  487,  529,   54,  134,    0,   62,    0,  487,  548,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  487,    0,    0,  712,    0,  142,    0,    0,   14,   38,
  487,    0,    0,    0,    0,  -10,    0,  -31,    0,  744,
    0,    0,    0,  749,    0,    0,  529,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  763,    0,   86,    0,
    0,    0,  779,    0,  110,    0,    0,  -34,  788,    0,
  380,  -34,    0,    0,    0,    0,    0,    0,  470,    0,
  -34,  -34,  -34,  404,    0,    0,    0,    0,    0,    0,
  529,    6,    0,    0,  724,   30,    0,  805,  813,    0,
    0,  -34,    0,    0,    0,    0,  119,  -34,  571,  -34,
  187,    0,  571,    0,  -45,  571,  396,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -35,   -8,    0,  -84, 1318,   17, -128, 1306,
    4,    0,   57,    0,   68,  -17,   89,    0,    0,  398,
  -81,   64,  353,   31,
};
#define YYTABLESIZE 1464
static const YYINT yytable[] = {                         57,
  120,   58,  118,   28,  124,   77,   28,   82,   65,    9,
  146,   72,   88,   50,  146,   26,   25,  146,   55,  125,
   97,  127,   18,   19,   28,   57,   56,   57,   81,   57,
   57,   90,   58,   32,  106,  131,   84,   62,  103,   34,
   91,   25,   61,   26,   63,   94,   26,   20,   57,   19,
   57,   19,   78,   19,   19,   90,  104,   90,  149,   77,
  148,  151,   80,    7,   26,   79,   80,   34,  119,   85,
   34,   48,   19,   20,  150,   20,    5,   20,   20,   23,
  110,   83,   64,   57,    0,   57,   75,   11,   34,  121,
   28,   86,   52,    9,   53,   49,   20,   48,    0,   48,
    0,   48,   48,   77,    0,   66,    5,  133,   73,   19,
    0,    0,   57,  139,   57,    0,   75,   11,    0,   81,
   48,   49,    0,   49,    0,   49,   49,    0,   33,    0,
   26,    0,    0,   20,    0,    0,   19,   92,   19,    0,
    0,    0,    0,   28,   49,   81,    0,   81,    0,   81,
   81,   28,    0,    0,   34,    0,   33,   48,    0,   33,
   20,    0,   20,  105,    0,    0,    0,    0,   81,    0,
    0,   28,    0,  115,    0,    0,    0,   33,  116,   28,
    0,   49,   28,    0,    0,    0,   48,    0,    0,    0,
    0,   82,   28,    0,    0,    0,   27,    0,    0,    0,
   28,    0,    0,    0,    0,   81,    0,    0,    0,    0,
   49,    0,   81,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,    0,   27,    0,   78,   27,    0,   28,
  117,    0,   81,    0,   81,   28,   28,    0,    0,   79,
   80,    0,    0,   33,    0,   27,   57,   57,   57,   57,
   57,   57,   57,   57,   57,   57,   57,   57,   57,   57,
   57,   57,   57,    0,   57,   57,   57,   57,   57,   26,
   19,   19,   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   31,   19,   19,
   19,   19,   19,   34,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   27,   20,   20,   20,   20,   20,    7,   48,   48,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   48,   48,   48,   48,    0,   48,   48,   48,   48,
   48,    0,   49,   49,   49,   49,   49,   49,   49,   49,
   49,   49,   49,   49,   49,   49,   49,   49,   49,    0,
   49,   49,   49,   49,   49,   46,   81,   81,   81,   81,
   81,    0,   81,   81,   81,   81,   81,   81,   81,   81,
   81,   81,   33,    0,   81,   81,   81,   81,   81,   80,
   28,   46,    0,   46,    0,   46,   46,   28,   28,   49,
    0,    0,    0,   28,   28,   32,    0,   59,   60,    0,
   78,   28,   28,   15,   46,   80,  102,   80,    0,   80,
   80,    0,    0,   79,   80,    0,    0,   89,    0,    0,
  111,  112,  113,   32,    0,  108,   32,    0,   80,   15,
    0,   15,    0,   15,   15,    0,    0,    0,    0,    0,
   27,   46,   96,    0,   32,    0,    0,  152,    0,  100,
  101,   17,   15,    0,    0,   19,  107,    0,  109,    0,
  132,    0,   59,    0,    0,   80,  134,    0,   46,   84,
   46,  114,    0,   17,    0,  138,    0,   19,  140,    0,
    0,    0,    0,    0,    0,    0,   28,    0,    0,   15,
    0,    0,    0,    0,   80,   84,  153,    0,    0,   84,
   84,  120,    0,    0,    0,    0,    0,    0,    0,    0,
   32,   20,    0,    0,   28,    0,   15,   28,   15,    0,
    0,    0,    0,    0,    0,    0,    0,   17,   16,    0,
    0,   19,    0,   20,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,    0,
    0,    0,    0,    0,    0,   84,   16,    0,    0,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    0,    0,    0,    0,   29,    0,   16,   29,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,    0,   29,    0,   28,    0,
    0,   28,   46,   46,   46,    0,   46,   46,    0,   46,
   46,   46,   46,   46,   18,   46,   46,   46,   46,   28,
   46,   46,   46,   46,   46,    0,   80,   80,   80,   80,
   80,    0,   80,   80,   80,   80,   80,   80,   80,   80,
   80,   80,    0,   16,   80,   80,   80,   80,   80,   32,
   15,   15,   15,    0,   15,   15,    0,   15,   15,   15,
   15,   15,   29,   15,   15,   15,   15,    0,   15,   15,
   15,   15,   15,    2,   34,   35,    4,    0,   36,    0,
    6,   37,   38,   39,   40,   28,    0,   41,    0,    0,
   42,   43,   44,   45,   16,    2,   34,   35,    4,    0,
   36,    0,    6,   37,   38,   39,   40,    0,    0,   41,
    0,   45,   42,   43,   44,   45,   16,   84,   84,   84,
   84,    0,   84,   36,   84,   84,   84,   84,   84,    0,
    0,   84,    0,   28,   84,   84,   84,   84,   84,   45,
   28,    0,   45,   28,    0,    0,   28,   28,   41,    2,
    3,   36,    4,    5,   36,    0,    6,    7,    8,    9,
   45,    0,   40,   10,   11,    0,   12,   13,   14,   15,
   16,   28,   36,    0,   28,   16,   41,    0,   42,   41,
    0,    0,   16,    0,    0,    0,    0,   43,   16,   16,
   40,    0,   28,   40,   29,    0,    0,   41,    0,    0,
    0,   29,    0,    0,   37,    0,   42,   29,   29,   42,
    0,   40,   38,    0,    0,   43,    0,   28,   43,    0,
    0,    0,    0,    0,    0,    0,   45,   42,    0,    0,
   28,   28,   37,    0,    0,   37,   43,    0,   36,    0,
   38,    0,    0,   38,    0,    0,    0,    0,    0,    0,
    0,   17,    0,   37,    0,   19,    0,    0,   28,    0,
    0,   38,    0,   41,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   17,    0,    0,   40,   19,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   42,    0,    0,    0,    0,    0,   17,
    0,    0,   43,   19,    0,    0,    0,    0,    0,    0,
    0,   20,    0,    0,    0,    0,    0,    0,    0,   37,
    0,    0,    0,    0,    0,   17,    0,   38,    0,   19,
    0,    0,   90,    0,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   17,    0,    0,
    0,   19,  135,    0,    0,    0,    0,    0,   45,   20,
    0,   18,    0,    0,    0,   45,    0,    0,    0,   17,
   36,   45,   45,   19,  136,    0,    0,   36,    0,    0,
    0,    0,    0,   36,   36,   20,   18,    0,    0,    0,
   28,    0,   17,    0,    0,   41,   19,    0,    0,    0,
    0,    0,   41,   28,   28,    0,    0,   20,   41,   40,
    0,    0,   18,    0,    0,    0,   40,    0,    0,    0,
    0,    0,   40,    0,    0,   42,   17,    0,    0,   20,
   19,    0,   42,    0,   43,    0,    0,    0,   42,    0,
    0,   43,    0,    0,    0,    0,    0,   43,    0,   46,
    0,   37,   20,   46,    0,    0,    0,    0,   37,   38,
    0,    0,    0,    0,   37,    0,   38,    0,    0,    0,
    0,    0,   38,    2,   34,   35,    4,    5,   36,   18,
    6,   37,   38,   39,   40,    0,   20,   10,   11,    0,
   42,   43,   44,   45,   16,    0,    2,   34,   35,    4,
    0,   36,    0,    6,   37,   38,   39,   40,    0,   46,
   41,    0,    0,   42,   43,   44,   45,   16,    0,    1,
    0,    2,    3,    0,    4,    5,    0,    0,    6,    7,
    8,    9,    0,    0,    0,   10,   11,    0,   12,   13,
   14,   15,   16,    0,    0,    0,    0,    2,   34,   35,
    4,    0,   36,    0,    6,   37,   38,   39,   40,   17,
    0,   41,    0,   19,   42,   43,   44,   45,   16,    2,
   34,   35,    4,    0,   36,    0,    6,   37,   38,   39,
   40,    0,    0,   41,    0,    0,   42,   43,   44,   45,
   16,    2,   34,   35,    4,    0,   36,    0,    6,   37,
   38,   39,   40,    0,    0,   41,    0,    0,   42,   43,
   44,   45,   16,    0,    2,    3,  142,    4,    5,   20,
    0,    6,    7,    8,    9,    0,    0,    0,   10,   11,
    0,   12,   13,   14,   15,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    2,   34,
   35,    4,    0,   36,    0,    6,   37,   38,   39,   40,
    0,    0,   41,    0,    0,   42,   43,   44,   45,   16,
    0,   46,   46,   46,   46,    0,   46,    0,   46,   46,
   46,   46,   46,    0,    0,   46,    0,    0,   46,   46,
   46,   46,   46,    0,    0,   26,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   24,    0,    0,
    0,    0,    0,   26,    0,    0,    0,   26,    0,    0,
   26,    0,    0,    0,   26,    0,    0,    0,    0,   74,
    0,    0,   24,    0,    0,    0,   87,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,   26,    0,    0,    0,    0,   26,    0,   93,    0,
    0,    0,    0,    0,    0,   26,    0,    0,   99,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    3,    0,    4,    5,    0,    0,    6,    7,
    8,    9,    0,   26,    0,   10,   11,   26,   12,   13,
   14,   15,   16,    0,    0,  122,   26,   26,   26,  126,
    0,    0,    0,    0,    0,    0,    0,    0,  128,  129,
  130,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,   26,   26,   26,    0,    0,   26,  137,
    0,   26,    0,    0,    0,  141,  145,  147,    0,    0,
  145,    0,    0,  145,
};
static const YYINT yycheck[] = {                         10,
   10,   10,   41,   38,   41,   23,   41,   38,   17,   41,
  139,   20,   30,   94,  143,   10,    0,  146,   40,  101,
   56,  103,  123,   10,   59,   36,   40,   38,   59,   40,
   41,   94,   41,   10,   70,  117,   61,   40,  274,   10,
   49,   25,   12,   38,   14,   54,   41,   10,   59,   36,
   61,   38,  257,   40,   41,   94,  125,   94,  143,   77,
  142,  146,  271,   10,   59,  270,  271,   38,   41,   94,
   41,   10,   59,   36,  125,   38,  262,   40,   41,  125,
   77,   25,   15,   94,   -1,   96,  272,  273,   59,   98,
  125,   28,    4,  125,    6,   10,   59,   36,   -1,   38,
   -1,   40,   41,  121,   -1,   17,  262,  263,   20,   96,
   -1,   -1,  123,  123,  125,   -1,  272,  273,   -1,   10,
   59,   36,   -1,   38,   -1,   40,   41,   -1,   10,   -1,
  125,   -1,   -1,   96,   -1,   -1,  123,   49,  125,   -1,
   -1,   -1,   -1,   10,   59,   36,   -1,   38,   -1,   40,
   41,   10,   -1,   -1,  125,   -1,   38,   96,   -1,   41,
  123,   -1,  125,   10,   -1,   -1,   -1,   -1,   59,   -1,
   -1,   38,   -1,   85,   -1,   -1,   -1,   59,   90,   38,
   -1,   96,   41,   -1,   -1,   -1,  125,   -1,   -1,   -1,
   -1,   38,   59,   -1,   -1,   -1,   10,   -1,   -1,   -1,
   59,   -1,   -1,   -1,   -1,   96,   -1,   -1,   -1,   -1,
  125,   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,   -1,   38,   -1,  257,   41,   -1,  264,
  269,   -1,  123,   -1,  125,  270,  271,   -1,   -1,  270,
  271,   -1,   -1,  125,   -1,   59,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,   -1,  275,  276,  277,  278,  279,  264,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  264,  275,  276,
  277,  278,  279,  264,  257,  258,  259,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,  125,  275,  276,  277,  278,  279,  264,  257,  258,
  259,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,   -1,  275,  276,  277,  278,
  279,   -1,  257,  258,  259,  260,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,   -1,
  275,  276,  277,  278,  279,   10,  257,  258,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  264,   -1,  275,  276,  277,  278,  279,   10,
  257,   36,   -1,   38,   -1,   40,   41,  264,  257,    2,
   -1,   -1,   -1,  270,  271,   10,   -1,   10,   11,   -1,
  257,  270,  271,   10,   59,   36,   64,   38,   -1,   40,
   41,   -1,   -1,  270,  271,   -1,   -1,   30,   -1,   -1,
   78,   79,   80,   38,   -1,   10,   41,   -1,   59,   36,
   -1,   38,   -1,   40,   41,   -1,   -1,   -1,   -1,   -1,
  264,   96,   55,   -1,   59,   -1,   -1,   10,   -1,   62,
   63,   36,   59,   -1,   -1,   40,   41,   -1,   71,   -1,
  118,   -1,   75,   -1,   -1,   96,  124,   -1,  123,   10,
  125,   84,   -1,   36,   -1,  133,   -1,   40,  136,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,   96,
   -1,   -1,   -1,   -1,  125,   36,   59,   -1,   -1,   40,
   41,   10,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  125,   96,   -1,   -1,   38,   -1,  123,   41,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,   10,   -1,
   -1,   40,   -1,   96,   -1,   59,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   10,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   96,   38,   -1,   -1,   41,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   10,   -1,   -1,   -1,   -1,   38,   -1,   59,   41,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   96,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,   38,   -1,
   -1,  125,  257,  258,  259,   -1,  261,  262,   -1,  264,
  265,  266,  267,  268,  123,  270,  271,  272,  273,   59,
  275,  276,  277,  278,  279,   -1,  257,  258,  259,  260,
  261,   -1,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,   -1,  125,  275,  276,  277,  278,  279,  264,
  257,  258,  259,   -1,  261,  262,   -1,  264,  265,  266,
  267,  268,  125,  270,  271,  272,  273,   -1,  275,  276,
  277,  278,  279,  258,  259,  260,  261,   -1,  263,   -1,
  265,  266,  267,  268,  269,  125,   -1,  272,   -1,   -1,
  275,  276,  277,  278,  279,  258,  259,  260,  261,   -1,
  263,   -1,  265,  266,  267,  268,  269,   -1,   -1,  272,
   -1,   10,  275,  276,  277,  278,  279,  258,  259,  260,
  261,   -1,  263,   10,  265,  266,  267,  268,  269,   -1,
   -1,  272,   -1,  257,  275,  276,  277,  278,  279,   38,
  264,   -1,   41,   10,   -1,   -1,  270,  271,   10,  258,
  259,   38,  261,  262,   41,   -1,  265,  266,  267,  268,
   59,   -1,   10,  272,  273,   -1,  275,  276,  277,  278,
  279,   38,   59,   -1,   41,  257,   38,   -1,   10,   41,
   -1,   -1,  264,   -1,   -1,   -1,   -1,   10,  270,  271,
   38,   -1,   59,   41,  257,   -1,   -1,   59,   -1,   -1,
   -1,  264,   -1,   -1,   10,   -1,   38,  270,  271,   41,
   -1,   59,   10,   -1,   -1,   38,   -1,  257,   41,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  125,   59,   -1,   -1,
  270,  271,   38,   -1,   -1,   41,   59,   -1,  125,   -1,
   38,   -1,   -1,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   36,   -1,   59,   -1,   40,   -1,   -1,  125,   -1,
   -1,   59,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   36,   -1,   -1,  125,   40,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,   36,
   -1,   -1,  125,   40,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   96,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   36,   -1,  125,   -1,   40,
   -1,   -1,   94,   -1,   96,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,   -1,   -1,
   -1,   40,   41,   -1,   -1,   -1,   -1,   -1,  257,   96,
   -1,  123,   -1,   -1,   -1,  264,   -1,   -1,   -1,   36,
  257,  270,  271,   40,   41,   -1,   -1,  264,   -1,   -1,
   -1,   -1,   -1,  270,  271,   96,  123,   -1,   -1,   -1,
  257,   -1,   36,   -1,   -1,  257,   40,   -1,   -1,   -1,
   -1,   -1,  264,  270,  271,   -1,   -1,   96,  270,  257,
   -1,   -1,  123,   -1,   -1,   -1,  264,   -1,   -1,   -1,
   -1,   -1,  270,   -1,   -1,  257,   36,   -1,   -1,   96,
   40,   -1,  264,   -1,  257,   -1,   -1,   -1,  270,   -1,
   -1,  264,   -1,   -1,   -1,   -1,   -1,  270,   -1,   36,
   -1,  257,   96,   40,   -1,   -1,   -1,   -1,  264,  257,
   -1,   -1,   -1,   -1,  270,   -1,  264,   -1,   -1,   -1,
   -1,   -1,  270,  258,  259,  260,  261,  262,  263,  123,
  265,  266,  267,  268,  269,   -1,   96,  272,  273,   -1,
  275,  276,  277,  278,  279,   -1,  258,  259,  260,  261,
   -1,  263,   -1,  265,  266,  267,  268,  269,   -1,   96,
  272,   -1,   -1,  275,  276,  277,  278,  279,   -1,  256,
   -1,  258,  259,   -1,  261,  262,   -1,   -1,  265,  266,
  267,  268,   -1,   -1,   -1,  272,  273,   -1,  275,  276,
  277,  278,  279,   -1,   -1,   -1,   -1,  258,  259,  260,
  261,   -1,  263,   -1,  265,  266,  267,  268,  269,   36,
   -1,  272,   -1,   40,  275,  276,  277,  278,  279,  258,
  259,  260,  261,   -1,  263,   -1,  265,  266,  267,  268,
  269,   -1,   -1,  272,   -1,   -1,  275,  276,  277,  278,
  279,  258,  259,  260,  261,   -1,  263,   -1,  265,  266,
  267,  268,  269,   -1,   -1,  272,   -1,   -1,  275,  276,
  277,  278,  279,   -1,  258,  259,  260,  261,  262,   96,
   -1,  265,  266,  267,  268,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,  279,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  258,  259,
  260,  261,   -1,  263,   -1,  265,  266,  267,  268,  269,
   -1,   -1,  272,   -1,   -1,  275,  276,  277,  278,  279,
   -1,  258,  259,  260,  261,   -1,  263,   -1,  265,  266,
  267,  268,  269,   -1,   -1,  272,   -1,   -1,  275,  276,
  277,  278,  279,   -1,   -1,    0,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,   -1,
   -1,   -1,   -1,   18,   -1,   -1,   -1,   22,   -1,   -1,
   25,   -1,   -1,   -1,   29,   -1,   -1,   -1,   -1,   22,
   -1,   -1,   25,   -1,   -1,   -1,   29,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   51,   -1,   -1,   -1,
   -1,   56,   -1,   -1,   -1,   -1,   61,   -1,   51,   -1,
   -1,   -1,   -1,   -1,   -1,   70,   -1,   -1,   61,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,   -1,  261,  262,   -1,   -1,  265,  266,
  267,  268,   -1,   98,   -1,  272,  273,  102,  275,  276,
  277,  278,  279,   -1,   -1,   98,  111,  112,  113,  102,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  111,  112,
  113,   -1,   -1,   -1,   -1,   -1,   -1,  132,   -1,   -1,
   -1,   -1,   -1,  138,  139,  140,   -1,   -1,  143,  132,
   -1,  146,   -1,   -1,   -1,  138,  139,  140,   -1,   -1,
  143,   -1,   -1,  146,
};
#define YYFINAL 21
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 307
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
0,0,0,0,0,0,"illegal-symbol",
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
"assign : first '=' word",
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
"simple : simple word",
"simple : simple redir",
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
#line 170 "parse.y"

void initparse() {
	star = treecpy(mk(nVar, mk(nWord,"*", NULL, FALSE)), ealloc);
	nolist = treecpy(mk(nVar, mk(nWord,"ifs", NULL, FALSE)), ealloc);
}

#line 642 "parse.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
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

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
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
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 49 "parse.y"
	{ parsetree = yystack.l_mark[-1].node; YYACCEPT; }
break;
case 2:
#line 50 "parse.y"
	{ yyerrok; parsetree = NULL; YYABORT; }
break;
case 3:
#line 53 "parse.y"
	{ if (!heredoc(1)) YYABORT; }
break;
case 4:
#line 54 "parse.y"
	{ if (!heredoc(0)) YYABORT; }
break;
case 6:
#line 58 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nNowait,yystack.l_mark[-1].node) : yystack.l_mark[-1].node); }
break;
case 8:
#line 62 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[0].node); }
break;
case 10:
#line 66 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node == NULL ? yystack.l_mark[0].node : yystack.l_mark[0].node == NULL ? yystack.l_mark[-1].node : mk(nBody,yystack.l_mark[-1].node,yystack.l_mark[0].node)); }
break;
case 12:
#line 69 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; if (!heredoc(0)) YYABORT; }
break;
case 13:
#line 71 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 14:
#line 73 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 15:
#line 75 "parse.y"
	{ yyval.node = mk(nAssign,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 16:
#line 77 "parse.y"
	{ yyval.node = NULL; }
break;
case 17:
#line 78 "parse.y"
	{ yyval.node = mk(nEpilog,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 18:
#line 81 "parse.y"
	{ yyval.node = mk(nDup,yystack.l_mark[0].dup.type,yystack.l_mark[0].dup.left,yystack.l_mark[0].dup.right); }
break;
case 19:
#line 82 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 20:
#line 85 "parse.y"
	{ yyval.node = mk(nRedir,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node);
				  if (yystack.l_mark[-1].redir.type == rHeredoc && !qdoc(yystack.l_mark[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 21:
#line 89 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 22:
#line 90 "parse.y"
	{ yyval.node = mk(nCase, yystack.l_mark[-1].node); }
break;
case 23:
#line 92 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[0].node, NULL); }
break;
case 24:
#line 93 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 25:
#line 94 "parse.y"
	{ yyval.node = mk(nCbody, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 27:
#line 97 "parse.y"
	{ yyval.node = mk(nElse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 28:
#line 99 "parse.y"
	{ yyval.node = NULL; }
break;
case 30:
#line 101 "parse.y"
	{ yyval.node = mk(nBrace,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 31:
#line 102 "parse.y"
	{ yyval.node = mk(nIf,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 32:
#line 103 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-5].node,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 33:
#line 104 "parse.y"
	{ yyval.node = mk(nForin,yystack.l_mark[-3].node,star,yystack.l_mark[0].node); }
break;
case 34:
#line 105 "parse.y"
	{ yyval.node = mk(nWhile,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 35:
#line 106 "parse.y"
	{ yyval.node = mk(nSwitch,yystack.l_mark[-5].node,yystack.l_mark[-1].node); }
break;
case 36:
#line 107 "parse.y"
	{ yyval.node = mk(nMatch,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 37:
#line 108 "parse.y"
	{ yyval.node = mk(nAndalso,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 38:
#line 109 "parse.y"
	{ yyval.node = mk(nOrelse,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 39:
#line 110 "parse.y"
	{ yyval.node = mk(nPipe,yystack.l_mark[-2].pipe.left,yystack.l_mark[-2].pipe.right,yystack.l_mark[-3].node,yystack.l_mark[0].node); }
break;
case 40:
#line 111 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 41:
#line 112 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nPre,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 42:
#line 113 "parse.y"
	{ yyval.node = mk(nBang,yystack.l_mark[0].node); }
break;
case 43:
#line 114 "parse.y"
	{ yyval.node = mk(nSubshell,yystack.l_mark[0].node); }
break;
case 44:
#line 115 "parse.y"
	{ yyval.node = mk(nNewfn,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 45:
#line 116 "parse.y"
	{ yyval.node = mk(nRmfn,yystack.l_mark[0].node); }
break;
case 49:
#line 122 "parse.y"
	{ yyval.node = (yystack.l_mark[0].node != NULL ? mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node); }
break;
case 50:
#line 123 "parse.y"
	{ yyval.node = mk(nArgs,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 52:
#line 126 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 54:
#line 129 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].keyword, NULL, FALSE); }
break;
case 56:
#line 132 "parse.y"
	{ yyval.node = mk(nConcat,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 57:
#line 134 "parse.y"
	{ yyval.node = mk(nVar,yystack.l_mark[0].node); }
break;
case 58:
#line 135 "parse.y"
	{ yyval.node = mk(nVarsub,yystack.l_mark[-3].node,yystack.l_mark[-1].node); }
break;
case 59:
#line 136 "parse.y"
	{ yyval.node = mk(nCount,yystack.l_mark[0].node); }
break;
case 60:
#line 137 "parse.y"
	{ yyval.node = mk(nFlat, yystack.l_mark[0].node); }
break;
case 61:
#line 138 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 62:
#line 139 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 63:
#line 140 "parse.y"
	{ yyval.node = mk(nBackq,nolist,yystack.l_mark[0].node); }
break;
case 64:
#line 141 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 65:
#line 142 "parse.y"
	{ yyval.node = mk(nBackq,yystack.l_mark[-1].node,yystack.l_mark[0].node); }
break;
case 66:
#line 143 "parse.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 67:
#line 144 "parse.y"
	{ yyval.node = mk(nNmpipe,yystack.l_mark[-1].redir.type,yystack.l_mark[-1].redir.fd,yystack.l_mark[0].node); }
break;
case 68:
#line 145 "parse.y"
	{ yyval.node = mk(nWord, yystack.l_mark[0].word.w, yystack.l_mark[0].word.m, yystack.l_mark[0].word.q); }
break;
case 69:
#line 147 "parse.y"
	{ yyval.keyword = "for"; }
break;
case 70:
#line 148 "parse.y"
	{ yyval.keyword = "in"; }
break;
case 71:
#line 149 "parse.y"
	{ yyval.keyword = "while"; }
break;
case 72:
#line 150 "parse.y"
	{ yyval.keyword = "if"; }
break;
case 73:
#line 151 "parse.y"
	{ yyval.keyword = "switch"; }
break;
case 74:
#line 152 "parse.y"
	{ yyval.keyword = "fn"; }
break;
case 75:
#line 153 "parse.y"
	{ yyval.keyword = "else"; }
break;
case 76:
#line 154 "parse.y"
	{ yyval.keyword = "case"; }
break;
case 77:
#line 155 "parse.y"
	{ yyval.keyword = "~"; }
break;
case 78:
#line 156 "parse.y"
	{ yyval.keyword = "!"; }
break;
case 79:
#line 157 "parse.y"
	{ yyval.keyword = "@"; }
break;
case 80:
#line 159 "parse.y"
	{ yyval.node = NULL; }
break;
case 81:
#line 160 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
case 82:
#line 162 "parse.y"
	{ yyval.node = NULL; }
break;
case 84:
#line 164 "parse.y"
	{ yyval.node = (yystack.l_mark[-1].node != NULL ? (yystack.l_mark[0].node != NULL ? mk(nLappend,yystack.l_mark[-1].node,yystack.l_mark[0].node) : yystack.l_mark[-1].node) : yystack.l_mark[0].node); }
break;
#line 1132 "parse.tab.c"
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
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
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
