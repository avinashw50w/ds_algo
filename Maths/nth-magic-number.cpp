/*A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5. First few magic numbers are 
5, 25, 30(5 + 25), 125, 130(125 + 5), ….

If we notice carefully the magic numbers can be represented as 001, 010, 011, 100, 101, 110 etc, where 001 is 0*pow(5,3) + 0*pow(5,2) + 1*pow(5,1). 
So basically we need to add powers of 5 for each bit set in given integer n.*/

// Function to find n'th magic numebr
int nthMagicNo(int n)
{
    int pow = 1, answer = 0;
 
    // Go through every bit of n
    while (n)
    {
       pow = pow*5;
 
       // If last bit of n is set
       if (n & 1)
         answer += pow;
 
       // proceed to next bit
       n >>= 1;  // or n = n/2
    }
    return answer;
}