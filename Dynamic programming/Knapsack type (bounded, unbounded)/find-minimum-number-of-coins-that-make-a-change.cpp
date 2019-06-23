/*Find minimum number of coins that make a given value
Given a value V, if we want to make change for V cents, and we have infinite supply of 
each of C = { C1, C2, .. , Cn} valued coins, what is the minimum number of coins to make the change?

Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents */

// no of coins required to make a change of sum
int solve(int coins[], int n, int sum) {
	int dp[sum+1];
	fill(dp, dp+sum+1, INT_MAX);
	dp[0] = 0;

	// pick a coin
	for (int i = 0; i < n; ++i) {
		// pick a sum to be represented with coins[i]
		for (int j = coins[i]; j <= sum; ++j)
			if (dp[j-coins[i]] != INT_MAX) dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
	}

	return dp[sum];
}

// recursive //
#define INF 100000000
int solve(int a[], int n, int sum) {
	if(sum == 0) return 0; // coins required to make sum of 0 is 0

	int res = INF;

	for(int i = 0; i < n; ++i) {
		if(a[i] <= sum) {
			int t = solve(a, n, sum-a[i]);

			if (1 + t < res)
				res = 1 + t;
		}
	}
	return res;
}

// dp solution //

int solve(int a[], int n, int sum) {

	int dp[sum + 1];

	fill(dp, dp+sum+1, INF);
	dp[0] = 0;

	for(int S = 1; S <= sum; ++S) {
		for(int i = 0; i < n; ++i)
			if(a[i] <= S and 1 + dp[S-a[i]] < dp[S])
				dp[S] = 1 + dp[S-a[i]];
	}

	return dp[sum];
}

