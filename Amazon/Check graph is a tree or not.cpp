/*Check whether a graph is a tree or not
IDEA: a tree is a connected and acyclic
*/

vector<int> vis(n + 1, 0);

bool isCyclic(vector<vector<int>> g, int u, int p = -1) {
	vis[u] = 1;
	for (int v : g[u]) {
		if (v == p) continue;
		if ((vis[v] == 0 and isCyclic(g, v, u)) or vis[v] == 1) return true;
	}

	vis[u] = 2;
	return false;
}

bool checkTree(vector<vector<int>> g) {
	int n = g.size();

	if (isCyclic(g, 0)) return false;

	for (int e : vis) if (e == 0) return false;

	return true;
}