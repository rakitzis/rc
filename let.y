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
%type <m_Val> expr logor logand bitor bitxor bitand eq cmp shift add 
%type <m_Val> sadd fmult mult pow unit

%token LET_OROR LET_ANDAND EQEQ NEQ LEQ GEQ LSHIFT RSHIFT 
%token <m_Val> NUMBER
%token END_TOKEN BAD_TOKEN

%start expr

%%
expr	: logor   { letResult = $$ = $1; }
	;

logor	: logand 
	| logor LET_OROR logand    { $$ = $1 || $3; }
	;

logand	: bitor 
	| logand LET_ANDAND  bitor { $$ = $1 && $3; }
	;

bitor	: bitxor 
	| bitor '|' bitxor  { $$ = $1 | $3; }
	;

bitxor	: bitand 
	| bitxor '^' bitand { $$ = $1 ^ $3; }
	;

bitand	: eq 
	| bitand '&' eq     { $$ = $1 & $3; }
	;

eq	: cmp 
	| cmp EQEQ cmp { $$ = ($1 == $3); }
	| cmp NEQ cmp  { $$ = ($1 != $3); }
	;

cmp	: shift 
	| shift '>' shift { $$ = $1 > $3; }
	| shift '<' shift { $$ = $1 < $3; }
        | shift LEQ shift { $$ = $1 <= $3; }
	| shift GEQ shift { $$ = $1 >= $3; }
	;

shift	: sadd 
	| shift LSHIFT sadd 
		{ letValue v3 = $3;
		  $$ = (v3 >= 0) ? ($1 << v3) : ($1 >> (-v3));
		}
	| shift RSHIFT sadd
		{ letValue v3 = $3; 
		  $$ = (v3>=0) ? ($1 >> v3) : ($1 << (-v3));
		}
	;

sadd	: fmult
	| fmult '+' add { $$ = $1 + $3; }
	| fmult '-' add { $$ = $1 - $3; }
	;

fmult	: mult
	| '-' mult { $$ = - $2; }
	| '+' mult { $$ = + $2; }
	;

add	: mult
	| add '+' mult { $$ = $1 + $3; }
        | add '-' mult { $$ = $1 - $3; }
	;

/*
presign	:
		{ $$ = 1; }
	| '+'   { $$ = 1; }
	| '-'   { $$ = -1; }
	;
*/

mult	: pow 
	| mult '*' pow    { $$ = $1 * $3; }
	| mult '/' pow
		{ long v3 = $3;
		  if (v3 == 0) { leterror("Division by 0"); }
		  $$ = $1 / (v3);
		}
	| mult '%' pow
		{ long v3 = $3;
		  if (v3 == 0) { leterror("Module by 0"); }
		  $$ = $1 % (v3);
		}
	;

pow	: unit 
	| unit '@' pow
		{ long v3 = $3;
		  if (v3 < 0) { leterror("Negative power"); }
		  $$ = letpwr($1, v3);
		}
	;

unit : '(' expr ')'    { $$ = $2; }
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

  if (lex->last_token != BAD_TOKEN) {
    tok = lex->last_token;
    lex->last_token = BAD_TOKEN;
    return tok;
  }
  p = lex->current;
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
        letlval->val = val;
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
  lex->current = p;
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
  lex.current = lex.buf = s;
  lex.last_token = BAD_TOKEN;

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


