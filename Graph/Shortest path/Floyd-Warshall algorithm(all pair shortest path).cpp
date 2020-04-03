// Floyd Warshall algorithm for all pairs shortest path //
/* Here, for a given graph G(V,E), we find the shortest distance between vertices u,v i.e., du,v, for all u,v∈V. We'll discuss the Floyd-Warshall algorithm to solve this problem.

Floyd-Warshall Algorithm


This is again a dynamic programming algorithm. 
We keep building the shortest distances between all vertices of the graph. 
Initially,
d(u,v) = w(u,v), if (u,v)∈E
       =   ∞   ,  otherwise
Then, for every intermediate vertex k, we update the shortest distance of (u,v) to:
d(u,v)=min(d(u,v), d(u,k)+d(k,v))
After doing this for all such vertices k∈V, du,v is the shortest distance between u and v for every u,v∈V. 
The running time of this algorithm is O(|V|3) and its implementation is extremely straightforward.  */

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define INF 1000000000
using namespace std;

int main(){
    int N, M, u, v, w;
    cin>> N >> M; //Input the number of nodes(0 based), number of edges and the source vertex.
    int G[N][N];
    
	fill(&G[0][0], &G[N][0], INF);
	
    rep(i, 0, N) G[i][i] = 0;

    rep(i, 0, M) { 
        cin >> u >> v >> w;
        G[u][v] = w;
    }
   
    //Code for Floyd Warshall which computes all pair shortest path.
    
    rep(k, 0, N) 
    	rep(i, 0, N) 
    		rep(j, 0, N) 
    			G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    
    return 0;
}
