/*Find the median of two sorted arrays of different sizes.
			a1 a2 a3|a4 a5 a6
			   b1 b2|b3 b4

|total elements on the left side - total elements on the right side| should be atmost 1
we need to find a pivot in both arrays such that all the elements in the left side of
the pivot is less than all the elements in the right side of the pivot and the
difference in the no of elements in both sides is not greater than 1
ie, suppose the size of a is n and b is m, then if i is chosen as the pivot in a, then
the pivot chosen in b will be (n + m + 1) / 2 - i. This way the no of elements in each
half will be almost equal(diff is atmost 1)
Conditons to satify so that the elements in the left half is > the right half
1. a3 < b3
2. b2 < a4
since a3 < a4 and b2 < b3 (both a and b are sorted)
so do a binary search, choose a middle element as the pivot in a, say i, then using i
the pivot in b will be j = (n + m + 1) / 2 - i.
If a[i-1] > b[j], then we need to search in the range [0 - i-1], so decrement i
If b[j-1] > a[i], then we need to search in the range [i+1 - n], so increment i
*/

int median(vector<int> a, vector<int> b) {
	if (a.size() > b.size()) swap(a, b);
	int n = a.size(), m = b.size();
	int halfLen = (n + m + 1) / 2;
	int l = 0, r = n;
	while (l <= r) {
		int i = l;
		int j = halfLen - i;

		if (i > l and a[i - 1] > b[j]) r = i - 1;
		else if (i < r and j > 0 and b[j - 1] > a[i]) l = i + 1;
		else {
			int maxLeft = 0;
			if (i == 0) maxLeft = B[j - 1];
			else if (j == 0) maxLeft = A[i - 1];
			else maxLeft = max(A[i - 1], B[j - 1]);

			if ((n + m) & 1) return maxLeft;

			int minRight = 0;
			if (i == n) minRight = B[j];
			else if (j == m) minRight = A[i];
			else minRight = min(A[i], B[j]);

			return (maxLeft + minRight) / 2.0;
		}
	}

	return -1;
}