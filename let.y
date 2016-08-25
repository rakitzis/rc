/*
 * process with
 *    byacc -t -v -d [-P] -b let -p let let.y
 * or with
 *    bison -t -v -d -b let -p let let.y
 */

%{
#include <assert.h>

extern int printf(const char *, ...);

#include "let.h"




#define letparse(a)  LetParser(LetLex *lex)
#define letparse_r(a)  LetParser(LetLex *lex)
#define letlex(a)  LetLexer(lex, &letlval)


%}


%union {
    LetValue m_Val;
}

/* Non-terminals */
%type <m_Val> expr assignment

/* Tokens */
%nonassoc '='
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
%token END_TOKEN BAD_TOKEN LET_VAR

%pure-parser


%start let

%%
let
    : expr
        {   assert('\0' == lex->m_Indent[0]);
            letResult = $1;
        }
    | assignment
        {   assert('\0' != lex->m_Indent[0]);
            letResult = $1;
        }
    ;

assignment
    : LET_VAR '=' expr
        {   assert('\0' != lex->m_Indent[0]);
            $$ = $3;
        }
    ;

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
        {   const LetValue v3 = $3;
            $$ = (v3 >= 0) ? ($1 << v3) : ($1 >> (-v3));
        }
    | expr RSHIFT expr
        {   const LetValue v3 = $3; 
            $$ = (v3>=0) ? ($1 >> v3) : ($1 << (-v3));
        }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr    { $$ = $1 * $3; }
    | expr '/' expr
        {   const LetValue v3 = $3;
            if (v3 == 0) {
                leterror("Division by 0");
                YYABORT;
            }
            $$ = $1 / (v3);
        }
    | expr '%' expr
        { const LetValue v3 = $3;
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
        {   const LetValue v3 = $3;
            if (v3 < 0) {
                leterror("Negative power");
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


