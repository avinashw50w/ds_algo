const int MAXN = 1e5+5;
const int LOGN = 30;

vector<int> G[MAXN];
int euler[2*MAXN]; // to store the euler tour of the tree
int level[2*MAXN]; // to store the height of the respective nodes in the euler array
int height[MAXN]; // to store the height of nodes in the tree
int occur[MAXN]; // index of the first occurance of the nodes in the euler tour array
int log[2*MAXN];
int dp[2*MAXN][LOGN];
int N; // number of nodes
int cnt; // number of elements in the euler tour array

void dfs(int u, int p, int l) {
	height[u] = l;
	euler[cnt++] = u;

	for(auto v: G[u])
		if(v != p) {
			dfs(v, u, l+1);
			euler[cnt++] = u;
		}

}

void RMQ(int N) {
	for(int i = 2; i <= N; ++i)
		log[i] = log[i/2] + 1;

	for(int i = 1; i <= N; ++i)
		dp[i][0] = i;

	for(int j = 1; (1 << j) <= N; ++j)
		for(int i = 1; i + (1 << j) <= N; ++i) {
			if(level[dp[i][j-1]] < level[dp[i + (1<<(j-1))][j-1]])
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i + (1<<(j-1))][j-1];
		}
}

int query(int L, int R) {
	int k = log[R-L+1];

	if(level[dp[L][k]] < level[dp[R - (1<<k) + 1][k]])
		return dp[L][k];
	else
		return dp[R - (1<<k) + 1];
}

int LCA(int u, int v) {
	if(occur[u] > occur[v])
		swap(u, v);

	return euler[query(occur[u], occur[v])];
}


int main() {
	cin >> N;

	int x, y;

	for(int i = 0; i < N-1; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	cnt = 1;

	dfs(1, -1, 0);

	for(int i = 1; i < cnt; ++i)
		level[i] = height[euler[i]];

	memset(occur, -1, sizeof(occur));

	for(int i = 1; i < cnt; ++i)
		if(occur[euler[i]] == -1)
			occur[euler[i]] = i;

	RMQ(2*N);

	int Q; cin >> Q; // queries

	while(Q--) {
		int u, v; 
		cin >> u >> v;

		cout << LCA(u, v) << endl;
	}
}