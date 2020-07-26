/*Cound the no of nodes at a given level in a tree*/
// can be found by using both dfs and bfs


const int maxn = 1e3;

int level[maxn];

void dfs(int u, int p) {

	for (auto v: G[u]) {
		if (v != p) {
			level[v] = level[u] + 1;
			dfs(v, u);
		}
	}
}

int solve(int root, int lvl) {

	dfs(root, -1);

	int cnt = 0;

	for (int i = 0; i < maxn; ++i) {
		cnt += (level[i] == lvl);
	}

	return cnt;
}

//////////////////////////////////
// using BFS

int bfs(int src, int lvl) {
	int vis[N] = {0};
	int level[N] = {0};
	queue<int> Q;
	q.push(src);

	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		vis[u] = 1;

		for (int v: G[u]) {
			if (!vis[v]) {
				level[v] = level[u] + 1;
				Q.push(v);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i)
		cnt += (level[i] == lvl);

	return cnt;
}
