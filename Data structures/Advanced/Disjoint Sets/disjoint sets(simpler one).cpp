/*DSU without any heuristics runs O(n), path compression + ranking heuristics runs O(a(n)),
where a(n) is th inverse ackermann function 
and only zipping or only ranking heuristic will run O(log(n)).*/
#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> rank, parent;

void makeSet(int v){
	rank[v] = 0;
	parent[v] = v;
}

int findSet(int v){
	if(parent[v] == v) return v;
	else return parent[v] = findSet(parent[v]);
}

void Union(int a,int b){
	a = findSet(a);
	b = findSet(b);
	if(rank[a] >= rank[b]){
		rank[a] = (rank[a] == rank[b])? rank[a]+1 : rank[a];
		parent[b] = a;
	}
	else parent[a] = b;
}
////////////////////////////////////////////////////////////////////////////
//another one : but the merge process is not optimized(path compressed) //

int par[MAXN];

int init() {
	for(int i=0; i<n; ++i)
		par[i] = i;
}

int root(int v) {
	if(v == par[v]) return v;
	else return par[v] = root(par[v]);
}

void merge(int x, int y) {
	int u = root(x);
	int v = root(y);
	
	par[u] = par[v];
}


