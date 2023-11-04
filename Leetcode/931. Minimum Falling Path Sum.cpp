/*Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.*/

class Solution {
    const int INF = 1e9;
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        
        for (int i = 0; i < n; ++i) dp[0][i] = A[0][i];
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int ans = INF;
                if (i-1 >= 0 and dp[i-1][j] != INF) 
                    ans = min(ans, A[i][j] + dp[i-1][j]);
                
                if (i-1 >= 0 and j-1 >= 0 and dp[i-1][j-1] != INF) 
                    ans = min(ans, A[i][j] + dp[i-1][j-1]);
                
                if (i-1 >= 0 and j+1 < n and dp[i-1][j+1] != INF) 
                    ans = min(ans, A[i][j] + dp[i-1][j+1]);
                
                dp[i][j] = ans;
            }
        }
        
       
        int ans = INF;
        for (int i = 0; i < n; ++i) ans = min(ans, dp[n-1][i]);
        
        return ans;
    }
};