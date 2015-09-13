/* process with "byacc -b let -p let let.y */

%{

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

/*
*/
static Token LetLexer(struct LetLex *lex, YYSTYPE* letlval);
static letValue letpwr(letValue a, letValue b);


