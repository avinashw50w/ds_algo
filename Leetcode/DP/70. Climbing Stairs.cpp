/*You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


exp: dp[i]: no of ways to reach the ith step

dp[i] = no of ways to reach i-1th step + no of ways to reach i-2th step
dp[i] = dp[i-1] + dp[i-2] 

just find the nth fibonacci no. */

class Solution {
public:
    int climbStairs(int n) {
        return round((1.0/sqrt(5)) * (pow((1 + sqrt(5))/2, n+1)));
    }
};