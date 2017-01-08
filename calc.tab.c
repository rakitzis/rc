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

#ifndef yyparse
#define yyparse    calcparse
#endif /* yyparse */

#ifndef yylex
#define yylex      calclex
#endif /* yylex */

#ifndef yyerror
#define yyerror    calcerror
#endif /* yyerror */

#ifndef yychar
#define yychar     calcchar
#endif /* yychar */

#ifndef yyval
#define yyval      calcval
#endif /* yyval */

#ifndef yylval
#define yylval     calclval
#endif /* yylval */

#ifndef yydebug
#define yydebug    calcdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    calcnerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  calcerrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      calclhs
#endif /* yylhs */

#ifndef yylen
#define yylen      calclen
#endif /* yylen */

#ifndef yydefred
#define yydefred   calcdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    calcdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   calcsindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   calcrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   calcgindex
#endif /* yygindex */

#ifndef yytable
#define yytable    calctable
#endif /* yytable */

#ifndef yycheck
#define yycheck    calccheck
#endif /* yycheck */

#ifndef yyname
#define yyname     calcname
#endif /* yyname */

#ifndef yyrule
#define yyrule     calcrule
#endif /* yyrule */
#define YYPREFIX "calc"

#define YYPURE 1

#line 9 "calc.y"
#include <assert.h>

extern int printf(const char *, ...);

#include "calc.h"




/* The name of the lexer argument for CalcParser() in the body of the macro calcparse():
 *      CalcParser(lexer, lexData)
 *                 ^^^^^
 * must be equal to the function name in the body of the macro calclex():
 *      lexer(lexData, &calcval)
 *      ^^^^^
 */
#define calcparse(a)  CalcParser(CalcLexerType lexer, CalcLexData *lexData)
#define calcparse_r(a)  CalcParser(CalcLexerType lexer, CalcLexData *lexData)
#define calclex(a)  lexer(lexData, &calclval)
#define calcerror(s) CalcError(s, lexData);


#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 34 "calc.y"
typedef union YYSTYPE {
    CalcValue m_Val;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 135 "calc.tab.c"

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
# ifdef YYLEX_PARAM_TYPE
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, YYLEX_PARAM_TYPE YYLEX_PARAM)
# else
#  define YYLEX_DECL() yylex(YYSTYPE *yylval, void * YYLEX_PARAM)
# endif
# define YYLEX yylex(&yylval, YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(YYSTYPE *yylval)
# define YYLEX yylex(&yylval)
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
typedef enum calctoken {
    CALC_OROR = 257,
    CALC_ANDAND = 258,
    CALC_EQEQ = 259,
    CALC_NEQ = 260,
    CALC_LEQ = 261,
    CALC_GEQ = 262,
    CALC_LSHIFT = 263,
    CALC_RSHIFT = 264,
    CALC_UNARY_PLUSMINUS = 265,
    CALC_NUMBER = 266,
    CALC_VAR = 267,
    CALC_END_TOKEN = 268,
    CALC_BAD_TOKEN = 269,
} calctoken;
#endif /* !YYTOKEN_IS_DECLARED */
#define YYERRCODE 256
typedef short YYINT;
static const YYINT calclhs[] = {                         -1,
    0,    0,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT calclen[] = {                          2,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    2,    2,    2,    3,    3,    1,
};
static const YYINT calcdefred[] = {                       0,
    0,    0,    0,    0,   28,    0,    0,    0,    0,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT calcdgoto[] = {                        8,
    9,   10,
};
static const YYINT calcsindex[] = {                     -13,
  197,  197,  197,  197,    0,  -61,  197,    0,  464,    0,
  -62,  -62,  -62,  -62,  197,  453,  197,  197,  197,  197,
  197,  197,  197,  197,  197,  197,  197,  197,  197,  197,
  197,  197,  197,  197,  197,  464,    0,  495,  538,  566,
  578,  506,  592,  592,  -28,  -28,  -28,  -28,  297,  297,
  -31,  -31,  -62,  -62,  -62,  -62,
};
static const YYINT calcrindex[] = {                       0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,
    1,   12,   28,   40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    0,   10,   96,   79,
   23,  115,   92,  107,  410,  420,  426,  437,  172,  333,
  144,  183,   56,   67,  128,  155,
};
static const YYINT calcgindex[] = {                       0,
  788,    0,
};
#define YYTABLESIZE 856
static const YYINT calctable[] = {                       15,
   25,   35,    1,    3,    0,   34,    0,    0,   34,    4,
   32,   24,    0,   32,   30,   33,   31,    0,   33,    3,
    0,    0,    7,    0,    0,    0,    7,   22,    0,    1,
    0,    2,   35,    0,    0,   35,    0,   25,   25,   23,
    0,   25,   25,   25,    0,   25,    0,   25,   24,   24,
    4,    0,   24,   24,   24,   19,   24,    0,   24,    0,
   25,    0,   25,    7,   22,   22,   20,    0,   22,   22,
   22,   24,   22,   24,   22,    0,   23,   23,    6,    0,
   23,   23,   23,    0,   23,    0,   23,   22,    0,   22,
    0,    9,   19,   19,   25,    5,   19,   19,   19,   23,
   19,   23,   19,   20,   20,   24,   10,   20,   20,   20,
    0,   20,    4,   20,    8,   19,    7,   19,    0,    6,
    0,   22,    0,    0,   25,    0,   20,   21,   20,    9,
    0,    0,    9,   23,    0,   24,    5,    0,    0,    0,
    0,    0,    0,   17,   10,    0,    7,   10,    0,   19,
    0,   22,    8,    0,   26,    8,    0,    0,    0,    0,
   20,    0,    0,   23,   21,   21,    0,    0,   21,   21,
   21,   15,   21,    0,   21,    0,    0,    0,    0,   19,
    0,   17,   18,    0,   17,    9,   17,   21,   17,   21,
   20,   26,   26,    0,    0,   26,   26,   26,    0,   26,
   10,   26,    6,   17,    0,   17,    0,    0,    8,   15,
    0,    0,   15,    0,   26,    9,   26,    0,    0,    0,
   18,   21,    0,   18,    0,   18,    0,   18,    0,    3,
   10,   15,    0,   15,   28,   29,    7,   17,    8,    1,
    0,    2,   18,    0,   18,    0,    0,    0,   26,    0,
    0,   21,    5,    6,    0,    0,    0,   25,   25,   25,
   25,   25,   25,   25,   25,   15,    4,   17,   24,   24,
   24,   24,   24,   24,   24,   24,   18,    0,   26,    7,
    7,    0,    0,    0,   22,   22,   22,   22,   22,   22,
   22,   22,    0,    0,    0,   15,   23,   23,   23,   23,
   23,   23,   23,   23,    0,    0,   18,    0,    0,    0,
    0,    0,   19,   19,   19,   19,   19,   19,   19,   19,
    0,    0,    4,   20,   20,   20,   20,   20,   20,   20,
   20,    0,   16,   34,    0,    6,    6,    0,   32,   30,
    0,   31,    0,   33,    0,    0,    0,    0,    9,    9,
    9,    9,    5,    5,    0,    0,    0,    0,    0,    0,
   35,    0,    0,   10,   10,   10,   10,    0,    0,    0,
   16,    8,    8,   16,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,   21,   21,   21,   21,   21,
   21,   21,   16,    0,   16,    0,    0,    0,    0,    0,
   17,   17,   17,   17,   17,   17,   17,   17,    0,   12,
    0,   26,   26,   26,   26,   26,   26,   26,   26,   11,
    0,    0,    0,    0,    0,   13,   16,    0,   15,   15,
   15,   15,   15,   15,   15,   15,   14,    0,    0,   18,
   18,   18,   18,   18,   18,   18,   18,   12,    0,    0,
   12,    0,    0,    0,    0,    0,   16,   11,    0,    0,
   11,    0,    5,   13,    0,    0,   13,    0,    0,   12,
    0,   12,    0,    0,   14,    0,    0,   14,    0,   11,
    0,   11,    0,    0,    0,   13,    0,   13,    0,   34,
   21,    0,    0,   37,   32,   30,   14,   31,   14,   33,
   34,   21,    0,   12,    0,   32,   30,    0,   31,    0,
   33,    0,   24,   11,   25,    0,   35,    0,    0,   13,
    0,    0,    0,   24,    0,   25,    0,   35,    0,    0,
   14,   34,   21,   12,    0,    0,   32,   30,    0,   31,
    0,   33,   34,   11,    0,    0,   20,   32,   30,   13,
   31,    0,   33,    0,   24,    0,   25,   20,   35,    0,
   14,    0,    0,    0,    0,   24,    0,   25,    0,   35,
    0,    0,    0,    0,   34,   21,   19,    0,    0,   32,
   30,    0,   31,    0,   33,    0,    0,   19,   20,   16,
   16,   16,   16,   16,   16,   16,   16,   24,    0,   25,
    0,   35,   34,   21,    0,    0,    0,   32,   30,    0,
   31,    0,   33,    0,   34,   21,    0,    0,   19,   32,
   30,    0,   31,    0,   33,   24,    0,   25,   34,   35,
    0,   20,    0,   32,   30,    0,   31,   24,   33,   25,
    0,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   24,    0,   25,    0,   35,    0,    0,    0,   20,
    0,   19,    0,    0,    0,    0,   12,   12,   12,   12,
   12,   12,    0,    0,    0,    0,   11,   11,   11,   11,
   11,   11,   13,   13,   13,   13,   13,   13,    0,    0,
    0,    0,    0,   14,   14,   14,   14,   14,   14,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   18,   22,   23,   26,   27,   28,   29,    0,    0,    0,
   17,   18,   22,   23,   26,   27,   28,   29,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,   22,   23,   26,   27,   28,   29,    0,
    0,    0,    0,    0,   22,   23,   26,   27,   28,   29,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   11,   12,
   13,   14,    0,    0,   16,    0,   22,   23,   26,   27,
   28,   29,   36,    0,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,
   54,   55,   56,    0,   22,   23,   26,   27,   28,   29,
    0,    0,    0,    0,    0,    0,   22,   23,   26,   27,
   28,   29,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   26,   27,   28,   29,
};
static const YYINT calccheck[] = {                       61,
    0,   64,    0,    0,   -1,   37,   -1,   -1,   37,    0,
   42,    0,   -1,   42,   43,   47,   45,   -1,   47,   33,
   -1,   -1,    0,   -1,   -1,   -1,   40,    0,   -1,   43,
   -1,   45,   64,   -1,   -1,   64,   -1,   37,   38,    0,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   37,   38,
   41,   -1,   41,   42,   43,    0,   45,   -1,   47,   -1,
   60,   -1,   62,   41,   37,   38,    0,   -1,   41,   42,
   43,   60,   45,   62,   47,   -1,   37,   38,    0,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   60,   -1,   62,
   -1,    0,   37,   38,   94,    0,   41,   42,   43,   60,
   45,   62,   47,   37,   38,   94,    0,   41,   42,   43,
   -1,   45,  126,   47,    0,   60,   94,   62,   -1,   41,
   -1,   94,   -1,   -1,  124,   -1,   60,    0,   62,   38,
   -1,   -1,   41,   94,   -1,  124,   41,   -1,   -1,   -1,
   -1,   -1,   -1,    0,   38,   -1,  124,   41,   -1,   94,
   -1,  124,   38,   -1,    0,   41,   -1,   -1,   -1,   -1,
   94,   -1,   -1,  124,   37,   38,   -1,   -1,   41,   42,
   43,    0,   45,   -1,   47,   -1,   -1,   -1,   -1,  124,
   -1,   38,    0,   -1,   41,   94,   43,   60,   45,   62,
  124,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   94,   47,  124,   60,   -1,   62,   -1,   -1,   94,   38,
   -1,   -1,   41,   -1,   60,  124,   62,   -1,   -1,   -1,
   38,   94,   -1,   41,   -1,   43,   -1,   45,   -1,   33,
  124,   60,   -1,   62,  263,  264,   40,   94,  124,   43,
   -1,   45,   60,   -1,   62,   -1,   -1,   -1,   94,   -1,
   -1,  124,  266,  267,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,   94,  257,  124,  257,  258,
  259,  260,  261,  262,  263,  264,   94,   -1,  124,  257,
  258,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,  124,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,  263,  264,
   -1,   -1,  126,  257,  258,  259,  260,  261,  262,  263,
  264,   -1,    0,   37,   -1,  257,  258,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,
   64,   -1,   -1,  257,  258,  259,  260,   -1,   -1,   -1,
   38,  257,  258,   41,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,  261,  262,  263,  264,   -1,    0,
   -1,  257,  258,  259,  260,  261,  262,  263,  264,    0,
   -1,   -1,   -1,   -1,   -1,    0,   94,   -1,  257,  258,
  259,  260,  261,  262,  263,  264,    0,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,   38,   -1,   -1,
   41,   -1,   -1,   -1,   -1,   -1,  124,   38,   -1,   -1,
   41,   -1,  266,   38,   -1,   -1,   41,   -1,   -1,   60,
   -1,   62,   -1,   -1,   38,   -1,   -1,   41,   -1,   60,
   -1,   62,   -1,   -1,   -1,   60,   -1,   62,   -1,   37,
   38,   -1,   -1,   41,   42,   43,   60,   45,   62,   47,
   37,   38,   -1,   94,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   60,   94,   62,   -1,   64,   -1,   -1,   94,
   -1,   -1,   -1,   60,   -1,   62,   -1,   64,   -1,   -1,
   94,   37,   38,  124,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   37,  124,   -1,   -1,   94,   42,   43,  124,
   45,   -1,   47,   -1,   60,   -1,   62,   94,   64,   -1,
  124,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,   64,
   -1,   -1,   -1,   -1,   37,   38,  124,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,  124,   94,  257,
  258,  259,  260,  261,  262,  263,  264,   60,   -1,   62,
   -1,   64,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   37,   38,   -1,   -1,  124,   42,
   43,   -1,   45,   -1,   47,   60,   -1,   62,   37,   64,
   -1,   94,   -1,   42,   43,   -1,   45,   60,   47,   62,
   -1,   64,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   60,   -1,   62,   -1,   64,   -1,   -1,   -1,   94,
   -1,  124,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  257,  258,  259,  260,  261,  262,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,   -1,   -1,   -1,
  257,  258,  259,  260,  261,  262,  263,  264,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  258,  259,  260,  261,  262,  263,  264,   -1,
   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    1,    2,
    3,    4,   -1,   -1,    7,   -1,  259,  260,  261,  262,
  263,  264,   15,   -1,   17,   18,   19,   20,   21,   22,
   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,
   33,   34,   35,   -1,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  261,  262,  263,  264,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 274
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const calcname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,0,"'<'","'='","'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CALC_OROR","CALC_ANDAND","CALC_EQEQ",
"CALC_NEQ","CALC_LEQ","CALC_GEQ","CALC_LSHIFT","CALC_RSHIFT",
"CALC_UNARY_PLUSMINUS","CALC_NUMBER","CALC_VAR","CALC_END_TOKEN",
"CALC_BAD_TOKEN",0,0,0,0,"illegal-symbol",
};
static const char *const calcrule[] = {
"$accept : calc",
"calc : expr",
"calc : assignment",
"assignment : CALC_VAR '=' expr",
"expr : expr CALC_OROR expr",
"expr : expr CALC_ANDAND expr",
"expr : expr '|' expr",
"expr : expr '^' expr",
"expr : expr '&' expr",
"expr : expr CALC_EQEQ expr",
"expr : expr CALC_NEQ expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr CALC_LEQ expr",
"expr : expr CALC_GEQ expr",
"expr : expr CALC_LSHIFT expr",
"expr : expr CALC_RSHIFT expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : '!' expr",
"expr : '~' expr",
"expr : '-' expr",
"expr : '+' expr",
"expr : expr '@' expr",
"expr : '(' expr ')'",
"expr : CALC_NUMBER",

};
#endif

int      yydebug;
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
#line 140 "calc.y"

/*
*/


#line 497 "calc.tab.c"

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
    int      yyerrflag;
    int      yychar;
    YYSTYPE  yyval;
    YYSTYPE  yylval;

    /* variables for the parser stack */
    YYSTACKDATA yystack;
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
#line 69 "calc.y"
	{   assert('\0' == lexData->m_Indent[0]);
            lexData->m_CalcResult = yystack.l_mark[0].m_Val;
        }
break;
case 2:
#line 73 "calc.y"
	{   assert('\0' != lexData->m_Indent[0]);
            lexData->m_CalcResult = yystack.l_mark[0].m_Val;
        }
break;
case 3:
#line 80 "calc.y"
	{   assert('\0' != lexData->m_Indent[0]);
            yyval.m_Val = yystack.l_mark[0].m_Val;
        }
break;
case 4:
#line 85 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val || yystack.l_mark[0].m_Val; }
break;
case 5:
#line 86 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val && yystack.l_mark[0].m_Val; }
break;
case 6:
#line 87 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val | yystack.l_mark[0].m_Val; }
break;
case 7:
#line 88 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val ^ yystack.l_mark[0].m_Val; }
break;
case 8:
#line 89 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val & yystack.l_mark[0].m_Val; }
break;
case 9:
#line 90 "calc.y"
	{ yyval.m_Val = (yystack.l_mark[-2].m_Val == yystack.l_mark[0].m_Val); }
break;
case 10:
#line 91 "calc.y"
	{ yyval.m_Val = (yystack.l_mark[-2].m_Val != yystack.l_mark[0].m_Val); }
break;
case 11:
#line 92 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val > yystack.l_mark[0].m_Val; }
break;
case 12:
#line 93 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val < yystack.l_mark[0].m_Val; }
break;
case 13:
#line 94 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val <= yystack.l_mark[0].m_Val; }
break;
case 14:
#line 95 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val >= yystack.l_mark[0].m_Val; }
break;
case 15:
#line 97 "calc.y"
	{   const CalcValue v3 = yystack.l_mark[0].m_Val;
            yyval.m_Val = (v3 >= 0) ? (yystack.l_mark[-2].m_Val << v3) : (yystack.l_mark[-2].m_Val >> (-v3));
        }
break;
case 16:
#line 101 "calc.y"
	{   const CalcValue v3 = yystack.l_mark[0].m_Val; 
            yyval.m_Val = (v3>=0) ? (yystack.l_mark[-2].m_Val >> v3) : (yystack.l_mark[-2].m_Val << (-v3));
        }
break;
case 17:
#line 104 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val + yystack.l_mark[0].m_Val; }
break;
case 18:
#line 105 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val - yystack.l_mark[0].m_Val; }
break;
case 19:
#line 106 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val * yystack.l_mark[0].m_Val; }
break;
case 20:
#line 108 "calc.y"
	{   const CalcValue v3 = yystack.l_mark[0].m_Val;
            if (v3 == 0) {
                calcerror("Division by 0");
                YYABORT;
            }
            yyval.m_Val = yystack.l_mark[-2].m_Val / (v3);
        }
break;
case 21:
#line 116 "calc.y"
	{ const CalcValue v3 = yystack.l_mark[0].m_Val;
          if (v3 == 0) {
            calcerror("Module by 0");
            YYABORT;
          }
          yyval.m_Val = yystack.l_mark[-2].m_Val % (v3);
        }
break;
case 22:
#line 123 "calc.y"
	{ yyval.m_Val = !yystack.l_mark[0].m_Val; }
break;
case 23:
#line 124 "calc.y"
	{ yyval.m_Val = ~yystack.l_mark[0].m_Val; }
break;
case 24:
#line 125 "calc.y"
	{ yyval.m_Val = -yystack.l_mark[0].m_Val; }
break;
case 25:
#line 126 "calc.y"
	{ yyval.m_Val = +yystack.l_mark[0].m_Val; }
break;
case 26:
#line 128 "calc.y"
	{   const CalcValue v3 = yystack.l_mark[0].m_Val;
            if (v3 < 0) {
                calcerror("Negative power");
                YYABORT;
            }
            yyval.m_Val = CalcPower(yystack.l_mark[-2].m_Val, v3);
        }
break;
case 27:
#line 135 "calc.y"
	{ yyval.m_Val = yystack.l_mark[-1].m_Val; }
break;
case 28:
#line 136 "calc.y"
	{ yyval.m_Val = yystack.l_mark[0].m_Val; }
break;
#line 854 "calc.tab.c"
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
