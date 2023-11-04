/*Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character*/
class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        int dp[n+1][m+1];
        fill(&dp[0][0], &dp[n][0], 1e9);
        // if b is empty, remove all chars from a
        for (int i = 0; i <= n; ++i) dp[i][0] = i;
        // if a is empty, add all chars of b to a
        for (int i = 0; i <= m; ++i) dp[0][i] = i;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        
        return dp[n][m] == 1e9 ? 0 : dp[n][m];
    }
};