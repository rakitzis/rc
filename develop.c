#include "rc.h"

void dump(Node *, int);

/* dump a Node * as a tree */

static void dump_1(char *p, Node *n, int indent) {
	fprint(2, "%s:\n", p);
	dump(n->u[0].p, indent + 1);
}

static void dump_2(char *p, Node *n, int indent) {
	fprint(2, "%s:\n", p);
	dump(n->u[0].p, indent + 1);
	if (n->u[1].p != NULL)
		dump(n->u[1].p, indent + 1);
}

static void dump_3(char *p, Node *n, int indent) {
	fprint(2, "%s:\n", p);
	dump(n->u[0].p, indent + 1);
	if (n->u[1].p != NULL)
		dump(n->u[1].p, indent + 1);
	if (n->u[2].p != NULL)
		dump(n->u[2].p, indent + 1);
}

static void dump_s(char *p, Node *n, int indent) {
	fprint(2, "%s: %S\n", p, n->u[0].s);
}

static void dump_pipe(char *p, Node *n, int indent) {
	int ifd = n->u[0].i, ofd = n->u[1].i;
	fprint(2, "%s %d %d:\n", p, ifd, ofd);
	dump(n->u[2].p, indent + 1);
	dump(n->u[3].p, indent + 1);
}

static char *redir(int op) {
	switch (op) {
	case rCreate: return ">";
	case rAppend: return ">>";
	case rFrom: return "<";
	case rHeredoc: return "<<";
	case rHerestring: return "<<<";
	default: return "?";
	}
}
static void dump_dup(char *p, Node *n, int indent) {
	fprint(2, "%s %s %d %d:\n", p, redir(n->u[0].i), n->u[1].i, n->u[2].i);
}

static void dump_redir(char *p, Node *n, int indent) {
	fprint(2, "%s %s %d:\n", p, redir(n->u[0].i), n->u[1].i);
	dump(n->u[2].p, indent + 1);
}

void dump(Node *n, int indent) {
	int i;

	if (n == NULL)
		return;

	for (i = 0; i < indent; ++i)
		fprint(2, "    ");

	switch (n->type) {
	case nAndalso:
		dump_2("nAndalso", n, indent);
		break;
	case nArgs:
		dump_2("nArgs", n, indent);
		break;
	case nAssign:
		dump_2("nAassign", n, indent);
		break;
	case nBackq:
		dump_1("nBackq", n, indent);
		break;
	case nBang:
		dump_1("nBang", n, indent);
		break;
	case nBody:
		dump_2("nBody", n, indent);
		break;
	case nBrace:
		dump_1("nBrace", n, indent);
		break;
	case nCase:
		dump_1("nCase", n, indent);
		break;
	case nCbody:
		dump_2("nCbody", n, indent);
		break;
	case nConcat:
		dump_2("nConcat", n, indent);
		break;
	case nCount:
		dump_1("nCount", n, indent);
		break;
	case nDup:
		dump_dup("nDup", n, indent);
		break;
	case nElse:
		dump_2("nElse", n, indent);
		break;
	case nEpilog:
		dump_2("nEpilog", n, indent);
		break;
	case nFlat:
		dump_1("nFlat", n, indent);
		break;
	case nForin:
		dump_3("nForin", n, indent);
		break;
	case nIf:
		dump_2("nIf", n, indent);
		break;
	case nLappend:
		dump_2("nLappend", n, indent);
		break;
	case nMatch:
		dump_2("nMatch", n, indent);
		break;
	case nNewfn:
		dump_2("nNewfn", n, indent);
		break;
	case nNmpipe:
		dump_redir("nNowait", n, indent);
		break;
	case nNowait:
		dump_1("nNowait", n, indent);
		break;
	case nOrelse:
		dump_2("nNowait", n, indent);
		break;
	case nPipe:
		dump_pipe("nPipe", n, indent);
		break;
	case nPre:
		dump_2("nPre", n, indent);
		break;
	case nRedir:
		dump_redir("nRedir", n, indent);
		break;
	case nRmfn:
		dump_1("nRmfn", n, indent);
		break;
	case nSubshell:
		dump_1("nSubshell", n, indent);
		break;
	case nSwitch:
		dump_2("nSwitch", n, indent);
		break;
	case nVar:
		dump_1("nVar", n, indent);
		break;
	case nVarsub:
		dump_2("nVarsub", n, indent);
		break;
	case nWhile:
		dump_2("nWhile", n, indent);
		break;
	case nWord:
		dump_s("nWord", n, indent);
		break;
	default:
		fprint(2, "unknown\n");
		break;
	}
}

void tree_dump(Node *f) {
	dump(f, 0);
}
#if 0
	bool dollar = f->flags & FMT_altform;
	Node *n = va_arg(f->args, Node *);

	if (n == NULL) {
		fmtprint(f, "()");
		return FALSE;
	}
	switch (n->type) {
	case nBang:     fmtprint(f, "!%X", n->u[0].p);                          break;
	case nCase:     fmtprint(f, "case %X", n->u[0].p);                      break;
	case nNowait:   fmtprint(f, "%X&", n->u[0].p);                          break;
	case nRmfn:     fmtprint(f, "fn %X", n->u[0].p);                        break;
	case nSubshell: fmtprint(f, "@ %X", n->u[0].p);                         break;
	case nAndalso:  fmtprint(f, "%X&&%X", n->u[0].p, n->u[1].p);            break;
	case nAssign:   fmtprint(f, "%X=%X", n->u[0].p, n->u[1].p);             break;
	case nConcat:   fmtprint(f, "%X^%X", n->u[0].p, n->u[1].p);             break;
	case nElse:     fmtprint(f, "{%X}else %X", n->u[0].p, n->u[1].p);       break;
	case nNewfn:    fmtprint(f, "fn %X {%X}", n->u[0].p, n->u[1].p);        break;
	case nIf:       fmtprint(f, "if(%X)%X", n->u[0].p, n->u[1].p);          break;
	case nOrelse:   fmtprint(f, "%X||%X", n->u[0].p, n->u[1].p);            break;
	case nArgs:     fmtprint(f, "nArgs: ");
			Xconv(n->u[0].p, 4);
			Xconv(n->u[1].p, 4);            break;
	case nSwitch:   fmtprint(f, "switch(%X){%X}", n->u[0].p, n->u[1].p);    break;
	case nMatch:    fmtprint(f, "~ %X %X", n->u[0].p, n->u[1].p);           break;
	case nWhile:    fmtprint(f, "while(%X)%X", n->u[0].p, n->u[1].p);       break;
	case nForin:    fmtprint(f, "for(%X in %X)%X", n->u[0].p, n->u[1].p, n->u[2].p); break;
	case nVarsub:   fmtprint(f, "$%X(%X)", n->u[0].p, n->u[1].p);           break;
	case nWord:
		fmtprint(f, n->u[2].i && quotep(n->u[0].s, dollar) ?
				"%#S" : "%S", n->u[0].s);
		break;
	case nLappend: {
		static bool inlist;
		if (!inlist) {
			inlist = TRUE;
			fmtprint(f, "(%X %X)", n->u[0].p, n->u[1].p);
			inlist = FALSE;
		} else {
			fmtprint(f, "%X %X", n->u[0].p, n->u[1].p);
		}
		break;
	}
	case nCount: case nFlat: case nVar: {
		char *lp = "", *rp = "";
		Node *n0 = n->u[0].p;

		if (n0->type != nWord)
			lp = "(", rp = ")";

		switch (n->type) {
		default:        panic("this can't happen");             break;
		case nCount:    fmtprint(f, "$#%s%#T%s", lp, n0, rp);   break;
		case nFlat:     fmtprint(f, "$^%s%#T%s", lp, n0, rp);   break;
		case nVar:      fmtprint(f, "$%s%#T%s", lp, n0, rp);    break;
		}
		break;
	}
	case nDup:
		if (n->u[2].i != -1)
			fmtprint(f, "%D[%d=%d]", n->u[0].i, n->u[1].i, n->u[2].i);
		else
			fmtprint(f, "%D[%d=]", n->u[0].i, n->u[1].i);
		break;
	case nBackq: {
		Node *n0 = n->u[0].p, *n00;
		if (n0 != NULL && n0->type == nVar
		    && (n00 = n0->u[0].p) != NULL && n00->type == nWord && streq(n00->u[0].s, "ifs"))
			fmtprint(f, "`");
		else
			fmtprint(f, "``%X", n0);
		fmtprint(f, "{%X}", n->u[1].p);
		break;
	}
	case nCbody:
	case nBody: {
		Node *n0 = n->u[0].p;
		if (n0 != NULL)
			fmtprint(f, "%X", n->u[0].p);
		if (n->u[1].p != NULL) {
			if (n0 != NULL && n0->type != nNowait)
				fmtprint(f, ";");
			fmtprint(f, "%X", n->u[1].p);
		}
		break;
	}
	case nBrace:
		fmtprint(f, "{%X}", n->u[0].p);
		if (n->u[1].p != NULL)
			fmtprint(f, "%X", n->u[1].p);
		break;
	case nEpilog:
	case nPre:
		fmtprint(f, "%X", n->u[0].p);
		if (n->u[1].p != NULL)
			fmtprint(f, " %X", n->u[1].p);
		break;
	case nPipe: {
		int ofd = n->u[0].i, ifd = n->u[1].i;
		fmtprint(f, "%X|", n->u[2].p);
		if (ifd != 0)
			fmtprint(f, "[%d=%d]", ofd, ifd);
		else if (ofd != 1)
			fmtprint(f, "[%d]", ofd);
		fmtprint(f, "%X", n->u[3].p);
		break;
	}
	case nRedir: {
		int op = n->u[0].i;
		fmtprint(f, "%D", op);
		fmtprint(f, "[%d]", n->u[1].i);
		fmtprint(f, "%X", n->u[2].p);
		break;
	}
	case nNmpipe: {
		int op = n->u[0].i;
		fmtprint(f, "%D", op);
		fmtprint(f, "[%d]", n->u[1].i);
		fmtprint(f, "{%X}", n->u[2].p);
		break;
	}
	}
	return FALSE;
}
#endif
