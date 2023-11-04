/*Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

Example 1:

Input: 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.*/

class Solution {
public:
    
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(dp[j], j) * max(dp[i-j], i-j));
            }
        }
        
        return dp[n];
    }
};