/*Find the longest path in a matrix with given constraints
Given a n*n matrix where all numbers are distinct, find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.

We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

Example:

Input:  mat[][] = {{1, 2, 9}
                   {5, 3, 8}
                   {4, 6, 7}}
Output: 4
The longest path is 6-7-8-9 */


vector<vector<int>> grid;
vector<vector<int>> dp;
int N, M;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int solve(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) return 0;

    int &res = dp[i][j];

    if (res != -1) return res;

    int len = 0;

    for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and nx < N and ny >= 0 and ny < M and (grid[i][j] + 1) == grid[nx][ny])
            len = max(len, solve(nx, ny));
    }

    return res = 1 + len;
}

int longestPath() {

    N = grid.size();
    M = grid[0].size();

    dp = new vector<vector<int>>(N, vector<int>(M, -1));

    int res = INT_MIN;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            res = max(res, solve(i, j));
        }
    }

    return res;
}