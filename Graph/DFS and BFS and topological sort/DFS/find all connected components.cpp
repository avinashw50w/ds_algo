class Graph {
	int N;
	vector<int> *G;
	int *vis;
public:
	Graph(int N) {
		this->N = N;
		G = new vector<int>[N];
		vis = new int[N](); // also initializes the array with 0
	}

	void dfs(int u, vector<int> &comp) {
		vis[u] = 1;
		comp.push_back(u);
		for (int v: G[u]) {
			if (!vis[v])
				dfs(v, comp);
		}
	}

	vector<vector<int>> findConnectedComponents() {
		vector<vector<int>> res;
		vector<int> comp;
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < N; ++i) {
			if (!vis[i]) {
				dfs(i, comp);
				res.push_back(comp);
			}
		}

		return res;
	}
};