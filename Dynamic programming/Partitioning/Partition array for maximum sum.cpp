/*Given an integer array arr, you should partition the array into (contiguous) subarrays of
length at most k. After partitioning, each subarray has their values changed to become the
maximum value of that subarray.

Return the largest sum of the given array after partitioning.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83*/

/*IDEA: if a subarray [i..j] has x as the maximum element then after replacing all the elements 
of that subarray to x, the sum of elements of that subarray will be x * (i-j+1)
Let dp[i] be the maximum sum after partitioning the subarray [0..i] into subarrays of length 
atmost k.
so if we know the answer for dp[i], then dp[j+1] = max(dp[j+1], dp[i] + (j-i+1) * x)
*/
int solve(vector<int> a, int k) {
	int n = a.size();
	vector<int> dp(n + 1, INT_MIN);
	dp[0] = 0;
	
	for (int i = 0; i < n; ++i) {
		int mx = a[i];
		for (int j = i; j < n and j - i + 1 <= k; ++j) {
			mx = max(mx, a[j]);
			dp[j+1] = max(dp[j+1], dp[i] + (j - i + 1) * mx);
		}
	}
	

	return dp[n];
}

/////////////////////////////////////////////////////////////
/*another variation:
partition the array into contiguous subarray of length atmost k, and after partitioning replace the subarray with
just the maximum element of the partition. So calculate the minimum sum possible of all the maximum of each partition.

eg. [1,15,7,9,2,5,10], k = 3
after
*/