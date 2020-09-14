/*Minimum number of squares whose sum equals to given number n
A number can always be represented as a sum of squares of other numbers.
Note that 1 is a square and we can always break a number as (1*1 + 1*1 + 1*1 + …).
Given a number n, find the minimum number of squares that sum to X.

Examples:

Input:  n = 100
Output: 1
100 can be written as 10^2. Note that 100 can also be
written as 5^2 + 5^2 + 5^2 + 5^2, but this
representation requires 4 squares.

Input:  n = 6
Output: 3
We strongly recommend you to minimize your browser and try this yourself first.
The idea is simple, we start from 1 and go till a number whose square is smaller than or equals to n.
For every number x, we recur for n-x. Below is the recursive formula.

If n <= 3, then return n
Else
   minSquares(n) = min {1 + minSquares(n - x*x)}
                       where x >= 1 and x*x <= n */

// recursive //

int fun(int n) {
	if (n <= 3) return n;
	// Maximum squares required is n (1*1 + 1*1 + ..)
	int res = n;

	for (int x = 1; x * x <= n; ++x) {
		res = min(res, 1 + fun(n - x * x));
	}

	return res;
}


// dp solution //

int fun(int n) {
	int dp[n + 1];
	// each no n can be represented by sum of 1^2, eg, 3 = 1^2 + 1^2 + 1^2
	for (int i = 0; i <= n; ++i) dp[i] = i;

	for (int i = 4; i <= n; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	return dp[n];
}


