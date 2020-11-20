/* Given a binary matrix, find the largest square sub-matrix of all 1's . */

// dp[i][j] : largest square sub-matrix with (i, j) as the bottom right corner
// dp[i][j] = 1 + min(dp[i-1][j], d[i][j-1], dp[i-1][j-1]);
int maxSubMatrix(int a[][COL], int n, int m) {

	int ans = 0;
	int dp[n + 1][m + 1];

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i - 1][j - 1]) {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
				ans = max(ans, dp[i][j]);
			}

	return ans;
}