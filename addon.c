#include <stdio.h>
#include <ctype.h>
#include "sigmsgs.h"
#include "rc.h"


#if RC_ADDON

#include "let.h"

/******************************************************/
/******************************************************/

LetValue letResult;


#define KILL_USAGE "usage: kill [-signame|-signum] pid\n"
#define CHECK(cond, msg) if (cond) { fprint(2, (msg)); set(FALSE); return; }

void b_kill (char **av)
{
  char *sig_p, *proc_p;
  pid_t proc;
  int sig, r;

  if (av[1]  == NULL) {
    fprint(2, KILL_USAGE); set(FALSE); return; 
  }
  sig_p = av[1];
  if (av[2] == NULL) {
    sig = SIGTERM;
    proc_p = sig_p;
  } else {
    proc_p = av[2];
    CHECK((av[3] != NULL), KILL_USAGE);
    CHECK((*sig_p != '-'), KILL_USAGE)
    sig = a2u(sig_p+1);
    if (sig < 0) {
        int i;
        for (i=0; signals[i].name; ++i) {
            if (0 == strcasecmp(sig_p+1, signals[i].name)) {
                /* -sigkill */
                sig = signals[i].signum;
                break;
            } else if (0 == strcasecmp(sig_p+1, signals[i].name+3)) {
                /* -kill */
                sig = signals[i].signum;
                break;
            }
        }
    }
    CHECK((sig < 0), "bad signal\n")
  }

  proc = a2u(proc_p);
  CHECK((proc < 0), "bad process id\n")
  r = kill(proc, sig);
  CHECK((r < 0), "kill failed\n")
#undef KILL_USAGE
#undef CHECK
}

extern int LetDoParse(char *s, long *r);

#if 0
static void set_var (char *varname, long R)
{
  List *val = nnew(List); var->w = nprint("%ld", R);
  varassign(varname, val, FALSE);
}
#endif

static int check_var_name (char *p)
{
  if (!isalpha(*p) && (*p) != '_') {
    return 0;
  }
  for ( ; *p; ++p) {
    if (!isalnum(*p) && (*p) != '_') {
      return 0;
    }
  }
  return 1;
}


enum { VAL_ZERO = 1, VAL_NONZERO = 0, BAD_EXP = 2 };
static int ret_value(int parse_status, long value)
{
  if (0==parse_status) {
    if (0L == value) {
      return VAL_ZERO;
    } else {
      return VAL_NONZERO;
    }
  } else {
    return BAD_EXP;
  }
}

void b_let (char **av)
{
  long R = 0;
  int parse_status;
  int rc_status = BAD_EXP;
  char *exp, *varname;

  if (av[1] == 0) {
    fprint(2, "let: cannot have 0 args\n");
    goto returnLabel;
  }

  if (av[2] == 0) {
    exp = av[1];
    parse_status = LetDoParse(exp, &R);
    rc_status = ret_value(parse_status, R);
    goto returnLabel;
  }

  if (av[3] != 0) {
    fprint(2, "let: cannot have more than 2 args\n");
    goto returnLabel;
  }

  varname = av[1];
  exp = av[2];

  if (0 == strcmp(varname, "-p")) {
    parse_status = LetDoParse(exp, &R);
    if (0==parse_status) {
      fprint(1, "%ld\n", R);
    }
    rc_status = ret_value(parse_status, R);
    goto returnLabel;
  }

  if (!check_var_name(av[1])) {
    fprint(2, "let: bad variable name '%s'\n", av[1]);
    goto returnLabel;
  }

  parse_status = LetDoParse(av[2], &R);
  if (0 == parse_status) {
    List val;
    val.w = nprint("%ld", R);
    val.n = NULL;
    varassign(av[1], &val, FALSE);
  }
  rc_status = ret_value(parse_status, R);
  goto returnLabel;


returnLabel:
  setN(rc_status);
  return;
}





/******************************************************/

LetValue letpwr(LetValue a, LetValue b)
{
  LetValue z = 1;   /* z*a^b = A^B */
  while (b > 0) {
    if (b & 1) { /* odd */
      /* z*a^b = z*a * a^(b-1) */
      --b;
      z *= a;
    } else {
      /* z*a^(2k) = z * (a^2)^k */
      b /= 2;
      a *= a;
    }
  }
  return z;
}
/******************************************************/
Token LetLexer (struct LetLex *lex, YYSTYPE* letlval)
{
  const char *p;
  Token tok;
  int c;

  if (lex->m_LastToken != BAD_TOKEN) {
    tok = lex->m_LastToken;
    lex->m_LastToken = BAD_TOKEN;
    return tok;
  }
  p = lex->m_Current;
  while (*p == ' ' || *p == '\t') {
    p++;
  }
  switch (*p) {
  case '+': case '-': case '*': case '/': case '%':
  case '^': case '(': case ')':
  case '@':
    tok = (Token) (*p);
    p++;
    break;

  case '|': case '&':
    c = *p++;
    if (*p == c) {
       tok = (c == '|' ? LET_OROR : LET_ANDAND);
       p++; 
    } else {
       tok = (Token)(c);
    }
    break;

  case '<': case '>':
    c = *p++;
    if (*p == '=') {
      tok = (c == '<' ? LEQ : GEQ);
      p++;
    } else if (c == *p) {
      tok = (c == '<' ? LSHIFT : RSHIFT);
      p++;
    } else {
      tok = (Token) (c);
    }
    break;

  case '!': case '=':
    c = *p++;
    if (*p == '=') {
      tok = ((c == '=') ? EQEQ : NEQ);
      p++;
    } else {
      tok = BAD_TOKEN;
    }
    break;

  case '0': case '1': case '2': case '3': case '4': 
  case '5': case '6': case '7': case '8': case '9': 
    {
        LetValue val = 0;
        while ('0' <= *p && *p <= '9') {
          val = 10 * val + (*p++ -'0');
        }
        letlval->m_Val = val;
        tok = NUMBER;
    }
    break;
  case '\0':
    tok = 0;
    break;
  default:
    tok = BAD_TOKEN;
    break;
  }
  lex->m_Current = p;
  return tok;
} /* LetLexer */

/******************************************************/
#include "setjmp.h"

static jmp_buf jbuf;

/******************************************************/
int LetDoParse(char *s, LetValue *r)
{
  int status;
  struct LetLex lex;

  if (setjmp(jbuf)) {
    return -1;
  }
  lex.m_Current = lex.m_Buf = s;
  lex.m_LastToken = BAD_TOKEN;

  status = LetParser(&lex);
  *r = letResult;
  return status;
}

/******************************************************/


int leterror(const char *s)
{
  fprint(2, "let: %s\n", s);
  longjmp(jbuf, 1);
  return 0;
}
/******************************************************/
/******************************************************/



#endif

