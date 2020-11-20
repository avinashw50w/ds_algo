/*DSU without any heuristics runs O(n), path compression + ranking heuristics runs O(a(n)),
where a(n) is th inverse ackermann function
and only zipping or only ranking heuristic will run O(log(n)).*/
#include <bits/stdc++.h>
using namespace std;

class DSU {
	vector<int> par, sz;
public:
	DSU(int N) {
		par.resize(N);
		sz.assign(N, 1);
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	// using path compression
	int root(int v) {
		if (par[v] == v) return v;
		else return par[v] = root(par[v]);
	}

	int in_same_set(int a, int b) {
		return root(a) == root(b);
	}

	int join(int a, int b) {
		int x = root(a);
		int y = root(b);

		if (x == y) return 0;
		if (sz[x] < sz[y]) swap(x, y);

		par[y] = x;
		sz[x] += sz[y];
	}
};

///////////////////////////////////////////////////
// using rank for union
unordered_map<int, int> rank, parent;

void makeSet(int v) {
	rank[v] = 0;
	parent[v] = v;
}

int findSet(int v) {
	if (parent[v] == v) return v;
	else return parent[v] = findSet(parent[v]);
}

void Union(int a, int b) {
	a = findSet(a);
	b = findSet(b);
	if (rank[a] >= rank[b]) {
		rank[a] = (rank[a] == rank[b]) ? rank[a] + 1 : rank[a];
		parent[b] = a;
	}
	else parent[a] = b;
}



