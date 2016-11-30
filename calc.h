#ifndef CALC_H_INCLUDE
#define CALC_H_INCLUDE

typedef long int CalcValue;
#include "calc.tab.h"

typedef int Token;

typedef struct CalcLex {
    const char* m_Buf;
    const char* m_Current;
    Token       m_LastToken;
    char        m_Indent[256];
} CalcLex;

extern CalcValue calcResult;
extern const char* calcCmdName;

extern int calcerror(const char *s);
extern int CalcDoParse(const char *s, CalcValue *r, CalcLex* lex);
extern CalcValue calcpwr(CalcValue a, CalcValue b);
extern Token CalcLexer(CalcLex *lex, YYSTYPE* calclval);
extern int CalcParser(CalcLex *lex);


#endif
