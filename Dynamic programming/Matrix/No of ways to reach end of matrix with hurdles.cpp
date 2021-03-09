/*Given a grid with '.' and '*', where '.' represents a free path while '*' represents a hurdle.
If you start from (0, 0), find the no of ways to reach the bottom right corner of the grid.*/

const int maxn = 1e3;
int dp[maxn][maxn];

int sovle(vector<vector<int>> grid) {
	int n = grid.size(), m = grid[0].size();

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i) dp[i][j] += dp[i - 1][j];
			if (j) dp[i][j] += dp[i][j - 1];
			if (grid[i][j] == '*')
				dp[i][j] = 0;
		}
	}

	return dp[n - 1][m - 1];
}