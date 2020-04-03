/*Objective: Given two dimensional matrix, write an algorithm to find out the snake sequence which has the maximum length. There could be many snake sequence in the matrix, you need to return the one with the maximum length. Travel is allowed only in two directions, either go right OR go down.

What is snake sequence: Snake sequence can be made if number in adjacent right cell or number in the adjacent down cell is either +1 or -1 from the number in the current cell.*/

int solve(vector<vector<int>> grid) {

    int N = grid.size();
    int M = grid[0].size();

    int dp[N][M];
    fill(&dp[0][0], &dp[0][M], 1);

    int ans = 1, maxrow = 0, maxcol = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i > 0 and abs(grid[i][j] - grid[i-1][j]) == 1) {
                dp[i][j] = max(dp[i][j], 1 + dp[i-1][j]);
            }

            if (j > 0 and abs(grid[i][j] - grid[i][j-1]) == 1) {
                dp[i][j] = max(dp[i][j], 1 + dp[i][j-1]);
            }

            if (ans < dp[i][j]) {
                ans = dp[i][j];
                maxrow = i;
                maxcol = j;
            }
        }
    }

    return ans;
}

void printPath() {
    while (len >= 1) {
        cout << grid[maxrow][maxcol] << "-";
        if (maxrow > 0 and abs(grid[maxrow][maxcol] - grid[maxrow-1][maxcol]) == 1) maxrow--;
        else if (maxcol > 0 and abs(grid[maxrow][maxcol] - grid[maxrow][maxcol-1]) == 1) maxcol--;
        len--;
    }
}