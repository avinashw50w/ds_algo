/*Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:

Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
             excluding 11,22,33,44,55,66,77,88,99*/

/* 3 digit nos with unique digits = 9 * 9 * 8 (using combinatorics) */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        
        int dp[n+1], fac[n+1];
        
        fac[0] = 1; 

        for (int i = 1, m = 9; i <= n; ++i) fac[i] = m * fac[i-1], m--;
    
        dp[1] = 10;
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = 9 * fac[i-1] + dp[i-1];
        }
        
        return dp[n];
    }
};