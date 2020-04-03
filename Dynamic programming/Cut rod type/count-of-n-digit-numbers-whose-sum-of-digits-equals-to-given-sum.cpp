/* count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum
Given two integers ‘n’ and ‘sum’, find count of all n digit numbers with sum of digits as ‘sum’. Leading 0’s are not counted as digits.
1 <= n <= 100 and 1 <= sum <= 50000

Example:

Input:  n = 2, sum = 2
Output: 2
Explanation: Numbers are 11 and 20

Input:  n = 2, sum = 5
Output: 5
Explanation: Numbers are 14, 23, 32, 41 and 50

The idea is simple, we subtract all values from 0 to 9 from given sum and recur for sum minus that digit. Below is recursive formula.

     countRec(n, sum) = ∑CountRec(n-1, sum-x)
                           where 0 =< x <= 9 and
                                 sum-x >= 0
    One important observation is, leading 0's must be
    handled explicitly as they are not counted as digits.
    So our final count can be written as below.
     
    finalCount(n, sum) = ∑CountRec(n-1, sum-x)
                            where 1 =< x <= 9 and
                                 sum-x >= 0
 */

// Recursive function to count 'n' digit numbers
// with sum of digits as 'sum'. This function
// considers leading 0's also as digits, that is
// why not directly called
unsigned long long int countRec(int n, int sum)
{
    // Base case
    if (n == 0)
       return sum == 0;
 
    // Initialize answer
    unsigned long long int ans = 0;
 
    // Traverse through every digit and count
    // numbers beginning with it using recursion
    for (int i=0; i<=9; i++)
       if (sum-i >= 0)
          ans += countRec(n-1, sum-i);
 
    return ans;
}
 
// This is mainly a wrapper over countRec. It
// explicitly handles leading digit and calls
// countRec() for remaining digits.
unsigned long long int finalCount(int n, int sum)
{
    // Initialize final answer
    unsigned long long int ans = 0;
 
    // Traverse through every digit from 1 to
    // 9 and count numbers beginning with it
    for (int i = 1; i <= 9; i++)
      if (sum-i >= 0)
         ans += countRec(n-1, sum-i);
 
    return ans;
}
 ////////////////////////////////////////////////////////////////////////////
// dp //
unsigned long long int countRec(int n, int sum)
{
    if (n == 0)
       return sum == 0;
 
    if (lookup[n][sum] != -1)
       return lookup[n][sum];
 
    unsigned long long int ans = 0;
 
    for (int i=0; i<10; i++)
       if (sum-i >= 0)
          ans += countRec(n-1, sum-i);
 
    return lookup[n][sum] = ans;
}
 
// For handing first digit and count possibilities
// for the remaining digits
unsigned long long int finalCount(int n, int sum)
{
    memset(lookup, -1, sizeof lookup);
 
    unsigned long long int ans = 0;
 
    for (int i = 1; i <= 9; i++)
      if (sum-i >= 0)
         ans += countRec(n-1, sum-i);
    
    return ans;
}