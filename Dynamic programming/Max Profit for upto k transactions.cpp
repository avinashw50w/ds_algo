/*Given the list of stock prices for n no of days. Find the maximum profit which can be earned
if a maximum of k transations are allowed. A transation involves buy -> sell in sequence. No two trasactions
should overlap.*/

/*
For any ith day, one can either buy/sell on that day or don't do any transation at all. So the recurrence
relation for this is:
let dp[t][i] = the maximum profit on day i after doing upto t transations

dp[t][i] = max(
				dp[t][i-1] // no transation on day i
				max(price[i] - price[j] + dp[t-1][i]) for all j in [0..i-1] // if a stock is bought or sold on day i
			)
 */

int solve(vector<int> prices, int K) {
	int n  = prices.size();
	int dp[K + 1][n];

	memset(dp, 0, sizeof(dp));

	for (int t = 1; t <= K; t++) {
		for (int i = 1; i < n; ++i) {
			int max_so_far = INT_MIN;
			for (int j = 0; j < i; ++j)
				max_so_far = max(max_so_far, price[i] - price[j] + dp[t - 1][i]);

			dp[t][i] = max(dp[t][i], max_so_far);
		}
	}

	return dp[K][n - 1];
}