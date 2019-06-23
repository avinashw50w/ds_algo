/* strstr example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="This is a simple string";
  char * pch;
  pch = strstr (str,"simple");
  strncpy (pch,"sample",6);
  puts (str);
  return 0;
}
Edit & Run

This example searches for the "simple" substring in str and replaces that word for "sample".

Output:

This is a sample string



str1
C string to be scanned.
str2
C string containing the sequence of characters to match.

Return Value
A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2, or a null pointer if the sequence is not present in str1.


char * strstr ( const char *, const char * ); 
