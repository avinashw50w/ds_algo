/*Use  DFS with backtracking*/
vector<int> G[maxn];
int vis[maxn];

void dfs(int u, int dest, int &cnt) {
	vis[u] = 1;

	if (u == desc) cnt++;

	else {
		for (int v: G[u])
			if (!vis[v]) dfs(v, dest, cnt);
	}

	v[u] = 0;
}
