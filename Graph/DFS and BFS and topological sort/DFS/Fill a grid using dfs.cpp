/*Flood fill Algorithm – how to implement fill() in paint?
In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color. Following is the problem statement to do this task.
Given a 2D screen, location of a pixel in the screen and a color, replace color of the given pixel and all adjacent same colored pixels with the given color.

Example:

Input:
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };
    x = 4, y = 4, newColor = 3
The values in the given 2D screen indicate colors of the pixels.
x and y are coordinates of the brush, newColor is the color that
should replace the previous color on screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 3, 3, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 3, 3, 0},
                      {1, 1, 1, 1, 1, 3, 1, 1},
                      {1, 1, 1, 1, 1, 3, 3, 1},
                      };
*/

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool safe(vector<vector<int>> grid, int x, int y) {
    return (x >= 0 and x < N and y >= 0 and y < M);
}

void dfs(vector<vector<int>> &grid, int x, int y, int currColor, int newColor) {

    grid[x][y] = newColor;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!safe(grid, nx, ny)) continue;
        if(grid[nx][ny] != currColor) continue;

        dfs(grid, nx, ny, currColor, newColor);
    }
}

// Given the starting coordinates, flood fill with newColor
vector<vector<int>> floodFill(vector<vector<int>> grid, int x, int y, int newColor) {
    int currColor = grid[x][y];

    int N = grid.size();
    int M = grid[0].size();

    dfs(grid, x, y, currColor, newColor);
}
