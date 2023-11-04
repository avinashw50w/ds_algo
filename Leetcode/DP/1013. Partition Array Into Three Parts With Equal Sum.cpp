/*Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])



Example 1:

Input: A = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1*/

class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int n = A.size();
		int sum = 0;
		for (int e : A) sum += e;
		if (sum % 3 != 0) return false;

		int s1 = sum / 3;
		int s2 = s1 * 2;

		int idx1 = -1, idx2 = -1;
		int pre = 0;
		for (int i = 0; i < n - 1; ++i) {
			pre += A[i];
			if (pre == s1 and idx1 == -1) idx1 = i;
			else if (pre == s2 and idx1 != -1) {
				idx2 = i;
				break;
			}
		}

		if (idx1 != -1 and idx2 != -1) return true;

		return false;
	}
};