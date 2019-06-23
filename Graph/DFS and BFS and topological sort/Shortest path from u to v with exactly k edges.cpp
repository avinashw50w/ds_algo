/*Given two vertices u and v, find the shortest path from u to v with exactly k edges*/
// using DFS. Time complexity : O(V^k)

class Solution {
	static const int maxn = 1e3;
	int G[maxn][maxn];
	int V;
public: 
	int DFS(int u, int v, int k) {
		if (k == 0 and u == v) return 0;
		if (k == 1 and G[u][v] != INF) return G[u][v];
		if (k <= 0) return INF;

		int res = INF;

		for (int i = 0; i < V; ++i) {
			if (G[u][i] != INF and u != i) {
				int t = DFS(i, v, k-1);

				if (t != INF)
					res = min(res, G[u][i] + t);
			}			
		}

		return res;
	}
};

// using DP, Time complexity : O(k * V * V * V)
// its just like Floyd Warshall's algo to find all pair shortest path
int solve(int u, int v, int k) {
	int dp[maxn][maxn][k+1];

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			if (i == j) dp[i][j][0] = 0; // min cost to move from i to i with 0 steps is 0
			if (G[i][j] != INF) dp[i][j][1] = G[i][j]; // min cost to move from i to j with 1 step is G[i][j]
		}
	}

	for (int l = 2; l <= k; ++l) {
		for (int i = 0; i < V; ++i) { // for source
			for (int j = 0; j < V; ++j) { // for destination
				dp[i][j][l] = INF;

				for (int a = 0; a < V; ++a) { // for any middle node between i and j
					if (G[i][a] != INF and i != a and j != a and dp[a][j][l-1] != INF)
						dp[i][j][l] = min(dp[i][j][l], G[i][a] + dp[a][j][l-1]);
				}
			}
		}
	}	

	return dp[u][v][k]
}

