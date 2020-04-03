/*Transitive Closure of a Graph using DFS
Given a directed graph, find out if a vertex v is reachable from another vertex u 
for all vertex pairs (u, v) in the given graph. Here reachable mean that there is a 
path from vertex u to v. The reach-ability matrix is called transitive closure of a graph.

For example, consider below graph
transitiveclosure
Transitive closure of above graphs is 
     1 1 1 1 
     1 1 1 1 
     1 1 1 1 
     0 0 0 1 */

void dfs(int u, int v, vector<vector<int>> &tc) {
	tc[u][v] = 1;

	for (int i: G[v])
		if (!tc[u][i]) dfs(u, i, tc);
}

vector<vector<int>> getTransitiveClosure(vector<vector<int>> &graph) {
	int N = graph.size();
	vector<vector<int>> tc(N, vector<int> (N, 0));

	for (int i = 0; i < N;  ++i) {
		dfs(i, i, tc);
	}
}