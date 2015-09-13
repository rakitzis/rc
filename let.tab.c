#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)


#ifndef yyparse
#define yyparse    letparse
#endif /* yyparse */

#ifndef yylex
#define yylex      letlex
#endif /* yylex */

#ifndef yyerror
#define yyerror    leterror
#endif /* yyerror */

#ifndef yychar
#define yychar     letchar
#endif /* yychar */

#ifndef yyval
#define yyval      letval
#endif /* yyval */

#ifndef yylval
#define yylval     letlval
#endif /* yylval */

#ifndef yydebug
#define yydebug    letdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    letnerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  leterrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      letlhs
#endif /* yylhs */

#ifndef yylen
#define yylen      letlen
#endif /* yylen */

#ifndef yydefred
#define yydefred   letdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    letdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   letsindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   letrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   letgindex
#endif /* yygindex */

#ifndef yytable
#define yytable    lettable
#endif /* yytable */

#ifndef yycheck
#define yycheck    letcheck
#endif /* yycheck */

#ifndef yyname
#define yyname     letname
#endif /* yyname */

#ifndef yyrule
#define yyrule     letrule
#endif /* yyrule */
#define YYPREFIX "let"

#define YYPURE 1

#line 4 "let.y"

extern int printf(const char *, ...);

#include "let.h"




#define letparse(a)  LetParser(struct LetLex *lex)
#define letparse_r(a)  LetParser(struct LetLex *lex)
#define letlex(a)  LetLexer(lex, &letlval)


#line 20 "let.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    LetValue m_Val;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 124 "let.tab.c"

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

#define LET_OROR 257
#define LET_ANDAND 258
#define EQEQ 259
#define NEQ 260
#define LEQ 261
#define GEQ 262
#define LSHIFT 263
#define RSHIFT 264
#define NUMBER 265
#define END_TOKEN 266
#define BAD_TOKEN 267
#define YYERRCODE 256
static const short letlhs[] = {                          -1,
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
static const short letlen[] = {                           2,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,
};
static const short letdefred[] = {                        0,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const short letdgoto[] = {                         3,
    4,
};
static const short letsindex[] = {                      -36,
    0,  -36,    0,  373,  183,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,    0,  389,  417,  428,  306,  361,
  -29,  -29,  456,  456,  456,  456,  153,  153,  -32,  -32,
  -64,  -64,  -64,  -64,
};
static const short letrindex[] = {                        0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,   21,   60,  107,  142,
  144,  156,   99,  124,  128,  133,   79,  116,   51,   67,
    1,   12,   28,   40,
};
static const short letgindex[] = {                        0,
  536,
};
#define YYTABLESIZE 720
static const short lettable[] = {                        24,
   17,    1,    0,    2,   23,    0,    0,   23,    0,   21,
    0,   18,   21,   19,   22,   20,    0,   22,    0,    0,
    3,    0,    0,    0,    0,    0,    2,   19,    0,    0,
   13,   24,   14,    0,   24,    0,    0,   17,   17,   20,
    0,   17,   17,   17,    0,   17,    0,   17,   18,   18,
   15,    0,   18,   18,   18,    0,   18,    0,   18,    4,
   17,    3,   17,    0,   19,   19,   16,    2,   19,   19,
   19,   18,   19,   18,   19,    0,   20,   20,   13,    0,
   20,   20,   20,    0,   20,    0,   20,   19,   15,   19,
    0,   15,    0,   15,   17,   15,    0,    0,   10,   20,
    4,   20,    0,    0,   16,   18,    5,   16,    0,   16,
   15,   16,   15,    0,    0,   14,   13,    0,    0,   13,
    0,   19,    0,    9,   17,    0,   16,   11,   16,    0,
    0,    0,   12,   20,    0,   18,   10,    0,   13,   10,
   13,    6,    0,    7,   15,    0,    0,    5,    0,    0,
    0,   19,    0,   14,    0,    8,   14,    0,    0,    0,
   16,    9,    0,   20,    9,   11,    0,    0,   11,    0,
   12,    0,   13,   12,   15,   14,    0,   14,    0,    6,
    0,    7,    6,    4,    7,    0,    0,    0,    0,   23,
   16,    0,   10,    8,   21,   19,    8,   20,    0,   22,
    5,    0,   13,    0,    0,    0,    0,    0,    0,   14,
    0,    0,    0,    0,    0,    0,   24,    9,    0,   23,
   10,   11,   10,   25,   21,   19,   12,   20,    1,   22,
    5,   15,   16,   17,   18,    6,    0,    7,    0,   14,
    0,    0,   13,    0,   14,    0,   24,    9,    0,    8,
    0,   11,    0,    0,    0,    0,   12,   17,   17,   17,
   17,   17,   17,   17,   17,    6,    0,    7,   18,   18,
   18,   18,   18,   18,   18,   18,    9,    3,    3,    8,
    0,    0,    0,    2,   19,   19,   19,   19,   19,   19,
   19,   19,    0,    0,    0,    0,   20,   20,   20,   20,
   20,   20,   20,   20,    0,    0,    8,   15,   15,   15,
   15,   15,   15,   15,   15,    0,    4,    4,    0,    0,
    0,    0,    0,   16,   16,   16,   16,   16,   16,   16,
   16,    0,    0,    0,    0,   13,   13,   13,   13,   13,
   13,    0,   23,   10,    0,    0,    0,   21,   19,    0,
   20,    0,   22,    0,    0,   10,   10,   10,   10,    0,
    0,    0,    0,    5,    5,   13,    0,   14,    0,   24,
    0,    0,   14,   14,   14,   14,   14,   14,    0,    0,
    9,    9,    9,    9,   11,   11,   11,   11,    0,   12,
   12,   12,   12,    0,    0,    0,    0,   23,    6,    6,
    7,    7,   21,   19,    0,   20,    0,   22,    0,   23,
   10,    0,    8,    8,   21,   19,    0,   20,    0,   22,
   13,    0,   14,    0,   24,   23,   10,    0,    0,    0,
   21,   19,   13,   20,   14,   22,   24,    0,    0,    6,
    7,   11,   12,   15,   16,   17,   18,    0,   13,    0,
   14,    0,   24,   23,   10,    0,    0,    0,   21,   19,
    0,   20,    0,   22,   23,   10,    9,    0,    0,   21,
   19,    0,   20,    0,   22,    0,   13,    0,   14,    0,
   24,    0,    9,    0,    0,    0,    0,   13,    0,   14,
    0,   24,   23,    0,    0,    0,    8,   21,   19,    0,
   20,    0,   22,    0,    0,    0,    0,    0,    0,    0,
    9,    0,    8,    0,    0,    0,    0,    0,    0,   24,
    0,    9,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    8,   26,   27,   28,   29,   30,   31,   32,   33,   34,
   35,   36,   37,   38,   39,   40,   41,   42,   43,   44,
    0,    0,    0,    0,   11,   12,   15,   16,   17,   18,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   11,
   12,   15,   16,   17,   18,    0,    0,    0,    0,    6,
    7,   11,   12,   15,   16,   17,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    7,   11,   12,   15,
   16,   17,   18,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,   12,   15,   16,   17,
   18,    0,    0,    0,    0,    0,   11,   12,   15,   16,
   17,   18,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   17,   18,
};
static const short letcheck[] = {                        64,
    0,    0,   -1,   40,   37,   -1,   -1,   37,   -1,   42,
   -1,    0,   42,   43,   47,   45,   -1,   47,   -1,   -1,
    0,   -1,   -1,   -1,   -1,   -1,    0,    0,   -1,   -1,
   60,   64,   62,   -1,   64,   -1,   -1,   37,   38,    0,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   37,   38,
    0,   -1,   41,   42,   43,   -1,   45,   -1,   47,    0,
   60,   41,   62,   -1,   37,   38,    0,   41,   41,   42,
   43,   60,   45,   62,   47,   -1,   37,   38,    0,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   60,   38,   62,
   -1,   41,   -1,   43,   94,   45,   -1,   -1,    0,   60,
   41,   62,   -1,   -1,   38,   94,    0,   41,   -1,   43,
   60,   45,   62,   -1,   -1,    0,   38,   -1,   -1,   41,
   -1,   94,   -1,    0,  124,   -1,   60,    0,   62,   -1,
   -1,   -1,    0,   94,   -1,  124,   38,   -1,   60,   41,
   62,    0,   -1,    0,   94,   -1,   -1,   41,   -1,   -1,
   -1,  124,   -1,   38,   -1,    0,   41,   -1,   -1,   -1,
   94,   38,   -1,  124,   41,   38,   -1,   -1,   41,   -1,
   38,   -1,   94,   41,  124,   60,   -1,   62,   -1,   38,
   -1,   38,   41,  124,   41,   -1,   -1,   -1,   -1,   37,
  124,   -1,   94,   38,   42,   43,   41,   45,   -1,   47,
   94,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   64,   94,   -1,   37,
   38,   94,  124,   41,   42,   43,   94,   45,  265,   47,
  124,  261,  262,  263,  264,   94,   -1,   94,   -1,  124,
   -1,   -1,   60,   -1,   62,   -1,   64,  124,   -1,   94,
   -1,  124,   -1,   -1,   -1,   -1,  124,  257,  258,  259,
  260,  261,  262,  263,  264,  124,   -1,  124,  257,  258,
  259,  260,  261,  262,  263,  264,   94,  257,  258,  124,
   -1,   -1,   -1,  257,  257,  258,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,  124,  257,  258,  259,
  260,  261,  262,  263,  264,   -1,  257,  258,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
  264,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
  262,   -1,   37,   38,   -1,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,  257,  258,  259,  260,   -1,
   -1,   -1,   -1,  257,  258,   60,   -1,   62,   -1,   64,
   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,   -1,
  257,  258,  259,  260,  257,  258,  259,  260,   -1,  257,
  258,  259,  260,   -1,   -1,   -1,   -1,   37,  257,  258,
  257,  258,   42,   43,   -1,   45,   -1,   47,   -1,   37,
   38,   -1,  257,  258,   42,   43,   -1,   45,   -1,   47,
   60,   -1,   62,   -1,   64,   37,   38,   -1,   -1,   -1,
   42,   43,   60,   45,   62,   47,   64,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,   -1,   60,   -1,
   62,   -1,   64,   37,   38,   -1,   -1,   -1,   42,   43,
   -1,   45,   -1,   47,   37,   38,   94,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   60,   -1,   62,   -1,
   64,   -1,   94,   -1,   -1,   -1,   -1,   60,   -1,   62,
   -1,   64,   37,   -1,   -1,   -1,  124,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   94,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,   64,
   -1,   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,    2,   -1,   -1,
  124,    6,    7,    8,    9,   10,   11,   12,   13,   14,
   15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,  261,  262,  263,  264,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,  263,  264,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,  261,
  262,  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  259,  260,  261,  262,  263,
  264,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,0,"'<'",0,"'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"LET_OROR","LET_ANDAND","EQEQ","NEQ","LEQ","GEQ","LSHIFT",
"RSHIFT","NUMBER","END_TOKEN","BAD_TOKEN",
};
static const char *yyrule[] = {
"$accept : top",
"top : expr",
"expr : expr LET_OROR expr",
"expr : expr LET_ANDAND expr",
"expr : expr '|' expr",
"expr : expr '^' expr",
"expr : expr '&' expr",
"expr : expr EQEQ expr",
"expr : expr NEQ expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr LEQ expr",
"expr : expr GEQ expr",
"expr : expr LSHIFT expr",
"expr : expr RSHIFT expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '@' expr",
"expr : '(' expr ')'",
"expr : NUMBER",

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
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
#line 97 "let.y"

/*
*/


#line 437 "let.tab.c"

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
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

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

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
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

    yyerror("syntax error");

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
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
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
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
#line 50 "let.y"
	{ letResult = yystack.l_mark[0].m_Val; }
break;
case 2:
#line 52 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val || yystack.l_mark[0].m_Val; }
break;
case 3:
#line 53 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val && yystack.l_mark[0].m_Val; }
break;
case 4:
#line 54 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val | yystack.l_mark[0].m_Val; }
break;
case 5:
#line 55 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val ^ yystack.l_mark[0].m_Val; }
break;
case 6:
#line 56 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val & yystack.l_mark[0].m_Val; }
break;
case 7:
#line 57 "let.y"
	{ yyval.m_Val = (yystack.l_mark[-2].m_Val == yystack.l_mark[0].m_Val); }
break;
case 8:
#line 58 "let.y"
	{ yyval.m_Val = (yystack.l_mark[-2].m_Val != yystack.l_mark[0].m_Val); }
break;
case 9:
#line 59 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val > yystack.l_mark[0].m_Val; }
break;
case 10:
#line 60 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val < yystack.l_mark[0].m_Val; }
break;
case 11:
#line 61 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val <= yystack.l_mark[0].m_Val; }
break;
case 12:
#line 62 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val >= yystack.l_mark[0].m_Val; }
break;
case 13:
#line 64 "let.y"
	{ LetValue v3 = yystack.l_mark[0].m_Val;
          yyval.m_Val = (v3 >= 0) ? (yystack.l_mark[-2].m_Val << v3) : (yystack.l_mark[-2].m_Val >> (-v3));
        }
break;
case 14:
#line 68 "let.y"
	{ LetValue v3 = yystack.l_mark[0].m_Val; 
          yyval.m_Val = (v3>=0) ? (yystack.l_mark[-2].m_Val >> v3) : (yystack.l_mark[-2].m_Val << (-v3));
        }
break;
case 15:
#line 71 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val + yystack.l_mark[0].m_Val; }
break;
case 16:
#line 72 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val - yystack.l_mark[0].m_Val; }
break;
case 17:
#line 73 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val * yystack.l_mark[0].m_Val; }
break;
case 18:
#line 75 "let.y"
	{ long v3 = yystack.l_mark[0].m_Val;
          if (v3 == 0) { leterror("Division by 0"); }
          yyval.m_Val = yystack.l_mark[-2].m_Val / (v3);
        }
break;
case 19:
#line 80 "let.y"
	{ long v3 = yystack.l_mark[0].m_Val;
          if (v3 == 0) { leterror("Module by 0"); }
          yyval.m_Val = yystack.l_mark[-2].m_Val % (v3);
        }
break;
case 20:
#line 85 "let.y"
	{ long v3 = yystack.l_mark[0].m_Val;
          if (v3 < 0) { leterror("Negative power"); }
          yyval.m_Val = letpwr(yystack.l_mark[-2].m_Val, v3);
        }
break;
case 21:
#line 89 "let.y"
	{ yyval.m_Val = yystack.l_mark[-1].m_Val; }
break;
case 22:
#line 90 "let.y"
	{ 
          LetValue v = yystack.l_mark[0].m_Val;
         yyval.m_Val = v; 
     }
break;
#line 754 "let.tab.c"
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
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
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
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
