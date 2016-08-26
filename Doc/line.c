#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main (int ac, char* av[])
{
  int l;
  char buf[1024];
  const char* p = fgets(buf, sizeof(buf)-1, stdin);
  if (! p) {
    return 1;
  }

  l = strlen(buf);
  /*
  fprintf(stderr, "L=%d, b=<%s>\n", l, buf);
  */

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

