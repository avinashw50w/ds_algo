/*A directed graph is strongly connected if there is a path between all pairs of vertices.
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph
Algo:
1. store the topological order of the nodes in a stack
2. create the transpose of the graph by reversing direction of all the edges
3. process all the nodes in the stack one by one, for each node do a dfs on the reversed graph
*/
const int maxn = 1e5;
vector<int> G[maxn], RG[maxn];
vector<int> vis, st;

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		RG[v].push_back(u);
	}

	vis.assign(maxn, 0);
}

void dfs(int u) {
	vis[u] = 1;
	for (int v : G[u]) if (!vis[v]) dfs(v);
	st.push_back(u);
}

void dfs1(int u, vector<int> &res) {
	vis[u] = 1;
	res.push_back(u);
	for (int v : RG[u]) if (!vis[v]) dfs1(v, res);
}

vector<vector<int>> SCC() {
	init();

	for (int i = 0; i < N; ++i) {
		if (!vis[i]) dfs(i);
	}

	vector<vector<int>> res;
	vis.assign(maxn, 0);

	while (!st.empty()) {
		int u = st.top();
		vector<int> tmp;
		if (!vis[u]) {
			dfs1(u, tmp);
			res.push_back(tmp);
		}
	}

	return res;
}