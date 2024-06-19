#include "edit-bestline.c"
#include "version.h"
#include "acutest.h"

#define TEST_CHECK_INT(var, expected) \
	(TEST_CHECK_(var == expected, "%s = %i (exp.: %i)", \
		#var, (int)var, (int)expected))

#define TEST_ASSERT_INT(var, expected) \
	TEST_ASSERT_(var == expected, "%s = %i (exp.: %i)", \
		#var, (int)var, (int)expected)

#define TEST_CHECK_STR(var, expected) \
	(TEST_CHECK_(streq(var, expected), "%s = \"%s\" (exp.: \"%s\")", \
		#var, var, expected))


bool dashdee, dashee, dasheye, dashell, dashen;
bool dashpee, dashoh, dashess, dashvee, dashex;
bool interactive;
char *dashsee[2];
pid_t rc_pid;
char* envp[] = {
	"PATH=/tmp/rc/fakebin",
	"fn_edit={emacs $*}",
	"fn_editor={ed $*}",
	"fn_v={vim $*}",
	NULL};

bestlineCompletions lc = {0};

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

static void init(void) {
	static bool executed = 0;
	if (executed) return;
	rc_pid = getpid();
	inithash();
	assigndefault("ifs", " ", "\t", "\n", (void *)0);
	assigndefault("nl", "\n", (void *)0);
	assigndefault("pid", nprint("%d", rc_pid), (void *)0);
	assigndefault("prompt", "; ", "", (void *)0);
	assigndefault("tab", "\t", (void *)0);
	assigndefault("version", VERSION, (void *)0);
	executed = 1;
}

static void reset_completions(void) {
	bestlineFreeCompletions(&lc);
	lc.len = 0;
	lc.cvec = NULL;
}

void test_quote(void) {
	TEST_CHECK_STR(quote("my file"), "'my file'");
	TEST_CHECK_STR(quote("it's a file"), "'it''s a file'");
}

void test_strip_quotes(void) {
	char str[] = "'my file'";
	strip_quotes(str);
	TEST_CHECK_STR(str, "my file");
	char str2[] = "my' 'file";
	strip_quotes(str2);
	TEST_CHECK_STR(str2, "my file");
	char str3[] = "my fi'le";
	strip_quotes(str3);
	TEST_CHECK_STR(str3, "my file");
	char str4[] = "my''file";
	strip_quotes(str4);
	TEST_CHECK_STR(str4, "myfile");
	char str5[] = "'my''file";
	strip_quotes(str5);
	TEST_CHECK_STR(str5, "my'file");
}

void test_findbeginningoftoken(void) {
	TEST_CHECK_INT(findbeginningoftoken("echo hello", 10), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo 'hello", 11), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo 'hello wo", 14), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo 'hello world'", 18), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo hello' 'world", 18), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo hello^' '^world", 20), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo hello' world'", 18), 5);
	TEST_CHECK_INT(findbeginningoftoken("echo 'it''s me", 14), 5);
	TEST_CHECK_INT(findbeginningoftoken("ls '/home/x/My Docum", 20), 3);
}

void test_completion_builtins(void) {
	init();

	// one match
	reset_completions();
	completion("buil", 4, &lc);
	TEST_CHECK_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "builtin");

	// two matches
	reset_completions();
	completion("ex", 2, &lc);
	TEST_CHECK(lc.len == 2);
	TEST_CHECK_STR(lc.cvec[0], "exec");
	TEST_CHECK_STR(lc.cvec[1], "exit");

	// no matches
	reset_completions();
	completion("d", 1, &lc);
	TEST_CHECK_INT(lc.len, 0);

	// one match, cursor in word (between 'i' and 'l')
	reset_completions();
	completion("buil", 3, &lc);
	TEST_CHECK_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "builtinl");

	// one match, cursor not at end
	reset_completions();
	completion("what $PATH", 4, &lc);
	TEST_CHECK_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "whatis $PATH");
}

void test_completion_functions(void) {
	init();
	initenv(envp);

	// no matches
	reset_completions();
	add_completions("xy", 0, 2, &compl_fn, &lc);
	TEST_CHECK_INT(lc.len, 0);

	// two matches
	reset_completions();
	add_completions("ed", 0, 2, &compl_fn, &lc);
	TEST_ASSERT_INT(lc.len, 2);
	TEST_CHECK_STR(lc.cvec[0], "edit");
	TEST_CHECK_STR(lc.cvec[1], "editor");

	// two matches, cursor not at end
	reset_completions();
	add_completions("ed myfile", 0, 2, &compl_fn, &lc);
	TEST_ASSERT_INT(lc.len, 2);
	TEST_CHECK_STR(lc.cvec[0], "edit myfile");
	TEST_CHECK_STR(lc.cvec[1], "editor myfile");
}

void test_completion_commands(void) {
	init();
	initenv(envp);

	// one match
	reset_completions();
	completion("vi", 2, &lc);
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "vim");

	// two matches
	reset_completions();
	add_completions("e", 0, 1, &compl_extcmd, &lc);
	TEST_ASSERT_INT(lc.len, 2);
	TEST_CHECK_STR(lc.cvec[0], "ed");
	TEST_CHECK_STR(lc.cvec[1], "emacs");

	// no matches
	reset_completions();
	completion("xy", 2, &lc);
	TEST_CHECK_INT(lc.len, 0);
}

void test_completion_variables(void) {
	init();
	initenv(envp);

	// one match
	reset_completions();
	completion("echo $PA", 8, &lc);
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "echo $PATH");

	// no matches
	reset_completions();
	completion("echo $XY", 8, &lc);
	TEST_CHECK(lc.len == 0);
}

void test_completion_filenames(void) {
	init();
	initenv(envp);

	// no matches
	reset_completions();
	add_completions("ls /tmp/rc/x", 3, 12, &compl_filename, &lc);
	TEST_CHECK(lc.len == 0);

	// one match
	reset_completions();
	add_completions("ls /tmp/rc/he", 3, 13, &compl_filename, &lc);
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "ls /tmp/rc/hello");

	// three matches, one of them with whitespace
	reset_completions();
	add_completions("ls /tmp/rc/", 3, 11, &compl_filename, &lc);
	TEST_ASSERT_INT(lc.len, 5);
	TEST_CHECK_STR(lc.cvec[0], "ls /tmp/rc/fakebin");
	TEST_CHECK_STR(lc.cvec[1], "ls /tmp/rc/hello");
	TEST_CHECK_STR(lc.cvec[2], "ls '/tmp/rc/it''s rc'");
	TEST_CHECK_STR(lc.cvec[3], "ls /tmp/rc/world");
	TEST_CHECK_STR(lc.cvec[4], "ls '/tmp/rc/world wide'");

	// empty string
	reset_completions();
	completion("ls ", 3, &lc);
	TEST_CHECK(lc.len > 0);

	// with ~, one match
	reset_completions();
	// call completion instead of add_completions to get ~ expanded
	completion("ls ~/.", 6, &lc);
	TEST_ASSERT(lc.len > 0);

	// before space, unquoted, two matches
	reset_completions();
	completion("ls /tmp/rc/wor", 14, &lc);
	TEST_ASSERT_INT(lc.len, 2);
	TEST_CHECK_STR(lc.cvec[0], "ls /tmp/rc/world");
	TEST_CHECK_STR(lc.cvec[1], "ls '/tmp/rc/world wide'");

	// after space, quoted, one match
	reset_completions();
	completion("ls '/tmp/rc/world wi", 20, &lc);
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "ls '/tmp/rc/world wide'");

	// quoted space, one match
	reset_completions();
	completion("ls /tmp/rc/world' ", 18, &lc);
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "ls '/tmp/rc/world wide'");

	// quoted space, one match
	reset_completions();
	completion("ls /tmp/rc/'world ", 18, &lc);
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "ls '/tmp/rc/world wide'");

	// empty quotes, one match
	reset_completions();
	completion("ls /tmp/rc/it''", 15, &lc);
	// '' does not expand to a single quote. It's an empty string and can be ignored.
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "ls '/tmp/rc/it''s rc'");

	// escaped single quote, one match
	reset_completions();
	completion("ls '/tmp/rc/it''", 16, &lc);
	// Now, '' is an escaped single quote and must not be ignored.
	TEST_ASSERT_INT(lc.len, 1);
	TEST_CHECK_STR(lc.cvec[0], "ls '/tmp/rc/it''s rc'");
}

TEST_LIST = {
	{ "quote", test_quote },
	{ "stripquotes", test_strip_quotes },
	{ "beginning", test_findbeginningoftoken },
	{ "builtins", test_completion_builtins },
	{ "functions", test_completion_functions },
	{ "commands", test_completion_commands },
	{ "variables", test_completion_variables },
	{ "filenames", test_completion_filenames },
	{ NULL, NULL }     /* zeroed record marking the end of the list */
};
