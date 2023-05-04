/*
 * process with
 *    byacc -t -v -d [-P] -b calc -p calc calc.y
 * or with
 *    bison -t -v -d -b calc -p calc calc.y
 */

%{
#include <assert.h>

extern int printf(const char *, ...);

#include "calc_decl.h"




/* The name of the lexer argument for CalcParser() in the body of the macro calcparse():
 *      CalcParser(lexer, lexData)
 *                 ^^^^^
 * must be equal to the function name in the body of the macro calclex():
 *      lexer(lexData, &calcval)
 *      ^^^^^
 */
#define calcparse(a) CalcParser(CalcLexerType lexer, CalcLexData *lexData)
#define calcparse_r(a) CalcParser(CalcLexerType lexer, CalcLexData *lexData)
#define calclex(a) lexer(lexData, &calclval)
#define calcerror(s) CalcError(s, lexData);


%}


%union {
	CalcValue m_Val;
}

/* Non-terminals */
%type <m_Val> expr assignment

/* Tokens - highest precedence last */
%nonassoc '='
%left CALC_OROR
%left CALC_ANDAND
%left '|'
%left '^'
%left '&'
%left CALC_EQEQ CALC_NEQ
%left '<' '>' CALC_LEQ CALC_GEQ
%left CALC_LSHIFT CALC_RSHIFT
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' CALC_UNARY_PLUSMINUS
%right '@'


%token <m_Val> CALC_NUMBER
%token CALC_VAR
%token CALC_END_TOKEN CALC_BAD_TOKEN

%pure-parser


%start calc

%%
calc
	: expr
		{	assert('\0' == lexData->m_Indent[0]);
			lexData->m_CalcResult = $1;
		}
	| assignment
		{	assert('\0' != lexData->m_Indent[0]);
			lexData->m_CalcResult = $1;
		}
	;

assignment
	: CALC_VAR '=' expr
		{	assert('\0' != lexData->m_Indent[0]);
			$$ = $3;
		}
	;

expr: expr CALC_OROR expr    { $$ = $1 || $3; }
	| expr CALC_ANDAND  expr { $$ = $1 && $3; }
	| expr '|' expr { $$ = $1 | $3; } ;
	| expr '^' expr { $$ = $1 ^ $3; } ;
	| expr '&' expr { $$ = $1 & $3; } ;
	| expr CALC_EQEQ expr { $$ = ($1 == $3); }
	| expr CALC_NEQ expr  { $$ = ($1 != $3); }
	| expr '>' expr { $$ = $1 > $3; }
	| expr '<' expr { $$ = $1 < $3; }
	| expr CALC_LEQ expr { $$ = $1 <= $3; }
	| expr CALC_GEQ expr { $$ = $1 >= $3; }
	| expr CALC_LSHIFT expr
		{	const CalcValue v3 = $3;
			$$ = (v3 >= 0) ? ($1 << v3) : ($1 >> (-v3));
		}
	| expr CALC_RSHIFT expr
		{	const CalcValue v3 = $3;
			$$ = (v3>=0) ? ($1 >> v3) : ($1 << (-v3));
		}
	| expr '+' expr { $$ = $1 + $3; }
	| expr '-' expr { $$ = $1 - $3; }
	| expr '*' expr    { $$ = $1 * $3; }
	| expr '/' expr
		{	const CalcValue v3 = $3;
			if (v3 == 0) {
				calcerror("Division by 0");
				YYABORT;
			}
			$$ = $1 / (v3);
		}
	| expr '%' expr
		{	const CalcValue v3 = $3;
			if (v3 == 0) {
				calcerror("Module by 0");
				YYABORT;
			}
			$$ = $1 % (v3);
		}
	| '!' expr  { $$ = !$2; }
	| '~' expr  { $$ = ~$2; }
	| '-' expr %prec CALC_UNARY_PLUSMINUS { $$ = -$2; }
	| '+' expr %prec CALC_UNARY_PLUSMINUS { $$ = +$2; }
	| expr '@' expr
		{	const CalcValue v3 = $3;
			if (v3 < 0) {
				calcerror("Negative power");
				YYABORT;
			}
			$$ = CalcPower($1, v3);
		}
	| '(' expr ')'    { $$ = $2; }
	|  CALC_NUMBER { $$ = $1; }
	;

%%

/*
*/

