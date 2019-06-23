// invert k bits from position pos in an integer

the mask required will be 
int mask = (~((~0) << k)) << pos;

First, extract them into y:

y = x & mask
Then, invert y and get only the bits you need:

y = ~y & mask
Clear the bits extracted from x:

x = x & (~mask)
OR those 2 numbers to get the result:

x = x | y

/* eg. x = 13 = 1011 , we need to invert 2 bits from position 1, so that the final ans is 1101 = 13 

mask = 0110 

y = x & mask = 1011 & 0110 = 0010

y = ~y & mask = 1101 & 0110 = 0100

x = x & ~mask = 1011 & 1001 = 1001

x = x | y = 1001 | 0100 = 1101 = 13

*/