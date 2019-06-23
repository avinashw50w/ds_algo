/*A matrix probability question
Given a rectangular matrix, we can move from current cell in 4 directions with equal probability. The 4 directions are right, left, top or bottom. Calculate the Probability that after K moves from a given position (i, j) in the matrix, we will not cross boundaries of the matrix at any point.

We strongly recommend you to minimize your browser and try this yourself first.

The idea is to perform something similar to DFS. We recursively traverse in each of the 4 allowed direction and for each cell encountered, we calculate the required probability with one less move. As each direction has equal probability, each direction will contribute to 1/4 of total probability of that cell i.e. 0.25. We return 0 if we step outside the matrix and return 1 if N steps are completed without crossing matrix boundaries.*/

// dp[x][y][k]
double dp[100][100][10];
double vis[100][100][10];

bool isSafe(int x, int y, int N, int M) {
    return (x >= 0 and x < N and y >= 0 and y < M);
}

double solve(int i, int j, int N, int M, int K) {
    if (!isSafe(i, j, N, M)) return 0.0;

    if (K == 0) return 1.0;

    if (vis[i][j][K]) return dp[i][j][K];
    vis[i][j][K] = 1;

    double prob = 0.0;

    prob += solve(i-1, j, N, M, K-1) * 0.25;
    prob += solve(i, j-1, N, M, K-1) * 0.25;
    prob += solve(i+1, j, N, M, K-1) * 0.25;
    prob += solve(i, j+1, N, M, K-1) * 0.25;

    return dp[i][j][K] = prob;
}