#ifndef lint
static char const yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
/* cfront 1.2 defines "c_plusplus" instead of "__cplusplus" */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
extern "C" { char *getenv(const char *); }
#else
extern char *getenv();
extern int yylex();
extern int yyparse();
#endif
#define YYPREFIX "yy"
#line 8 "parse.y"
#include "rc.h"
#ifndef lint
#define lint		/* hush up gcc -Wall, leave out the dumb sccsid's. */
#endif
static Node *star, *nolist;
Node *parsetree;	/* not using yylval because bison declares it as an auto */
#line 28 "parse.y"
typedef union {
	struct Node *node;
	struct Redir redir;
	struct Pipe pipe;
	struct Dup dup;
	struct Word word;
	char *keyword;
} YYSTYPE;
#line 43 "y.tab.c"
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
const short yylhs[] = {                                        -1,
    0,    0,   22,   22,    8,    8,   13,   13,    3,    3,
    9,    9,    4,   15,    2,   11,   11,   16,   16,   16,
    5,    5,    6,    6,    6,   19,   19,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,   24,   24,   18,   18,   18,
   12,   12,   17,   17,   20,   20,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,   21,   21,
   14,   14,   14,   23,   23,
};
const short yylen[] = {                                         2,
    2,    2,    1,    1,    2,    2,    1,    2,    1,    2,
    1,    2,    3,    3,    3,    0,    2,    1,    2,    2,
    3,    3,    1,    2,    2,    1,    4,    0,    1,    2,
    4,    8,    6,    4,    8,    4,    4,    4,    4,    2,
    2,    3,    3,    3,    2,    0,    1,    1,    2,    2,
    1,    3,    1,    1,    1,    3,    2,    5,    2,    2,
    2,    2,    3,    3,    3,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    0,    2,
    0,    2,    2,    0,    2,
};
const short yydefred[] = {                                      0,
    0,    0,    0,    0,   18,    0,   79,    0,    0,    0,
    0,    0,    0,    0,    0,   67,    0,    0,   81,    0,
    0,    0,    0,    0,    0,   51,    0,    0,    0,    0,
    3,    4,    2,   77,   75,   74,   73,   68,   71,   69,
    0,   78,   72,   76,   70,   54,   53,   55,    0,   47,
    0,   59,   60,    0,    0,    0,   84,   66,    0,    0,
    0,    0,    0,   84,    0,    0,    0,   11,    0,    0,
   62,   61,    0,    0,   30,    0,   84,   84,   84,    5,
    6,    8,    0,    0,    1,    0,   50,    0,    0,   63,
   64,    0,   44,    0,    0,    0,    0,    0,    0,    0,
    0,   79,   13,   12,   10,   65,   82,    0,   17,    0,
    0,    0,    0,   52,   56,   79,   84,   14,   85,    0,
    0,   31,   84,    0,    0,    0,    0,    0,   39,    0,
    0,   84,    0,   58,   84,    0,    0,    0,    0,    0,
   79,    0,    0,    0,    0,    0,    0,   24,   35,   25,
   22,   21,
};
const short yydgoto[] = {                                      21,
   46,   22,   66,   23,  142,  143,   67,   68,   69,   47,
   75,   27,   28,   70,   57,   29,   48,   30,  122,   94,
   54,   33,   97,   51,
};
const short yysindex[] = {                                    874,
   24, 1001,  -82, 1001,    0, 1001,    0,  -27,  -26,  900,
 1001,  -82,  -20,  -82,  -26,    0, 1001, 1134,    0,  900,
    0, 1134, -203,  -30, 1134,    0,  -55,   24, 1134,  826,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -66,    0,    0,    0,    0,    0,    0,    0,  849,    0,
 1134,    0,    0,  900, 1001, 1134,    0,    0,  -52,  -52,
 1134, 1001, 1001,    0, -212,  -58,  154,    0, 1134,  426,
    0,    0, -196, 1001,    0, -203,    0,    0,    0,    0,
    0,    0, 1001, 1001,    0, -196,    0,  -52, 1001,    0,
    0, -196,    0,  -52,  -38,   36,  502, -196,  -36,  -52,
  502,    0,    0,    0,    0,    0,    0,  -52,    0,  502,
  502,  502,  -52,    0,    0,    0,    0,    0,    0,  -97,
 -234,    0,    0, 1001, -234,  922, -196, -196,    0,  944,
  502,    0,   -9,    0,    0, -234,  502,  967,  502, -234,
    0,  967,  -45,  154,  967, -234,  448,    0,    0,    0,
    0,    0,
};
const short yyrindex[] = {                                    134,
    0,    0,  356,    0,    0,    0,    0,    0,    0,    0,
    0,  356,    0, 1024,    0,    0,    0,  571,    0,    0,
    0,  487,  529,   54,  134,    0,   62,    0,  487,  548,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  487,    0,    0,  712,    0,  142,    0,    0,   14,   38,
  487,    0,    0,    0,  -10,    0,  -32,    0,  744,    0,
    0,    0,  749,    0,    0,  529,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  763,    0,   86,    0,    0,
    0,  779,    0,  110,    0,    0,  -34,  788,    0,  380,
  -34,    0,    0,    0,    0,    0,    0,  470,    0,  -34,
  -34,  -34,  404,    0,    0,    0,    0,    0,    0,  529,
    6,    0,    0,  724,   30,    0,  805,  813,    0,    0,
  -34,    0,    0,    0,    0,  119,  -34,  571,  -34,  187,
    0,  571,    0,  -44,  571,  396,    0,    0,    0,    0,
    0,    0,
};
const short yygindex[] = {                                      0,
    0,    0,  -23,   12,    0, -104, 1319,    2, -127, 1307,
    7,    0,   57,    0,   70,  -13,   84,    0,    0,  420,
  -81,   59,  369,   31,
};
#define YYTABLESIZE 1464
const short yytable[] = {                                      57,
  119,   25,  117,   28,  123,   83,   28,   81,    9,   76,
  145,   50,   55,   56,  145,   26,   87,  145,  124,   62,
  126,   58,   77,   19,   28,   57,   25,   57,   80,   57,
   57,   71,   96,   32,  130,   78,   79,  148,   84,   34,
  150,   89,   61,   26,   63,  105,   26,   20,   57,   19,
   57,   19,   58,   19,   19,   89,   18,   89,    5,  147,
   90,  102,   76,    7,   26,   93,  103,   34,   74,   11,
   34,   48,   19,   20,   79,   20,  118,   20,   20,  149,
   23,   82,  109,   57,   64,   57,   85,   52,   34,   53,
   28,    0,    9,    0,    0,   49,   20,   48,    0,   48,
   65,   48,   48,   72,    0,    0,   76,    0,  120,   19,
    0,    0,   57,  138,   57,    0,    0,    0,    0,   80,
   48,   49,    0,   49,    0,   49,   49,    0,   33,    0,
   26,    0,   91,   20,    0,    0,   19,    0,   19,    0,
    0,    0,    0,   28,   49,   80,    0,   80,    0,   80,
   80,   28,    0,    0,   34,    0,   33,   48,    0,   33,
   20,    0,   20,  104,    5,  132,    0,  114,   80,    0,
    0,   28,  115,    0,   74,   11,    0,   33,    0,   28,
    0,   49,   28,    0,    0,    0,   48,    0,    0,    0,
    0,   81,   28,    0,    0,    0,   27,    0,    0,    0,
   28,    0,    0,    0,    0,   80,    0,    0,    0,    0,
   49,    0,   80,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,    0,   27,    0,   77,   27,    0,   28,
  116,    0,   80,    0,   80,   28,   28,    0,    0,   78,
   79,    0,    0,   33,    0,   27,   57,   57,   57,   57,
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
   49,   49,   49,   49,   49,   46,   80,   80,   80,   80,
   80,    0,   80,   80,   80,   80,   80,   80,   80,   80,
   80,   80,   33,    0,   80,   80,   80,   80,   80,   79,
   28,   46,    0,   46,    0,   46,   46,   28,   28,    0,
    0,    0,    0,   28,   28,   32,    0,    0,    0,    0,
   77,   28,   28,   15,   46,   79,    0,   79,    0,   79,
   79,   49,    0,   78,   79,    0,    0,    0,    0,   59,
   60,    0,  101,   32,    0,  107,   32,    0,   79,   15,
    0,   15,    0,   15,   15,  110,  111,  112,    0,   88,
   27,   46,    0,    0,   32,    0,    0,  151,    0,    0,
    0,   17,   15,    0,    0,   19,  106,    0,    0,    0,
    0,    0,    0,    0,   95,   79,    0,    0,   46,   83,
   46,   99,  100,   17,    0,  131,    0,   19,    0,  108,
    0,  133,    0,   59,    0,    0,   28,    0,    0,   15,
  137,    0,  113,  139,   79,   83,  152,    0,    0,   83,
   83,  119,    0,    0,    0,    0,    0,    0,    0,    0,
   32,   20,    0,    0,   28,    0,   15,   28,   15,    0,
    0,    0,    0,    0,    0,    0,    0,   17,   16,    0,
    0,   19,    0,   20,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,    0,
    0,    0,    0,    0,    0,   83,   16,    0,    0,   16,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    0,    0,    0,    0,   29,    0,   16,   29,    0,
    0,    0,    0,    0,    0,    0,    0,   20,    0,    0,
    0,    0,    0,    0,    0,    0,   29,    0,   28,    0,
    0,   28,   46,   46,   46,    0,   46,   46,    0,   46,
   46,   46,   46,   46,   18,   46,   46,   46,   46,   28,
   46,   46,   46,   46,   46,    0,   79,   79,   79,   79,
   79,    0,   79,   79,   79,   79,   79,   79,   79,   79,
   79,   79,    0,   16,   79,   79,   79,   79,   79,   32,
   15,   15,   15,    0,   15,   15,    0,   15,   15,   15,
   15,   15,   29,   15,   15,   15,   15,    0,   15,   15,
   15,   15,   15,    2,   34,   35,    4,    0,   36,    0,
    6,   37,   38,   39,   40,   28,    0,   41,    0,    0,
   42,   43,   44,   45,   16,    2,   34,   35,    4,    0,
   36,    0,    6,   37,   38,   39,   40,    0,    0,   41,
    0,   45,   42,   43,   44,   45,   16,   83,   83,   83,
   83,    0,   83,   36,   83,   83,   83,   83,   83,    0,
    0,   83,    0,   28,   83,   83,   83,   83,   83,   45,
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
    0,    0,   89,    0,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   17,    0,    0,
    0,   19,  134,    0,    0,    0,    0,    0,   45,   20,
    0,   18,    0,    0,    0,   45,    0,    0,    0,   17,
   36,   45,   45,   19,  135,    0,    0,   36,    0,    0,
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
   44,   45,   16,    0,    2,    3,  141,    4,    5,   20,
    0,    6,    7,    8,    9,    0,    0,    0,   10,   11,
    0,   12,   13,   14,   15,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   18,    0,    2,   34,
   35,    4,    0,   36,    0,    6,   37,   38,   39,   40,
    0,    0,   41,    0,    0,   42,   43,   44,   45,   16,
    0,   46,   46,   46,   46,    0,   46,    0,   46,   46,
   46,   46,   46,    0,    0,   46,    0,    0,   46,   46,
   46,   46,   46,    0,    0,    0,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   24,    0,
    0,    0,    0,    0,   26,    0,    0,    0,   26,    0,
    0,   26,    0,    0,    0,   26,    0,    0,    0,    0,
   73,    0,    0,   24,    0,    0,    0,   86,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,   26,    0,    0,    0,    0,   26,    0,   92,
    0,    0,    0,    0,    0,   26,    0,    0,    0,   98,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    3,    0,    4,    5,    0,    0,    6,    7,
    8,    9,    0,   26,    0,   10,   11,   26,   12,   13,
   14,   15,   16,    0,    0,  121,   26,   26,   26,  125,
    0,    0,    0,    0,    0,    0,    0,    0,  127,  128,
  129,    0,    0,    0,    0,    0,    0,   26,    0,    0,
    0,    0,    0,   26,   26,   26,    0,    0,   26,  136,
    0,   26,    0,    0,    0,  140,  144,  146,    0,    0,
  144,    0,    0,  144,
};
const short yycheck[] = {                                      10,
   10,    0,   41,   38,   41,   61,   41,   38,   41,   23,
  138,   94,   40,   40,  142,   10,   30,  145,  100,   40,
  102,   10,  257,   10,   59,   36,   25,   38,   59,   40,
   41,   20,   56,   10,  116,  270,  271,  142,   94,   10,
  145,   94,   12,   38,   14,   69,   41,   10,   59,   36,
   61,   38,   41,   40,   41,   94,  123,   94,  262,  141,
   49,  274,   76,   10,   59,   54,  125,   38,  272,  273,
   41,   10,   59,   36,  271,   38,   41,   40,   41,  125,
  125,   25,   76,   94,   15,   96,   28,    4,   59,    6,
  125,   -1,  125,   -1,   -1,   10,   59,   36,   -1,   38,
   17,   40,   41,   20,   -1,   -1,  120,   -1,   97,   96,
   -1,   -1,  123,  123,  125,   -1,   -1,   -1,   -1,   10,
   59,   36,   -1,   38,   -1,   40,   41,   -1,   10,   -1,
  125,   -1,   49,   96,   -1,   -1,  123,   -1,  125,   -1,
   -1,   -1,   -1,   10,   59,   36,   -1,   38,   -1,   40,
   41,   10,   -1,   -1,  125,   -1,   38,   96,   -1,   41,
  123,   -1,  125,   10,  262,  263,   -1,   84,   59,   -1,
   -1,   38,   89,   -1,  272,  273,   -1,   59,   -1,   38,
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
  257,   36,   -1,   38,   -1,   40,   41,  264,  257,   -1,
   -1,   -1,   -1,  270,  271,   10,   -1,   -1,   -1,   -1,
  257,  270,  271,   10,   59,   36,   -1,   38,   -1,   40,
   41,    2,   -1,  270,  271,   -1,   -1,   -1,   -1,   10,
   11,   -1,   64,   38,   -1,   10,   41,   -1,   59,   36,
   -1,   38,   -1,   40,   41,   77,   78,   79,   -1,   30,
  264,   96,   -1,   -1,   59,   -1,   -1,   10,   -1,   -1,
   -1,   36,   59,   -1,   -1,   40,   41,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   55,   96,   -1,   -1,  123,   10,
  125,   62,   63,   36,   -1,  117,   -1,   40,   -1,   70,
   -1,  123,   -1,   74,   -1,   -1,   10,   -1,   -1,   96,
  132,   -1,   83,  135,  125,   36,   59,   -1,   -1,   40,
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
  277,  278,  279,   -1,   -1,   -1,    0,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,    0,   -1,
   -1,   -1,   -1,   -1,   18,   -1,   -1,   -1,   22,   -1,
   -1,   25,   -1,   -1,   -1,   29,   -1,   -1,   -1,   -1,
   22,   -1,   -1,   25,   -1,   -1,   -1,   29,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   51,   -1,   -1,
   -1,   -1,   56,   -1,   -1,   -1,   -1,   61,   -1,   51,
   -1,   -1,   -1,   -1,   -1,   69,   -1,   -1,   -1,   61,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  258,  259,   -1,  261,  262,   -1,   -1,  265,  266,
  267,  268,   -1,   97,   -1,  272,  273,  101,  275,  276,
  277,  278,  279,   -1,   -1,   97,  110,  111,  112,  101,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  110,  111,
  112,   -1,   -1,   -1,   -1,   -1,   -1,  131,   -1,   -1,
   -1,   -1,   -1,  137,  138,  139,   -1,   -1,  142,  131,
   -1,  145,   -1,   -1,   -1,  137,  138,  139,   -1,   -1,
  142,   -1,   -1,  145,
};
#define YYFINAL 21
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'$'",0,"'&'",0,"'('","')'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,
"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'^'",0,
"'`'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"ANDAND","BACKBACK","BANG","CASE","COUNT","DUP","ELSE","END",
"FLAT","FN","FOR","IF","IN","OROR","PIPE","REDIR","SREDIR","SUB","SUBSHELL",
"SWITCH","TWIDDLE","WHILE","WORD","HUH",
};
const char * const yyrule[] = {
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
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 169 "parse.y"

void initparse() {
	star = treecpy(mk(nVar,mk(nWord,"*",NULL)), ealloc);
	nolist = treecpy(mk(nVar,mk(nWord,"ifs",NULL)), ealloc);
}

#line 590 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
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
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
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
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
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
                *++yyssp = yystate = yytable[yyn];
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
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
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
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 49 "parse.y"
{ parsetree = yyvsp[-1].node; YYACCEPT; }
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
{ yyval.node = (yyvsp[-1].node != NULL ? mk(nNowait,yyvsp[-1].node) : yyvsp[-1].node); }
break;
case 8:
#line 62 "parse.y"
{ yyval.node = (yyvsp[-1].node != NULL ? mk(nBody,yyvsp[-1].node,yyvsp[0].node) : yyvsp[0].node); }
break;
case 10:
#line 66 "parse.y"
{ yyval.node = (yyvsp[-1].node == NULL ? yyvsp[0].node : yyvsp[0].node == NULL ? yyvsp[-1].node : mk(nBody,yyvsp[-1].node,yyvsp[0].node)); }
break;
case 12:
#line 69 "parse.y"
{ yyval.node = yyvsp[-1].node; if (!heredoc(0)) YYABORT; }
break;
case 13:
#line 71 "parse.y"
{ yyval.node = yyvsp[-1].node; }
break;
case 14:
#line 73 "parse.y"
{ yyval.node = yyvsp[-1].node; }
break;
case 15:
#line 75 "parse.y"
{ yyval.node = mk(nAssign,yyvsp[-2].node,yyvsp[0].node); }
break;
case 16:
#line 77 "parse.y"
{ yyval.node = NULL; }
break;
case 17:
#line 78 "parse.y"
{ yyval.node = mk(nEpilog,yyvsp[-1].node,yyvsp[0].node); }
break;
case 18:
#line 81 "parse.y"
{ yyval.node = mk(nDup,yyvsp[0].dup.type,yyvsp[0].dup.left,yyvsp[0].dup.right); }
break;
case 19:
#line 82 "parse.y"
{ yyval.node = mk(nRedir,yyvsp[-1].redir.type,yyvsp[-1].redir.fd,yyvsp[0].node);
				  if (yyvsp[-1].redir.type == rHeredoc && !qdoc(yyvsp[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 20:
#line 85 "parse.y"
{ yyval.node = mk(nRedir,yyvsp[-1].redir.type,yyvsp[-1].redir.fd,yyvsp[0].node);
				  if (yyvsp[-1].redir.type == rHeredoc && !qdoc(yyvsp[0].node, yyval.node)) YYABORT; /* queue heredocs up */
				}
break;
case 21:
#line 89 "parse.y"
{ yyval.node = mk(nCase, yyvsp[-1].node); }
break;
case 22:
#line 90 "parse.y"
{ yyval.node = mk(nCase, yyvsp[-1].node); }
break;
case 23:
#line 92 "parse.y"
{ yyval.node = mk(nCbody, yyvsp[0].node, NULL); }
break;
case 24:
#line 93 "parse.y"
{ yyval.node = mk(nCbody, yyvsp[-1].node, yyvsp[0].node); }
break;
case 25:
#line 94 "parse.y"
{ yyval.node = mk(nCbody, yyvsp[-1].node, yyvsp[0].node); }
break;
case 27:
#line 97 "parse.y"
{ yyval.node = mk(nElse,yyvsp[-3].node,yyvsp[0].node); }
break;
case 28:
#line 99 "parse.y"
{ yyval.node = NULL; }
break;
case 30:
#line 101 "parse.y"
{ yyval.node = mk(nBrace,yyvsp[-1].node,yyvsp[0].node); }
break;
case 31:
#line 102 "parse.y"
{ yyval.node = mk(nIf,yyvsp[-2].node,yyvsp[0].node); }
break;
case 32:
#line 103 "parse.y"
{ yyval.node = mk(nForin,yyvsp[-5].node,yyvsp[-3].node,yyvsp[0].node); }
break;
case 33:
#line 104 "parse.y"
{ yyval.node = mk(nForin,yyvsp[-3].node,star,yyvsp[0].node); }
break;
case 34:
#line 105 "parse.y"
{ yyval.node = mk(nWhile,yyvsp[-2].node,yyvsp[0].node); }
break;
case 35:
#line 106 "parse.y"
{ yyval.node = mk(nSwitch,yyvsp[-5].node,yyvsp[-1].node); }
break;
case 36:
#line 107 "parse.y"
{ yyval.node = mk(nMatch,yyvsp[-1].node,yyvsp[0].node); }
break;
case 37:
#line 108 "parse.y"
{ yyval.node = mk(nAndalso,yyvsp[-3].node,yyvsp[0].node); }
break;
case 38:
#line 109 "parse.y"
{ yyval.node = mk(nOrelse,yyvsp[-3].node,yyvsp[0].node); }
break;
case 39:
#line 110 "parse.y"
{ yyval.node = mk(nPipe,yyvsp[-2].pipe.left,yyvsp[-2].pipe.right,yyvsp[-3].node,yyvsp[0].node); }
break;
case 40:
#line 111 "parse.y"
{ yyval.node = (yyvsp[0].node != NULL ? mk(nPre,yyvsp[-1].node,yyvsp[0].node) : yyvsp[-1].node); }
break;
case 41:
#line 112 "parse.y"
{ yyval.node = (yyvsp[0].node != NULL ? mk(nPre,yyvsp[-1].node,yyvsp[0].node) : yyvsp[-1].node); }
break;
case 42:
#line 113 "parse.y"
{ yyval.node = mk(nBang,yyvsp[0].node); }
break;
case 43:
#line 114 "parse.y"
{ yyval.node = mk(nSubshell,yyvsp[0].node); }
break;
case 44:
#line 115 "parse.y"
{ yyval.node = mk(nNewfn,yyvsp[-1].node,yyvsp[0].node); }
break;
case 45:
#line 116 "parse.y"
{ yyval.node = mk(nRmfn,yyvsp[0].node); }
break;
case 49:
#line 122 "parse.y"
{ yyval.node = (yyvsp[0].node != NULL ? mk(nArgs,yyvsp[-1].node,yyvsp[0].node) : yyvsp[-1].node); }
break;
case 50:
#line 123 "parse.y"
{ yyval.node = mk(nArgs,yyvsp[-1].node,yyvsp[0].node); }
break;
case 52:
#line 126 "parse.y"
{ yyval.node = mk(nConcat,yyvsp[-2].node,yyvsp[0].node); }
break;
case 54:
#line 129 "parse.y"
{ yyval.node = mk(nWord,yyvsp[0].keyword, NULL); }
break;
case 56:
#line 132 "parse.y"
{ yyval.node = mk(nConcat,yyvsp[-2].node,yyvsp[0].node); }
break;
case 57:
#line 134 "parse.y"
{ yyval.node = mk(nVar,yyvsp[0].node); }
break;
case 58:
#line 135 "parse.y"
{ yyval.node = mk(nVarsub,yyvsp[-3].node,yyvsp[-1].node); }
break;
case 59:
#line 136 "parse.y"
{ yyval.node = mk(nCount,yyvsp[0].node); }
break;
case 60:
#line 137 "parse.y"
{ yyval.node = mk(nFlat, yyvsp[0].node); }
break;
case 61:
#line 138 "parse.y"
{ yyval.node = mk(nBackq,nolist,yyvsp[0].node); }
break;
case 62:
#line 139 "parse.y"
{ yyval.node = mk(nBackq,nolist,yyvsp[0].node); }
break;
case 63:
#line 140 "parse.y"
{ yyval.node = mk(nBackq,yyvsp[-1].node,yyvsp[0].node); }
break;
case 64:
#line 141 "parse.y"
{ yyval.node = mk(nBackq,yyvsp[-1].node,yyvsp[0].node); }
break;
case 65:
#line 142 "parse.y"
{ yyval.node = yyvsp[-1].node; }
break;
case 66:
#line 143 "parse.y"
{ yyval.node = mk(nNmpipe,yyvsp[-1].redir.type,yyvsp[-1].redir.fd,yyvsp[0].node); }
break;
case 67:
#line 144 "parse.y"
{ yyval.node = (yyvsp[0].word.w[0] == '\'') ? mk(nQword, yyvsp[0].word.w+1, NULL) : mk(nWord,yyvsp[0].word.w, yyvsp[0].word.m); }
break;
case 68:
#line 146 "parse.y"
{ yyval.keyword = "for"; }
break;
case 69:
#line 147 "parse.y"
{ yyval.keyword = "in"; }
break;
case 70:
#line 148 "parse.y"
{ yyval.keyword = "while"; }
break;
case 71:
#line 149 "parse.y"
{ yyval.keyword = "if"; }
break;
case 72:
#line 150 "parse.y"
{ yyval.keyword = "switch"; }
break;
case 73:
#line 151 "parse.y"
{ yyval.keyword = "fn"; }
break;
case 74:
#line 152 "parse.y"
{ yyval.keyword = "else"; }
break;
case 75:
#line 153 "parse.y"
{ yyval.keyword = "case"; }
break;
case 76:
#line 154 "parse.y"
{ yyval.keyword = "~"; }
break;
case 77:
#line 155 "parse.y"
{ yyval.keyword = "!"; }
break;
case 78:
#line 156 "parse.y"
{ yyval.keyword = "@"; }
break;
case 79:
#line 158 "parse.y"
{ yyval.node = NULL; }
break;
case 80:
#line 159 "parse.y"
{ yyval.node = (yyvsp[-1].node != NULL ? (yyvsp[0].node != NULL ? mk(nLappend,yyvsp[-1].node,yyvsp[0].node) : yyvsp[-1].node) : yyvsp[0].node); }
break;
case 81:
#line 161 "parse.y"
{ yyval.node = NULL; }
break;
case 83:
#line 163 "parse.y"
{ yyval.node = (yyvsp[-1].node != NULL ? (yyvsp[0].node != NULL ? mk(nLappend,yyvsp[-1].node,yyvsp[0].node) : yyvsp[-1].node) : yyvsp[0].node); }
break;
#line 1015 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
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
            if ((yychar = yylex()) < 0) yychar = 0;
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
