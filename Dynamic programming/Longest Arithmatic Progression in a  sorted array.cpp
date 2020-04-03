/*Given a set of numbers, find the Length of the Longest Arithmetic Progression (LLAP) in it.

Examples:

set[] = {1, 7, 10, 15, 27, 29}
output = 3
The longest arithmetic progression is {1, 15, 29}

set[] = {5, 10, 15, 20, 25, 30}
output = 6
The whole set is in AP

The above function returns a boolean value. The required output of original problem is Length of the Longest Arithmetic Progression (LLAP) 
which is an integer value. If the given set has two or more elements, then the value of LLAP is at least 2 (Why?).
The idea is to create a 2D table L[n][n]. An entry L[i][j] in this table stores LLAP with set[i] and set[j] as first two elements of AP and j > i. 
The last column of the table is always 2 (Why – see the meaning of L[i][j]). Rest of the table is filled from bottom right to top left. 
To fill rest of the table, j (second element in AP) is first fixed. i and k are searched for a fixed j. If i and k are found 
such that i, j, k form an AP, then the value of L[i][j] is set as L[j][k] + 1. Note that the value of L[j][k] must have been filled 
before as the loop traverses from right to left columns.*/

int LAP(int A[], int N) {

	if(N < 2) return 1;

	// dp[i][j] stores the maximum len arithmatic progression from index i to j
	int dp[N][N];

	memset(dp, 0, sizeof(dp));

	// the minimum len of AP b/w index i and j (i < j) will be 2
	REP(i, 0, N-1)
	REP(j, i+1, N)
	dp[i][j] = 2;

	int maxLen = 2;
	
	// take j as the pivot element
	for(int j = N-2; j >= 1; --j) {

		int i = j-1, k = j+1;

		// expand around j and check whether A[i]+A[k] = 2*A[j]
		while(i >= 0 and k < N) {

			if(A[i] + A[k]  < 2*A[j]) k++;

			else if(A[i] + A[k] > 2*A[j]) i--;

			else {
				dp[i][j] = dp[j][k] + 1;

				maxLen = max(maxLen, dp[i][j]);

				i--; k++;
			}
		}
	}

	return maxLen;
}