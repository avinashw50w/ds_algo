/*Height of a tree is defined only for a root tree, ie, the height is relative to the root.*/

const int MAXN = 1e5;
vector<int> G[MAXN];
int height[MAXN]; // height[u] stores the height of the subtree rooted at u

void dfs(int u, int p)
{
	height[u] = 1;
	int mx = 0;

	for(auto v: G[u])
	{
		if(v == p) continue;
		dfs(v, u);
		mx = max(mx, height[v]);
	}

	height[u] += mx;
}

int main() {

	int N; cin >> N;

	for(int i = 0; i < N-1; ++i) {
		int u, v;
		cin >> u >> v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int root = 1;
	int parent = 0;

	dfs(root, parent);
}