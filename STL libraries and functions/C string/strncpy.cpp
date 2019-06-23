/* strncpy example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[]= "To be or not to be";
  char str2[40];
  char str3[40];

  /* copy to sized buffer (overflow safe): */
  strncpy ( str2, str1, sizeof(str2) );

  /* partial copy (only 5 chars): */
  strncpy ( str3, str2, 5 );
  str3[5] = '\0';   /* null character manually added */

  puts (str1);
  puts (str2);
  puts (str3);

  return 0;
}
Edit & Run


Output:

To be or not to be
To be or not to be
To be 


Parameters
destination
Pointer to the destination array where the content is to be copied.
source
C string to be copied.
num
Maximum number of characters to be copied from source.
size_t is an unsigned integral type.

