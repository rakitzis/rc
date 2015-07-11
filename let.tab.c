#ifndef lint
static char yysccsid[] = "@(#)yaccpar 1.9 (Berkeley) 02/21/93";
#endif

#define yyclearin (yychar = YYEMPTY)
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define yyparse letparse
#define yylex letlex
#define yyerror leterror
#define yychar letchar
#define yyval letval
#define yylval letlval
#define yydebug letdebug
#define yynerrs letnerrs
#define yyerrflag leterrflag
#define yyss letss
#define yyssp letssp
#define yyvs letvs
#define yyvsp letvsp
#define yylhs letlhs
#define yylen letlen
#define yydefred letdefred
#define yydgoto letdgoto
#define yysindex letsindex
#define yyrindex letrindex
#define yygindex letgindex
#define yytable lettable
#define yycheck letcheck
#define yyname letname
#define yyrule letrule
#define YYPREFIX "let"
#define YYSTYPE LETSTYPE
#line 9 "let.y"

extern int printf(const char *, ...);

typedef int Token;
#if 1
typedef long letValue;
extern int LetDoParse(char *s, letValue *);
/* extern letValue letResult; */
#endif

struct LetLex {
  const char *m_Buf;
  const char *m_Current;
  Token m_LastToken;
};

static int LetParser(struct LetLex*);
#define letparse(a)  LetParser(struct LetLex *lex)
#define letlex(a)  LetLexer(lex, &letlval)

#line 32 "let.y"
typedef union {
	letValue m_Val;
} YYSTYPE;
#line 59 "let.tab.c"
enum LETtoken {
  LET_OROR = 257,
  LET_ANDAND = 258,
  EQEQ = 259,
  NEQ = 260,
  LEQ = 261,
  GEQ = 262,
  LSHIFT = 263,
  RSHIFT = 264,
  NUMBER = 265,
  END_TOKEN = 266,
  BAD_TOKEN = 267
};
static const short letlhs[] = {                                        -1,
    0,    1,    1,    2,    2,    3,    3,    4,    4,    5,
    5,    6,    6,    6,    7,    7,    7,    7,    7,    8,
    8,    8,   10,   10,   10,   11,   11,   11,    9,    9,
    9,   12,   12,   12,   12,   13,   13,   14,   14,
};
static const short letlen[] = {                                         2,
    1,    1,    3,    1,    3,    1,    3,    1,    3,    1,
    3,    1,    3,    3,    1,    3,    3,    3,    3,    1,
    3,    3,    1,    3,    3,    1,    2,    2,    1,    3,
    3,    1,    3,    3,    3,    1,    3,    3,    1,
};
static const short letdefred[] = {                                      0,
   39,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   10,    0,    0,   20,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0,    0,    0,   11,   13,   14,    0,    0,
   21,   22,    0,    0,    0,    0,    0,   33,   34,   35,
   37,    0,    0,    0,    0,
};
static const short letdgoto[] = {                                       5,
    6,    7,    8,    9,   10,   11,   12,   13,   55,   14,
   15,   16,   17,   18,
};
static const short letsindex[] = {                                    -40,
    0,  -38,  -38,  -40,    0, -253, -251, -111,  -66,   -8,
    0, -227,  -50,    0,  -19,  -31,    0,  -28,  -31,  -31,
   10,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,
  -40,  -40,  -40,  -40,  -38,  -38,  -38,  -38,  -38,  -38,
    0, -251, -111,  -66,   -8,    0,    0,    0, -229, -229,
    0,    0, -229, -229,  -14,  -31,  -14,    0,    0,    0,
    0,  -38,  -38,  -31,  -31,
};
static const short letrindex[] = {                                      0,
    0,    0,    0,    0,    0,    8,   25,  135,  194,  326,
    0,  350,   85,    0,   76,    9,    0,    1,   17,   27,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  101,  137,  203,  348,    0,    0,    0,  122,  127,
    0,    0,  199,  283,  102,   37,  112,    0,    0,    0,
    0,    0,    0,   45,   53,
};
static const short letgindex[] = {                                     52,
    0,   35,   36,   40,   56,   41,   13,  -15,   48,   42,
    0,  155,  -17,    0,
};
static const short lettable[] = {                                       4,
   36,    4,    2,   22,    3,   39,   23,    1,   26,   34,
   37,   33,   24,   49,   50,   38,   28,   53,   54,   58,
   59,   60,   61,   35,    2,   36,   27,   25,   62,   26,
   63,   27,   28,   31,   32,   40,   29,   36,   36,   47,
   48,   36,   36,   36,   30,   36,   26,   36,    1,   26,
   41,   26,   31,   26,   28,   21,   42,   28,   43,   28,
   36,   28,   36,   44,   27,    2,   46,   27,   26,   27,
   26,   27,   51,   52,   29,   23,   28,   29,   28,   29,
   45,   29,   30,   57,   15,   30,   27,   30,   27,   30,
   31,    0,    0,   31,   36,   31,   29,   31,   29,    0,
    3,   24,   26,    0,   30,    0,   30,    0,    0,    0,
   28,   25,   31,   23,   31,    0,   23,    0,    0,    0,
   27,   18,   15,    0,   36,   15,   19,    0,    0,    0,
   29,    0,   26,    0,    4,   23,    5,   23,   30,   24,
   28,    3,   24,    0,    0,    0,   31,    0,    0,   25,
   27,    0,   25,    0,    0,    0,   19,   20,    0,   18,
   29,   24,   18,   24,   19,    0,    0,   19,   30,   23,
    0,   25,    0,   25,    0,    4,   31,    5,   15,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
   56,    0,    0,    6,    0,   24,    0,    0,   16,   23,
    0,    0,    7,    0,    0,   25,    0,    0,   15,    0,
   29,   30,   31,   32,    0,   18,   64,   65,    0,    0,
   19,    0,    0,    0,    1,   24,    1,    0,    0,    0,
    0,    0,    0,    0,    6,   25,   16,    0,    0,   16,
    0,    0,    0,    7,    0,   18,    0,    0,    0,    0,
   19,    0,    0,    0,    0,    0,    0,   36,   36,   36,
   36,   36,   36,   36,   36,   26,   26,   26,   26,   26,
   26,   26,   26,   28,   28,   28,   28,   28,   28,   28,
   28,    2,   17,   27,   27,   27,   27,   27,   27,   27,
   27,    0,   16,   29,   29,   29,   29,   29,   29,   29,
   29,   30,   30,   30,   30,   30,   30,   30,   30,   31,
   31,   31,   31,   31,   31,   31,   31,    6,    0,    0,
   17,    0,   16,   17,    0,    8,    7,    0,    0,    0,
    0,    0,   23,   23,   23,   23,   23,   23,   23,   23,
    0,   15,   15,   15,   15,    0,    0,    9,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    3,   24,   24,
   24,   24,   24,   24,   24,   24,    8,    0,   25,   25,
   25,   25,   25,   25,   25,   25,   17,    0,   18,   18,
   18,   18,    0,   19,   19,   19,   19,   12,    9,    0,
   12,    4,    4,    5,    5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    9,    0,   12,    0,    0,    0,    0,    0,    8,
    6,    6,    0,    0,    0,   16,   16,   16,   16,    7,
    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    9,    0,   12,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   17,
   17,   17,   17,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    8,    8,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    9,    9,   12,   12,
};
static const short letcheck[] = {                                      40,
    0,   40,   43,  257,   45,   37,  258,    0,    0,   60,
   42,   62,  124,   29,   30,   47,    0,   33,   34,   37,
   38,   39,   40,   43,    0,   45,    0,   94,   43,   38,
   45,  259,  260,  263,  264,   64,    0,   37,   38,   27,
   28,   41,   42,   43,    0,   45,   38,   47,   41,   41,
   41,   43,    0,   45,   38,    4,   22,   41,   23,   43,
   60,   45,   62,   24,   38,   41,   26,   41,   60,   43,
   62,   45,   31,   32,   38,    0,   60,   41,   62,   43,
   25,   45,   38,   36,    0,   41,   60,   43,   62,   45,
   38,   -1,   -1,   41,   94,   43,   60,   45,   62,   -1,
    0,    0,   94,   -1,   60,   -1,   62,   -1,   -1,   -1,
   94,    0,   60,   38,   62,   -1,   41,   -1,   -1,   -1,
   94,    0,   38,   -1,  124,   41,    0,   -1,   -1,   -1,
   94,   -1,  124,   -1,    0,   60,    0,   62,   94,   38,
  124,   41,   41,   -1,   -1,   -1,   94,   -1,   -1,   38,
  124,   -1,   41,   -1,   -1,   -1,    2,    3,   -1,   38,
  124,   60,   41,   62,   38,   -1,   -1,   41,  124,   94,
   -1,   60,   -1,   62,   -1,   41,  124,   41,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   35,
   36,   -1,   -1,    0,   -1,   94,   -1,   -1,    0,  124,
   -1,   -1,    0,   -1,   -1,   94,   -1,   -1,  124,   -1,
  261,  262,  263,  264,   -1,   94,   62,   63,   -1,   -1,
   94,   -1,   -1,   -1,  265,  124,  265,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   41,  124,   38,   -1,   -1,   41,
   -1,   -1,   -1,   41,   -1,  124,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  257,  258,  259,  260,  261,
  262,  263,  264,  257,  258,  259,  260,  261,  262,  263,
  264,  257,    0,  257,  258,  259,  260,  261,  262,  263,
  264,   -1,   94,  257,  258,  259,  260,  261,  262,  263,
  264,  257,  258,  259,  260,  261,  262,  263,  264,  257,
  258,  259,  260,  261,  262,  263,  264,  124,   -1,   -1,
   38,   -1,  124,   41,   -1,    0,  124,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  262,  263,  264,
   -1,  257,  258,  259,  260,   -1,   -1,    0,   -1,    0,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  257,  258,
  259,  260,  261,  262,  263,  264,   41,   -1,  257,  258,
  259,  260,  261,  262,  263,  264,   94,   -1,  257,  258,
  259,  260,   -1,  257,  258,  259,  260,   38,   41,   -1,
   41,  257,  258,  257,  258,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   94,   -1,   94,   -1,   -1,   -1,   -1,   -1,  124,
  257,  258,   -1,   -1,   -1,  257,  258,  259,  260,  257,
  258,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  124,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  257,  258,
};
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
enum YYconsts {
  /* yacc version */
  YYBYACC     = 1,
  YYMAJOR     = 1,
  YYMINOR     = 9,
  /* special states */
  YYSTART     = 0,
  YYFINAL     = 5,
  /* special tokens */
  YYEOF       = 0,
  YYEMPTY     = (-1),
  YYMAXTOKEN  = 267,
  YYERRCODE   = 256,
  /* tables */
  YYTABLESIZE = 608
};
#if YYDEBUG
static const char* const letname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,0,"'<'",0,"'>'",0,"'@'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"LET_OROR","LET_ANDAND","EQEQ","NEQ","LEQ","GEQ","LSHIFT","RSHIFT",
"NUMBER","END_TOKEN","BAD_TOKEN",
};
static const char* const letrule[] = {
"$accept : expr",
"expr : logor",
"logor : logand",
"logor : logor LET_OROR logand",
"logand : bitor",
"logand : logand LET_ANDAND bitor",
"bitor : bitxor",
"bitor : bitor '|' bitxor",
"bitxor : bitand",
"bitxor : bitxor '^' bitand",
"bitand : eq",
"bitand : bitand '&' eq",
"eq : cmp",
"eq : cmp EQEQ cmp",
"eq : cmp NEQ cmp",
"cmp : shift",
"cmp : shift '>' shift",
"cmp : shift '<' shift",
"cmp : shift LEQ shift",
"cmp : shift GEQ shift",
"shift : sadd",
"shift : shift LSHIFT sadd",
"shift : shift RSHIFT sadd",
"sadd : fmult",
"sadd : fmult '+' add",
"sadd : fmult '-' add",
"fmult : mult",
"fmult : '-' mult",
"fmult : '+' mult",
"add : mult",
"add : add '+' mult",
"add : add '-' mult",
"mult : pow",
"mult : mult '*' pow",
"mult : mult '/' pow",
"mult : mult '%' pow",
"pow : unit",
"pow : unit '@' pow",
"unit : '(' expr ')'",
"unit : NUMBER",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif

#define yystacksize YYSTACKSIZE
#line 144 "let.y"



/******************************************************/
/******************************************************/
static letValue letResult;



/******************************************************/

static letValue letpwr (
  letValue a,
  letValue b)
{
  letValue z = 1;   /* z*a^b = A^B */
  while (b > 0) {
    if (b & 1) { /* odd */
      /* z*a^b = z*a * a^(b-1) */
      --b;
      z *= a;
    } else {
      /* z*a^(2k) = z * (a^2)^k */
      b /= 2;
      a *= a;
    }
  }
  return z;
}
/******************************************************/
static Token LetLexer (struct LetLex *lex, YYSTYPE* letlval)
{
  const char *p;
  Token tok;
  int c;

  if (lex->m_LastToken != BAD_TOKEN) {
    tok = lex->m_LastToken;
    lex->m_LastToken = BAD_TOKEN;
    return tok;
  }
  p = lex->m_Current;
  while (*p == ' ' || *p == '\t') {
    p++;
  }
  switch (*p) {
  case '+': case '-': case '*': case '/': case '%':
  case '^': case '(': case ')':
  case '@':
    tok = (Token) (*p);
    p++;
    break;

  case '|': case '&':
    c = *p++;
    if (*p == c) {
       tok = (c == '|' ? LET_OROR : LET_ANDAND);
       p++; 
    } else {
       tok = (Token)(c);
    }
    break;

  case '<': case '>':
    c = *p++;
    if (*p == '=') {
      tok = (c == '<' ? LEQ : GEQ);
      p++;
    } else if (c == *p) {
      tok = (c == '<' ? LSHIFT : RSHIFT);
      p++;
    } else {
      tok = (Token) (c);
    }
    break;

  case '!': case '=':
    c = *p++;
    if (*p == '=') {
      tok = ((c == '=') ? EQEQ : NEQ);
      p++;
    } else {
      tok = BAD_TOKEN;
    }
    break;

  case '0': case '1': case '2': case '3': case '4': 
  case '5': case '6': case '7': case '8': case '9': 
    {
        letValue val = 0;
        while ('0' <= *p && *p <= '9') {
          val = 10 * val + (*p++ -'0');
        }
        letlval->m_Val = val;
        tok = NUMBER;
    }
    break;
  case '\0':
    tok = 0;
    break;
  default:
    tok = BAD_TOKEN;
    break;
  }
  lex->m_Current = p;
  return tok;
} /* LetLexer */

/******************************************************/
#include "setjmp.h"

static jmp_buf jbuf;

/******************************************************/
int LetDoParse (
  char *s,
  letValue *r)
{
  int status;
  struct LetLex lex;

  if (setjmp(jbuf)) {
    return -1;
  }
  lex.m_Current = lex.m_Buf = s;
  lex.m_LastToken = BAD_TOKEN;

  status = LetParser(&lex);
  *r = letResult;
  return status;
}

/******************************************************/


static int leterror (
  const char *s)
{
  printf("let: %s\n", s);
  longjmp(jbuf, 1);
  return 0;
}
/******************************************************/
/******************************************************/


#line 480 "let.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_ARG void
#endif

int yyparse(YYPARSE_PARAM_ARG)
{
#if YYDEBUG
    int yydebug;
#endif
    int yynerrs = 0;
    int yyerrflag = 0;
    int yychar = 0;
    short *yyssp = 0;
    YYSTYPE *yyvsp = 0;
    YYSTYPE yyval;
    YYSTYPE yylval;
    short yyss[YYSTACKSIZE];
    YYSTYPE yyvs[YYSTACKSIZE];

    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;
    extern char *getenv(const char*);

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    yyssp = yyss;
    yyvsp = yyvs;
    yystate = YYSTART;
    *yyssp = yystate;

yyloop:
    if ((yyn = yydefred[yystate]))
        goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex(&yylval)) < 0)
             yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN)
                yys = yyname[yychar];
            if (!yys)
                yys = "illegal-symbol";
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
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)
            --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag)
        goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yyssp = yystate;
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss)
                    goto yyabort;
                --yyssp;
                --yyvsp;
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
            yys = 0;
            if (yychar <= YYMAXTOKEN)
                yys = yyname[yychar];
            if (!yys)
                yys = "illegal-symbol";
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
    if (yym >= 1) { /* For zero length rules, avoid $$ = $1. */
        yyval = yyvsp[1-yym];
    }
    switch (yyn)
    {
case 1:
#line 45 "let.y"
{ letResult = yyval.m_Val = yyvsp[0].m_Val; }
break;
case 3:
#line 49 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val || yyvsp[0].m_Val; }
break;
case 5:
#line 53 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val && yyvsp[0].m_Val; }
break;
case 7:
#line 57 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val | yyvsp[0].m_Val; }
break;
case 9:
#line 61 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val ^ yyvsp[0].m_Val; }
break;
case 11:
#line 65 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val & yyvsp[0].m_Val; }
break;
case 13:
#line 69 "let.y"
{ yyval.m_Val = (yyvsp[-2].m_Val == yyvsp[0].m_Val); }
break;
case 14:
#line 70 "let.y"
{ yyval.m_Val = (yyvsp[-2].m_Val != yyvsp[0].m_Val); }
break;
case 16:
#line 74 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val > yyvsp[0].m_Val; }
break;
case 17:
#line 75 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val < yyvsp[0].m_Val; }
break;
case 18:
#line 76 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val <= yyvsp[0].m_Val; }
break;
case 19:
#line 77 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val >= yyvsp[0].m_Val; }
break;
case 21:
#line 82 "let.y"
{ letValue v3 = yyvsp[0].m_Val;
		  yyval.m_Val = (v3 >= 0) ? (yyvsp[-2].m_Val << v3) : (yyvsp[-2].m_Val >> (-v3));
		}
break;
case 22:
#line 86 "let.y"
{ letValue v3 = yyvsp[0].m_Val; 
		  yyval.m_Val = (v3>=0) ? (yyvsp[-2].m_Val >> v3) : (yyvsp[-2].m_Val << (-v3));
		}
break;
case 24:
#line 92 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val + yyvsp[0].m_Val; }
break;
case 25:
#line 93 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val - yyvsp[0].m_Val; }
break;
case 27:
#line 97 "let.y"
{ yyval.m_Val = - yyvsp[0].m_Val; }
break;
case 28:
#line 98 "let.y"
{ yyval.m_Val = + yyvsp[0].m_Val; }
break;
case 30:
#line 102 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val + yyvsp[0].m_Val; }
break;
case 31:
#line 103 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val - yyvsp[0].m_Val; }
break;
case 33:
#line 115 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val * yyvsp[0].m_Val; }
break;
case 34:
#line 117 "let.y"
{ long v3 = yyvsp[0].m_Val;
		  if (v3 == 0) { leterror("Division by 0"); }
		  yyval.m_Val = yyvsp[-2].m_Val / (v3);
		}
break;
case 35:
#line 122 "let.y"
{ long v3 = yyvsp[0].m_Val;
		  if (v3 == 0) { leterror("Module by 0"); }
		  yyval.m_Val = yyvsp[-2].m_Val % (v3);
		}
break;
case 37:
#line 130 "let.y"
{ long v3 = yyvsp[0].m_Val;
		  if (v3 < 0) { leterror("Negative power"); }
		  yyval.m_Val = letpwr(yyvsp[-2].m_Val, v3);
		}
break;
case 38:
#line 136 "let.y"
{ yyval.m_Val = yyvsp[-1].m_Val; }
break;
case 39:
#line 137 "let.y"
{ 
          letValue v = yyvsp[0].m_Val;
         yyval.m_Val = v; 
     }
break;
#line 772 "let.tab.c"
    default:
        break;
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == YYSTART && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex(&yylval)) < 0)
                yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN)
                    yys = yyname[yychar];
                if (!yys)
                    yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF)
            goto yyaccept;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
