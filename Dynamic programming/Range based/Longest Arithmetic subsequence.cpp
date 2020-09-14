/*Find the longest arithmetic subsequence in an array A.
IDEA: a b c are in AP, then b-a = c-b => 2*b = a + c => a = 2*b - c;

let dp[i][j] = longest AP subsequence ending with A[i] and A[j]
so, if A[i] and A[j] are the last two terms, then the previous term will be x = 2*A[i] - A[j],
lets say the index of x is k, then
dp[i][j] = dp[k][i] + 1
*/


int solve(vector<int> a) {
	int n = a.size();
	if (n <= 2) return n;
	vector<vector<int>> dp(n, vector<int>(n, 2));
	unordered_map<int, int> index;

	int ans = 2;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int x = 2 * a[i] - a[j];
			if (index.count(x) == 0) continue;
			dp[i][j] = dp[index[x]][i] + 1;
			ans = max(ans, dp[i][j]);
		}
		index[a[i]] = i;
	}

	return dp[]
}