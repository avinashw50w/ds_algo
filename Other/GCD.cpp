/*GCD
The greatest common divisor (GCD) of two numbers a and b is the greatest number that divides evenly into both a and b. Naively we could start from the 
smallest of the two numbers and work our way downwards until we find a number that divides into both of them:*/

for (int i=Math.min(a,b); i>=1; i--)
   if (a%i==0 && b%i==0)
      return i;
/*Although this method is fast enough for most applications, there is a faster method called Euclid’s algorithm. Euclid’s algorithm iterates over the two 
numbers until a remainder of 0 is found. For example, suppose we want to find the GCD of 2336 and 1314. We begin by expressing the larger number (2336) in
 terms of the smaller number (1314) plus a remainder:

2336 = 1314 x 1 + 1022
We now do the same with 1314 and 1022:

1314 = 1022 x 1 + 292
We continue this process until we reach a remainder of 0:

1022 = 292 x 3 + 146
292 = 146 x 2 + 0
The last non-zero remainder is the GCD. So the GCD of 2336 and 1314 is 146. This algorithm can be easily coded as a recursive function:*/

//assume that a and b cannot both be 0
public int GCD(int a, int b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}
//Using this algorithm we can find the lowest common multiple (LCM) of two numbers. For example the LCM of 6 and 9 is 18 since 18 is the smallest number 
//that divides both 6 and 9. Here is the code for the LCM method:

public int LCM(int a, int b)
{
   return b*a/GCD(a,b);
}
//As a final note, Euclid’s algorithm can be used to solve linear Diophantine equations. These equations have integer coefficients and are of the form:

ax + by = c
