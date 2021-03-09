/* DP
Given an array of integers where each element represents the max number of steps that can be
 made forward from that element. Write a function to return the minimum number of jumps to
reach the end of the array (starting from the first element). If an element is 0,
then cannot move through that element.
 */

int solve(vector<int> a) {
    int n = a.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j + a[j] >= i and dp[j] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[j]);
        }
    }

    return dp[n - 1] == INT_MAX ? -1 : dp[n - 1];
}