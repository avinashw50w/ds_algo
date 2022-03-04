/*Find the length of the longest substring which is repeated in the string s and does
not overlap with each other.

IDEA: let dp[i][j] - the length of the longest such substring where the first substring
ends at i and the repeated one ends at j

so if s[i] == s[j] and dp[i-1][j-1] < j-i, then include this char
otherwise dp[i][j] = 0

dp[i][j] = 1 + dp[i-1][j-1] if s[i] == s[j] and dp[i-1][j-1] < j-i
         = 0 otherwise
*/

int solve(string s) {
    int n = s.length();
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) {
            if (s[i-1] == s[j-1] and dp[i-1][j-1] < j-i) 
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}
