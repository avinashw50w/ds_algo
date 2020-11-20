/*
Given a 2D array, find the maximum sum subarray in it.
 */

int kadane(vector<int> a, int &start, int &end) {
	int sum = 0, maxsum = INT_MIN, n = a.size(), local_start = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum > maxsum) {
			maxsum = sum;
			start = local_start;
			end = i;
		}
		if (sum < 0) {
			sum = 0;
			local_start = i + 1;
		}
	}

	return maxsum;
}

void solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	int x1, y1, x2, y2;
	int maxsum = INT_MIN;

	for (int l = 0; l < m; ++l) {
		vector<int> t(n, 0);
		for (int r = l; r < m; ++r) {
			for (int i = 0; i < n; ++i)
				t[i] += mat[i][r];

			int start, end;
			int sum = kadane(t, start, end);

			if (sum > maxsum) {
				maxsum = sum;
				x1 = l;
				x2 = r;
				y1 = start;
				y2 = end;
			}
		}
	}

	printf("maximum sum = %d\n and the top-left and bottom-right coords are
	       (%d, %d), (%d, %d)", maxsum, x1, y1, x2, y2);
}