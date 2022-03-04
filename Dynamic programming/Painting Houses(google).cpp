/*You are looking to paint a row of N fences that can be of K different colors. You have a goal of minimizing cost while ensuring that no two neighboring fences are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to paint the nth fence with kth color, return the minimum cost which achieves this goal.

Note: All costs will be integers greater than or equal to 0, and there is guaranteed to be at least 2 possible colors.

Bonus: solve in \mathcal{O}(1)O(1) space.

Constraints

N, K ≤ 500
Example 1
Input
matrix = [
    [5, 3, 4],
    [2, 1, 6],
    [2, 3, 4],
    [4, 3, 3]
]
Output
10

IDEA: let dp[i][j] - min cost to paint i fences such that the last fence is painted with color j
now we need to paint fence i+1, so we need a different color than j, say jj
dp[i+1][jj] = min(dp[i+1][jj], dp[i][j] + cost[i][j]), where cost[i][j] is the cost of painting
fence i with color j
*/
// T: O(N*M*M)
// S: O(N*M)
int solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    const int inf = 1e9 + 7;
    vector<vector<int>> dp(n+1, vector<int>(m, inf));
    for (int j = 0; j < m; ++j) {
        dp[1][j] = min(dp[1][j], mat[0][j]);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int jj = 0; jj < m; ++jj) {
                if (j == jj) continue;
                dp[i+1][jj] = min(dp[i+1][jj], dp[i][j] + mat[i][jj]);
            }
        }
    }

    int ans = inf;
    for (int j = 0; j < m; ++j) {
        ans = min(ans, dp[n][j]);
    }
    return ans;
}

/////////////////////////////
// further optimisation
/* if we paint the ith fence with color j, then 
dp[i][j] = cost[i][j] + min(dp[i-1][jj]) where jj != j
so we find the index of the minimum (mn1) and second minimum (mn2) value in the row dp[i-1]
so dp[i][j] = dp[i-1][mn2] + cost[i][j], if j == mn1 then 
            = dp[i-1][mn1] + cost[i][j], otherwise
 */
// T: O(n*m)
// S: O(n*m)
int solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    const int inf = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m, inf));
    for (int j = 0; j < m; ++j) {
        dp[0][j] = mat[0][j];
    }
    for (int i = 1; i < n; ++i) {
        int mn1 = 0, mn2 = -1;
        for (int j = 1; j < m; ++j) {
            if (dp[i-1][j] <= dp[i-1][mn1]) {
                mn2 = mn1;
                mn1 = j;
            }
            else if (mn2 == -1) mn2 = j;
            else if (dp[i-1][j] < dp[i-1][mn2]) {
                mn2 = j;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (j == mn1) 
                dp[i][j] = mat[i][j] + dp[i-1][mn2];
            else 
                dp[i][j] = mat[i][j] + dp[i-1][mn1];
        }
    }

    int ans = inf;
    for (int j = 0; j < m; ++j) {
        ans = min(ans, dp[n-1][j]);
    }
    return ans;
}

//////////////////////////////////////////////////////////////////
// futher optimisation on space
// we can use the matrix itself as the dp array
// T: O(n*m)
// S: O(1)
int solve(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
        const int inf = 1e9 + 7;

        for (int i = 1; i < n; ++i) {
            int mn1 = 0, mn2 = -1;
            for (int j = 1; j < m; ++j) {
                if (mat[i-1][j] <= mat[i-1][mn1]) {
                    mn2 = mn1;
                    mn1 = j;
                }
                else if (mn2 == -1) mn2 = j;
                else if (mat[i-1][j] < mat[i-1][mn2]) {
                    mn2 = j;
                }
            }

            for (int j = 0; j < m; ++j) {
                if (j == mn1) 
                    mat[i][j] = mat[i][j] + mat[i-1][mn2];
                else 
                    mat[i][j] = mat[i][j] + mat[i-1][mn1];
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
}