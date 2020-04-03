

bool hasCycle(int u) {
	vis[u] = 1;

	for (int v: G[u]) {
		if ((!vis[v] and hasCycle(v)) or vis[v] == 1) return true;
	}

	vis[u] = 2;
	return false;
}

bool isCyclic() {
	memset(vis, 0, sizeof(vis));

	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			if (hasCycle(i))
				return true;
		}
	}

	return false;
}