/*Minimize the maximum difference between the heights
Last Updated: 10-07-2019
Given heights of n towers and a value k. We need to either increase or decrease height of every tower by k (only once) where k > 0. The task is to minimize the difference between the heights of the longest and the shortest tower after modifications, and output this difference.

Examples:

Input  : arr[] = {1, 15, 10}, k = 6
Output :  Maximum difference is 5.
Explanation : We change 1 to 6, 15 to
9 and 10 to 4. Maximum difference is 5
(between 4 and 9). We can't get a lower
difference.

Input : arr[] = {1, 5, 15, 10}
        k = 3
Output : Maximum difference is 8
arr[] = {4, 8, 12, 7}
*/
// IDEA: Sort the heights and try every possible split into two halves [0, i-1]
// and [i, n-1], where you add K to the left half and subtract K from the right half.
// Then the difference for that split is
// max(a[n-1] - K, a[i] + K) - min(a[0] + K, a[i] - K);

int solve(vector<int> a, int K) {
	int n = a.size();
	sort(a.begin(), a.end());

	int ans = a[n - 1] - a[0];
	for (int i = 1; i < n; ++i) {
		int diff = max(a[n - 1] - K, a[i - 1] + K) - min(a[0] + K, a[i] - K);
		ans = min(ans, diff);
	}

	return ans;
}