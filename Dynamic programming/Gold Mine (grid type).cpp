/*Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only diagonal up, diagonal down and right that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.*/

int solve(vector<vector<int>> grid) {
    int n = grid.size(), m = grid[0].size();

    int dp[n][m];

    for (int j = m-1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            int right = j+1 < m ? dp[i][j+1] : 0;
            int rightup = i-1 > 0 and j+1 < m ? dp[i-1][j+1] : 0;
            int rightdown = i+1 < n and j+1 < m ? dp[i+1][j+1] : 0;

            dp[i][j] = grid[i][j] + max(right, max(rightup, rightdown));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[i][0]);
    }

    return ans;
}