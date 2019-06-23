#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000+2
vector<int> G[MAXN];
int par[MAXN], subtree[MAXN];
int nodes;
/* eg. tree :        1
					/ \
				   2   3
				 / \    \
				4  5    6  

		i  = 1 2 3 4 5 6
subtree[i] = 6 3 2 1 1 1    */

int dfs(int u, int p) {
	subtree[u] = 1;
	nodes++;
	for(auto i: G[u]) {
		if(i != p) {
			dfs(i, u);
			subtree[u] += subtree[i];
		}
	}
}

int find_centroid(int u, int p) {
	for(auto i: G[u])
		if(i!=p and subtree[i] > nodes/2) 
			find_centroid(i, u);

	return u;
}

void Decompose(int root, int p) {
	nodes = 0;
	dfs(root, root);
	int centroid = find_centroid(root, root);

	par[centroid] = (p == -1? centroid : p);

	for(auto i: G[centroid]) {
		G[i].erase(centroid);
		Decompose(i, centroid);
	}
	G[centroid].clear();
}