/* memset example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  memset (str,'-',6);
  puts (str);
  return 0;
}
Edit & Run


Output:

------ every programmer should know memset!



Parameters
ptr
Pointer to the block of memory to fill.
value
Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
num
Number of bytes to be set to the value.
size_t is an unsigned integral type.

