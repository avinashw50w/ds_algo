/* strncat example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[20];
  char str2[20];
  strcpy (str1,"To be ");
  strcpy (str2,"or not to be");
  strncat (str1, str2, 6);
  puts (str1);
  return 0;
}
Edit & Run


Output:

To be or not



Parameters
destination
Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string, including the additional null-character.
source
C string to be appended.
num
Maximum number of characters to be appended.
size_t is an unsigned integral type.

