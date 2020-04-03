/*Pick a random node A, then find the farthest node from A, let it be B, 
then again find the farthest node from B, let it be C. 
Now the distance between B and C is the diameter of the tree. */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
pair<int, int> best;
int N;

void DFS(int u, int par, int len) {
	best = max(best, {len, u});
	for(auto v: G[u]) {
		if (v == par) continue;
		DFS(v, u, len + 1);
	}
}

int main() {
	cin >> N;

	G.clear();
	G.resize(N+1);

	for(int i = 0; i < N; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int first = 1;
	best = {-1, -1};
	DFS(first, -1, 0);

	int second = best.second;
	
	best = {-1, -1};
	DFS(second, -1, 0);

	return best.first;	
}