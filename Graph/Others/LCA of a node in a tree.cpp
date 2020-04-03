#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int LOGN = 20;
int par[MAXN][LOGN], level[MAXN];
vector<int> G[MAXN];

void dfs0(int u) {
	for(auto i: G[u]) 
		if(i != par[u][0]) {
			par[i][0] = u;
			level[i] = level[u] + 1;
			dfs(i);
		}
}

void preprocess() {
	par[0][0] = 0;
	level[0] = 0;
	dfs0(0);

	for(int j = 1; j < LOGN; ++j)
		for(int i = 0; i < n; ++i)
			par[i][j] = par[par[i][j-1]][j-1];
}

int lca(int a, int b) {
	if(level[a] > level[b]) a^=b^=a^=b;
	int d = level[b] - level[a];
	for(int i = 0; i < LOGN; ++i)
		if(d & (1<<i)) 
			b = par[b][i];

	if(a == b) return a;
	for(int i = LOGN-1; i >= 0; --i)
		if(par[a][i] != par[b][i]) 
			a = par[a][i], b = par[b][i];

	return par[a][0];
}

////////////////////////////////////////////////////////////
