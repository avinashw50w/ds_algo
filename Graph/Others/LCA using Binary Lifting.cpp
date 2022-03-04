#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int LOGN = 18;

vector<pair<int, int>> G[MAXN];
int N; // number of nodes (the nodes are from 1 to N)
int dp[LOGN][MAXN]; // dp[i][j] stores the 2^i th parent of node j
int depth[MAXN], dist[MAXN];

void dfs(int u, int par) {
	dp[0][u] = par;

	for(auto it: G[u]) {
		int v = it.first;
		int w = it.second;
		if(v != par) {
			depth[v] = depth[u] + 1;
			dist[v] = dist[u] + w;
			dfs(v, u);
		}
	}
}

// returns the lowest common ancestor of a and b
int LCA(int a, int b) {
	if(depth[a] < depth[b]) 
		swap(a, b);
    
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOGN; ++i) {
        if (diff>>i&1)
            a = dp[i][a];
    }
	// for (int i = LOGN - 1; i >= 0; i--)
 //        if (depth[dp[i][a]] >= depth[b]) 
 //            a = dp[i][a];

	if(a != b) {
		for(int i = LOGN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        a = dp[0][a];
    }
    return a;
}

// returns the min distance between two nodes a and b of the tree
int distt(int a, int b) {
	int lca = LCA(a, b);
	return dist[a] + dist[b] - 2*dist[lca];
}


int main() {
	cin >> N;

	for(int i = 0; i < N-1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}

	dp[0][1] = 0;
	depth[1] = 0;
	dist[1] = 0;

	dfs(1, 0);
    // let x = 2^i th parent of j
    // let y = 2^(i-1) th parent of j
    // then x = 2^(i-1) th parent of y
	for(int i = 1; i < LOGN; ++i)
		for(int j = 1; j <= N; ++j)
			dp[i][j] = dp[i-1][dp[i-1][j]];
}