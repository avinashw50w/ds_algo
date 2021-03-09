/*Given an array of integers, you have to find the longest wiggle suquence.
A wiggle sequence is such that the a1 > a2 < a3 > a4 < ... or a1 < a2 > a3 < a4 > ...
eg. [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
ans = [1, 17, 5, 15, 5, 16, 8]

IDEA: let up[i] = longest alternate subsequnce such that a[i] > a[i-1]
down[i] = longest such subsequence such that a[i] < a[i-1]
So at each step, we can either take a[i] or not.
So if we take a[i] the up[i] = down[i-1] + 1, and if we don't then up[i] = up[i-1]
the up[i] = max(up[i-1], down[i-1] + 1) if a[i] > a[i-1] . eg a[i-2] > a[i-1] < a[i]
and down[i] = max(down[i-1], up[i-1] + 1) if a[i] < a[i-1]. eg a[i-2] < a[i-1] > a[i]
*/

int solve(vector<int> a) {
	int n = a.size();
	vector<int> up(n), down(n);
	up[0] = down[0] = 1;
	int ans = 1;

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1])
			up[i] = max(up[i - 1], down[i - 1] + 1);
		else if (a[i] < a[i - 1])
			down[i] = max(down[i - 1], up[i - 1] + 1);
		ans = max(up[i], down[i]);
	}

	return ans;
}

//////////////////////////////////
// Space Optimized: since we are only considering the previous state
// we can just use 2 variables up and down

int solve(vector<int> a) {
	int n = a.size();
	int up = 1, down = 1;

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1])
			up = down + 1;
		else if (a[i] < a[i - 1])
			down = up + 1;

	}

	return max(up, down);
}

///////////////////////////
// Other NON efficient ways of doing this
int longestAlternatingSubsequence(vector<int> a) {
	int n = a.size();
	/*
	    dp[i][0] stores longest alternating subsequence till A[0..i]
	    where A[i] is greater than the previous element

	    dp[i][1] stores longest alternating subsequence till A[0..i]
	    where A[i] is smaller than the previous element
	*/
	int dp[n][2];

	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i)
		dp[i][0] = dp[i][1] = 1;

	int res = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			// .. > a[j] < a[i]
			// since a[i] > a[j], so dp[i][0] will get updated
			if (a[j] < a[i])
				dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
			// .. < a[j] > a[i]
			if (a[j] > a[i])
				dp[i][1] = max(dp[i][1], 1 + dp[j][0]);

			res = max(res, max(dp[i][0], dp[i][1]));
		}
	}

	return res;
}

/////////////////////////////////////////////////////////////////
// top down approach
vector<vector<int>> dp;
int solve(vector<int> a, int pos, int flag) {
	if (pos == a.size()) return 0;
	if (dp[pos][flag] != -1) return dp[i][flag];

	int res = 0;

	for (int i = pos; i < n; ++i) {
		if (flag and a[i] > a[i - 1])
			res = max(res, 1 + solve(a, i + 1, !flag));
		else if (!flag and a[i] < a[i - 1])
			res = max(res, 1 + solve(a, i + 1, !flag));
		else
			res = max(res, solve(a, i + 1, flag));
	}

	return dp[pos][flag] = res;
}

int LAS(vector<int> a) {
	int n = a.size();
	dp = vector<vector<int>> (n, vector<int> (2, -1));
	// Fix first element and recur for remaining elements.
	// There are two possibilities -

	// 1. Next element is greater (pass true)
	// 2. Next element is smaller (pass false)
	return 1 + max(solve(a, 1, true), solve(a, 1, false));
}

////////////////////////////////////////////////////////////