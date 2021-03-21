#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> mat, int k) {
	int n = mat.size();
	int m = mat[0].size();

	int dp[n][m];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			dp[i][j] = mat[i][j];
			if (i) dp[i][j] += dp[i-1][j];
			if (j) dp[i][j] += dp[i][j-1];
			if (i and j) dp[i][j] -= dp[i-1][j-1];
		}

	int ans = 0;
	for (int i = n-1; i-k >= 0; --i)
		for (int j = m-1; j-k >= 0; --j) {
			int x = dp[i][j] - dp[i][j-k] - dp[i-k][j] + dp[i-k][j-k];
			ans = max(ans, x);
		}

	return ans;
}

int main() {
	vector<vector<int>> mat = {{1, 1, 1, 1, 1}, 
						        {2, 2, 2, 2, 2}, 
						        {3, 8, 6, 7, 3}, 
						        {4, 4, 4, 4, 4}, 
						        {5, 5, 5, 5, 5}, 
						    }; 
	int K = 3;
	cout << solve(mat, K);
}