#include <stdio.h>
#include <setjmp.h>
#include <stdnoreturn.h>
 
/*******************************************************************
The two differently compiled executables behave differently:

With variable count volatile, the loop finishes after 9 iterations.
  $ gcc -O3 -W -DVOLATILE=1 -o v volatile.c
  $ ./v

With variable count non-volatile, the program does not finish.
  $ gcc -O3 -W -DVOLATILE=0 -o v volatile.c
  $ ./v

With optimizations -O1, -O2, and -O3 the same behavior as above can be
observerd. With -O0 program finishes with and without volatile.
*******************************************************************/

/******************************************************************/
static jmp_buf buf;

/******************************************************************/
static
void optimize_me()
{
}

/******************************************************************/
int f(int x)
{
#if VOLATILE
  volatile
#endif
  int foo;

  foo = 5;
  if ( setjmp(buf) != 2 ) {
    if ( foo != 5 ) {
      optimize_me();
      longjmp(buf, 2);
    }
    foo = 6;
    printf("foo=%d\n", foo);
    longjmp( buf, 1 );
    return 1;
  }
  return 0;
}

/******************************************************************/
int main()
{
  f(3);
  return 0;
}
