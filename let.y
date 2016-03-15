/* process with "byacc -b let -p let let.y */

%{

extern int printf(const char *, ...);

#include "let.h"




#define letparse(a)  LetParser(struct LetLex *lex)
#define letparse_r(a)  LetParser(struct LetLex *lex)
#define letlex(a)  LetLexer(lex, &letlval)


%}


%union {
    LetValue m_Val;
}

/* Non-terminals */
%type <m_Val> expr

/* Tokens */
%left LET_OROR
%left LET_ANDAND
%left '|'
%left '^'
%left '&'
%left EQEQ NEQ 
%left '<' '>' LEQ GEQ
%left LSHIFT RSHIFT 
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' UNARY_PLUSMINUS
%right '@'


%token <m_Val> NUMBER
%token END_TOKEN BAD_TOKEN

%pure-parser


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
        { LetValue v3 = $3;
          $$ = (v3 >= 0) ? ($1 << v3) : ($1 >> (-v3));
        }
    | expr RSHIFT expr
        { LetValue v3 = $3; 
          $$ = (v3>=0) ? ($1 >> v3) : ($1 << (-v3));
        }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr    { $$ = $1 * $3; }
    | expr '/' expr
        { long v3 = $3;
          if (v3 == 0) {
            leterror("Division by 0");
            YYABORT;
          }
          $$ = $1 / (v3);
        }
    | expr '%' expr
        { long v3 = $3;
          if (v3 == 0) {
            leterror("Module by 0");
            YYABORT;
          }
          $$ = $1 % (v3);
        }
    | '!' expr  { $$ = !$2; }
    | '~' expr  { $$ = ~$2; }
    | '-' expr %prec UNARY_PLUSMINUS { $$ = -$2; }
    | '+' expr %prec UNARY_PLUSMINUS { $$ = +$2; }
    | expr '@' expr
        { long v3 = $3;
          if (v3 < 0) {
            if (! YYRECOVERING) {
              leterror("Negative power");
	    }
            YYABORT;
          }
          $$ = letpwr($1, v3);
        }
     | '(' expr ')'    { $$ = $2; }
     |  NUMBER { $$ = $1; }
     ;

%%

/*
*/


