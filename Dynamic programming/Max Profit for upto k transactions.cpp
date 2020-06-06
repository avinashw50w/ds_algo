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

////////////////////////////////////////////////////////////////
// Another variation is that one can do any no of transation to obtain maximum profit
// for that just keep adding the difference between the consecutive elements which are
// strictly increasing.


int solve(vector<int> prices) {
	int n = prices.size();

	int ans = 0;
	for (int i = 1; i < n; ++i)
		if (a[i] > a[i - 1]) ans += a[i] - a[i - 1];

	return ans;
}

////////////////////////////////////////////////////
// another variation is that one can do atmost 2 transations
// which is = max(
// 			      	max profit after one transation for subarray [0..i]
// 			      	max profit after one transation for subarray [i..n-1]
// 			      ) for all i in [1..n-1];

int solve(vector<int> prices) {
	int n = prices.size();
	int profit[n] = {0};

	int max_price = prices[n - 1];
	// profit[i] = max profit after one transation for subarray [i..n-1]
	for (int i = n - 2; i >= 0; --i) {
		max_price = max(max_price, prices[i]);
		profit[i] = max(profit[i + 1], max_price - prices[i]);
	}

	int min_price = prices[0];
	for (int i = 1; i < n; ++i) {
		min_price = min(min_price, prices[i]);
		profit[i] = max(profit[i - 1], prices[i] - min_price + profit[i]);
	}

	return profit[n - 1];
}