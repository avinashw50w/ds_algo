/*Given a tree with N nodes numbered from 1 to N and an array A where A[i] store the cost of the node i.
Find the maximum root to leaf cost path in the tree. */

const int MAXN = 1e5;
vector<int> G[MAXN]; // adjacency list for storing the tree
int A[MAXN]; // A[i] stores the cost of the node i
int dp[MAXN]; // dp[u] stores the maximum cost path from the node u to any leaf node in the subtree rooted at u

void dfs(int u, int p) {
	dp[u] = A[u];
	int mx = 0;

	for(auto v: G[u]) {
		if(v == p) continue;

		dfs(v, u);
		mx = max(mx, dp[v]);
	}

	dp[u] += mx;
}

int main() {
	int N; cin >> N;
	int u, v;

	for(int i = 0; i < N; ++i)
		cin >> A[i];

	for(int i = 0; i < N; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int root = 1;
	int parent = 0;

	dfs(root, parent);

	int ans = dp[1]; // maximum cost path from the root to leaf

	cout << ans << endl;
}