
int maxSum(int a[], int n, int k) {

	int i, sum = 0, maxSum = 0;

	for(i = 0; i < k; ++i) sum += a[i];

	maxSum = sum;

	for( ; i < n; ++i) {
		sum = sum + a[i] - a[i-k];
		maxSum = max(maxSum, sum);
	}
	return maxSum;
}

// varaition 2: find the maximum average subarray of size k
/* this is just bulshit, because the maximum sum among all subarrays of size k divided by k will be the max avg subarray.
So we simply have to compute the maximum sum subarray of size k and return the maxSum/k */
