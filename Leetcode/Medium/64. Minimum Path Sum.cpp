/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = grid[i][j];
                int mn = INT_MAX;
                if (i) mn = min(mn, dp[i-1][j]);
                if (j) mn = min(mn, dp[i][j-1]);
                if (mn != INT_MAX) dp[i][j] += mn;
            }
        }
        
        return dp[n-1][m-1];
    }
};

/////////////////////////////////////////////////////////////////
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp = vector<vector<int>>(n+1, vector<int>(m+1, INT_MAX));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = grid[i-1][j-1];
                int mn = min(dp[i-1][j], dp[i][j-1]);
                if (mn != INT_MAX) 
                    dp[i][j] += mn;
            }
        }

        return dp[n][m];
    }
};

/////////////////////////////////////////////////////////////////
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        int dp[n][m];
        
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < n; ++i) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int i = 1; i < m; ++i) {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);

            }
        }

        return dp[n-1][m-1];
    }
};