/*Maximum sum such that no two elements are adjacent
Given an array of positive numbers, find the maximum sum of a subsequence with the
constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10
should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
Answer the question in most efficient way.

Examples :

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110*/

// dp way:
// if a[i] is taken then dp[i] = a[i] + dp[i-2];
// if a[i] not taken then dp[i] = dp[i-1];
// so dp[i] = max(dp[i-1], a[i] + dp[i-2])

int solve(vector<int> a) {
	int n = a.size();
	int dp[n];
	dp[0] = a[0];
	dp[1] = max(a[0], a[1]);
	int ans = 0;
	for (int i = 2; i < n; ++i) {
		dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
		ans = max(ans, dp[i]);
	}

	return ans;
}

//// using three variables
// it also handles all -ve nos : returns 0 
int solve(vector<int> arr) {
	int n = arr.size();
	int a = 0, b = 0, c = 0;

	for (int i = 0; i < n; ++i) {
		c = max(b, a[i] + a);
		a = b;
		b = c;
	}

	return c;
}