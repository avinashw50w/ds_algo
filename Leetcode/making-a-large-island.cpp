/*In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.*/

class Solution {
    int N;
    int cnt;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
public:
    
    int dfs(vector<vector<int>> grid, int x, int y) {
        int N = grid.size();
        bool vis[N][N];
        memset(vis, false, sizeof(vis));
        
        vis[x][y] = true;
        stack<int> st;
        st.push(x*N + y);
        int cnt = 0;
        
        while(!st.empty()) {
            cnt++;
            int code = st.top();
            st.pop();
            int r = code/N;
            int c = code%N;
            
            for (int i = 0; i < 4; ++i) {
                int nx = r + dx[i];
                int ny = c + dy[i];
                
                if (nx >= 0 and nx < N and ny >= 0 and ny < N and !vis[nx][ny]
                   and grid[nx][ny] == 1) {
                    st.push(nx*N + ny);
                    vis[nx][ny] = true;
                }
            }
        }
        return cnt;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
    
        int ans = 0, hasZero = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    hasZero = 1;
                    grid[i][j] = 1;
                    ans = max(ans, dfs(grid, i, j));
                    grid[i][j] = 0;
                }
            }
        }
        
        return hasZero ? ans : N*N;
    }
};