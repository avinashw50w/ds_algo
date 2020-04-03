/*Total number of non-decreasing numbers with n digits
A number is non-decreasing if every digit (except the first one) is greater than or equal to previous digit. 
For example, 223, 4455567, 899, are non-decreasing numbers.

So, given the number of digits n, you are required to find the count of total non-decreasing numbers with n digits.

Examples:

Input:  n = 1
Output: count  = 10

Input:  n = 2
Output: count  = 55

Input:  n = 3
Output: count  = 220
We strongly recommend you to minimize your browser and try this yourself first.

One way to look at the problem is, count of numbers is equal to count n digit number ending with 9 plus count of ending 
with digit 8 plus count for 7 and so on. How to get count ending with a particular digit? We can recur for n-1 length and 
digits smaller than or equal to the last digit. So below is recursive formula.

Count of n digit numbers = (Count of (n-1) digit numbers Ending with digit 9) +
                           (Count of (n-1) digit numbers Ending with digit 8) +
                           .............................................+ 
                           .............................................+
                           (Count of (n-1) digit numbers Ending with digit 0) 
Let count ending with digit ‘d’ and length n be count(n, d)

count(n, d) = ∑ (count(n-1, i)) where i varies from 0 to d

Total count = ∑ count(n-1, d) where d varies from 0 to n-1
The above recursive solution is going to have many overlapping subproblems. 
Therefore, we can use Dynamic Programming to build a table in bottom up manner*/

int count(int N) {

	// dp[i][j] contains total count of non decreasing
    // numbers ending with digit i and of length j
	int dp[10][N+1];
	memset(dp, 0, sizeof(dp));

	// Fill table for non decreasing numbers of length 1
    // having digit 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	REP(i, 0, 10) dp[i][1] = 1;

	REP(digit, 0, 10) {

		REP(len, 2, N+1)

			REP(x, 0, digit+1)

				dp[digit][len] += dp[x][len-1];
	}

	int ans = 0;

	REP(i, 0, N) 
		ans += dp[i][N];

	return ans;
}