// doing dfs on a tree and calculating the parent and the level of a node along with the number of nodes in its subtree //

const int MAXN = 1e5 + 5;  // maximum no of nodes in the tree
const int LOGN = 20;       // maximum no of levels of the tree ,ie, log(N)
int par[LOGN][MAXN];      // par[i][j] = 2^ith parent of a node j
int level[MAXN];			  // the level of a node
int sub[MAXN];			  // the no of nodes in the subtree of a node
int tin[MAXN], tout[MAXN]; // stores the entry and exit times of a node in dfs traversal
int timer;

void dfs(int u, int p = -1) {
	sub[u] = 1;
	tin[u] = timer++;
	par[0][u] = p;

	for(int i=1; i<LOGN; ++i){
		if(par[i-1][u] != -1)
			par[i][u] = par[i-1][par[i-1][u]];
		else
			break;
	}

	for(auto v: G[u]) {
		if(v != p) {
			level[v] = level[u] + 1;
			dfs(v, u);
			sub[u] += sub[v];
		}
	}

	tout[u] = timer++;
}

// check whether u is ancestor of v
bool isAncestor(int u, int v) {
	return tin[u] < tin[v] and tout[u] > tout[v];
}

///////////////////////////// another way /////////////////////////////////////////////

void dfs0(int u) {
	for(auto i: G[u])
		if(i != par[0][u]) {
			par[0][i] = u;
			level[i] = level[u] + 1;
			dfs(i);
		}
}

void preprocess() {
	par[0][0] = 0;
	dfs0(0);

	for(int i=1; i<LOGN; ++i)
		for(int j=0; j<n; ++j)
			par[i][j] = par[i-1][par[i-1][j]];
}

////////////////////////////////////////////////////////////////////////////////
