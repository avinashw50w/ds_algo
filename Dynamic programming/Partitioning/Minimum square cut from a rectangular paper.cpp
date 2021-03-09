/*Given a paper of size A x B. Task is to cut the paper into squares of any size. Find the
minimum number of squares that can be cut from the paper.

Examples:

Input  : 36 x 30
Output : 5
Explanation :
3 (squares of size 12x12) +
2 (squares of size 18x18)*/

int solve(int A, int B) {
	int dp[A + 1][B + 1] = {{}};

	for (int i = 1; i <= A; ++i) {
		for (int j = 1; j <= B; ++j) {
			if (i == j) continue;
			int ans = 1e9;
			for (int k = 1; k < j; ++k) {
				ans = min(ans, dp[i][k] + dp[i][j - k]);
				ans = min(ans, dp[k][j] + dp[i - k][j]);
			}
			dp[i][j] = ans;
		}
	}

	return ans;
}