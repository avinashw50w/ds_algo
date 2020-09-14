/*find the number of subsets having sum S*/

int solve(vector<int> a, int S) {
	int sum = 0;
	for (int x : a) sum += x;
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = sum; j >= a[i]; --j) {
			if (dp[j - a[i]]) dp[j] += dp[j - a[i]];
		}
	}
	return dp[S];
}