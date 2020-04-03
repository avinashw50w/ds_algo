/*Given the source u and destination v of a graph, find and print all possible paths from u to v
Can be used for both directed and undirected graphs
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
vector<int> G[maxn];
int vis[maxn];

void dfs(int u, int d, vector<int> buff, vector<vector<int>> &paths) {

	vis[u] = 1;
	buff.push_back(u);

	if (u == d) {
		paths.push_back(buff);
	}

	for (int v: G[u]) {
		if (!vis[v]) dfs(v, d, buff, paths);
	}

	vis[u] = 0;
	buff.pop_back();
}

vector<vector<int>> getAllPaths(int source, int dest) {
	vector<vector<int>> paths;

	vector<int> buffer;

	dfs(source, dest, buffer, paths);

	return paths;
}

void addEdge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

int main() {
	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	// addEdge(2,0);
	addEdge(2,1);
	addEdge(1,3);

	vector<vector<int>> res = getAllPaths(2, 3);

	for(auto i: res)  {
		for (int j: i) cout << j << " ";
		cout << endl;
	}
}