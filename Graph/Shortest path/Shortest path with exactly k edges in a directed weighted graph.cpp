/*Given a 2D array cost where cost[i][j] represents the cost of travelling from i to j.
Find the minimum cost to reach from src to dest in exactly k steps.
If cost[i][j] = INF, then there is no edge between i and j*/

int solve(vector<vector<int>> cost, int src, int dest, int k) {
    int n = cost.size();
    int dp[n][n][k+1];

    for (int steps = 0; steps <= k; ++steps) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][steps] = INF;
                if (i == j and steps == 0) dp[i][j][steps] = 0;
                else if (i == j and steps == 1) dp[i][j][steps] = cost[i][j];
                else if (steps > 1) {
                    for (int a = 0; a < n; ++a) {
                        if (i != a and cost[i][a] != INF) {
                            dp[i][j][steps] = min(dp[i][j][steps], cost[i][a] + dp[a][j][steps-1]);
                        }
                    }
                }
            }
        }
    }

    return dp[src][dest][k];
}