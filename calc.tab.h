#ifndef YYTOKEN_IS_DECLARED
#define YYTOKEN_IS_DECLARED 1
typedef enum calc_token {
  CALC_OROR = 257,
  CALC_ANDAND = 258,
  EQEQ = 259,
  NEQ = 260,
  LEQ = 261,
  GEQ = 262,
  LSHIFT = 263,
  RSHIFT = 264,
  UNARY_PLUSMINUS = 265,
  NUMBER = 266,
  END_TOKEN = 267,
  BAD_TOKEN = 268,
  CALC_VAR = 269,
} calc_token;
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
extern YYSTYPE calclval;
