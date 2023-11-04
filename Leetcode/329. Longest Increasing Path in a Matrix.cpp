/*Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not 
move diagonally or move outside the boundary (i.e., wrap-around is not allowed).*/

class Solution {
public:
    vector<vector<int>> dp;
    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };
    int n, m;
    
    bool valid(int x, int y) {
        return x >= 0 and y >= 0 and x < n and y < m;
    }
    
    int dfs(vector<vector<int>> &mat, int x, int y) {
        if (dp[x][y] != -1) return dp[x][y];
        int ret = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny) and mat[nx][ny] > mat[x][y])
                ret = max(ret, dfs(mat, nx, ny));
        }
        
        return dp[x][y] = 1 + ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        if (n == 0) return 0;
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};

/////////////////////////////////////////////////////////////////
// another easier method
class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        
        // build indegree
        vector<vector<int>> indegree(m, vector<int>(n,0));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(auto dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] < matrix[i][j]) {
                        indegree[i][j]++;
                    }
                }
                if(indegree[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        
        // bfs, topo sort
        int len = 0;
        while(!q.empty()) {
            int sz = q.size();
            while (sz--) { 
                auto t = q.front();
                q.pop();
                
                for(auto dir : dirs) {
                    int x = t.first + dir[0];
                    int y = t.second + dir[1];
                    if(x >= 0 && x < m && y >= 0 && y < n && matrix[t.first][t.second] < matrix[x][y] && --indegree[x][y] == 0) {
                        q.push({x, y});
                    }
                }
            }
            len++;
        }
        return len;
    }    
};