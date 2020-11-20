/*For general graph, finding longest path is an NP-Hard problem.
But for DAG, it can be solved in O(V+E)
Algo is almost similar to finding the shortest path in DAG
1. find the topological order of all the nodes
2. initialize the dist of all the nodes to -INF and the dist of source node to 0
3. process each node in the topological order one by one
4. for each of the node processed, update the dist of the adjacent nodes
*/

// Time complexity: O(V + E)
const int maxn = 1e5;
const int INF = 1e9;
vector<pair<int, int>> G[maxn];
vector<int> dist, vis, st;

void init() {
	vis.assign(maxn, 0);
	dist.assign(maxn, -INF);

	cin >> N >> M; // N: no of nodes, M: no of edges
	for (int i = 0; i < M; ++i) {
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
}

void dfs(int u) {
	vis[u] = 1;
	for (auto e : G[u]) {
		int v = e.first;
		if (!vis[v]) dfs(v);
	}
	st.push_back(u);
}

vector<int> shortestPathDAG(int src) {
	init();
	dfs(src);

	dist[src] = 0;

	while (!st.empty()) {
		int u = st.back(); st.pop_back();

		if (dist[u] != INF) {
			for (auto e : G[u]) {
				int v = e.first, w = e.second;
				if (dist[v] < dist[u] + w) {
					dist[v] = dist[u] + w;
				}
			}
		}
	}

	return dist;
}