// doing dfs on a tree and calculating the parent and the level of a node along with the number of nodes in its subtree //

const int MAXN = 1e5 + 5;  // maximum no of nodes in the tree
const int LOGN = 20;       // maximum no of levels of the tree ,ie, log(N)
int par[LOGN][MAXN];      // parent of a node on a given level
int lev[MAXN];			  // the level of a node
int sub[MAXN];			  // the no of nodes in the subtree of a node

void dfs(int u, int p = -1) {
	sub[u] = 1;
	par[0][u] = p;
	lev[u] = (p == -1 ? 0 : lev[p] + 1);

	for(int i=1; i<LOGN; ++i){
		if(par[i-1][u] != -1)
			par[i][u] = par[i-1][par[i-1][u]];
		else
			break;
	}

	for(auto i: G[u]) {
		if(i != p) {
			dfs(i, u);
			sub[u] += sub[i];
		}
	}
}

///////////////////////////// another way /////////////////////////////////////////////

void dfs0(int u) {
	for(auto i: G[u]) 
		if(i != par[0][u]) {
			par[0][i] = u;
			lev[i] = lev[u] + 1;
			dfs(i);
		}
}

void preprocess() {
	par[0][0] = 0;
	lev[0] = 0;
	dfs0(0);

	for(int i=1; i<LOGN; ++i)
		for(int j=0; j<n; ++j)
			par[i][j] = par[i-1][par[i-1][j]];
}

////////////////////////////////////////////////////////////////////////////////