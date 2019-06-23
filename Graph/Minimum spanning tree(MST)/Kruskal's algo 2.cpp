/* Algorithm : 
1. Sort all the edges based on their weights. 
2. Now for each edge in the sorted order, check whether the two end vertices of that edge belongs to the same set or not,
3. If they donot belong to the same set then add its cost and take their union. Otherwise check another edge in the sorted order.  */

// time complexity  O(ElogE + ElogV)  //  to sort the edges : O(ElogE)  and for each edge we call root() which takes O(ElogV)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 5;
int nodes, edges, par[MAXN];
set<tuple<ll,ll,ll> > E;

void init(){
	for(int i=0; i<MAXN; ++i)
		par[i] = i;
}

int root(int x){
	if(x == par[x]) return x;
	else return par[x] = root(par[x]);
}

void Union(int x, int y){
	int p = root(x);
	int q = root(y);

	par[p] = q;
}

ll Kruskal( set< tuple<ll,ll,ll> > E ) {
	
	init();

	ll minCost = 0;
	int x, y, cost;

	while(!E.empty()) {
		auto it = E.begin();
		tie(cost, x, y) = *it;
		E.erase(it);

		if(root(x) != root(y)){
			minCost += cost;
			Union(x, y);
		}
	}
	
	return minCost;
}

int main() {
	int x, y, cost;
	cin >> nodes >> edges;

	for(int i=0; i<edges; ++i){
		cin >> x >> y >> cost;
		E.insert(make_tuple(cost, x, y));
	}

	ll minCost = Kruskal(E);

	cout << minCost << endl;

	return 0;
}
