/*On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)*/

class Solution {
    int ans;
    vector<vector<int>> grid;
    int R, C;
    int dr, dc;
    int steps;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};

    int uniquePaths(vector<vector<int>> &grid) {
        R = grid.size();
        C = grid[0].size();

        int sr = 0, sc = 0;
        steps = 0;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] != -1) steps++;
                else if (grid[i][j] == 1) sr = i, sc = j;
                else if (grid[i][j] == 2) dr = i, dc = j;
            }
        }

        ans = 0;
        dfs(sr, sc, steps);

        return ans;
    }

    void dfs(int x, int y, int steps) {
        steps--;
        if (steps < 0) return;

        if (x == dr and y == dc) {
            if (steps == 0) ans++;
            return;
        }

        grid[x][y] = 3;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and nx < R and ny >= 0 and ny < C) {
                if (grid[nx][ny] == 0 or grid[nx][ny] == 2) 
                    dfs(nx, ny, steps);
            }
        }

        grid[x][y] = 0;
    }
}
// Time complexity: O(4^(R*C))
///////////////////////////////////////////////////////////////////////
// another solution using dp and bitmasking

class Solution {
    static const int maxn = 15;
    vector<vector<int>> grid;
    int dp[maxn][maxn][1 << (maxn*maxn)];
    int R, C;
    int mask, dr, dc;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};

    int code(int r, int c) {
        return (1 << (r*C + c));
    }

    int uniquePaths(vector<vector<int>> &grid) {
        R = grid.size();
        C = grid[0].size();

        mask = 0,;
        int sr = 0, sc = 0;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C: ++j) {
                // both cell 0 and cell 2 are included in the mask
                if (grid[i][j] & 1 == 0) mask |= code(i, j);
                else if (grid[i][j] == 2) dr = i, dc = j;
                else if (grid[i][j] == 1) sr = i, sc = j;
            }
        }

        memset(dp, -1, sizeof(dp));

        solve(sr, sc, mask);
    }

    int solve(int x, int y, int mask) {
        if (dp[x][y][mask] != -1) return dp[x][y][mask];

        if (x == dr and y == dc) return mask == 0 ? 1: 0;

        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and nx < R and ny >= 0 and ny < C) {
                if (mask & code(nx, ny)) {
                    ans += solve(nx, ny, mask ^ code(nx, ny));
                }
            }
        }

        return dp[x][y][mask] = ans;
    }

}


