/* process with "byacc -b let -p let let.y */

%{

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

%}


%union {
	letValue m_Val;
}

/* Non-terminals */
%type <m_Val> expr

/* Tokens */
%left LET_OROR
%left LET_ANDAND
%left '|'
%left '^'
%left '&'
%nonassoc EQEQ NEQ 
%nonassoc '<' '>' LEQ GEQ
%nonassoc LSHIFT RSHIFT 
%left '+' '-'
%left '*' '/' '%'
%right '@'


%token <m_Val> NUMBER
%token END_TOKEN BAD_TOKEN



%start top

%%
top: expr   { letResult = $1; } ;

expr: expr LET_OROR expr    { $$ = $1 || $3; }
    | expr LET_ANDAND  expr { $$ = $1 && $3; }
    | expr '|' expr  { $$ = $1 | $3; } ;
    | expr '^' expr { $$ = $1 ^ $3; } ;
    | expr '&' expr     { $$ = $1 & $3; } ;
    | expr EQEQ expr { $$ = ($1 == $3); }
	| expr NEQ expr  { $$ = ($1 != $3); }
	| expr '>' expr { $$ = $1 > $3; }
	| expr '<' expr { $$ = $1 < $3; }
    | expr LEQ expr { $$ = $1 <= $3; }
	| expr GEQ expr { $$ = $1 >= $3; }
	| expr LSHIFT expr 
		{ letValue v3 = $3;
		  $$ = (v3 >= 0) ? ($1 << v3) : ($1 >> (-v3));
		}
	| expr RSHIFT expr
		{ letValue v3 = $3; 
		  $$ = (v3>=0) ? ($1 >> v3) : ($1 << (-v3));
		}
	| expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
	| expr '*' expr    { $$ = $1 * $3; }
	| expr '/' expr
		{ long v3 = $3;
		  if (v3 == 0) { leterror("Division by 0"); }
		  $$ = $1 / (v3);
		}
	| expr '%' expr
		{ long v3 = $3;
		  if (v3 == 0) { leterror("Module by 0"); }
		  $$ = $1 % (v3);
		}
	| expr '@' expr
		{ long v3 = $3;
		  if (v3 < 0) { leterror("Negative power"); }
		  $$ = letpwr($1, v3);
		}
     | '(' expr ')'    { $$ = $2; }
	 |  NUMBER { 
          letValue v = $1;
         $$ = v; 
     }
	 ;

%%



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


