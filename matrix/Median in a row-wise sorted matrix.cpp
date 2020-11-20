/*Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median.
IDEA: since the no of elements n are odd, so there will be n/2 elements less than the median.
so do a binary search to find the element such that the no of elements less than it are n/2
*/

int solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	int mn = INT_MAX, mx = INT_MIN;
	for (int i = 0; i < n; ++i) {
		mn = min(mn, mat[i][0]);
		mx = max(mx, mat[i][m - 1]);
	}

	int l = mn, r = mx, ans = mn, mid;
	int required = (n * m + 1) / 2;
	while (l <= r) {
		mid = (l + r) >> 1;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();

		if (cnt >= required) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	return ans;
}