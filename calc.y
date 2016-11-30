/*
 * process with
 *    byacc -t -v -d [-P] -b calc -p calc calc.y
 * or with
 *    bison -t -v -d -b calc -p calc calc.y
 */

%{
#include <assert.h>

extern int printf(const char *, ...);

#include "calc.h"




/* the name of the lexer in CalcParser(), lexer, must be equal to the call
 * that calclex() represents, lexer(lexData, &calcval
 */
#define calcparse(a)  CalcParser(CalcLexerType lexer, CalcLexData *lexData)
#define calcparse_r(a)  CalcParser(CalcLexerType lexer, CalcLexData *lexData)
#define calclex(a)  (*lexer)(lexData, &calclval)


%}


%union {
    CalcValue m_Val;
}

/* Non-terminals */
%type <m_Val> expr assignment

/* Tokens */
%nonassoc '='
%left CALC_OROR
%left CALC_ANDAND
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
%token END_TOKEN BAD_TOKEN CALC_VAR

%pure-parser


%start calc

%%
calc
    : expr
        {   assert('\0' == lexData->m_Indent[0]);
            calcResult = $1;
        }
    | assignment
        {   assert('\0' != lexData->m_Indent[0]);
            calcResult = $1;
        }
    ;

assignment
    : CALC_VAR '=' expr
        {   assert('\0' != lexData->m_Indent[0]);
            $$ = $3;
        }
    ;

expr: expr CALC_OROR expr    { $$ = $1 || $3; }
    | expr CALC_ANDAND  expr { $$ = $1 && $3; }
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
        {   const CalcValue v3 = $3;
            $$ = (v3 >= 0) ? ($1 << v3) : ($1 >> (-v3));
        }
    | expr RSHIFT expr
        {   const CalcValue v3 = $3; 
            $$ = (v3>=0) ? ($1 >> v3) : ($1 << (-v3));
        }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr    { $$ = $1 * $3; }
    | expr '/' expr
        {   const CalcValue v3 = $3;
            if (v3 == 0) {
                calcerror("Division by 0");
                YYABORT;
            }
            $$ = $1 / (v3);
        }
    | expr '%' expr
        { const CalcValue v3 = $3;
          if (v3 == 0) {
            calcerror("Module by 0");
            YYABORT;
          }
          $$ = $1 % (v3);
        }
    | '!' expr  { $$ = !$2; }
    | '~' expr  { $$ = ~$2; }
    | '-' expr %prec UNARY_PLUSMINUS { $$ = -$2; }
    | '+' expr %prec UNARY_PLUSMINUS { $$ = +$2; }
    | expr '@' expr
        {   const CalcValue v3 = $3;
            if (v3 < 0) {
                calcerror("Negative power");
                YYABORT;
            }
            $$ = calcpwr($1, v3);
        }
     | '(' expr ')'    { $$ = $2; }
     |  NUMBER { $$ = $1; }
     ;

%%

/*
*/


