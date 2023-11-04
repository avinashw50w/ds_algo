/*In a N x N grid representing a field of cherries, each cell is one of three possible integers.

0 means the cell is empty, so you can pass through;
1 means the cell contains a cherry, that you can pick up and pass through;
-1 means the cell contains a thorn that blocks your way.

Your task is to collect maximum number of cherries possible by following the rules below:

Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.

IDEA: one path from (0, 0) -> (n-1, n-1) and other from (n-1, n-1) -> (0, 0)
simply boils down to taking 2 persons who starts from (0, 0) and at each move, the no of steps
taken by both of them is same, eg if A is at (a, b) and B at (c, d) then a+b = c+d
*/

class Solution {
	const int INF = 1e9;
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, -INF));
		dp[0][0] = grid[0][0];
		// for t no of steps from origin
		for (int t = 1; t <= 2 * n - 2; ++t) {
			vector<vector<int>> dp2 = vector<vector<int>>(n, vector<int>(n, -INF));
			// (i, j) => i+j = t => (i, t-i)
			for (int i = max(0, t - (n - 1)); i <= min(n - 1, t); ++i) {
				for (int j = max(0, t - (n - 1)); j <= min(n - 1, t); ++j) {
					if (grid[i][t - i] == -1 or grid[j][t - j] == -1) continue;
					int val = grid[i][t - i];
					if (i != j) val += grid[j][t - j];
					int sum = -INF;
					for (int ni = i - 1; ni <= i; ++ni) {
						for (int nj = j - 1; nj <= j; ++nj) {
							if (ni >= 0 and nj >= 0)
								dp2[i][j] = max(dp2[i][j], dp[ni][nj] + val);
						}
					}
				}
			}
			dp = dp2;
		}

		return max(0, dp[n - 1][n - 1]);
	}
};