/*Given an array of n integers, find the maximum absolute difference between two subarrays which are not overalpping with each other*/

/*For each index i calculate and store the min and max sum subarrays of both its left and right side.
For that we need 4 arrays, leftMax, leftMin, rightMax and rightMin */

void maxSumSubarray(int a[], int n, int *dp, bool isLeft) {
	if (isLeft) {
		dp[0] = a[0];
		for (int i = 1; i < n; ++i)
			dp[i] = max(a[i], dp[i-1] + a[i]);
	}
}

int solve(int a[], int n) {

	int leftMax[n], leftMin[n], rightMax[n], rightMin[n];

	maxSumSubarray(a, n, leftMax, true);

	maxSumSubarray(a, n, rightMax false);

	for (int i = 0; i < n; ++i) a[i] = -a[i];

	maxSumSubarray(a, n, leftMin, true);

	for (int i = 0; i < n; ++i) leftMin[i] = -leftMin[i];

	maxSumSubarray(a, n, rightMin, false);

	for (int i = 0; i < n; ++i) rightMin[i] = -rightMin[i];

	int ans = INT_MIN, maxDiff = INT_MIN;

	for (int i = 0; i < n-1; ++i) {
		maxDiff = max(abs(leftMin[i] - rightMax[i+1]), abs(leftMax[i] - rightMin[i+1]));
		ans = max(ans, maxDiff);
	}

	return ans;
}