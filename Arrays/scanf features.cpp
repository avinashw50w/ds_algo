//Program to illustrate %[^] specifier
/* %[] : It allows you to specify a set of characters to be stored away (likely in an array of chars). 
		Conversion stops when a character that is not in the set is matched.
   %[^(x)] : Conversion stops when a character is matched with x  */

#include <stdio.h>

int main()
{
char *ptr="fruit|apple|lemon",type[10],fruit1[10],fruit2[10];

sscanf(ptr, "%[^|]%*c%[^|]%*c%s", type,fruit1, fruit2);
printf("%s,%s,%s",type,fruit1,fruit2);
}

// output : fruit,apple,lemon