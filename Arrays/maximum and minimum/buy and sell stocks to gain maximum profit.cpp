// Given stock prices of a number of days, you have to maximize the profit given that you can buy and sell stock only one time.
// this problem is similar to finding the maximum value of a[i] - a[j] such that i > j;

int findProfit(int stockPrices[], int N) {
	if(N < 2) return 0;
	int minimumPrice = stockPrices[0];
	int profit = stockPrices[1] - stockPrices[0];

	REP(i, 1, N) {
		profit = max(profit, stockPrices[i] - minimumPrice);
		minimumPrice = min(minimumPrice, stockPrices[i]);
	}

	return profit;
}
