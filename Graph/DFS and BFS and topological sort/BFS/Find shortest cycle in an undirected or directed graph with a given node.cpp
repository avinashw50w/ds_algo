

const int maxn = 100;
vector<int> G[maxn];
vector<int> dist;
vector<int> par;

int bfs(int src) {
	queue<int> Q;
	dist.assign(maxn, -1);
	par.assign(maxn, -1);

	Q.push(src);
	dist[src] = 0;

	while (!Q.empty()) {
		int u = Q.front();  Q.pop();

		for (int v: G[u]) {
			if (dist[v] == -1 or dist[v] == 0) {
				dist[v] = dist[u] + 1;
				par[v] = u;

				if (v == src) return dist[v];
				Q.push(v);
			}
		}
	}

	return -1;
}

void printPath(int src) {
	cout << src;

	int v = par[src];
	
	while(v != src and v != -1) {
		cout << "<--" << v;
		v = par[v];
	}
}