/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.
 
Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]*/

class Solution {
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        int ans = 0;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0) ans++;
                    if (i == N-1) ans++;
                    if (j == 0) ans++;
                    if (j == M-1) ans++;
                }
                else {
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (!(nx >= 0 and nx < N and ny >= 0 and ny < M 
                              and grid[nx][ny] == 1)) continue;
                        ans++;
                    }
                }
            }
            
        }
        
        return ans;
    }
};