/*Maximum path sum in matrix
Given a matrix of N * M. Find the maximum path sum in matrix. The maximum path is sum of all elements from first row to last row where you are allowed to move only down or diagonally to left or right. You can start from any element in first row.

Examples:

Input : mat[][] = 10 10  2  0 20  4
                   1  0  0 30  2  5
                   0 10  4  0  2  0
                   1  0  2 20  0  4
Output : 74
The maximum sum path is 20-30-4-20.*/

int solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	const int inf = 1e9;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			// find the maximum of the up, up-left and up-right
			int mx = -inf;
			mx = max(mx, mat[i-1][j]);
			if (j) mx = max(mx, mat[i-1][j-1]);
			if (j + 1 < m) mx = max(mx, mat[i-1][j+1]);
			mat[i][j] += mx;
		}
	}

	int ans = INT_MIN;
	for (int i = 0; i < m; ++i) {
		ans = max(ans, mat[n - 1][i]);
	}

	return ans;
}