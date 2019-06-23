/* memcmp example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char buffer1[] = "DWgaOtP12df0";
  char buffer2[] = "DWGAOTP12DF0";

  int n;

  n=memcmp ( buffer1, buffer2, sizeof(buffer1) );

  if (n>0) printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
  else if (n<0) printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
  else printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);

  return 0;
}

/*

Output:

'DWgaOtP12df0' is greater than 'DWGAOTP12DF0'.

DWgAOtp12Df0 is greater than DWGAOTP12DF0 because the first non-matching character in both words are 'g' and 'G' respectively, and 'g' (103) evaluates as greater than 'G' (71).

*/