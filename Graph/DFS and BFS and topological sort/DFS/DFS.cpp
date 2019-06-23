vector<int> G[1000];
vector<int> vis[1000];

void dfs(int u) {
	vis[u] = 1;

	for(int i = 0; i < G[u].size(); ++i)
		if(!vis[G[u][i]])
			dfs(G[u][i]);
}

int main() {
	int N; // no of nodes
	int M; // no of edges

	cin >> N >> M;

	// input all the edges
	for(int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1);
}