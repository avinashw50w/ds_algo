/* Find the height of the tree when root is x. */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
int in[MAXN], out[MAXN];
int dp[MAXN]; // dp[i] stores the height of the tree when the root is i

vector<int> G[MAXN];

void dfs1(int u, int baap) {
	in[u] = 0;

	for(int v: G[u]) {
		if(v == baap) continue;
		dfs1(v, u);
		in[u] = max(in[u], 1 + in[v])
	}
}

void dfs2(int u, int baap) {
	int mx1(-1), mx2(-1);

	// find the 2 max values of in[v]
	for(int v: G[u]) {
		if(v == baap) continue;
		if(in[v] >= mx1) mx2 = mx1, mx1 = in[v];
		else if(in[v] > mx2) mx2 = in[v];
	}

	for(int v: G[u]) {
		if(v == baap) continue;

		int use = mx1;
		if(in[v] == mx1)
			use = mx2;

		out[v] = 1 + max(out[u], 1 + use);
	}
}
int main() {
	int N; cin >> N;

	int u, v;

	for(int i = 0; i < N-1; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}


	dfs1(1, 0);
	dfs2(1, 0);

	for(int i = 0; i < N; ++i)
		dp[i] = max(in[i], out[i]);
}
