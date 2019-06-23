//  Graph Edges Property Check via DFS Spanning Tree  //

void graphCheck(int u) { // DFS for checking graph edge properties...
dfs_num[u] = DFS_GRAY; // color this as GRAY (temporary)
TRvii (AdjList[u], v) { // traverse this AdjList
if (dfs_num[v->first] == DFS_WHITE) { // GRAY to WHITE
// printf(" Tree Edge (%d, %d)\n", u, v->first);
dfs_parent[v->first] = u; // parent of this children is me
graphCheck(v->first);
}
else if (dfs_num[v->first] == DFS_GRAY) { // GRAY to GRAY
if (v->first == dfs_parent[u])
printf(" Bidirectional (%d, %d) - (%d, %d)\n", u, v->first, v->first, u);
else
printf(" Back Edge (%d, %d) (Cycle)\n", u, v->first);
}
else if (dfs_num[v->first] == DFS_BLACK) // GRAY to BLACK
printf(" Forward/Cross Edge (%d, %d)\n", u, v->first);
}
dfs_num[u] = DFS_BLACK; // now color this as BLACK (DONE)
}


/* Running DFS on a connected component of a graph will form a DFS spanning tree (or spanning
forest if the graph has more than one component and DFS is run on each component). With one
more vertex state: DFS_GRAY = 2 (visited but not yet completed) on top of DFS_WHITE (unvisited)
and DFS_BLACK (visited and completed), we can use this DFS spanning tree (or forest) to classify
graph edges into four types:
1. Tree edges: those traversed by DFS, i.e. from vertex with DFS_GRAY to vertex with DFS_WHITE.
2. Back edges: part of cycle, i.e. from vertex with DFS_GRAY to vertex with DFS_GRAY too.
Note that usually we do not count bi-directional edges as having ‘cycle’
(We need to remember dfs_parent to distinguish this, see the code below).
3. Forward/Cross edges from vertex with DFS_GRAY to vertex with DFS_BLACK.
These two type of edges are not typically used in programming contest problem.  */