#define CALC_OROR 257
#define CALC_ANDAND 258
#define EQEQ 259
#define NEQ 260
#define LEQ 261
#define GEQ 262
#define LSHIFT 263
#define RSHIFT 264
#define UNARY_PLUSMINUS 265
#define NUMBER 266
#define END_TOKEN 267
#define BAD_TOKEN 268
#define CALC_VAR 269
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
