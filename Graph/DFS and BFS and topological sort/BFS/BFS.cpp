
vector<int> G[1000];
int vis[1000];

void bfs(int u) {

	queue<int> Q;
	Q.push(u);

	while(!Q.empty()) {
		int top = Q.front(); Q.pop();
		
		vis[top] = 1;

		for(int i = 0; i < G[top].size(); ++i) {
			if(!vis[G[top][i]])
				Q.push(G[top][i]);
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