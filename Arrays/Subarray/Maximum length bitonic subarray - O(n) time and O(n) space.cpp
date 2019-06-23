/*Maximum Length Bitonic Subarray | Set 1 (O(n) tine and O(n) space)

Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic if there is a k with i <= k <= j 
such that A[i] <= A[i + 1] ... <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j]. Write a function that takes an array as 
argument and returns the length of the maximum length bitonic subarray.*/

void solve(int a[], int n) {
	int inc[n], dec[n];

	int ans = 1;

	inc[0] = dec[n-1] = 1;

	for(int i = 1; i < n; ++i)
		inc[i] = (a[i-1] <= a[i]) ? inc[i-1] + 1: 1;

	for(int i = n-2; i >= 0; --i)
		dec[i] = (dec[i] >= dec[i+1]) ? dec[i+1] + 1: 1;

	for(int i = 0; i < n; ++i)
		ans = max(ans, inc[i]+dec[i]-1);

	cout << ans;
}