/* printf example */
#include <stdio.h>

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld %lld\n", 1977, 650000L, 1234567890LL);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}

/* output:
Characters: a A 
Decimals: 1977 650000
Preceding with blanks:       1977 
Preceding with zeros: 0000001977 
Some different radices: 100 64 144 0x64 0144 
floats: 3.14 +3e+000 3.141600E+000 
Width trick:    10 
A string 
*/