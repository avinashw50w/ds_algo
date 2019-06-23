/*Find Next Sparse Number
A number is Sparse if there are no two adjacent 1s in its binary representation. 
For example 5 (binary representation: 101) is sparse, but 6 (binary representation: 110) is not sparse.
Given a number x, find the smallest Sparse number which greater than or equal to x.

Examples:

Input: x = 6
Output: Next Sparse Number is 8

Input: x = 4
Output: Next Sparse Number is 4
A Simple Solution is to do following:

1) Write a utility function isSparse(x) that takes a number 
   and returns true if x is sparse, else false.  This function
   can be easily written by traversing the bits of input number.
2) Start from x and do following 
   while(1)
   {
      if (isSparse(x))
         return x;
      else 
         x++
   }

An Efficient Solution can solve this problem without checking all numbers on by one. Below are steps.

1) Find binary of the given number and store it in a 
   boolean array.
2) Initialize last_finalized bit position as 0.
2) Start traversing the binary from least significant bit.
    a) If we get two adjacent 1's such that next (or third) 
       bit is not 1, then 
          (i)  Make all bits after this 1 to last finalized
               bit (including last finalized) as 0. 
          (ii) Update last finalized bit as next bit. 
For example, let binary representation be 01010001011101, we change it to 01010001100000 
(all bits after highlighted 11 are set to 0). Again two 1’s are adjacent, so change binary 
representation to 01010010000000. This is our final answer.*/

int nextSparse(int x)
{

    vector<bool> bin;
    while (x != 0)
    {
        bin.push_back(x&1);
        x >>= 1;
    }
 	// when x becomes 0, we need to push it
    bin.push_back(0);
    int n = bin.size();  

    int last_final = 0;
 
    // Start from second bit (next to LSB)
    for (int i=1; i<n-1; i++)
    {
       if (bin[i-1] == 1 && bin[i] == 1 && bin[i+1] != 1)
       {
            bin[i+1] = 1;

            for (int j=i; j>=last_final; j--)
                bin[j] = 0;
            
            last_final = i+1;
        }
    }
 
    // Find decimal equivalent of modified bin[]
    int ans = 0;
    for (int i=0; i<n; i++)
        ans += bin[i]*(1<<i);
    return ans;
}
