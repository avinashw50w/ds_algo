/* strcpy example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str1[]="Sample string";
  char str2[40];
  char str3[40];
  strcpy (str2,str1);
  strcpy (str3,"copy successful");
  printf ("str1: %s\nstr2: %s\nstr3: %s\n",str1,str2,str3);
  return 0;
}
Edit & Run


Output:

str1: Sample string
str2: Sample string
str3: copy successful


parameters:	
destination
Pointer to the destination array where the content is to be copied.
source
C string to be copied.


char * strcpy ( char * destination, const char * source );
