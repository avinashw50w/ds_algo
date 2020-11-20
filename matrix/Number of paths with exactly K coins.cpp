/*Number of paths with exactly k coins
Given a matrix where every cell has some number of coins. Count number of ways to reach bottom right from top left with exactly k coins. We can move to (i+1, j) and (i, j+1) from a cell (i, j).
Example:

Input:  k = 12
        mat[][] = { {1, 2, 3},
                    {4, 6, 5},
                    {3, 2, 1}
                  };
Output:  2
There are two paths with 12 coins
1 -> 2 -> 6 -> 2 -> 1
1 -> 2 -> 3 -> 5 -> 1 */

int dp[n][m][k];

int solve(vector<vector<int>> mat, int n, int m, int k) {
	if (n < 0 or m < 0) return 0;
	if (n == 0 and m == 0) return k == mat[n][m];
	if (dp[n][m][k] != -1) return dp[n][m][k];
	dp[n][m][k] = solve(mat, n, m - 1, k - 1) + solve(mat, n - 1, m, k - 1);
	return dp[n][m][k];
}

int paths(vector<vector<int>> mat, int K) {
	int n = mat.size(), m = mat[0].size();
	return solve(mat, n, m, K);
}