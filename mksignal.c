#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef NSIG
#define NUMSIG NSIG
#else
#define NUMSIG 1
#endif

struct signaming {
    int signo;
    const char *signame;
    const char *sigmsg;
};

static struct signaming signamings[] = {
#ifdef SIGABRT
    { SIGABRT,	"sigabrt",	"abort"},
#endif
#ifdef SIGALRM
    { SIGALRM,	"sigalrm",	"alarm clock"},
#endif
#ifdef SIGBREAK
    { SIGBREAK,	"sigbreak",	"break"},
#endif
#ifdef SIGBUS
    { SIGBUS,	"sigbus",	"bus error"},
#endif
#ifdef SIGCANCEL
    { SIGCANCEL,	"sigcancel",	"thread cancellation"},
#endif
#ifdef SIGCHLD
    { SIGCHLD,	"sigchld",	"child stop or exit"},
#endif
#ifdef SIGCLD
    { SIGCLD,	"sigcld",	"child stop or exit"},
#endif
#ifdef SIGCONT
    { SIGCONT,	"sigcont",	"continue"},
#endif
#ifdef SIGDIL
    { SIGDIL,	"sigdil",	"dil signal"},
#endif
#ifdef SIGEMT
    { SIGEMT,	"sigemt",	"emt instruction"},
#endif
#ifdef SIGFPE
    { SIGFPE,	"sigfpe",	"floating point error"},
#endif
#ifdef SIGFREEZE
    { SIGFREEZE,	"sigfreeze",	"cpr freeze"},
#endif
#ifdef SIGHUP
    { SIGHUP,	"sighup",	"hangup"},
#endif
#ifdef SIGILL
    { SIGILL,	"sigill",	"illegal instruction"},
#endif

/* We don't want a default message for SIGINT. */
#ifdef SIGINT
    { SIGINT,	"sigint",	""},
#endif

#ifdef SIGIO
    { SIGIO,	"sigio",	"socket i/o possible"},
#endif
#ifdef SIGIOT
    { SIGIOT,	"sigiot",	"iot instruction"},
#endif
#ifdef SIGKILL
    { SIGKILL,	"sigkill",	"killed"},
#endif
#ifdef SIGLOST
    { SIGLOST,	"siglost",	"resource lost"},
#endif
#ifdef SIGLWP
    { SIGLWP,	"siglwp",	"thread library signal"},
#endif

/* By default, SIGPIPEs are silent. */
#ifdef SIGPIPE
    { SIGPIPE,	"sigpipe",	""},
#endif

#ifdef SIGPOLL
    { SIGPOLL,	"sigpoll",	"pollable event occurred"},
#endif
#ifdef SIGPROF
    { SIGPROF,	"sigprof",	"profiling timer alarm"},
#endif
#ifdef SIGPWR
    { SIGPWR,	"sigpwr",	"power-fail restart"},
#endif
#ifdef SIGQUIT
    { SIGQUIT,	"sigquit",	"quit"},
#endif
#ifdef SIGSEGV
    { SIGSEGV,	"sigsegv",	"segmentation violation"},
#endif
#ifdef SIGSTKFLT
    { SIGSTKFLT,	"sigstkflt",	"stack fault"},
#endif
#ifdef SIGSTOP
    { SIGSTOP,	"sigstop",	"stopped by program"},
#endif
#ifdef SIGSYS
    { SIGSYS,	"sigsys",	"invalid argument to system call"},
#endif
#ifdef SIGTERM
    { SIGTERM,	"sigterm",	"terminated"},
#endif
#ifdef SIGTHAW
    { SIGTHAW,	"sigthaw",	"cpr thaw"},
#endif
#ifdef SIGTRAP
    { SIGTRAP,	"sigtrap",	"trace trap"},
#endif
#ifdef SIGTSTP
    { SIGTSTP,	"sigtstp",	"stopped"},
#endif
#ifdef SIGTTIN
    { SIGTTIN,	"sigttin",	"background tty read"},
#endif
#ifdef SIGTTOU
    { SIGTTOU,	"sigttou",	"background tty write"},
#endif
#ifdef SIGURG
    { SIGURG,	"sigurg",	"urgent condition on i/o channel"},
#endif
#ifdef SIGUSR1
    { SIGUSR1,	"sigusr1",	"user defined signal 1"},
#endif
#ifdef SIGUSR2
    { SIGUSR2,	"sigusr2",	"user defined signal 2"},
#endif
#ifdef SIGVTALRM
    { SIGVTALRM,	"sigvtalrm",	"virtual timer alarm"},
#endif
#ifdef SIGWAITING
    { SIGWAITING,	"sigwaiting",	"lwps blocked"},
#endif
#ifdef SIGWINCH
    { SIGWINCH,	"sigwinch",	"window size change"},
#endif
#ifdef SIGWINDOW
    { SIGWINDOW,	"sigwindow",	"window size change"},
#endif
#ifdef SIGXCPU
    { SIGXCPU,	"sigxcpu",	"exceeded cpu time limit"},
#endif
#ifdef SIGXFSZ
    { SIGXFSZ,	"sigxfsz",	"exceeded file size limit"},
#endif
#ifdef SIGSAK
    { SIGSAK,	"sigsak",	"secure attention key"},
#endif
#ifdef SIGSOUND
    { SIGSOUND,	"sigsound",	"hft sound sequence completed"},
#endif
#ifdef SIGRETRACT
    { SIGRETRACT,	"sigretract",	"hft monitor mode retracted"},
#endif
#ifdef SIGKAP
    { SIGKAP,	"sigkap",	"keep alive poll"},
#endif
#ifdef SIGGRANT
    { SIGGRANT,	"siggrant",	"hft monitor mode granted"},
#endif
#ifdef SIGALRM1
    { SIGALRM1,	"sigalrm1",	"m:n condition alarm"},
#endif
#ifdef SIGVIRT
    { SIGVIRT,	"sigvirt",	"virtual time alarm"},
#endif
#ifdef SIGPRE
    { SIGPRE,	"sigpre",	"programming error"},
#endif
#ifdef SIGMIGRATE
    { SIGMIGRATE,	"sigmigrate",	"migrate process"},
#endif
#ifdef SIGDANGER
    { SIGDANGER,	"sigdanger",	"system crash imminent"},
#endif
#ifdef SIGMSG
    { SIGMSG,	"sigmsg",	"hft input data pending"},
#endif
#ifdef SIGINFO
    { SIGINFO,	"siginfo",	"information request"},
#endif
    { 0, 0, 0}
};

static void barf(const char *msg) {
    fprintf(stderr, "mksignals: %s\n", msg);
    exit(1);
}

int main(void) {
    int maxsig = NUMSIG-1;
    int s;
    struct signaming *snp;
    FILE *outf;

    for (snp = signamings; snp->signo; ++snp)
	if (snp->signo > maxsig)
	    maxsig = snp->signo;

    outf = fopen("sigmsgs.h", "w");
    if (!outf) barf("could not open sigmsgs.h for writing");
    fprintf(outf, "typedef struct {\n");
    fprintf(outf, "\tchar *name, *msg;\n");
    fprintf(outf, "} Sigmsgs;\n");
    fprintf(outf, "extern Sigmsgs signals[];\n");
    fprintf(outf, "#define NUMOFSIGNALS %d\n", maxsig+1);
    if (fclose(outf) == EOF)  barf("could not fclose sigmsgs.h after writing");

    outf = fopen("sigmsgs.c", "w");
    if (!outf) barf("could not open sigmsgs.c for writing");
    fprintf(outf, "#include \"sigmsgs.h\"\n\n");
    fprintf(outf, "Sigmsgs signals[] = {\n");
    fprintf(outf, "\t{\"\",\t\"\"},\n");

    /* yes, we could avoid the quadratic searching with an aux array. fap. */
    for (s = 1; s <= maxsig; ++s) {
        for (snp = signamings; snp->signo && snp->signo != s; ++snp)
	    /* */;
	if (snp->signo)
	    fprintf(outf, "\t{\"%s\",\t\"%s\"},\n",
		    snp->signame, snp->sigmsg);
	else
	    fprintf(outf, "\t{\"sigunknown%d\",\t\"unknown signal %d\"},\n",
		    s, s);
    }
    fprintf(outf, "};\n");
    if (fclose(outf) == EOF) barf("could not fclose sigmsgs.c after writing");
    return 0;
}
