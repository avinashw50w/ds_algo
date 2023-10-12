/*Maximum circular subarray sum
3.7
Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.

Examples:

Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Sol: 
case 1: ans can be the subarray with maximum sum
case 2: ans can be the (total sum - subarray with minimum sum)

ans = max(case 1, case 2)

to find the subarray with minimum sum, invert the array and run kadane
*/

int solve(int A[], int N) {

	int max_sum = kadane(A, N);
	int sum = 0;

	for (int i = 0; i < N; ++i) {
		sum += A[i];
		A[i] = -A[i];
	}

	sum = sum - (-1 * kadane(A, N));

	return max(max_sum, sum)
}

int kadane(int A[], int N) {
	int prefix = 0, ans = INT_MIN;

	for (int i = 0; i < N; ++i) {
		prefix = max(A[i], prefix + A[i]);
		ans = max(ans, prefix);
	}
	return ans;
}