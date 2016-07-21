#ifndef LET_H_INCLUDE
#define LET_H_INCLUDE

typedef long int LetValue;
#include "let.tab.h"

typedef int Token;

struct LetLex {
  const char* m_Buf;
  const char* m_Current;
  Token       m_LastToken;
};

extern LetValue letResult;

extern int leterror(const char *s);
extern int LetDoParse(const char *s, LetValue *);
extern LetValue letpwr(LetValue a, LetValue b);
extern Token LetLexer(struct LetLex *lex, YYSTYPE* letlval);
extern int LetParser(struct LetLex *lex);


#endif
