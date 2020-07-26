// DFS for general graph

const int manx = 1e5 + 5;

int N, M; // no of nodes and edges respectively
vector<int> G[maxn]; // the graph
int vis[maxn]; // visited array

void dfs(int u) {
	vis[u] = 1;

	for (auto v: G[u])
		if (!vis[v])
			dfs(v);
}

int main() {

	cin >> N >> M;
	int u, v;

	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}


	// start the dfs from node 0
	dfs(0);
}

/////////////////////////////////////////////////////////////

// DFS for a general tree

void dfs(int u, int baap = -1) {

	for (auto v: G[u]) {
		if (v == baap) continue;

		dfs(v, u);
	}
}

//////////////////////////////////////////////////////////

// calculate the level/depth of each of the nodes of a tree from the root

int level[maxn];

void dfs(int u, int baap = -1) {

	for (auto v: G[u]) {
		if (v == baap) continue;
		level[v] = level[u] + 1;
		dfs(v, u);
	}
}

//////////////////////////////////////////////////////////

// calculate height of a tree using DFS

int height[maxn]; // height[i] stores the height of the subtree rooted at i

void dfs(int u, int baap) {
	height[u] = 1;
	int mx = 0;

	for (auto v: G[u]) {
		if (v == baap) continue;
		dfs(v, u);

		mx = max(mx, height[v]);
	}

	height[u] += mx;
}

// OR
void dfs(int u, int baap) {
	height[u] = 0;

	for (auto v: G[u]) {
		if (v == baap) continue;
		dfs(v, u);

		height[u] = max(height[u], 1+height[v]);
	}
}


///////////////////////////////////////////////////////

// find the maximum sum path from root to leaf

int sum[maxn]; // sum[i] stores the maximum sum path from node i to leaf
int a[maxn]; // a[i] contains the value of node i

// the ans will be sum[0] if 0 is the root

void dfs(int u, int baap) {

	sum[u] = a[u];
	int mx = 0;

	for (auto v: G[u]) {
		if (v == baap) continue;
		dfs(v, u);

		mx = max(mx, sum[v]);
	}

	sum[u] += mx;
}

///////////////////////////////////////////////////////////

// find the height of the tree when u is the root

int in[maxn], out[maxn];
int dp[maxn]; // dp[i] stores the height of tree if i is the root of the tree

void dfs1(int u, int baap) {

	in[u] = 0;

	for (auto v: G[u]) {
		if (v == baap) continue;
		dfs(v, u);

		in[u] = max(in[u], 1+in[v]);
	}
}

void dfs2(int u, int baap) {

	int mx1 = -1, mx2 = -1;

	// find the top 2 maximum values of in[v]
	for (auto v: G[u]) {
		if (v == baap) continue;
		if (in[v] >= mx1) mx2 = mx1, mx1 = in[v];
		else if (in[v] > mx2) mx2 = in[v];
	}

	for (auto v: G[u]) {
		if (v == baap) continue;

		int use = mx1;
		if (mx1 == in[v])
			use = mx2;

		out[v] = max(1+out[u], 2+use);

		dfs(v, u);
	}
}



int main() {

	dfs1(1, 0);
	dfs2(1, 0);

	for (int i = 0; i < N; ++i)
		dp[i] = max(in[i], out[i]);
}


///////////////////////////////////////////////////////////
// dfs on a grid

// the direction vector for moving top, right, bottom and left
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

const int maxn = 1e3+1;
int N, M; // N x M grid
int grid[maxn][maxn]; // the grid
int vis[maxn][maxn]; // visited array

void dfs(int x, int y) {
	vis[x][y] = 1;

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 and ny >= 0 and nx < N and ny < M and !vis[nx][ny]) dfs(nx, ny);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> grid[i][j];

	dfs(0, 0);
}
