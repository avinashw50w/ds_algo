/*Maximum sum such that no two elements are adjacent
Given an array of positive numbers, find the maximum sum of a subsequence with the 
constraint that no 2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 
should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).
Answer the question in most efficient way.

Examples :

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110*/

int solve(int a[], int n) {

	int dp[n] = {0};

	dp[0] = a[0];
	dp[1] = max(a[0], a[1]);

	for (int i = 2; i < n; ++i)
		dp[i] = max(dp[i-1], a[i] + dp[i-2]);

	return dp[n-1];
}

////////////////////////////////////
// O(1) space

int solve(int a[], int n) {

	int inc = a[0];
	int exc = 0;

	for (int i = 1; i < n; ++i) {

		int tmp = max(inc, exc);

		inc = a[i] + exc; // dp[i] = a[i] + dp[i-2]
		exc = tmp; // dp[i-1] = max(dp[i-2], dp[i-1])
	}
}