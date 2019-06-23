/* A directed graph is strongly connected if there is a path between any two pair of vertices. */
/* Following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph:
1) Initialize all vertices as not visited.

2) Do a DFS traversal of graph starting from any arbitrary vertex v. If DFS traversal doesn’t visit all vertices, then return false.

3) Reverse all arcs (or find transpose or reverse of graph)

4) Mark all vertices as not-visited in reversed graph.

5) Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2). If DFS traversal doesn’t visit all vertices, 
then return false. Otherwise return true.

The idea is, if every node can be reached from a vertex v, and every node can reach v, then the graph is strongly connected. 
In step 2, we check if all vertices are reachable from v. In step 4, we check if all vertices can reach v 
(In reversed graph, if all vertices are reachable from v, then all vertices can reach v in original graph).

time complexity : O(E+V)  */
#define ALL(x) (x).begin(),(x).end()
#define vi vector<int>
vi V;
vi *G1, *G2;
int N;

void dfs(int i, vi G) {
	if(!V[i]){
		V[i] = 1;
		for_each(ALL(G[i]), dfs);
	}
}

bool IsStonglyConnected() {
	V.assign(N,0);

	dfs(0, G1);

	if(find(ALL(V), 0) != V.end()) return false;   // if all nodes are not reachable from a given node(say v), then return false.

	V.assign(N,0);

	dfs(0, G2);

	if(find(ALL(V), 0) != V.end()) return false;  // if any other node cannot reach to v, then return false.

	return true;
}

void addEdge(int u,int v){
	G1[u].push_back(v);
	G2[v].push_back(u);   // transpose of G1
}

int main() {
	cin>>N>>M;
	G1 = new vi[N+1];
	G2 = new vi[N+1];
	for(int i=0;i<M;++i){
		cin>>u>>v;
		addEdge(u,v);
	}

	if(IsStonglyConnected()) 
		cout << "Graph is strongly connected.";
}
