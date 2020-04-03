/* Given a binary matrix, find the largest square sub-matrix of 1's . */

int maxSubMatrix(int a[][COL], int n, int m) {

	int ans = 0;
	int dp[n+1][m+1];

	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) 
			if(a[i-1][j-1]) {
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])); 
				ans = max(ans, dp[i][j]);
			}
		
	return ans;
}