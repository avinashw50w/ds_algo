/* Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be 
none) of the characters without disturbing the remaining characters' relative positions. (i.e., 
"ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit*/

int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    // dp[i][j] - no of such subsequences when first i chars of s and first j chars of t are taken
    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    // if t is empty, then only an empty subsequence can match with t
    for (int i = 0; i <= m; ++i) dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // don't take the ith char of s
            dp[i][j] = dp[i-1][j];
            // if s[i] matches with t[j] then either include it of exclude it
            if (s[i-1] == t[j-1])
                dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[n][m];
}

////////////////////////////////////////////////////////////////
// top down
int numDistinct(string s, string t) {
    if (s.empty() && t.empty()) {
        // Both the strings are empty, then t is subsequence of s
        return 1;
    }

    if (s.empty() || t.empty()) {
        // If s is empty and t is not empty, then t is not a subsequence of s
        // If t is empty and s is not empty, then t is a subsequence of s ie..,
        //  "" is always a substring/subsequence of s
        return t.empty() ;
    }

    string sWithOutLastChar = s.substr(0, s.length() - 1);
    string tWithOutLastChar = t.substr(0, t.length() - 1);

    if (s[s.length() - 1] == t[t.length() - 1]) {
        // If both last chars are matching, need to evaluate the subproblems by excluding
        // the last char from s and other subproblem by excluding both the last chars from
        // s and t
        return numDistinct(sWithOutLastChar, t) + numDistinct(sWithOutLastChar, tWithOutLastChar);
    }

    // If last chars doesn't match then subsequence should be found in excluding last char of s
    return numDistinct(sWithOutLastChar, t);
}
