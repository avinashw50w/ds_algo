/*Given the list of stock prices for n no of days. Find the maximum profit which can be earned
if a maximum of k transations are allowed. A transation involves buy -> sell in sequence. No two trasactions
should overlap.*/

/*
For any ith day, one can either buy/sell on that day or don't do any transation at all. So the recurrence
relation for this is:
let dp[t][i] = the maximum profit on day i after doing upto t transations

dp[t][i] = max(
				dp[t][i-1] // no transation on day i
				max(price[i] - price[j] + dp[t-1][j]) for all j in [0..i-1] // if a stock is bought or sold on day i
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
				max_so_far = max(max_so_far, price[i] - price[j] + dp[t - 1][j]);

			dp[t][i] = max(dp[t][i], max_so_far);
		}
	}

	return dp[K][n - 1];
}

///////////////////////////////////////
/*
Optimized Solution:
The above solution has time complexity of O(k.n2). It can be reduced if we are able to calculate the maximum profit gained by selling shares on the ith day in constant time.

profit[t][i] = max(profit [t][i-1], max(price[i] – price[j] + profit[t-1][j]))
                            for all j in range [0, i-1]

If we carefully notice,
max(price[i] – price[j] + profit[t-1][j])
for all j in range [0, i-1]

can be rewritten as,
= price[i] + max(profit[t-1][j] – price[j])
for all j in range [0, i-1]
= price[i] + max(prevDiff, profit[t-1][i-1] – price[i-1])
where prevDiff is max(profit[t-1][j] – price[j])
for all j in range [0, i-2]

So, if we have already calculated max(profit[t-1][j] – price[j]) for all j in range [0, i-2], we can calculate it for j = i – 1 in constant time. In other words, we don’t have to look back in the range [0, i-1] anymore to find out best day to buy. We can determine that in constant time using below revised relation.*/

int solve(vector<int> prices, int K) {
	int n = prices.size();
	int dp[K + 1][n];

	memset(dp, 0, sizeof(dp));

	for (int t = 1; t <= K; ++t) {
		int prev_diff = INT_MIN;
		for (int i = 1; i < n; ++i) {
			prev_diff = max(prev_diff, dp[K - 1][i - 1] - prices[i - 1]);
			dp[t][i] = max(dp[t][i - 1], prices[i] + prev_diff);
		}
	}

	return dp[K][n - 1];
}

////////////////////////////////////////////////////////////////
// recursive
vector<int> price;
int dp[N][2][t + 1];

int solve(int i, int own, int t, int N) {
	if (i == N or t == 0) return 0;

	int &res = dp[i][own][t];
	if (res != -1) return res;

	if (own) {
		int op1 = price[i] + solve(i + 1, 0, t - 1, N); // sell the stock
		int op2 = solve(i + 1, own, t, N); // do nothing

		return res = max(op1, op2);
	}
	else {
		int op1 = -price[i] + solve(i + 1, 1, t, N); // buy the stock
		int op2 = solve(i + 1, own, t, N); // do nothing

		return res = max(op1, op2);
	}
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

// another method
int solve(vector<int> a) {
	int best_with_stock = INT_MIN, best_without_stock = 0;

	for (int x : a) {
		best_with_stock = max(best_with_stock, best_without_stock - x);
		best_without_stock = max(best_without_stock, best_with_stock + x);
	}

	return max(best_without_stock, best_with_stock);
}

////////////////////////////////////////////////////
// another variation is that one can do atmost 2 transations
// which is = max(
// 			      	max profit after one transation for subarray [0..i]
// 			      	max profit after one transation for subarray [i+1..n-1]
// 			      ) for all i in [1..n-1];

int solve(vector<int> prices) {
	int n = prices.size();
	int profit[n] = {0};

	int max_price = prices[n - 1];
	// profit[i] = max profit after one transation for subarray [i+1...n-1]
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

//////////////////////////////////////////////////
// when ONly 1 trasaction is allowed

int solve(vector<int> prices) {
	int ans = 0, mini = 1e9;

	for (int i = 0; i < prices.size(); ++i) {
		ans = max(ans, prices[i] - mini);
		mini = min(mini, prices[i]);
	}

	return ans;
}
