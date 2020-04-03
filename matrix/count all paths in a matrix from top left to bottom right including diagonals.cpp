/* Count all possible paths to reach from top left to bottom right of a 2D matrix. You can move down, right or diagonally right.*/

// recursive one

int solve(int r, int c) {
    if (r == 0) return 1;
    if (c == 0) return 1;

    return solve(r-1, c) + solve(r, c-1) + solve(r-1, c-1);
}

int countPaths(vector<vector<int>> grid) {
    int N = grid.size();
    int M = grid[0].size();

    return solve(N-1, M-1);
}

////////////////////////////
// dynamic

int countPaths(vector<vector<int>> grid) {
    int N = grid.size();
    int M = grid[0].size();

    int dp[N][M];
    for (int i = 0; i < N; ++i) dp[i][0] = 1;
    for (int i = 0; i < M; ++i) dp[0][i] = 1;

    for (int i = 1; i < N; ++i)
        for (int j = 1; j < M; ++j)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1];
}