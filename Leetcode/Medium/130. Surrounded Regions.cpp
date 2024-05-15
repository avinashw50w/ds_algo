/*Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.*/
class Solution {
    int vis[200][200];
    int dx [4]= {1, 0, -1, 0};
    int dy [4]= {0, 1, 0, -1};
    int n, m;
public:
    void dfs(int x, int y, bool capture, vector<vector<char>>& mat) {
        vis[x][y] = 1;
        if (capture) mat[x][y] = 'X';
        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and mat[nx][ny] == 'O')
                dfs(nx, ny, capture, mat);
        }
    }
    void solve(vector<vector<char>>& mat) {
        n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 or i == n-1 or j == 0 or j == m-1)
                    and mat[i][j] == 'O' and !vis[i][j]) dfs(i, j, 0, mat);
            }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] and mat[i][j] == 'O') 
                dfs(i, j, 1, mat);
        }
    }
}
};