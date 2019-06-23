/*Maximum circular subarray sum
3.7
Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.

Examples:

Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

There can be two cases for the maximum sum:

Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. 
Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there. 
Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. Let us see how. 
Wrapping of contributing elements implies non wrapping of non contributing elements, so find out the sum of non contributing 
elements and subtract this sum from the total sum. To find out the sum of non contributing, invert sign of each element 
and then run Kadane’s algorithm.Our array is like a ring and we have to eliminate the maximum continuous negative that 
implies maximum continuous positive in the inverted arrays.

Finally we compare the sum obtained by both cases, and return the maximum of the two sums.*/

int solve(int A[], int N) {

	int max_sum = kadane(A, N);
	int sum = 0;

	for(int i = 0; i < N; ++i) {
		sum += A[i];
		A[i] = -A[i];
	}

	sum = sum + kadane(A, N);

	return (max_sum > sum) ? max_sum: sum;
}

int kadane(int A[], int N) {
	int prefix = 0, ans = INT_MIN;

	for(int i = 0; i < N; ++i) {
		prefix = max(A[i], prefix + A[i]);
		ans = max(ans, prefix);
	}
	return ans;
}