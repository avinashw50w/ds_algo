/*Given a nxm binary matrix. Find the maximum side length of a sub square containing all 1's.*/

int solve(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mat[i][j] == 1) {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}