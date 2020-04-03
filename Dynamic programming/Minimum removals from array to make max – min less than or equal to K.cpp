/*Minimum removals from array to make max – min <= K
Given N integers and K, find the minimum number of elements that should be removed such that Amax-Amin<=K. After removal of elements, Amax and Amin is considered among the remaining elements.
Examples:

Input : a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20} 
          k = 4 
Output : 5 
Explanation: Remove 1, 3, 4 from beginning 
and 17, 20 from the end.

Input : a[] = {1, 5, 6, 2, 8}  K=2
Output : 3
Explanation: There are multiple ways to 
remove elements in this case.
One among them is to remove 5, 6, 8.
The other is to remove 1, 2, 5 

Approach: Sort the given elements. Using greedy approach, the best way is to remove the minimum element or the maximum element and then check if Amax-Amin <= K. There are various combinations of removals that have to be considered. We write a recurrence relation to try every possible combination. There will be two possible ways of removal, either we remove the minimum or we remove the maximum. Let(i…j) be the index of elements left after removal of elements. Initially, we start with i=0 and j=n-1 and the number of elements removed is 0 at the beginning. We only remove an element if a[j]-a[i]>k, the two possible ways of removal are (i+1…j) or (i…j-1). The minimum of the two is considered.*/

const int maxn = 1e3;
int dp[maxn][maxn];

int solve(int a[], int n, int l, int r, int K) {
	if (l >= r) return 0;

	if (a[r] - a[l] <= K) return 0;

	if (dp[l][r] != -1) return dp[l][r];

	if (a[r] - a[l] > K) {
		dp[l][r] = 1 + min(solve(a, l+1, r, K), solve(a, l, r-1, K));
	}

	return dp[l][r];
}

int minRemoval(int a[], int n, int K) {
	
	if (n == 1) return 0;

	sort(a, a + n);

	memset(dp, -1, sizeof(dp));

	return solve(a, 0, n-1, K);
}