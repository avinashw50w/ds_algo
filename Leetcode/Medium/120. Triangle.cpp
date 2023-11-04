/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        fill(&dp[0][0], &dp[n][0], INT_MAX);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (i == 0) dp[i][j] = triangle[i][j];
                else if (j == 0) dp[i][j] = triangle[i][j] + dp[i-1][j];
                else dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) ans = min(ans, dp[n-1][j]);

        return ans;
    }
};