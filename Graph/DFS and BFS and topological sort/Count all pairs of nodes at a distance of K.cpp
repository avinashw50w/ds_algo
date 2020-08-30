/*Given a tree, Count all pairs of nodes at a distance of K from each other*/

const int maxn = 1e5;

vector<int> G[maxn];
int dp[maxn][100]; // dp[i][j] = no of nodes in the subtree rooted at i and are at a distance of j from i
int N, K, ans;

void dfs(int u, int p = -1) {
	dp[u][0] = 1;

	for (int v : G[u]) {
		if (v == p) continue;
		dfs(v, u);
		// here dp[u][j] will not include the nodes in the subtree rooted at v
		// let x be the no of nodes in the subtree rooted at u but not in the subtree rooted at v
		// which are at a distance of j-1 from u
		// and let y = no of nodes in the subtree rooted at v which are at a distance of k-j from v
		// so the total no of nodes at a distance of k from u will be (x * y)
		for (int  j = 1; j <= k; ++j)
			ans += dp[u][j - 1] * dp[v][k - j];
		// here we consider the nodes in the subtree rooted at v in calculating dp[u][j]
		for (int j = 1; j <= k ++j) {
			dp[u][j] += dp[v][j - 1];
		}
	}
}