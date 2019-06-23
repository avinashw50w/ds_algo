const int MAXN = 1e5 + 5;  // maximum no of nodes in the tree
const int LOGN = 20;       // maximum no of levels of the tree ,ie, log(N)
int par[LOGN][MAXN];      // parent of a node on a given level
int lev[MAXN];			  // the level of a node
int sub[MAXN];			  // the no of nodes in the subtree of a node
int st[MAXN];			// the start time of entering a node
int ft[MAXN];			// the finish time of entering a node

int TIME = 0;

void dfs(int u) {
	st[u] = TIME++;
	sub[u] = 1;

	for(auto v: G[u]) {
		if(v != par[0][u]) {
			lev[v] = lev[u] + 1;
			dfs(v);
			sub[u] += sub[v];
		}
	}

	ft[u] = TIME;
}

void preprocess() {
	par[0][0] = 0;
	lev[0] = 0;
	dfs(0);

	for(int i=1; i<LOGN; ++i)
		for(int j=0; j<n; ++j)
			par[i][j] = par[i-1][par[i-1][j]];
}