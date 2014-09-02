/* main.c: handles initialization of rc and command line options */

#include "rc.h"

#include <errno.h>

#include "input.h"

bool dashdee, dashee, dashvee, dashex, dasheye,
	dashen, dashpee, interactive;
pid_t rc_pid;

static bool dashEYE, dashell, dashoh, dashess;

static void assigndefault(char *,...);
static void checkfd(int, enum redirtype);

extern int main(int argc, char *argv[], char *envp[]) {
	char *dashsee[2], *dollarzero, *null[1];
	int c;
	initprint();
	dashsee[0] = dashsee[1] = NULL;
	dollarzero = argv[0];
	rc_pid = getpid();
	dashell = (*argv[0] == '-'); /* Unix tradition */
	while ((c = rc_getopt(argc, argv, "c:deiIlnopsvx")) != -1)
		switch (c) {
		case 'c':
			dashsee[0] = rc_optarg;
			goto quitopts;
		case 'd':
			dashdee = TRUE;
			break;
		case 'e':
			dashee = TRUE;
			break;
		case 'I':
			dashEYE = TRUE;
			interactive = FALSE;
			break;
		case 'i':
			dasheye = interactive = TRUE;
			break;
		case 'l':
			dashell = TRUE;
			break;
		case 'n':
			dashen = TRUE;
			break;
		case 'o':
			dashoh = TRUE;
			break;
		case 'p':
			dashpee = TRUE;
			break;
		case 's':
			dashess = TRUE;
			break;
		case 'v':
			dashvee = TRUE;
			break;
		case 'x':
			dashex = TRUE;
			break;
		case '?':
			exit(1);
		}
quitopts:
	argv += rc_optind;
	/* use isatty() iff neither -i nor -I is set, and iff the input is not from a script or -c flags */
	if (!dasheye && !dashEYE && dashsee[0] == NULL && (dashess || *argv == NULL))
		interactive = isatty(0);
	if (!dashoh) {
		checkfd(0, rFrom);
		checkfd(1, rCreate);
		checkfd(2, rCreate);
	}
	initsignal();
	inithash();
	initparse();
	assigndefault("ifs", " ", "\t", "\n", (void *)0);
#ifdef DEFAULTPATH
	assigndefault("path", DEFAULTPATH, (void *)0);
#endif
	assigndefault("pid", nprint("%d", rc_pid), (void *)0);
	assigndefault("prompt", "; ", "", (void *)0);
	assigndefault("version", VERSION, "$Release: @(#)" PACKAGE " " VERSION " " RELDATE " $", (void *)0);
	initenv(envp);
	initinput();
	null[0] = NULL;
	starassign(dollarzero, null, FALSE); /* assign $0 to $* */
	inithandler();

	if (dashell) {
		char *rcrc;
		int fd;

		rcrc = concat(varlookup("home"), word("/.rcrc", NULL))->w;
		fd = rc_open(rcrc, rFrom);
		if (fd == -1) {
			if (errno != ENOENT)
				uerror(rcrc);
		} else {
			bool push_interactive;

			pushfd(fd);
			push_interactive = interactive;
			interactive = FALSE;
			doit(TRUE);
			interactive = push_interactive;
			close(fd);
		}
	}

	if (dashsee[0] != NULL || dashess) {	/* input from  -c or -s? */
		if (*argv != NULL)
			starassign(dollarzero, argv, FALSE);
		if (dashess)
			pushfd(0);
		else
			pushstring(dashsee, TRUE);
	} else if (*argv != NULL) {	/* else from a file? */
		b_dot(--argv);
		rc_exit(getstatus());
	} else {			/* else stdin */
		pushfd(0);
	}
	dasheye = FALSE;
	doit(TRUE);
	rc_exit(getstatus());
	return 0; /* Never really reached. */
}

static void assigndefault(char *name,...) {
	va_list ap;
	List *l;
	char *v;
	va_start(ap, name);
	for (l = NULL; (v = va_arg(ap, char *)) != NULL;)
		l = append(l, word(v, NULL));
	varassign(name, l, FALSE);
	set_exportable(name, FALSE);
	if (streq(name, "path"))
		alias(name, l, FALSE);
	va_end(ap);
}

/* open an fd on /dev/null if it is inherited closed */

static void checkfd(int fd, enum redirtype r) {
	int new = rc_open("/dev/null", r);
	if (new != fd && new != -1)
		close(new);
}
