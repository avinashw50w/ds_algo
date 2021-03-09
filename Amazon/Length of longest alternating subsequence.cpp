/*given an array of numbers containing positive and negative numbers, return the length of
the longest alternating subsequence
4. Modification of LIS: given an array of integers, return the length of longest alternating subsequence. i.e. 1 -2 3 -4  */

// Aproach 1: using LIS algo
// this can be useful for finding the longest alternating subsequence such that
// absolute value of each element of the subsequence is greater than the absolute value of
// the previous element
int solve(vector<int> a) {
	int n = a.size();
	vector<int> dp(n, 1);
	int ans = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] * a[j] < 0 and dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				ans = max(ans, dp[i]);
			}
		}
	}
	return ans;
}

// Efficient approach:
// this algo don't consider that the abs(a[i]) > abs(a[j]) j < i
bool sign(int n) { return n > 0; }

int solve(vector<int> a) {
	int n = a.size();
	int i = 0, ans = 0;
	while (i < n) {
		int j = i;
		while (j < n and sign(a[i]) == sign(a[j])) j++;
		ans++;
		i = j;
	}

	return ans;
}