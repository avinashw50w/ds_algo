/*given an array of numbers containing positive and negative numbers, return the no. of contiguous subsequences which sum to 0.
4. Modification of LIS: given an array of integers, return the length of longest alternating subsequence. i.e. a<b>c<d>e  */

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
/// Efficient Approach(space optimized)
/*In the above approach, at any moment we are keeping track of two values (Length of the longest alternating subsequence ending at index i, and last element is smaller than or greater than previous element), for every element on array. To optimise space, we only need to store two variables for element at any index i.

inc = Length of longest alternative subsequence so far with current value being greater than it’s previous value.
dec = Length of longest alternative subsequence so far with current value being smaller than it’s previous value.
The tricky part of this approach is to update these two values.

“inc” should be increased, if and only if the last element in the alternative sequence was smaller than it’s previous element.
“dec” should be increased, if and only if the last element in the alternative sequence was greater than it’s previous element.*/

int solve(vector<int> a) {
	int n = a.size();
	int inc = 1;
	int dec = 1;

	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i - 1]) inc = dec + 1;
		else if (a[i] < a[i - 1]) dec = inc + 1;
	}

	return max(inc, dec);
}