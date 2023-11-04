/*On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y, and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Now we view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3 dimensional figure to a 2 dimensional plane. 

Here, we are viewing the "shadow" when looking at the cubes from the top, the front, and the side.

Return the total area of all three projections.

 

Example 1:

Input: [[2]]
Output: 5
Example 2:

Input: [[1,2],[3,4]]
Output: 17
Explanation: 
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.*/

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N = grid.size();
        
        int ans = 0, top = 0;
        for (int i = 0; i < N; ++i) {
            int mx = INT_MIN, mx2 = INT_MIN;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) top++;
                mx = max(mx, grid[i][j]);
                mx2 = max(mx2, grid[j][i]);
            }
            
            ans += mx + mx2;
        }
        
        return ans + top;
    }
};