/*Find median in a row wise sorted matrix
IDEA: use binary search
The idea is that for a number to be median there should be exactly (n/2) numbers which are less
than this number. So, do a binary search on the median and count the no of elements less than
the current chosen median. For counting the no of elements less than median, use upper_bound.
There are N*M elements, so the median is the ((N*M + 1) / 2)th element

NOTE: this problem is also similar to finding the Kth smallest element in the array.
So, for this problem K = (N*M+1)/2
*/

int median(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		l = min(l, mat[i][0]);
		r = max(r, mat[i][m - 1]);
	}

	while (l < r) {
		int mid = l + (r - l) / 2;
		int pos = 0;
		for (int i = 0; i < n; ++i) {
			pos += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
		}

		if (pos < (n * m + 1) / 2)
			l = mid + 1;
		else
			r = mid;
	}

	return l;
}