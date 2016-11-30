#ifndef CALC_H_INCLUDE
#define CALC_H_INCLUDE

typedef long int CalcValue;
#include "calc.tab.h"

typedef int CalcToken;

typedef struct CalcLexData {
    const char* m_Buf;
    const char* m_Current;
    CalcToken   m_LastToken;
    char        m_Indent[256];
    CalcValue   m_CalcResult;
    const char* m_CalcCmdName;
} CalcLexData;

extern const char* calcCmdName;

extern int CalcError(const char *s, const CalcLexData* lexData);
extern int CalcDoParse(const char *s, CalcValue *r, CalcLexData* lexData);
extern CalcValue calcpwr(CalcValue a, CalcValue b);

typedef CalcToken (*CalcLexerType)(CalcLexData *lexData, YYSTYPE* calclval);
extern int CalcParser(CalcLexerType lexer, CalcLexData *lexData);


#endif
