/*Pick a random node A, then find the farthest node from A, let it be B,
then again find the farthest node from B, let it be C.
Now the distance between B and C is the diameter of the tree. 

reason:
If we run dfs from a random node, then the farthest node will end up in a leaf node.
Now again we run dfs from a leaf node, the farthest node from a leaf node will be another leaf node.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
pair<int, int> best; // {dist, node}
int N;

void DFS(int u, int par = -1, int dist = 0) {
	best = max(best, {dist, u});
	for (auto v : G[u]) {
		if (v == par) continue;
		DFS(v, u, dist + 1);
	}
}

int main() {
	cin >> N;

	G.clear();
	G.resize(N + 1);

	for (int i = 0; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int first = 1;
	best = { -1, -1 };
	DFS(first,);

	int second = best.second;
	best = { -1, -1 };
	DFS(second);

	return best.first;
}