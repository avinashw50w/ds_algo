/*Algorithm :
1.Start with a random vertex and mark it.
2.Check all the vertices that are adjacent to any marked vertex and select the cheapest vertex that does not create a cycle and mark it.
3.Repeat step 2 until all the vertices are marked. */

/* time complexity : O((V+E)logV) ,  for traversing each edge and vertex takes O(E+V), and
									 for pushing each vertex in priority queue takes (logV)   
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef tuple<int,int> tii;
const int MAXN = 1e4 + 5;
int nodes, edges, vist[MAXN];
vector<tii> G[MAXN];

ll Prims(int s) {
	int u, cost;
	ll minCost = 0;

	priority_queue<tii, vector<tii>, greater<tii> > Q;
	Q.push(make_tuple(0, s));

	while(!Q.empty()) {
		tie(cost, u) = Q.top();
		Q.pop();
		
		if(vist[u]) continue;
		vist[u] = 1;

		minCost += cost;

		for(auto i: G[u]) {
			int v = get<0>(i);
			int d = get<1>(i);
			if(!vist[ v ])
				Q.push(make_tuple(d, v));
		}
	}

	return minCost;
}


int main() {
	int x, y, cost;
	cin >> nodes >> edges;

	for(int i=0; i<edges; ++i) {
		cin >> x >> y >> cost;
		G[x].push_back(make_tuple(y, cost));
		G[y].push_back(make_tuple(x, cost));
	}

	ll minCost = Prims(0);

	cout << minCost << endl;

	return 0;
}
