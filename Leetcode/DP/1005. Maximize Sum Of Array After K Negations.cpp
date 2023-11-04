/*Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.

Example 1:
Input: A = [3,-1,45,2], K=4
Output: 49
Explanation: Choose indices (1,) and A becomes [4,-2,3].*/

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int sum = 0;

		for (int i = 0; i < A.size(); ++i) {
			if (K > 0 and A[i] < 0) A[i] = -A[i], K--;
			sum += A[i];
		}

		if (K & 1) {
			int mn = *min_element(A.begin(), A.end());
			sum -= 2 * mn;
		}

		return sum;
	}
};