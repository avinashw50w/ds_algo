/*A bridge is an edge, which when removed disconnects the graph.*/

const int maxn = 1e5;
vector<int> G[maxn];
int tin[maxn], low[maxn];
int timer;

void dfs(int u, int par) {
	tin[u] = low[u] = timer++;

	for (int to : G[u]) {
		if (to == par) continue;

		// if to is already visited and is not its parent then it's a back edge.
		// NOTE: back edge can never be a bridge
		if (tin[to]) {
			low[u] = min(low[u], tin[to]);
		}
		else {
			dfs(to, u);
			// if there is no back edge of the child, then a bridge is found
			if (low[to] > tin[u])
				cout << u << " -> " << to << " is a bridge\n";

			low[u] = min(low[u], low[to]);
		}
	}
}

int main() {
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> x >> y, G[x].push_back(y), G[y].push_back(x);

	dfs(1, -1);
}