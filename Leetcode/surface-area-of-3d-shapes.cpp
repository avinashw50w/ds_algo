/*On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.

 

Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34*/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        
        if (n == 0) return 0;
        
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        int ans = 0, nv;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) continue;
                ans += 2;
                
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    nv = 0;
                    if (ni >= 0 and ni < n and nj >= 0 and nj < m)
                        nv = grid[ni][nj];
                        
                    ans += max(grid[i][j] - nv, 0);
                }
            }
        }
        
        return ans;
    }
};