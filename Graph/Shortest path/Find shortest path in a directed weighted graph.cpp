/*Find the shortest cycle path sum in a directed weighted graph

Method 1: using FLoyd Warshall O(V^3)
Use Floyd warshall with a little tweak. Insted of assigning dist[i][i] = 0, assign dist[i][i] = INFINITY */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;

#define rep(i,a,b) for (int i = a;i <b;++i)

int fun(int g[maxn][maxn]) {

	int d[maxn][maxn];
	
	fill(&d[0][0], &d[maxn][0], 999999);
	
	for (int i = 0; i < maxn; ++i)
	for (int j = 0; j < maxn; ++j) if (g[i][j])  d[i][j] = g[i][j];// d[i][i] = 0;
	
	rep(k, 0, maxn) rep(i, 0, maxn) rep(j, 0, maxn) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	int ans = INT_MAX;
	rep(i, 0, maxn) d[i][i] = min(ans, d[i][i]);

	return ans;
}

int main() {
	int g[maxn][maxn] = {{0,8,0,0,0},
		{0,0,1,0,0},
		{0,0,0,2,0},
		{0,0,0,0,1},
		{0,3,0,0,0}
	};
	
	cout << fun(g);
}

////////////////////////////////////////////////////////////////////


