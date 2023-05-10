#include <stdio.h>
#include <ctype.h>
#include "sigmsgs.h"
#include "rc.h"


#if RC_ADDON

#include "calc_decl.h"

/******************************************************/
/******************************************************/

#define KILL_USAGE "usage: kill [-signame|-signum] pid+\n"

/******************************************************/
void b_kill(char **av) {
	int p, sig;
	bool ret;

	if (av[1] == NULL) {
		fprint(2, "%s", KILL_USAGE);
		set(FALSE);
		return;
	}

	if ('-' != av[1][0]) {
		sig = SIGTERM;
		p = 1;
	} else {
		const char *const sigStr = av[1] + 1;
		sig = a2u(sigStr);
		if (sig < 0) {
			int s;
			for (s = 0; signals[s].name; ++s) {
				if (0 == strcasecmp(sigStr, signals[s].name)) {
					/* -kill */
					sig = signals[s].signum;
					break;
				} else if (0 == strcasecmp(sigStr, signals[s].name + 3)) {
					/* -sigkill */
					sig = signals[s].signum;
					break;
				}
			}
			if (sig < 0) {
				fprint(2, "bad signal %s\n", sigStr);
				set(FALSE);
				return;
			}
		}
		p = 2;
	}

	if (!av[p]) { /* must have at least one process id */
		fprint(2, "%s", KILL_USAGE);
		set(FALSE);
		return;
	}

	ret = TRUE;
	for (/*empty*/; av[p]; ++p) {
		const char *const procStr = av[p];
		const pid_t proc = a2u(procStr);
		if (proc > 0) {
			const int r = kill(proc, sig);
			if (r < 0) {
				ret = FALSE;
				fprint(2, "failed to kill process %d with signal, return value %d\n", proc, sig, r);
			}
		} else {
			ret = FALSE;
			fprint(2, "bad process id: %s\n", procStr);
		}
	}
	set(ret);
}

static int CalcDoParse(const char *s, CalcValue *r, CalcLexData *lexData);

#if 0
static void set_var(char *varname, long R)
{
	List *val = nnew(List); var->w = nprint("%ld", R);
	varassign(varname, val, FALSE);
}
#endif

/******************************************************/
static int check_var_name(const char *p) {
	if (!isalpha(*p) && (*p) != '_') {
		return 0;
	}
	for (; *p; ++p) {
		if (!(isalnum(*p) || (*p) == '_')) {
			return 0;
		}
	}
	return 1;
}

/******************************************************/
enum {
	VAL_NONZERO = 0,
	VAL_ZERO = 1,
	BAD_EXP = 2,
};

/******************************************************/
static int ret_value(int parse_status, long value) {
	if (0 == parse_status) {
		if (0L == value) {
			return VAL_ZERO;
		} else {
			return VAL_NONZERO;
		}
	} else {
		return BAD_EXP;
	}
}

/******************************************************/
void b_calc(char **av) {
	const char *const calcCmdName = av[0];
	int rc_status = BAD_EXP;

	if (av[1] == 0) { /* no arg like parse error */
		fprint(2, "usage: %s [-p] [expr|assignment]\n", calcCmdName);
		rc_status = BAD_EXP;
	} else {
		int i;
		bool doPrint = FALSE;

		i = 1;
		if (streq(av[i], "-p")) {
			doPrint = TRUE;
			++i;
		}

		if (av[i] == 0) {
			fprint(2, "usage: %s [-p] [expr|assignment]\n", calcCmdName);
			rc_status = BAD_EXP;
		} else {
			CalcLexData lexData;
			long parse_value = 0;
			int parse_status;
			const char *exp;

			if (0 == av[i + 1]) {
				exp = av[i];
			} else {
				int j;
				char *p;
				int len = 0;

				for (j = i; av[j]; ++j) {	  /* count total len */
					len += strlen(av[j]) + 1; /* 1 space between args:(a,b) to 'a b', no to 'ab' */
				}

				exp = p = nnew_arr(char, len + 1);

				strcpy(p, av[i]); /* guaranteed non-null */
				p += strlen(av[i++]);

				for (; av[i]; ++i) {
					*p++ = ' ';
					strcpy(p, av[i]);
					p += strlen(av[i]);
				}
				*p = '\0';
			}

			lexData.m_CalcCmdName = calcCmdName;
			parse_status = CalcDoParse(exp, &parse_value, &lexData);

			if (0 == parse_status) {
				const char *const varName = &lexData.m_Indent[0];
				if ('\0' != varName[0]) { /* assignment */
					if (check_var_name(varName)) {
						List val;
						val.w = nprint("%ld", parse_value);
						val.n = NULL;
						varassign(varName, &val, FALSE);
						rc_status = ret_value(parse_status, parse_value);
						if (doPrint) {
							fprint(1, "%ld\n", parse_value);
						}
					} else {
						/* should this be treated as bad parse? */
						fprint(2, "%s: bad variable name '%s'\n", calcCmdName, varName);
						rc_status = BAD_EXP;
					}
				} else { /* no variable => not assignment */
					rc_status = ret_value(parse_status, parse_value);
					if (doPrint) {
						fprint(1, "%ld\n", parse_value);
					}
				}
			} else { /* parse error */
				rc_status = BAD_EXP;
			}
		}
	}

	setN(rc_status);
	return;
}

/******************************************************/
CalcValue CalcPower(const CalcValue A, const CalcValue B) {
	CalcValue a = A, b = B;
	CalcValue z = 1; /* z * a^b = A^B */
	while (b > 0) {
		if (b & 1) { /* odd */
			/*  z * a^b = (z * a) * (a^(b-1)) */
			z = z * a;
			b = b - 1;
		} else {
			/*  z * a^(2k) = z * (a*a)^k */
			a = a * a;
			b = b / 2;
		}
	}
	return z;
}
static CalcToken CalcLexer(CalcLexData *lexData, YYSTYPE *calclval) {
	const char *p;
	CalcToken tok;
	int c;

	if (lexData->m_LastToken != CALC_BAD_TOKEN) {
		tok = lexData->m_LastToken;
		lexData->m_LastToken = CALC_BAD_TOKEN;
		return tok;
	}
	p = lexData->m_Current;
	while (*p == ' ' || *p == '\t') {
		p++;
	}
	if (isalpha(*p) || '_' == *p) {
		enum { NUM_CHARS = sizeof(lexData->m_Indent) / sizeof(lexData->m_Indent[0]) - 1 };
		int i = 0;
		int c = *p;

		while (isalnum(c) || '_' == c) {
			if (i >= NUM_CHARS) {
				return CALC_BAD_TOKEN;
			}
			lexData->m_Indent[i++] = *(p++);
			c = *p;
		}

		lexData->m_Indent[i] = '\0';
		lexData->m_Current = p;
		return CALC_VAR;
	}
	switch (*p) {
	case '^':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '~':
	case '@':
	case '(':
	case ')':
		tok = (CalcToken)(*p);
		p++;
		break;

	case '|':
	case '&':
		c = *p++;
		if (*p == c) {
			tok = (c == '|' ? CALC_OROR : CALC_ANDAND);
			p++;
		} else {
			tok = (CalcToken)(c);
		}
		break;

	case '<':
	case '>':
		c = *p++;
		if (*p == '=') {
			tok = (c == '<' ? CALC_LEQ : CALC_GEQ);
			p++;
		} else if (c == *p) {
			tok = (c == '<' ? CALC_LSHIFT : CALC_RSHIFT);
			p++;
		} else {
			tok = (CalcToken)(c);
		}
		break;

	case '=':
		c = *p++;
		if (*p == '=') {
			tok = CALC_EQEQ;
			p++;
		} else {
			tok = (CalcToken)(c);
		}
		break;

	case '!':
		c = *p++;
		if (*p == '=') {
			tok = CALC_NEQ;
			p++;
		} else {
			tok = (CalcToken)(c);
		}
		break;

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': {
		CalcValue val = 0;
		while ('0' <= *p && *p <= '9') {
			val = 10 * val + (*p++ - '0');
		}
		calclval->m_Val = val;
		tok = CALC_NUMBER;
	} break;
	case '\0':
		tok = (CalcToken)(0);
		break;
	default:
		tok = CALC_BAD_TOKEN;
		break;
	}
	lexData->m_Current = p;
	return tok;
} /* CalcLexer */

/******************************************************/
/******************************************************/
#if YYDEBUG
extern int calcdebug;
#endif
static int CalcDoParse(const char *s, CalcValue *r, CalcLexData *lexData) {
	int status;

	lexData->m_Current = lexData->m_Buf = s;
	lexData->m_LastToken = CALC_BAD_TOKEN;
	lexData->m_Indent[0] = '\0';

#if YYDEBUG
	{
		const char *const yys = getenv("CALCDEBUG");
		if (yys != 0) {
			const int yyn = *yys;
			if ('0' <= yyn && yyn <= '9') {
				calcdebug = yyn - '0';
			}
		}
	}
#endif
	status = CalcParser(CalcLexer, lexData);
	*r = lexData->m_CalcResult;
	return status;
}

/******************************************************/
int CalcError(const char *s, const CalcLexData *lexData) {
	fprint(2, "%s: %s\n", lexData->m_CalcCmdName, s);
	return 0;
}
/******************************************************/
/******************************************************/

#endif

