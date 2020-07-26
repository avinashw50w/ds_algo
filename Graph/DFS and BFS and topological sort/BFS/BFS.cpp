
vector<int> G[1000];
int vis[1000];

void bfs(int u) {

	queue<int> Q;
	Q.push(u);

	while(!Q.empty()) {
		int u = Q.front(); Q.pop();

		vis[u] = 1;

		for(auto v: G[u]) {
			if(!vis[v])
				Q.push(v);
		}
	}
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

	bfs(1);
}
