/*Given an array A[0 … n-1] containing n positive integers, a subarray A[i … j] is bitonic if there is a k with i <= k <= j 
such that A[i] <= A[i + 1] ... <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j]. Write a function that takes an array as argument 
and returns the length of the maximum length bitonic subarray.
Expected time complexity of the solution is O(n)

Simply find the maximum length of the subarray which is first increasing and then decreasing.*/

int longestBitonicSubarray(int A[], int N) {

	int L[N], R[N];

	L[0] = 1;
	R[N-1] = 1;


	REP(i, 1, N) 
		L[i] = (A[i] > A[i-1]) ? L[i-1] + 1 : 1;

	PER(i, N-2, 0)
		R[i] = (A[i] > A[i+1]) ? R[i+1] + 1 : 1;

	int ans = 0;

	REP(i, 0, N)
	 	ans = max(ans, L[i] + R[i] - 1);

	return ans;
}