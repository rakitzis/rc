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
static jmp_buf jump_buffer;
  
/******************************************************************/
static
/*noreturn*/
void
a(int count) 
{
  printf("a(%d) called\n", count);
  longjmp(jump_buffer, count+1); // will return count+1 out of setjmp
}
           
/******************************************************************/
int main(void)
{
#if VOLATILE
  volatile 
#endif
  int count = 0; // modified local vars in setjmp scope must be volatile

  if (setjmp(jump_buffer) != 9) { // compare against constant in an if
    a(count++);
  }
  return 0;
}

