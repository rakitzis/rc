#ifndef _calc_defines_h_
#define _calc_defines_h_

#ifndef YYTOKEN_IS_DECLARED
#define YYTOKEN_IS_DECLARED 1
typedef enum calctoken {
    CALC_OROR = 257,
    CALC_ANDAND = 258,
    CALC_EQEQ = 259,
    CALC_NEQ = 260,
    CALC_LEQ = 261,
    CALC_GEQ = 262,
    CALC_LSHIFT = 263,
    CALC_RSHIFT = 264,
    CALC_UNARY_PLUSMINUS = 265,
    CALC_NUMBER = 266,
    CALC_VAR = 267,
    CALC_END_TOKEN = 268,
    CALC_BAD_TOKEN = 269
} calctoken;
#endif /* !YYTOKEN_IS_DECLARED */
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	CalcValue m_Val;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */

#endif /* _calc_defines_h_ */
