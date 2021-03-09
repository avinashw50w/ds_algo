/*You are given an integer n. On each step, you may subtract form it any digit that
appears in it. How many steps are required to make the number equal to 0.

let dp[i] = no of steps to make the number equal to 0
dp[i] = min(dp[i], dp[i - digit] + 1) where digit can be any digit in i
*/


int solve(int n) {
	int dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1e9;
		int i2 = i;
		while (i2) {
			dp[i] = min(dp[i], dp[i - i2 % 10] + 1);
			i2 /= 10;
		}
	}

	return dp[n];
}