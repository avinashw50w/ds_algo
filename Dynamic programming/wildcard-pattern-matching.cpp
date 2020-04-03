// time : O(n * m), where n and m are the size of the text and pattern resprectively
// space : O(n * m)
bool match(string txt, string pat, int n, int m) {
	if(m == 0) return (n == 0);

	bool dp[n+1][m+1];
	memset(dp, false, sizeof(dp));
	// empty pattern can match with empty string
	dp[0][0] = true;
	// Only '*' can match with empty string
	for(int i = 1; i <= m; ++i) {
		if(pat[i-1] == '*')
			dp[0][i] = dp[0][i-1];
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {

			if(txt[i-1] == pat[j-1] || pat[j-1] == '?')
				dp[i][j] = dp[i-1][j-1];

			else if(pat[j-1] == '*')
				dp[i][j] = dp[i-1][j] || dp[i][j-1];

			else dp[i][j] = false;
		}
	}

	return dp[n][m];
}

///////////////////////////////////////////////////////////////
// space optimized : O(n) //

bool match(string txt, string pat, int n, int m) {
	if(m == 0) return (n == 0);

	bool dp[2][m+1];
	memset(dp, false, sizeof(dp));

	dp[0][0] = true;

	for(int i = 1; i <= m; ++i) {
		if(pat[i-1] == '*')
			dp[0][i] = dp[0][i-1];
	}

	for(int i = 1; i <= n; ++i) {
		int ii = i&1;
		for(int j = 1; j <= m; ++j) {

			if(txt[i-1] == pat[j-1] || pat[j-1] == '?')
				dp[ii][j] = dp[1-ii][j-1];

			else if(pat[j-1] == '*')
				dp[ii][j] = dp[1-ii][j] || dp[ii][j-1];

			else dp[ii][j] = false;
		}
	}

	return dp[n&1][m];
}