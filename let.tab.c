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
#define UNARY_PLUSMINUS 265
#define NUMBER 266
#define END_TOKEN 267
#define BAD_TOKEN 268
#define YYERRCODE 256
static const short letlhs[] = {                          -1,
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,
};
static const short letlen[] = {                           2,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    3,    3,    1,
};
static const short letdefred[] = {                        0,
    0,    0,    0,    0,   26,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   25,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const short letdgoto[] = {                         7,
    8,
};
static const short letsindex[] = {                      -13,
  -13,  -13,  -13,  -13,    0,  -13,    0,  464,  -64,  -64,
  -64,  -64,  453,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -13,
  -13,  -13,    0,  495,  538,  566,  578,  506,  592,  592,
  -28,  -28,  -28,  -28,  297,  297,  -31,  -31,  -64,  -64,
  -64,  -64,
};
static const short letrindex[] = {                        0,
    0,    0,    0,    0,    0,    0,    0,    2,    1,   12,
   28,   40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   10,   96,   79,   23,  115,   92,  107,
  410,  420,  426,  437,  172,  333,  144,  183,   56,   67,
  128,  155,
};
static const short letgindex[] = {                        0,
  789,
};
#define YYTABLESIZE 856
static const short lettable[] = {                        32,
   23,    1,    0,    0,    0,   31,    0,    0,   31,    2,
   29,   22,    0,   29,   27,   30,   28,    0,   30,    3,
    0,    0,    5,    0,    0,    0,    6,   20,    0,    1,
    0,    2,   32,    0,    0,   32,    0,   23,   23,   21,
    0,   23,   23,   23,    0,   23,    0,   23,   22,   22,
    2,    0,   22,   22,   22,   17,   22,    0,   22,    0,
   23,    0,   23,    5,   20,   20,   18,    0,   20,   20,
   20,   22,   20,   22,   20,    0,   21,   21,    4,    0,
   21,   21,   21,    0,   21,    0,   21,   20,    0,   20,
    0,    7,   17,   17,   23,    3,   17,   17,   17,   21,
   17,   21,   17,   18,   18,   22,    8,   18,   18,   18,
    0,   18,    4,   18,    6,   17,    5,   17,    0,    4,
    0,   20,    0,    0,   23,    0,   18,   19,   18,    7,
    0,    0,    7,   21,    0,   22,    3,    0,    0,    0,
    0,    0,    0,   15,    8,    0,    5,    8,    0,   17,
    0,   20,    6,    0,   24,    6,    0,    0,    0,    0,
   18,    0,    0,   21,   19,   19,    0,    0,   19,   19,
   19,   13,   19,    0,   19,    0,    0,    0,    0,   17,
    0,   15,   16,    0,   15,    7,   15,   19,   15,   19,
   18,   24,   24,    0,    0,   24,   24,   24,    0,   24,
    8,   24,    4,   15,    0,   15,    0,    0,    6,   13,
    0,    0,   13,    0,   24,    7,   24,    0,    0,    0,
   16,   19,    0,   16,    0,   16,    0,   16,    0,    0,
    8,   13,    0,   13,   25,   26,    0,   15,    6,    0,
    0,    0,   16,    0,   16,    0,    0,    0,   24,    0,
    0,   19,    5,    0,    0,    0,    0,   23,   23,   23,
   23,   23,   23,   23,   23,   13,    2,   15,   22,   22,
   22,   22,   22,   22,   22,   22,   16,    0,   24,    5,
    5,    0,    0,    0,   20,   20,   20,   20,   20,   20,
   20,   20,    0,    0,    0,   13,   21,   21,   21,   21,
   21,   21,   21,   21,    0,    0,   16,    0,    0,    0,
    0,    0,   17,   17,   17,   17,   17,   17,   17,   17,
    0,    0,    0,   18,   18,   18,   18,   18,   18,   18,
   18,    0,   14,   31,    0,    4,    4,    0,   29,   27,
    0,   28,    0,   30,    0,    0,    0,    0,    7,    7,
    7,    7,    3,    3,    0,    0,    0,    0,    0,    0,
   32,    0,    0,    8,    8,    8,    8,    0,    0,    0,
   14,    6,    6,   14,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   19,   19,   19,   19,   19,
   19,   19,   14,    0,   14,    0,    0,    0,    0,    0,
   15,   15,   15,   15,   15,   15,   15,   15,    0,   10,
    0,   24,   24,   24,   24,   24,   24,   24,   24,    9,
    0,    0,    0,    0,    0,   11,   14,    0,   13,   13,
   13,   13,   13,   13,   13,   13,   12,    0,    0,   16,
   16,   16,   16,   16,   16,   16,   16,   10,    0,    0,
   10,    0,    0,    0,    0,    0,   14,    9,    0,    0,
    9,    0,    0,   11,    0,    0,   11,    0,    0,   10,
    0,   10,    0,    0,   12,    0,    0,   12,    0,    9,
    0,    9,    0,    0,    0,   11,    0,   11,    0,   31,
   18,    0,    0,   33,   29,   27,   12,   28,   12,   30,
   31,   18,    0,   10,    0,   29,   27,    0,   28,    0,
   30,    0,   21,    9,   22,    0,   32,    0,    0,   11,
    0,    0,    0,   21,    0,   22,    0,   32,    0,    0,
   12,   31,   18,   10,    0,    0,   29,   27,    0,   28,
    0,   30,   31,    9,    0,    0,   17,   29,   27,   11,
   28,    0,   30,    0,   21,    0,   22,   17,   32,    0,
   12,    0,    0,    0,    0,   21,    0,   22,    0,   32,
    0,    0,    0,    0,   31,   18,   16,    0,    0,   29,
   27,    0,   28,    0,   30,    0,    0,   16,   17,   14,
   14,   14,   14,   14,   14,   14,   14,   21,    0,   22,
    0,   32,   31,   18,    0,    0,    0,   29,   27,    0,
   28,    0,   30,    0,   31,   18,    0,    0,   16,   29,
   27,    0,   28,    0,   30,   21,    0,   22,   31,   32,
    0,   17,    0,   29,   27,    0,   28,   21,   30,   22,
    0,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,    0,   22,    0,   32,    0,    0,    0,   17,
    0,   16,    0,    0,    0,    0,   10,   10,   10,   10,
   10,   10,    0,    0,    0,    0,    9,    9,    9,    9,
    9,    9,   11,   11,   11,   11,   11,   11,    0,    0,
    0,    0,    0,   12,   12,   12,   12,   12,   12,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   14,
   15,   19,   20,   23,   24,   25,   26,    0,    0,    0,
   14,   15,   19,   20,   23,   24,   25,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   15,   19,   20,   23,   24,   25,   26,    0,
    0,    0,    0,    0,   19,   20,   23,   24,   25,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    9,
   10,   11,   12,    0,   13,    0,   19,   20,   23,   24,
   25,   26,   34,   35,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,
   52,    0,    0,    0,   19,   20,   23,   24,   25,   26,
    0,    0,    0,    0,    0,    0,   19,   20,   23,   24,
   25,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   23,   24,   25,   26,
};
static const short letcheck[] = {                        64,
    0,    0,   -1,   -1,   -1,   37,   -1,   -1,   37,    0,
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
   38,   94,   -1,   41,   -1,   43,   -1,   45,   -1,   -1,
  124,   60,   -1,   62,  263,  264,   -1,   94,  124,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   94,   -1,
   -1,  124,  266,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,   94,  257,  124,  257,  258,
  259,  260,  261,  262,  263,  264,   94,   -1,  124,  257,
  258,   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,  124,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,  263,
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
   41,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   60,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    1,
    2,    3,    4,   -1,    6,   -1,  259,  260,  261,  262,
  263,  264,   14,   15,   16,   17,   18,   19,   20,   21,
   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
   32,   -1,   -1,   -1,  259,  260,  261,  262,  263,  264,
   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,  262,
  263,  264,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  261,  262,  263,  264,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 268
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,0,"'<'",0,"'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",
0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LET_OROR","LET_ANDAND","EQEQ","NEQ","LEQ","GEQ",
"LSHIFT","RSHIFT","UNARY_PLUSMINUS","NUMBER","END_TOKEN","BAD_TOKEN",
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
"expr : '!' expr",
"expr : '~' expr",
"expr : '-' expr",
"expr : '+' expr",
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
#line 99 "let.y"

/*
*/


#line 473 "let.tab.c"

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
#line 51 "let.y"
	{ letResult = yystack.l_mark[0].m_Val; }
break;
case 2:
#line 53 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val || yystack.l_mark[0].m_Val; }
break;
case 3:
#line 54 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val && yystack.l_mark[0].m_Val; }
break;
case 4:
#line 55 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val | yystack.l_mark[0].m_Val; }
break;
case 5:
#line 56 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val ^ yystack.l_mark[0].m_Val; }
break;
case 6:
#line 57 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val & yystack.l_mark[0].m_Val; }
break;
case 7:
#line 58 "let.y"
	{ yyval.m_Val = (yystack.l_mark[-2].m_Val == yystack.l_mark[0].m_Val); }
break;
case 8:
#line 59 "let.y"
	{ yyval.m_Val = (yystack.l_mark[-2].m_Val != yystack.l_mark[0].m_Val); }
break;
case 9:
#line 60 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val > yystack.l_mark[0].m_Val; }
break;
case 10:
#line 61 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val < yystack.l_mark[0].m_Val; }
break;
case 11:
#line 62 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val <= yystack.l_mark[0].m_Val; }
break;
case 12:
#line 63 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val >= yystack.l_mark[0].m_Val; }
break;
case 13:
#line 65 "let.y"
	{ LetValue v3 = yystack.l_mark[0].m_Val;
          yyval.m_Val = (v3 >= 0) ? (yystack.l_mark[-2].m_Val << v3) : (yystack.l_mark[-2].m_Val >> (-v3));
        }
break;
case 14:
#line 69 "let.y"
	{ LetValue v3 = yystack.l_mark[0].m_Val; 
          yyval.m_Val = (v3>=0) ? (yystack.l_mark[-2].m_Val >> v3) : (yystack.l_mark[-2].m_Val << (-v3));
        }
break;
case 15:
#line 72 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val + yystack.l_mark[0].m_Val; }
break;
case 16:
#line 73 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val - yystack.l_mark[0].m_Val; }
break;
case 17:
#line 74 "let.y"
	{ yyval.m_Val = yystack.l_mark[-2].m_Val * yystack.l_mark[0].m_Val; }
break;
case 18:
#line 76 "let.y"
	{ long v3 = yystack.l_mark[0].m_Val;
          if (v3 == 0) { leterror("Division by 0"); }
          yyval.m_Val = yystack.l_mark[-2].m_Val / (v3);
        }
break;
case 19:
#line 81 "let.y"
	{ long v3 = yystack.l_mark[0].m_Val;
          if (v3 == 0) { leterror("Module by 0"); }
          yyval.m_Val = yystack.l_mark[-2].m_Val % (v3);
        }
break;
case 20:
#line 85 "let.y"
	{ yyval.m_Val = !yystack.l_mark[0].m_Val; }
break;
case 21:
#line 86 "let.y"
	{ yyval.m_Val = ~yystack.l_mark[0].m_Val; }
break;
case 22:
#line 87 "let.y"
	{ yyval.m_Val = -yystack.l_mark[0].m_Val; }
break;
case 23:
#line 88 "let.y"
	{ yyval.m_Val = +yystack.l_mark[0].m_Val; }
break;
case 24:
#line 90 "let.y"
	{ long v3 = yystack.l_mark[0].m_Val;
          if (v3 < 0) { leterror("Negative power"); }
          yyval.m_Val = letpwr(yystack.l_mark[-2].m_Val, v3);
        }
break;
case 25:
#line 94 "let.y"
	{ yyval.m_Val = yystack.l_mark[-1].m_Val; }
break;
case 26:
#line 95 "let.y"
	{ yyval.m_Val = yystack.l_mark[0].m_Val; }
break;
#line 803 "let.tab.c"
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
