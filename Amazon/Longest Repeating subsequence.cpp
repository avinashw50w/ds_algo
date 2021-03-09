/*Given a string, find length of the longest repeating subseequence such that the two
subsequence don't have same string character at same position, i.e., any i'th character in the
two subsequences shouldn't have the same index in the original string.
eg. str = AABEBCDD
output: 3 (ABD)

IDEA: similar to LCS
AABEBCDD
AABEBCDD
let dp[i][j] = the longest repeating subsequence btw index i and j
dp[i][j] = 1 + dp[i-1][j-1] if s[i-1]=s[j-1] and i != j
		 = max(dp[i-1][j], dp[i][j-1]) , otherwise
*/

int solve(string s) {
	int n = s.length();
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s[i - 1] == s[j - 1] and i != j)
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][n];
}
