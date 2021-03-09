/*Shortest path with exactly k edges in a directed and weighted graph | Set 2
Given a directed weighted graph and two vertices S and D in it, the task is to find the shortest path from S to D with exactly K edges on the path. If no such path exists, print -1.*/

/*
IDEA: let dp[v][j] store the shortest path to reach v with j edges on the path
then dp[v][j+1] = min(dp[u][j] + dist between u and v)

we can optimise space by taking dp of 1D
 */

struct Edge {
	int u, v, w;
};
// N is the no of nodes in the graph
int solve(int S, int D, int N, int K, vector<Edge> edges) {
	vector<int> dp(N, INF);
	dp[s] = 0;

	for (int i = 0; i <= K; ++i) {
		vector<int> ndp(N, INF);
		for (Edge edge : edges) {
			ndp[edge.v] = min(ndp[edge.v], dp[edge.u] + edge.w);
		}
		dp = ndp;
	}

	return dp[D] != INF ? dp[D] : -1;
}