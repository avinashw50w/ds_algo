// unbounded knapsack (if each item is available in infinite quantities and can be chosen multiple times)

// Time: O(N^2)
// space: O(N)
int Knapsack(int wt[], int val[], int N, int W) {

	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < N; ++i)
		for (int j = wt[i]; j <= W; ++j)
			dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);

	return dp[W];
}

///////////////////////////////////////
// Time: O(N^2)
// space: O(N)

int knapsack(int wt[], int val[], int N, int W) {
	int dp[N + 1][W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= W; ++j) {
			dp[i][j] = dp[i - 1][j];

			if (wt[i - 1] <= j)
				dp[i][j] = dp[i][j - wt[i - 1]]; // here ith element can be taken multiple times
		}
	}

	return dp[N][W];
}