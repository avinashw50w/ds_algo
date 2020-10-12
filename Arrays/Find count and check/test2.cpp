vector<int> g[500];
vector<int> vis;
int cnt;
void dfs(int u) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (!vis[v]) dfs(v);
	}
}

int countGroups(vector<string> m) {
	int n = m.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] == '1') {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	cnt = 0;
	vis.assign(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i), cnt++;
	}

	return cnt;
}