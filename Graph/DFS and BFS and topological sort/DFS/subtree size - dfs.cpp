#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<int> G[MAXN];
int vis[MAXN];
string sub[MAXN];
char nodes[MAXN];
int N;

void dfs(int u) {
	vis[u] = 1;
	sub[u] = nodes[u];

	for(auto v: G[u]) {
		if(!vis[v]) {
			dfs(v);
			sub[u] += sub[v];
		}
	}
}

/*
			a
		  /   \
		 b     c
	  / / \   / \
	 d e  f   g  h
*/
int main() {
	int Q; 
	cin >> N >> Q;

	for(int i = 1; i <= N; ++i) cin >> nodes[i];

	for(int i = 0; i < N-1; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 0; i < MAXN; ++i) sub[i] = "";

	dfs(1);
	
	while(Q--) {
		int X;
		string S;
		cin >> X >> S;

		cout << sub[X] << endl;
	}
}


/*input:
8 3
a b c d e f g h
1 2
2 4
3 1
5 2
2 6
3 7
3 8
1 shdfkh
2 dkjflg
3 dfkh
*/