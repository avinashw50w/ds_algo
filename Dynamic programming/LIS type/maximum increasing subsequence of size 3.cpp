/*Given an array of elements and cost of each element ai which is ci, Find the sum of 
the increasing subsequence of size k such that its sum is maximum*/
// dp[i][len] - maximum subsequence sum of size len upto index i
int solve(vector<int> a, vector<int> cost, int k) {
    int n = a.size();
    int dp[n][k];
    int ans = -1e9;
    for (int i = 0; i < n; ++i) dp[i][0] = cost[i];
    for (int i = 0; i < n; ++i) {
        for (int len = 1; len < k; ++len) {
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i])
                    dp[i][len] = max(dp[i][len], dp[j][len-1] + cost[i]);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i][k-1]);
    }

    return ans;
}