//  Topological sorting is done only for Directed Acyclic Graphs(DAG)  //
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int n;  // no of vertices
vector<int> g[MAXN];   // graph
vector<int> vist;     // visited array
stack<int> order;

void dfs (int v) {
	vist[v] = 1;
	for (auto i: g[v]) {
		if (!vist[i])
			dfs (i);
	}
	order.push(v);
}

void topological_sort() {
	vist.assign(n,0);

	for (int i=0; i<n; ++i)
		if (!vist[i])
			dfs (i);
}



// or do this :
void topological_sort(int u){
    V[u] = true;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!V[v]) topologicalSort(v);
    }
    order.push(u);

}
