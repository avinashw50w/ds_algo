/*Given an array of size n. Find the largest subset in which each pair satisfies the following:
for any pair (a,b) either a % b = 0 or b % a = 0
*/
/*sort the array and find the longest increasing subsequence which satisfies that for each element at
index i, it should be divisible by the element at index j where j < i */

int solve(vector<int> a) {
	int n = a.size(), ans = 0;
	vector<int> dp(n, 0);

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] % a[j] == 0 and dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				ans = max(ans, dp[i]);
			}
		}
	}

	return ans;
}