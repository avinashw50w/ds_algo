/*Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against
an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row,
removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount
of money we can definitely win if we move first.

Note: The opponent is as clever as the user.

There are two choices:
1. The user chooses the ith coin with value Vi: The opponent either chooses (i+1)th coin or jth coin.
The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vi + min(F(i+2, j), F(i+1, j-1) )

2. The user chooses the jth coin with value Vj: The opponent either chooses ith coin or (j-1)th coin.
The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vj + min(F(i+1, j-1), F(i, j-2) )*/

int MaxPoints(int V[], int N) {

	int dp[N][N];
	memset(dp, 0, sizeof(dp));

	for (int gap = 0; gap < N; ++gap) {
		for (int i = 0, j = gap; j < N; ++i, ++j) {

			int x = (i+2 <= j) ? dp[i+2][j] : 0;
			int y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
			int z = (i <= j-2) ? dp[i][j-2] : 0;

			dp[i][j] = max( V[i] + min(x, y), V[j] + min(y, z) );
		}
	}

	return dp[0][N-1];
}

////////////////////////////////////////////////////////////////
/*Recursive approach :
F(i, j)  represents the maximum value the user can collect from
         i'th coin to j'th coin.

    F(i, j)  = Max(Vi + min(F(i+2, j), F(i+1, j-1) ),
                   Vj + min(F(i+1, j-1), F(i, j-2) ))
Base Cases
    F(i, j)  = Vi           If j == i
    F(i, j)  = max(Vi, Vj)  If j == i+1
*/
int V[maxn], dp[maxn][maxn];

int solve(int l, int r) {
	if (l == r) return V[l];

	if (l+1 == r) return max(V[l], V[r]);

	if (dp[l][r] != -1) return dp[l][r];

	int option1 = V[l] + min(solve(i+2, j), solve(i+1, j-1));

	int option2 = V[r] + min(solve(i+1, j-1), solve(i, j-2));

	return dp[l][r] = max(option1, option2);
}
