/*Eulerian Cycle
An undirected graph has Eulerian cycle if following two conditions are true.
….a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path 
(we only consider all edges).
….b) All vertices have even degree.

Eulerian Path
An undirected graph has Eulerian Path if following two conditions are true.
….a) Same as condition (a) for Eulerian Cycle
….b) If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

How does this work?
In Eulerian path, each time we visit a vertex v, we walk through two unvisited edges with one end point as v. Therefore, all middle vertices in Eulerian Path must have even degree. For Eulerian Cycle, any vertex can be middle vertex, therefore all vertices must have even degree.*/

#include <bits/stdc++.h>
using namespace std;

#define NOT_EULERIAN 0 
#define SEMI_EULERIAN 1
#define EULERIAN 2

vector<int> *G;
vector<int> vis;
int N;

void dfs(int i) {
	if(!vis[i]){
		vis[i] = 1;
		for_each(G[i].begin(), G[i].end(), dfs);
	}
}

bool connected() {
	vis.clear();
	vis.assign(N, 0);
	int i;
	for(i=0; i<N; ++i) if(G[i].size()) break;  // find a vertex with non-zero degree

	if(i == N) return false;  // if no such vertex exists then return false;

	dfs(i);
	// if there is a vertex which is not visited means that the graph is disconnected
	for(int i = 0; i < N; ++i) if(!vis[i] and G[i].size()) return false;  

	return true;
}

int Eulerian() {
	if(!connected()) return 0;
	// check odd degree vertices //
	for(int i=0; i<N; ++i) if(G[i].size() & 1) odd++;

	if(odd > 2) return NOT_EULERIAN;

	if(odd == 2) return SEMI_EULERIAN;
	if(odd == 0) return EULERIAN; 
}

