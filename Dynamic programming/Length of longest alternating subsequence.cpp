/*given an array of numbers containing positive and negative numbers, return the no. of contiguous subsequences which sum to 0.
4. Modification of LIS: given an array of integers, return the length of longest alternating subsequence. i.e. a<b>c<d>e  */

int longestAlternatingSubsequence(int a[], int n) {
	int dp[n] = {};
	memset(dp, 1, sizeof(dp));

	bool flag = true; // check for '<'

	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(flag) {
				if(a[j] < a[i] and dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
			else {
				if(a[j] > a[i] and dp[j] + 1 > dp[i])
					dp[i] = dp[j] + 1;
			}
			flag = !flag;
		}
	}
}