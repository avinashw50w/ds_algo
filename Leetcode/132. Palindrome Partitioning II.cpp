/*Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.*/

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool p[n][n];
        memset(p, 0, sizeof(p));
        
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                if (l == 1) p[i][i] = 1;
                else if (l == 2) p[i][j] = s[i] == s[j];
                else p[i][j] = s[i] == s[j] && p[i+1][j-1];
            }
        }
        
        const int inf = 1e9;
        int dp[n];
        
        for (int i = 0; i < n; ++i) {
            if (p[0][i]) dp[i] = 0;
            else {
                dp[i] = inf;
                for (int j = 0; j < i; ++j) {
                    if (p[j + 1][i] and dp[i] > dp[j] + 1)
                        dp[i] = dp[j] + 1;
                }
            }
        }
        
        if (dp[n-1] == inf) return 0;
        return dp[n-1];
    }
};