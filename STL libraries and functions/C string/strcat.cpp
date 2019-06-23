/* strcat example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[80];
  strcpy (str,"these ");
  strcat (str,"strings ");
  strcat (str,"are ");
  strcat (str,"concatenated.");
  puts (str);
  return 0;
}
Edit & Run


Output:

these strings are concatenated. 



Parameters
destination
Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string.
source
C string to be appended. This should not overlap destination.

