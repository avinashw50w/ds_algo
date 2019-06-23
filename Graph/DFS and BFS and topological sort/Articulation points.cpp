/*A vertex in an undirected connected graph is an articulation point (or cut vertex) iff removing it (and edges through it) 
disconnects the graph. Articulation points represent vulnerabilities in a connected network – single points whose failure 
would split the network into 2 or more disconnected components. They are useful for designing reliable networks.
For a disconnected undirected graph, an articulation point is a vertex removing which increases number of connected components.
A O(V+E) algorithm to find all Articulation Points (APs)
The idea is to use DFS (Depth First Search). In DFS, we follow vertices in tree 
form called DFS tree. In DFS tree, a vertex u is parent 
of another vertex v, if v is discovered by u (obviously v is an adjacent of u in graph). 
In DFS tree, a vertex u is articulation point 
if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree 
rooted with v has a back edge to one of the ancestors (in DFS tree) of u.*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define vb vector<bool>
vi depth, low;
vi *G;
vb AP;
int N;

void DFS(int u, int baap = -1) {
	static int t = 0;
	int children = 0;
	// depth[i] is the depth for node i in the dfs tree 
	// L[i] the lowest depth of neighbors of all descendants of node i in the depth-first-search tree
	depth[u] = low[u] = ++t;

	for(auto v : G[u]) {
		if(v == baap) continue;

		// if there is a back edge from v to its ancestors(not u, but ancestors of u)
		if(depth[v]) 
			low[u] = min(low[u], depth[v]);
		else
		{
			children++;
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= depth[u]) // for finding cut-edges just do low[v] > depth[u]
				AP[u] = true;
		}
	}

	if(baap == -1 and children < 2)
		AP[u] = false;
}

void addEdge(int u,int v){ 
	G[u].push_back(v);
	G[v].push_back(u);
}

int main() {
	cin >> N;
	G = new vi[N+1];
	AP.assign(N,false);
	depth.assign(N,0);
	low.assign(N,0);

	for(int i=0;i<N;++i)
		if(!depth[i])
			DFS(i, -1);
	

	for(int i=0;i<N;++i)
		if(AP[i])
			cout << i <<", ";
}
