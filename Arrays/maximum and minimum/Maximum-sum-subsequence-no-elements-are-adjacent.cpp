
int maxSum(vector<int> A) {
	int n = A.size();
	int a = 0, b = A[0], c = b;
	for (int i = 1; i < n; ++i) {
		c = max(b, a + A[i]);
		a = b;
		b = c;
	}

	return c;
}

////////////////////////////////////////
// dp way

dp[n];

dp[0] = a[0];
dp[1] = max(a[0], a[1]);

for (int i = 2; i < n; ++i)
	dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);


return max(dp[n - 2], dp[n - 1]);
