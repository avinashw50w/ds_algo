/*Largest area rectangular sub-matrix with equal number of 1’s and 0’s
Last Updated: 26-09-2017
Given a binary matrix. The problem is to find the largest area rectangular sub-matrix with equal number of 1’s and 0’s.

Examples:

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 0},
                    {1, 1, 1, 0},
                    {1, 0, 0, 1} }
Output : 8 sq. units
(Top, left): (0, 0)
(Bottom, right): (3, 1)

Input : mat[][] = { {0, 0, 1, 1},
                    {0, 1, 1, 1} }
Output : 6 sq. units

IDEA: use kadane
*/
// maximum size subarray with sum zero
bool kadane(vector<int> a, int &start, int &end) {
	int sum = 0, n = a.size(), maxlen = 0;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; ++i) {
		sum += a[i] ? 1 : -1;
		if (sum == 0) {
			maxlen = i + 1;
			start = 0;
			end = i;
		}

		if (mp.count(sum)) {
			if (i - mp[sum] > maxlen) {
				maxlen = i - mp[sum];
				start = mp[sum] + 1;
				end = i;
			}
		} else {
			mp[sum] = i;
		}
	}

	return maxlen > 0;
}

void solve(vector<vector<int>> mat) {
	int r = mat.size(), c = mat[0].size();
	int maxArea = 0;
	int x1, y1, x2, y2; // coordinates of the final sub-matrix

	for (int left = 0; left < c; ++left) {
		vector<int> t(r);
		for (int right = left; right < c; ++right) {
			for (int i = 0; i < r; ++i) t[i] += mat[i][right];
			int startRow, endRow;
			if (kadane(t, startRow, endRow)) {
				int area = (endRow - startRow + 1) * (right - left + 1);
				if (area > maxArea) {
					maxArea = area;
					x1 = left;
					x2 = right;
					y1 = startRow;
					y2 = endRow;
				}
			}
		}
	}

	if (maxArea == 0) {
		printf("No such rectangle exists\n");
		return;
	}

	printf("(%d, %d), (%d, %d)\n", x1, y1, x2, y2);
}