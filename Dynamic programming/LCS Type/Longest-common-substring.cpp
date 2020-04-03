
/* eg; abcdaf  and zbcdf , the longest common substring is bcd of length 3. Here we have to find its length. */

int LongestCommonSubstring(string X, int n, string Y, int m) {
	int ans = 0;
	int dp[n+1][m+1];

	fill(&dp[0][0], &dp[0][m], 0);

	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) 
			if (X[i-1] == Y[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans, dp[i][j]);
			}
		
	return ans;
}

////////////////////////////////////////////////////////////////////////
// to also find the substring , traverse back the dp matrix from the 
// position where dp[i][j] is maximum

pair<int, string> LongestCommonSubstring(string X, int n, string Y, int m) {
	int ans = 0, idx_i, idx_j;
	int dp[n+1][m+1];

	fill(&dp[0][0], &dp[0][m], 0);

	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j) 
			if (X[i-1] == Y[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				if(dp[i][j] > ans) {
					ans = dp[i][j];
					idx_i = i;
					idx_j = j;
				}
			}
		
	i = idx_i; j = idx_j;
	string substring = "";

	while(i > 0 and j > 0) {
		if(X[i-1] == Y[j-1]) 
			substring  = X[i-1] + substring;
		i--; j--;
	}

	return make_pair(ans, substring);
}