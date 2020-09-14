// find the minimum difference between any two pairs of subset sums.

int solve(vector<int> a) {
	int sum = 0;
	for (int x : a) sum += x;

	vector<int> dp(sum + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < a.size(); ++i) {
		for (int j = sum; j >= a[i]; --j) dp[j] |= dp[j - a[i]];
	}

	int ans = INT_MAX;
	for (int i = sum / 2; i >= 0; --i) {
		if (dp[i]) {
			ans = sum - 2 * i;
			break;
		}
	}

	return ans;
}