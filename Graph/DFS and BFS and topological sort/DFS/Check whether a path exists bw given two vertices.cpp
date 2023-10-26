/* Find if there is a path between two vertices in a directed graph */

/* Simply use DFS or BFS. While traversing the graph if the desired vertex is encountered then return true. */

bool dfs(int i) {
	if(i == dest) return true;
	if(!V[i]){
		V[i] = true;
		for_each(G[i].begin(), G[i].end(), dfs);
	}
	return false;
}