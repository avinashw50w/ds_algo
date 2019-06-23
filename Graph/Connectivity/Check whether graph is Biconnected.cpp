/* A connected graph is Biconnected if it is connected and doesn’t have any Articulation Point. We mainly need to check two things in a graph.
1) The graph is connected.
2) There is not articulation point in graph.*/
#define ALL(x) (x).begin(),(x).end()
#define vi vector<int> 
#define vb vector<bool>
vi parent, disc, low;
vi *G;
vb AP, V;
int N;

void Articulation(int u) {
	V[u] = true;
	static int t = 0;
	int children = 0;
	disc[u] = low[u] = ++t;

	for(auto v : G[u]) {
		if(!V[v]) {
			children++;
			parent[v] = u;
			Articulation(v);

			low[u] = min(low[u], low[v]);

			if(parent[u] == -1 and children > 1)      // if u is the root and has more than one children,then it is an articulation point
				AP[u] = true;
			if(parent[u] != -1 and low[v] >= disc[u]) // if u is not the root and has children who don't have a back edge to any ancestor of u
				AP[u] = true;
		}
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

bool IsBiconnected(){
	V.assign(N,false);
	AP.assign(N,false);
	parent.assign(N,-1);
	disc.assign(N,0);
	low.assign(N,0);

	if(Articulation(0)) return false;       // if there is an articulation point, then the graph is not biconnected.

	if(find(ALL(V), 0) != V.end()) return false;  // if any node is not visited, then the graph is not connected.

	return true;
}