/*Dynamic Programming | Set 18 (Partition problem)
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements 
in both subsets is same. 

Examples

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets. */

/* Let the sum of all the elements of the array be S. Since both the sets have same sum,
So the sum of each set = S/2. So simply check whether a subset sum of S/2 exists or not. */

bool check(int A[], int N) {

	int sum = 0;

	REP(i, 0, N) sum += A[i];

	if(sum  & 1) return false;

	int dp[sum+2] = {};
	dp[0] = 1;

	for(int i = 0; i < N; ++i)
		for(int j = A[i]; j <= sum; ++j)
			dp[j] |= dp[j-A[i]];

	return dp[sum>>1];
}