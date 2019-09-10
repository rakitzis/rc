/* match.c: pattern matching routines */

#include "rc.h"

static int rangematch(char *, char);

/* match() matches a single pattern against a single string. */

extern bool match(char *p, char *m, char *s) {
	struct { char *p, *m, *s; } next;
	if (m == NULL)
		return streq(p, s);
	next.s = NULL;
	while (*p || *s) {
		if (*p) {
			if (!*m) {
				/* ordinary character */
				if (*s == *p) {
					p++, m++, s++;
					continue;
				}
			} else switch (*p) {
			case '?':
				if (*s) {
					p++, m++, s++;
					continue;
				}
				break;
			case '[': {
				int r = 1 + rangematch(p+1, *s);
				if (r > 0) {
					p += r, m += r, s++;
					continue;
				}
				break;
			}
			case '*':
				next.p = p++;
				next.m = m++;
				next.s = *s ? s+1 : NULL;
				continue;
			default:
				panic("bad metacharacter in match");
				/* NOTREACHED */
				return FALSE; /* hush up gcc -Wall */
			}
		}
		if (next.s != NULL) {
			p = next.p;
			m = next.m;
			s = next.s;
			continue;
		}
		return FALSE;
	}
	return TRUE;
}

/*
   From the ed(1) man pages (on ranges):

	The `-' is treated as an ordinary character if it occurs first
	(or first after an initial ^) or last in the string.

	The right square bracket does not terminate the enclosed string
	if it is the first character (after an initial `^', if any), in
	the bracketed string.

   rangematch() matches a single character against a class, and returns
   an integer offset to the end of the range on success, or -1 on
   failure.
*/

static int rangematch(char *p, char c) {
	char *orig = p;
	bool neg = (*p == '~');
	bool matched = FALSE;
	if (neg)
		p++;
	if (*p == ']') {
		p++;
		matched = (c == ']');
	}
	for (; *p != ']'; p++) {
		if (*p == '\0')
			return c == '[' ? 0 : -1;	/* no right-bracket */
		if (p[1] == '-' && p[2] != ']') { /* check for [..-..] but ignore [..-] */
			if (c >= *p)
				matched |= (c <= p[2]);
			p += 2;
		} else {
			matched |= (*p == c);
		}
	}
	if (matched ^ neg)
		return p - orig + 1; /* skip the right-bracket */
	else
		return -1;
}
