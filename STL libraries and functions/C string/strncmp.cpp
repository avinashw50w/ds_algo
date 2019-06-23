/* strncmp example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
  int n;
  puts ("Looking for R2 astromech droids...");
  for (n=0 ; n<3 ; n++)
    if (strncmp (str[n],"R2xx",2) == 0)
    {
      printf ("found %s\n",str[n]);
    }
  return 0;
}
Edit & Run


Output:

Looking for R2 astromech droids...
found R2D2
found R2A6

Parameters
str1
C string to be compared.
str2
C string to be compared.
num
Maximum number of characters to compare.
size_t is an unsigned integral type.

Return Value
Returns an integral value indicating the relationship between the strings:
return value	indicates
<0	the first character that does not match has a lower value in str1 than in str2
0	the contents of both strings are equal
>0	the first character that does not match has a greater value in str1 than in str2
