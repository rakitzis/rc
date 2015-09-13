
#define yyclearin (yychar = YYEMPTY)
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define yyparse letparse
#define yyparse_r letparse_r
#define yylex letlex
#define yylex_v letlex_v
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
#line 4 "let.y"

extern int printf(const char *, ...);

typedef int Token;
typedef long letValue;


struct LetLex {
  const char *m_Buf;
  const char *m_Current;
  Token m_LastToken;
};


#define letparse(a)  LetParser(struct LetLex *lex)
#define letparse_r(a)  LetParser(struct LetLex *lex)
#define letlex(a)  LetLexer(lex, &letlval)
static int leterror(const char *s);
extern int LetDoParse(char *s, letValue *);


static letValue letResult;
#line 29 "let.y"
typedef union YYSTYPE {
    letValue m_Val;
} YYSTYPE;
#line 60 "let.tab.c"

enum YYtoken {
  YYEOF = 0,
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
    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};

static const short letlen[] = {                                         2,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,
};

static const short letdefred[] = {                                      0,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};

static const short letdgoto[] = {                                       3,
    4,
};

static const short letsindex[] = {                                    -36,
    0,  -36,    0,  373,  183,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,  -36,
  -36,  -36,  -36,  -36,    0,  389,  417,  428,  306,  361,
  -29,  -29,  456,  456,  456,  456,  153,  153,  -32,  -32,
  -64,  -64,  -64,  -64,
};

static const short letrindex[] = {                                      0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,   21,   60,  107,  142,
  144,  156,   99,  124,  128,  133,   79,  116,   51,   67,
    1,   12,   28,   40,
};

static const short letgindex[] = {                                      0,
  536,
};

static const short lettable[] = {                                      24,
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

static const short letcheck[] = {                                      64,
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
  YYFINAL     = 3,
  /* special tokens */
  YYEMPTY     = (-1),
  YYERRCODE   = 256,
  YYMAXTOKEN  = 267,
  /* tables */
  YYTABLESIZE = 720
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
0,0,0,0,0,0,0,0,0,"LET_OROR","LET_ANDAND","EQEQ","NEQ","LEQ","GEQ","LSHIFT",
"RSHIFT","NUMBER","END_TOKEN","BAD_TOKEN",
};

static const char* const letrule[] = {
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

#define YYINITSTACKSIZE 500
#define yystacksize YYSTACKSIZE
#line 105 "let.y"

/*
*/
static Token LetLexer(struct LetLex *lex, YYSTYPE* letlval);
static letValue letpwr(letValue a, letValue b);


#line 353 "let.tab.c"
#ifndef lint
static const char yysccsid[] = "@(#)yaccpar 1.9 (Berkeley) 10/31/2009";
#endif
#ifdef YYDEBUG
#ifndef YYDEBUG_LEXER_TEXT /* pointer to the text isolated by the lexer*/
#define YYDEBUG_LEXER_TEXT "YYDEBUG_LEXER_TEXT not defined"
#endif
#ifndef YYDEBUG_INDENT_STRING
#define YYDEBUG_INDENT_STRING  "|       "
#endif
#ifndef YYDEBUG_REDUCE_STRING
#define YYDEBUG_REDUCE_STRING  "+-------"
#endif

#ifndef YYDEBUG_INDENT
void YYDEBUG_INDENT(int yyindent)
{
    while(yyindent-- > 0) {
        printf("%s", YYDEBUG_INDENT_STRING);
    }
}
#endif /* YYDEBUG_INDENT */

#ifndef YYDEBUG_REDUCE
void YYDEBUG_REDUCE (int yynew_state, int yyrule_num, const char * yyrule_string, int yynew_indent, int yyrhs_count)
{
    if (1 < yyrhs_count)
    {  /* draw the graphics for the reduction */
        YYDEBUG_INDENT(yynew_indent);
        while(1 < yyrhs_count--) {
            printf("%s", YYDEBUG_REDUCE_STRING);
        }
        putchar('+'); /* left rotated L would look nice */
        putchar('\n');
        YYDEBUG_INDENT(yynew_indent);
        putchar('|'); /* down arrow would look nice */
        putchar('\n');
    }
    YYDEBUG_INDENT(yynew_indent);
    /* Only print the resulting token name */
    while (*yyrule_string && ' ' != *yyrule_string) {
        putchar(*yyrule_string++);
    }
    putchar('\n');
}
#endif /* YYDEBUG_REDUCE */

#ifndef YYDEBUG_SHIFT_LEXEME
void YYDEBUG_SHIFT_LEXEME(int yyold_state, int yynew_state, const char * yytoken_string, int yynew_indent)
{
    YYDEBUG_INDENT(yynew_indent);
    printf("%s <-- `%s'\n", yytoken_string, YYDEBUG_LEXER_TEXT);
}
#endif /*  YYDEBUG_SHIFT_LEXEME */

#ifndef YYDEBUG_LOOK_AHEAD
void YYDEBUG_LOOK_AHEAD(int yynew_state, int yytoken_num, const char * yytoken_string, int yyindent)
{
    YYDEBUG_INDENT(yyindent);
    printf("          .... look ahead at %s   `%s'\n",
           yytoken_string,
           (0 == yytoken_num)? "\0": YYDEBUG_LEXER_TEXT);
}
#endif /* YYDEBUG_LOOK_AHEAD */

#ifndef YYDEBUG_DISCARD_STATE
void YYDEBUG_DISCARD_STATE(int yynew_state, int yyindent)
{
    if (0 < yyindent)
    {  /* draw the graphics for the reduction */
        YYDEBUG_INDENT(yyindent-1);
        printf("%s", YYDEBUG_REDUCE_STRING);
        putchar('+'); /* left rotated L would look nice */
        printf("  discarding state\n");
        YYDEBUG_INDENT(yyindent-1);
        putchar('|'); /* down arrow would look nice */
        putchar('\n');
    }
    else
    {
        if (0 == yyindent) {
            printf("discarding state\n");
        } else {
            printf("no more states to discard: parser will abort\n");
        }
    }
}
#endif /* YYDEBUG_DISCARD_STATE */

#ifndef YYDEBUG_DISCARD_TOKEN
void YYDEBUG_DISCARD_TOKEN(int yynew_state, int yytoken_num, const char * yytoken_string, int yyindent)
{
    YYDEBUG_INDENT(yyindent);
    printf("discarding token %s\n", yytoken_string);
}
#endif /* YYDEBUG_DISCARD_TOKEN */

#ifndef YYDEBUG_SHIFT_ERROR_LEXEME
void YYDEBUG_SHIFT_ERROR_LEXEME(int yyold_state, int yynew_state, int yyindent)
{
    YYDEBUG_INDENT(yyindent);
    printf("error\n");
}
#endif /* YYDEBUG_SHIFT_ERROR_LEXEME */

#endif /* YYDEBUG */


#if YYDEBUG
static void print_stack(short* bottom, short* top)
{
    short* sp;
    printf("stack: ");
    for (sp = bottom; sp <= top; ++sp) {
        int i = (sp - bottom);
        short s = (*sp);
        if (sp == bottom) {
            printf("(%d:%d)", i, s);
        } else {
            printf(" (%d:%d)", i, s);
        }
    }
    printf("\n");
}
#endif

#if STACKONHEAP
static int update_stack( int* size,
    short* *yyss, short* *yyssp,
    YYSTYPE* *yyvs, YYSTYPE* *yyvsp)
{
    int offset;
    int oldSize = (*size);
    int newSize = -1;

    if ( oldSize == 0 ) {  /* new stack */
        offset = 0;
        newSize = YYINITSTACKSIZE;
        (*yyss) = 0;
        (*yyvs) = 0;
    } else if (oldSize >= YYMAXDEPTH) {
       return 0;   /* too big */
    } else {  /* grow old slack */
        offset = (*yyssp) - (*yyss);
        newSize = oldSize + oldSize/2 + 1;
        if (newSize > YYMAXDEPTH) {;
            newSize = YYMAXDEPTH; /* not too much */
        }
    }
    short* ss = (short*)realloc((*yyss), newSize);
    if (!ss) {
       return 0;
    }
    (*yyss)  = ss; /* update immediately for later free */
    (*yyssp) = ss + offset;

    YYSTYPE* vs = (YYSTYPE*)realloc((*yyvs), newSize);
    if (!vs) {
        return 0;
    }
    (*yyvs)  = vs;
    (*yyvsp) = vs + offset;
    (*size)  = newSize;
    return 1;
}
#endif

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYREENTRANT
#define YYREENTRANT 1
#endif

#if YYREENTRANT
#ifndef YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_ARG
#endif
#define yy_lex() yylex(&yylval)
#else
#ifndef YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_ARG void
#endif
extern YYSTYPE yylval;
extern int yylex(void);
#define yy_lex() yylex()
#endif


#if YYREENTRANT
int yyparse_r( int(*yylex)(YYSTYPE*)
            YYPARSE_PARAM_ARG )
#else
int yyparse( YYPARSE_PARAM_ARG )
#endif
{
#if YYDEBUG
    int yydebug = 0;
#endif
    int yynerrs = 0;
    int yyerrflag = 0;
    int yychar = 0;
    short *yyssp = 0;
    YYSTYPE *yyvsp = 0;
    YYSTYPE yyval;
#if YYREENTRANT
    YYSTYPE yylval;
#endif
    short yyss[YYSTACKSIZE];
    YYSTYPE yyvs[YYSTACKSIZE];

    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;
    /* extern char *getenv(const char*); */

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
        if ((yychar = yy_lex()) < 0)
            yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN)
                yys = yyname[yychar];
            if (!yys)
                yys = "illegal-symbol";
            if (5 > yydebug) {
                print_stack(yyss, yyssp);
                printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
            } else {
                YYDEBUG_LOOK_AHEAD(yystate, yychar, yys, yyssp-yyss);
            }
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug) {
            if (5 > yydebug) {
                print_stack(yyss, yyssp);
                printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
            } else {
                YYDEBUG_SHIFT_LEXEME(yystate, yytable[yyn], yys, yyssp-yyss);
            }
        }
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yyssp = yystate;
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
                if (yydebug) {
                    if (5 > yydebug) {
                        print_stack(yyss, yyssp);
                        printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
                    } else {
                        YYDEBUG_SHIFT_ERROR_LEXEME(*yyssp, yytable[yyn], yyssp-yyss);
                    }
                }
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
                if (yydebug) {
                    if (5 > yydebug) {
                        print_stack(yyss, yyssp);
                        printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
                    } else {
                        YYDEBUG_DISCARD_STATE(*yyssp, yyssp-yyss-1);
                    }
                }
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
            if (5 > yydebug) {
                print_stack(yyss, yyssp);
                printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
            } else {
                YYDEBUG_DISCARD_TOKEN(yystate, yychar, yys, yyssp-yyss);
            }
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug) {
        if (5 > yydebug) {
            print_stack(yyss, yyssp);
            printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
        } else {
            YYDEBUG_REDUCE(yystate, yyn, yyrule[yyn], yyssp-yyss-yym, yym);
        }
    }
#endif
    yym = yylen[yyn];
    if (yym >= 1) { /* For zero length rules, avoid $$ = $1. */
        yyval = yyvsp[1-yym];
    }
    switch (yyn)
    {
case 1:
#line 58 "let.y"
{ letResult = yyvsp[0].m_Val; }
break;
case 2:
#line 60 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val || yyvsp[0].m_Val; }
break;
case 3:
#line 61 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val && yyvsp[0].m_Val; }
break;
case 4:
#line 62 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val | yyvsp[0].m_Val; }
break;
case 5:
#line 63 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val ^ yyvsp[0].m_Val; }
break;
case 6:
#line 64 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val & yyvsp[0].m_Val; }
break;
case 7:
#line 65 "let.y"
{ yyval.m_Val = (yyvsp[-2].m_Val == yyvsp[0].m_Val); }
break;
case 8:
#line 66 "let.y"
{ yyval.m_Val = (yyvsp[-2].m_Val != yyvsp[0].m_Val); }
break;
case 9:
#line 67 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val > yyvsp[0].m_Val; }
break;
case 10:
#line 68 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val < yyvsp[0].m_Val; }
break;
case 11:
#line 69 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val <= yyvsp[0].m_Val; }
break;
case 12:
#line 70 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val >= yyvsp[0].m_Val; }
break;
case 13:
#line 72 "let.y"
{ letValue v3 = yyvsp[0].m_Val;
          yyval.m_Val = (v3 >= 0) ? (yyvsp[-2].m_Val << v3) : (yyvsp[-2].m_Val >> (-v3));
        }
break;
case 14:
#line 76 "let.y"
{ letValue v3 = yyvsp[0].m_Val; 
          yyval.m_Val = (v3>=0) ? (yyvsp[-2].m_Val >> v3) : (yyvsp[-2].m_Val << (-v3));
        }
break;
case 15:
#line 79 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val + yyvsp[0].m_Val; }
break;
case 16:
#line 80 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val - yyvsp[0].m_Val; }
break;
case 17:
#line 81 "let.y"
{ yyval.m_Val = yyvsp[-2].m_Val * yyvsp[0].m_Val; }
break;
case 18:
#line 83 "let.y"
{ long v3 = yyvsp[0].m_Val;
          if (v3 == 0) { leterror("Division by 0"); }
          yyval.m_Val = yyvsp[-2].m_Val / (v3);
        }
break;
case 19:
#line 88 "let.y"
{ long v3 = yyvsp[0].m_Val;
          if (v3 == 0) { leterror("Module by 0"); }
          yyval.m_Val = yyvsp[-2].m_Val % (v3);
        }
break;
case 20:
#line 93 "let.y"
{ long v3 = yyvsp[0].m_Val;
          if (v3 < 0) { leterror("Negative power"); }
          yyval.m_Val = letpwr(yyvsp[-2].m_Val, v3);
        }
break;
case 21:
#line 97 "let.y"
{ yyval.m_Val = yyvsp[-1].m_Val; }
break;
case 22:
#line 98 "let.y"
{ 
          letValue v = yyvsp[0].m_Val;
         yyval.m_Val = v; 
     }
break;
#line 853 "let.tab.c"
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
        if (yydebug) {
            print_stack(yyss, yyssp);
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yy_lex()) < 0)
                yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN)
                    yys = yyname[yychar];
                if (!yys)
                    yys = "illegal-symbol";
                print_stack(yyss, yyssp);
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
    if (yydebug) {
        print_stack(yyss, yyssp);
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
    }
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

