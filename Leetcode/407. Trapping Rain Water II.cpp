/*Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.*/
class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    // struct Point {
    //     int x, y, val;
    //     Point(int a, int b, int c) {
    //         x = a;
    //         y = b;
    //         val = c;
    //     }
    //     bool operator < (const Point& p) { return val > p.val; }
    // };
    
public:
     
    int trapRainWater(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if (n == 0) return 0;
        bool vis[n][m];
        memset(vis, 0, sizeof(vis));
        auto cmp = [](auto a, auto b) { return a[0] > b[0]; };
        priority_queue<array<int, 3>, vector<array<int,3>>, decltype(cmp)> q(cmp);
        int sum0 = 0, sum1 = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 or i == n-1 or j == 0 or j == m-1) {
                    vis[i][j] = 1;
                    q.push({ mat[i][j], i, j });
                }
                sum0 += mat[i][j];
            }
        }
                
        while (!q.empty()) {
            auto top = q.top(); q.pop();
            int x = top[1], y = top[2], val = top[0];
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 and ny >= 0 and nx < n and ny < m and !vis[nx][ny]) {
                    mat[nx][ny] = max(mat[nx][ny], mat[x][y]);
                    vis[nx][ny] = 1;
                    q.push({ mat[nx][ny], nx, ny });
                }
            }
        }
        
        for (auto row: mat) {
            for (int e: row) sum1 += e;
        }

        return sum1 - sum0;
    }
};