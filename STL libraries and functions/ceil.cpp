#include <stdio.h>      /* printf */
#include <math.h>       /* ceil */

int main ()
{
  printf ( "ceil of 2.3 is %.1f\n", ceil(2.3) );
  printf ( "ceil of 3.8 is %.1f\n", ceil(3.8) );
  printf ( "ceil of -2.3 is %.1f\n", ceil(-2.3) );
  printf ( "ceil of -3.8 is %.1f\n", ceil(-3.8) );
  return 0;
}

/*
Output:

ceil of 2.3 is 3.0
ceil of 3.8 is 4.0
ceil of -2.3 is -2.0
ceil of -3.8 is -3.0
*/
