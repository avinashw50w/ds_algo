/*Find a Mother Vertex in a Graph
What is a Mother Vertex?
A mother vertex in a graph G = (V,E) is a vertex v such that all 
other vertices in G can be reached by a path from v.

Case 1:- Undirected Connected Graph : In this case, all the vertices are mother vertices as we 
can reach to all the other nodes in the graph.
Case 2:- Undirected/Directed Disconnected Graph : In this case, there is no mother vertices as 
we cannot reach to all the other nodes in the graph.
Case 3:- Directed Connected Graph : In this case, we have to find a vertex -v in the graph such 
that we can reach to all the other nodes in the graph through a directed path.

If there exist mother vertex (or vertices), then one of the mother vertices is the last finished 
vertex in DFS. (Or a mother vertex has the maximum finish time in DFS traversal).

A vertex is said to be finished in DFS if a recursive call for its DFS is over, i.e., 
all descendants of the vertex have been visited.

How does the above idea work?
Let the last finished vertex be v. Basically, we need to prove that there cannot be an edge from 
another vertex u to v if u is not another mother vertex 
(Or there cannot exist a non-mother vertex u such that u-→v is an edge). There can be two possibilities.

Recursive DFS call is made for u before v. If an edge u-→v exists, then v must have finished before u
because v is reachable through u and a vertex finishes after all its descendants.
Recursive DFS call is made for v before u. In this case also, if an edge u-→v exists,
then either v must finish before u (which contradicts our assumption that v is finished at the end)
 OR u should be reachable from v (which means u is another mother vertex).*/

int findMother() {

	vector<int> vis(N, 0);

	int v = 0; // the last visited node

	for (int i = 0; i < N; ++i) 
		if (!vis[i]) dfs(i, vis), v = i;

	vis.assign(N, 0);

	dfs(v, vis);

	if (find(vis.begin(), vis.end(), 0) != vis.end()) return -1;

	return v;
}