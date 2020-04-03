// shortest path for Directed Acyclic Graph  , using topological sorting  //
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define ALL(X) (X).begin(),(X).end()
const long long int oo = (1LL<<60);
int N;  //  no of vertices
vi V;   //  visited array
vi dist;  //  to store distance of each vertex from the source
vii *G;  // graph
stack<int> s;   //  to store the topologically sorted list of vertices

void topologicalSort(int u){
	V[u] = true;
	for(auto c: G[u]){
		int v = c.first;
		if(!V[v]) topologicalSort(v);
	}
	s.push(u);
	
}

void shortestPath(int s){
	dist.assign(N,oo);
	V.assign(N,0);
	dist[s] = 0;

	for(int i=0;i<N;i++){
		if(!V[i])
			topologicalSort(i)
	}

	while(!s.empty()){
		int u=s.top(); s.pop();
		if(dist[u]!=oo){
			for(int i=0;i<G[u].size();i++){
				int v=G[u][i].first , w=G[u][i].second;
				if(dist[v] > dist[u] + w)
					dist[v] = dist[u] + w;
			}
		}
	}

	for(int i=0;i<N;i++){
		cout<<( dist[i]==oo? -1 : dist[i] )<<" ";
	}
}

void addEdge(int u,int v,int w){
	G[u].push_back(pii(v,w));
}
