/*given n(number of variables) and val(sum of variables), find out how many such non negative
integral solutions are possible.
input: n = 5, val = 1
output: 5

explanation: x1 + x2 + x3 + x4 + x5 = 1
number of possible solutions are: (0 0 0 0 1), (0 0 0 1 0), (0 0 1 0 0), (0 1 0 0 0), (1 0 0 0 0)
*/

const int MAXN = 100;
int dp[MAXN][MAXN];

int solve(int n, int val) {
	int tot = 0;

	if(n == 1 and val >= 0) return dp[n][val] = 1;

	REP(i, 0, val+1) 
		tot += solve(n-1, val-i);

	return dp[n][val] = tot;
}

////////////////////////////////////////////////////////////////

/*simple solution:

x1 + x2 + x3 + ... + xr = n , where x1,x2,x3,...,xr >= 0

the total number of possible solutions are n+r-1Cr-1

*/