#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define DEBUG 0


int main (int ac, char* av[])
{
    int l;
    char buf[4096 + 1];
    const char* const p = fgets(buf, sizeof(buf)-1, stdin);

    if (! p) {
#if DEBUG
        fprintf(stderr, "NULL read\n");
#endif
        return 1;
    }

    l = strlen(buf);
#if DEBUG
    fprintf(stderr, "L=%d, b=<%s>\n", l, buf);
#endif

    if (l <= 1) {  // empty or newline alone
        return 1;
    } else {
        if (buf[l-1] == '\n') {
            buf[l-1] = '\0';
            --l;
        }
        write(1, buf, l);
        return 0;
    }
    return 1;
}

