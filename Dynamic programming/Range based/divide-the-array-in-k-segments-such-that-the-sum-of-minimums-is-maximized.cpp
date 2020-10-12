/*Divide the array in K segments such that the sum of minimums is maximized
Last Updated: 29-09-2020
Given an array a of size N and an integer K, the task is to divide the array into K segments such that sum of the minimum of K segments is maximized.
Examples:


Input: a[] = {5, 7, 4, 2, 8, 1, 6}, K = 3
Output: 7
Divide the array at indexes 0 and 1. Then the segments are {5}, {7}, {4, 2, 8, 1, 6}. Sum of the minimus is 5 + 7 + 1 = 13
Input: a[] = {6, 5, 3, 8, 9, 10, 4, 7, 10}, K = 4
Output: 27

Approach: The problem can be solved using Dynamic Programming. Try all the possible partitions that are possible using recursion. Let dp[i][k] be the maximum sum of minimums till index i with k partitions. Hence the possible states will be partition at every index from the index i till n. The maximum sum of minimums of all those states will be our answer. After writing this recurrence, we can use memorize.

if we know the answer for subarray [0..i-1] with k-1 no of partitions, then we can do the kth partition on any
of the index ranging from [i..n-1], lets say we do the kth partition at index j.
so dp[j][k] = dp[i-1][k-1] + min(A[i...k])*/

const int INF = 1e9;
int n;
vector<int> a;
vector<vector<int>> dp;

int solve(int pos, int k) {
	if (k == 0) {
		return *min_element(a.begin(), a.end());
	}
	if (pos == n) return -INF;

	int &ret = dp[pos][k];
	if (ret != -1) return ret;

	int ans = -INF, mn = INF;
	for (int i = pos; i < n; ++i) {
		mn = min(mn, a[i]);
		ans = max(ans, mn + solve(i + 1, k - 1));
	}

	return ret = ans;
}

int main() {
	a = vector<int> {5, 7, 4, 2, 8, 1, 6};
	n = a.size();
	int k = 3;
	dp = vector<vector<int>> (n + 1, vector<int> (k + 1, -1));
	cout << solve(0, k);
}

////////////////////////////////////////////////////////////////////
// another varation is to find the minimum sum of the maximum of all the partitions

int solve(int pos, int k) {
	if (k == 0) return *max_element(a.begin(), a.end());
	if (pos == n) return INF;

	if (dp[pos][k] != -1) return dp[pos][k];

	int ans = INF, mx = -INF;
	for (int i = pos; i < n; ++i) {
		mx = max(mx, a[i]);
		ans = min(ans, mx + solve(i + 1, k - 1));
	}

	return ret = ans;
}