/*given an NxM matrix, find the no of KxK submatrices with sum X */

int solve(vector<vector<int>> mat, int K, int X) {
	int n = mat.size(), m = mat[0].size();

	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dp[i + 1][j + 1] = mat[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];

	int ans = 0;
	for (int i = 0; i + K < n; ++i) {
		for (int j = 0; j + K < m; ++j) {
			int sum = dp[i + K][j + K] - dp[i + K][j] - dp[i][j + K] + dp[i][j];
			ans += sum == X;
		}
	}
	return ans;
}