/*Pick a random node A, then find the farthest node from A, let it be B, 
then again find the farthest node from B, let it be C. 
Now the distance between B and C is the diameter of the tree. */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<pair<int,int>> G[MAXN];

int dist[MAXN];
int N;

void DFS(int u) {

	for(auto it: G[u]) {
		int v = it.first;
		int w = it.second;

		if(dist[v] == -1) {
			dist[v] = dist[u] + w;
			DFS(v);
		}
	}
}

int main() {
	cin >> N;

	for(int i = 0; i < N; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}

	memset(dist, -1, sizeof(dist));

	int start = 1;

	DFS(start);

	int interm = 0;

	for(int i = 0; i < N; ++i)
		if(dist[i] > dist[interm])
			iterm = i;

	memset(dist, -1, sizeof(dist));
		
	DFS(iterm);

	int finish = 0;

	cout << *max_element(dist, dist + n);
}