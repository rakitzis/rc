#ifndef LET_H_INCLUDE
#define LET_H_INCLUDE

typedef long int LetValue;
#include "let.tab.h"

typedef int Token;

typedef struct LetLex {
  const char* m_Buf;
  const char* m_Current;
  Token       m_LastToken;
  char        m_Indent[256];
} LetLex;

extern LetValue letResult;

extern int leterror(const char *s);
extern int LetDoParse(const char *s, LetValue *r, LetLex* lex);
extern LetValue letpwr(LetValue a, LetValue b);
extern Token LetLexer(LetLex *lex, YYSTYPE* letlval);
extern int LetParser(LetLex *lex);


#endif
