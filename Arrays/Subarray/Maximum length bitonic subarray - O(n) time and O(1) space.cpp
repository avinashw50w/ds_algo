/*Maximum Length Bitonic Subarray | Set 1 (O(n) tine and O(1) space)

Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic if there is a k with i <= k <= j 
such that A[i] <= A[i + 1] ... <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j]. Write a function that takes an array as 
argument and returns the length of the maximum length bitonic subarray.*/

void solve(int a[], int n) {
	if(n == 0) return 0;

	int ans = 1;

	int start = 0, nextStart = 0, j = 0;

	while(j < n-1) {

		while(j < n-1 and a[j] <= a[j+1]) j++; // go to the end of ascent

		while(j < n-1 and a[j] >= a[j+1]) {

			if(j < n-1 and a[j] > a[j+1])
				nextStart = j+1;

			j++;
		}

		ans = max(ans, j-start+1);

		start = nextStart;
	}

	cout << ans;
}

////////////////////////////////////////////////

// dp solution : O(n) time and O(n) space

void solve(int a[], int n) {
	if(n == 0) return 0;

	int inc[n], dec[n];

	inc[0] = 1;
	for(int i = 1; i < n; ++i)
		inc[i] = a[i-1] <= a[i] ? inc[i-1] + 1 : 1;

	dec[n-1] = 1;
	for(int i = n-2;i >= 0; --i)
		dec[i] = a[i] >= a[i+1] ? dec[i+1] + 1 : 1;

	int ans = 1;
	for(int i = 0; i < n; ++i)
		ans = max(ans, inc[i] + dec[i] - 1);

	return ans;
}