#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ALL(X) (X).begin(),(X).end()
int N;  //  no of vertices
vi V;   //  visited array
vi *G;  // graph

void dfs(int i){
	if(!V[i]){
		V[i] = true;
		for_each(ALL(G[i]) , dfs);
	}
}

bool check_graph_connected(){
	int start_vertex = 0;
	V = vi(N,false);
	dfs(start_vertex);
	return (find(ALL(V), 0) == V.end());
}
void addEdge(int u,int v){
	G[u].push_back(v);
}

int main()
{
    // Create a graph given in the above diagram
    N=4;
    V.assign(4,0);
    G = new vi[N+2];
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    dfs(2);
 
    return 0;
}

/*STL algorithm 'for_each' calls the specified function, 'dfs', for each element in range. In check_graph_connected() function we first make the Visited array
 (of correct size and filled with zeroes). After DFS we have either visited all vertices, or not � this is easy to determine by searching for at least one zero in V,
  by means of a single call to find().  */
