/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.*/

/*To count total number solutions, we can divide all set solutions in two sets.
1) Solutions that do not contain ith coin (or Ai).
2) Solutions that contain at least one Ai.*/

// i : indicates the ith coin ; sum : the required sum needed
int count(int i, int sum) {

	if(sum == 0) return 1;	// possible if no coin is choosen

	if(i < 0) return 0;

	if(i <= 0 and sum > 0) return 0;
	// don't choose the ith coin //
	int res1 = count(i-1, sum);	
	// choose the ith coin //
	int res2 = count(i, sum-A[i-1]);

	return res1 + res2;
}

// top down //

int dp[n+1][sum+1];
memset(dp, -1, sizeof(dp));

int count(int i, int sum) {
	if(sum == 0) return 1;	

	if(i < 0) return 0;

	if(i <= 0 and sum > 0) return 0;

	if(dp[i][sum] != -1) return dp[i][sum];

	return dp[i][sum] = count(i-1, sum) + count(i, sum-A[i-1]);
}

// bottom up //

int count() {
	int dp[n][sum+1] = {};
// for a sum of 0, it is possible to make a change by not choosing any coin //
	for(int i=0; i<n; ++i) d[i][0] = 1; 

	// for each coin //
	for(int i=0; i<n; ++i) {
		// for each sum // 
		for(int j=1; j <= sum; ++j) {

			int x = (i-1>=0) ? dp[i-1][j] : 0;	// don't choose the ith element //

			int y = (j-A[i] >= 0) ? dp[i][j-A[i]] : 0;	// choose the ith element //

			dp[i][j] = x + y;
		}
	}
	return dp[n-1][sum];
}

// optimized O(n) space // 

int count() {
	int dp[sum+1] = {};

	dp[0] = 1;

	for(int i=0; i<n; ++i) 
		for(int j=A[i]; j<=sum; ++j)
			dp[j] += dp[j-A[i]];
	
	return dp[sum];
}
