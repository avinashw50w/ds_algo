/*Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83*/

/*IDEA: if a subarray [i..j] has a[k] as the maximum element then after replacing all the elements of that
subarray to a[k], the sum of elements of that subarray will be a[k] * (i-j+1)
Let dp[i] be the maximum sum after partitioning the subarray [0..i] into subarrays of lenght atmost k
*/
int solve(vector<int> a, int k) {
	int n = a.size();
	vector<int> dp(n, INT_MIN);
	int mx = INT_MIN;
	for (int i = 0; i < k; ++i) {
		mx = max(mx, a[i]);
		dp[i] = mx * (i + 1);
	}

	for (int i = k; i < n; ++i) {
		mx = a[i];
		for (subsize = 1; subsize <= k; ++subsize) {
			mx = max(mx, a[i - subsize + 1]);
			dp[i] = max(dp[i], mx * subsize + dp[i - subsize]);
		}
	}

	return dp[n - 1];
}

/////////////////////////////////////////////////////////////
/*another variation:
partition the array into contiguous subarray of length atmost k, and after partitioning replace the subarray with
just the maximum element of the partition. So calculate the minimum sum possible of all the maximum of each partition.

eg. [1,15,7,9,2,5,10], k = 3
after
*/