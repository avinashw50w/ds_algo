
// returns the number of ways to reach the n'th stair when a person
// can take steps of 1, 2, 3, _____, m at a time

// dp[i] denotes the no of ways to reach the ith stair
int count(int n, int m) {
	int dp[n+1] = {};
	dp[0] = dp[1] = 1;

	// for i-th stair
	for(int i = 2; i <= n; ++i) {
		// taking j-th no of steps at a time
		for(int j = 1; j <= m and j <=i; ++j)
			dp[i] += dp[i-j];
	}

	return dp[n];
}