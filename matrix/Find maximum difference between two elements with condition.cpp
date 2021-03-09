/*Find a specific pair in Matrix
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

Example:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 },
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2]
- mat[1][0] = 18 has maximum difference.

IDEA: if c = a+1 and d = b+1, and mat[c][d] contains the maximum element so far,
then ans = mat[c][d] - mat[a][b]. So to achieve to this, we need to start from the bottom right
to top left and keep updating mat[i][j] to the maximum element so far
*/

int solve(vector<vector<int>> mat) {
	int n = mat.size();
	int mx = INT_MIN;
	// update the last row
	for (int i = n - 1; i >= 0; --i) {
		mx = max(mx, mat[n - 1][i]);
		mat[n - 1][i] = mx;
	}

	// update the last column
	for (int i = n - 1; i >= 0; --i) {
		mx = max(mx, mat[i][n - 1]);
		mat[i][n - 1] = mx;
	}

	int ans = INT_MIN;

	for (int i = n - 2; i >= 0; --i) {
		for (int j = n - 2; j >= 0; --j) {
			ans = max(ans, mat[i + 1][j + 1] - mat[i][j]);
			mat[i][j] = max(mat[i][j], max(mat[i + 1][j], mat[i][j + 1]));
		}
	}

	return ans;
}