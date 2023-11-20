/*Given a matrix of size nxm. A robot is at top right(0,0). Find the # of ways to reach the bottom right 
corner (n-1xm-1) if allowed to move either right or down

sol: let dp[i][j] be the # of ways to reach (i,j). We can reach (i, j) from the top (i-1,j) 
or the left (i,j-1) positions
so dp[i][j] = dp[i-1][j] + dp[i][j-1]
*/

int solve(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    int dp[n][m] = {{}}; // fill with zeroes

    dp[0][0] = 1; 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0) dp[i][j] += dp[i][j-1];
            else if (j == 0) dp[i][j] += dp[i-1][j];
            else dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n-1][m-1];
}

// cleaner version
int solve(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    int dp[n+1][m+1] = {{}}; // fill with zeroes

    dp[1][1] = 1; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n][m];
}

// using combinatrics
// to reach the bottom right from top left corner in a nxm grid, 
// there will be exactly n down and m right paths
// so the total possible ways = total no of distinct ways to arrange n down and m right paths
// so ways = (n+m)!/n!*m! = (n+m)Cn or (n+m)Cm
// 
