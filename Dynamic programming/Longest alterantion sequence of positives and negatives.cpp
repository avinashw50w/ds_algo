// dp[i][j] : the longest such sequence ending at position i by either
// excluding or including a[i]
int dp[n][2];

int solve(vector<int> a, int i, int flag) {
	if (i == a.size()) return 0;
	if (dp[i][flag]) return dp[i][flag];

	int inc = 0, exc = 0;
	// if element to be taken is positive
	// and the curr element too is positive
	// then pick it and recurr for remaining elements
	if (a[i] > 0 and flag) {
		flag ^= 1;
		inc = 1 + solve(a, i + 1, pos);
	}
	else if (a[i] < 0 and !flag) {
		flag ^= 1;
		inc = 1 + solve(a, i + 1, flag);
	}
	// don't pick the current element and recurr for remaining elements
	exc = solve(a, i + 1, flag);

	return dp[i][flag] = max(inc, exc);
}

int LAS(vector<int> a) {
	int n = a.size();
	return max(solve(a, 0, 0), solve(a, 0, 1));
}