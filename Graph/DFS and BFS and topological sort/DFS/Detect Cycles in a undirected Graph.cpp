

bool hasCycle(int u, int par) {
	vis[u] = 1;

	for (int v : G[u]) {
		if (v == par) continue;
		if ((!vis[v] and hasCycle(v)) or vis[v] == 1) return true;
	}

	return false;
}

bool isCyclic() {
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			if (hasCycle(i, -1))
				return true;
		}
	}

	return false;
}