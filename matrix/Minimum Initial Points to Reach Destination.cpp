/*Minimum Initial Points to Reach Destination
Given a grid with each cell consisting of positive, negative or no points i.e, zero points.
 We can move across a cell only if we have positive points ( > 0 ). Whenever we pass
 through a cell, points in that cell are added to our overall points. We need to find
  minimum initial points to reach cell (m-1, n-1) from (0, 0).

Constraints :

From a cell (i, j) we can move to (i+1, j) or (i, j+1).
We cannot move from (i, j) if your overall points at (i, j) is <= 0.
We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

IDEA: use dp, where dp[i][j] = minimum no of points to required to reach bottom right
starting from (i, j)
for that calculate dp from bottom to up
for every cell (i, j) take the min from dp(i+1, j) and dp(i, j+1), let's call it x
so dp(i, j) = max(points(i, j) - x, 1)
*/

int solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	int dp[n + 1][m + 1];
	for (int i = 0; i < n; ++i) dp[i][m] = INT_MAX;
	for (int i = 0; i < m; ++i) dp[n][i] = INT_MAX;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i == n - 1 and j == m - 1) {
				// we have to reach the dest with atleast > 0 points
				dp[i][j] = mat[i][j] > 0 ? 1 : abs(mat[i][j]) + 1;
			} else {
				int min_from_sides = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = max(min_from_sides - mat[i][j], 1);
			}
		}
	}

	return dp[0][0];
}