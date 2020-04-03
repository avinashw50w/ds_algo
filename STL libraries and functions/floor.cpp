/* floor example */
#include <stdio.h>      /* printf */
#include <math.h>       /* floor */

int main ()
{
  printf ( "floor of 2.3 is %.1lf\n", floor (2.3) );
  printf ( "floor of 3.8 is %.1lf\n", floor (3.8) );
  printf ( "floor of -2.3 is %.1lf\n", floor (-2.3) );
  printf ( "floor of -3.8 is %.1lf\n", floor (-3.8) );
  return 0;
}

/*
Output:

floor of 2.3 is 2.0
floor of 3.8 is 3.0
floor of -2.3 is -3.0
floor of -3.8 is -4.0
*/
