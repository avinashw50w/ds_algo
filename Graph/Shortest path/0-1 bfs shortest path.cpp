/* find shortest path in a graph when the edge weights are either 1 or 0 */

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define oo (1<<30)
int n;
vii *g;
vi dist;
void bfs_shortestpath(int s){
	deque<int> q;
	dist.assign(n,oo);
	dist[s] = 0;
	q.push_back(s);
	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(auto i: g[u]){
			int v = i.first, w = w.second;
			if(dist[u] != oo and dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				if(w == 0) q.push_front(v);    //  since we have to maintain the deque in decreasing order, so push the edge with  
				else q.push_back(v);          // min weight(ie 0) at the front and the edge with weight 1 at the back.
			}
		}
	}
}
