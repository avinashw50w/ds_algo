/*We have discussed importance of maximum matching and Ford Fulkerson Based approach for maximal Bipartite Matching 
in previous post. Time complexity of the Ford Fulkerson based algorithm is O(V x E).

Hopcroft Karp algorithm is an improvement that runs in O(√V x E) time. Let us define few terms before we discuss the algorithm

Free Node or Vertex: Given a matching M, a node that is not part of matching is called free node. 
Initially all vertices as free (See first graph of below diagram). In second graph, u2 and v2 are free. 
In third graph, no vertex is free.

Matching and Not-Matching edges: Given a matching M, edges that are part of matching are called 
Matching edges and edges that are not part of M (or connect free nodes) are called Not-Matching edges. 
In first graph, all edges are non-matching. In second graph, (u0, v1), (u1, v0) and (u3, v3) are matching and others not-matching.



 

Alternating Paths: Given a matching M, an alternating path is a path in which the edges belong alternatively 
to the matching and not matching. All single edges paths are alternating paths. Examples of alternating 
paths in middle graph are u0-v1-u2 and u2-v1-u0-v2.

Augmenting path: Given a matching M, an augmenting path is an alternating path that starts from and ends
 on free vertices. All single edge paths that start and end with free vertices are augmenting paths. 
 In below diagram, augmenting paths are highlighted with blue color. Note that the augmenting path 
 always has one extra matching edge.

The Hopcroft Karp algorithm is based on below concept.

A matching M is not maximum if there exists an augmenting path. It is also true other way, i.e, 
a matching is maximum if no augmenting path exists

So the idea is to one by one look for augmenting paths. And add the found paths to current matching.

Hopcroft Karp Algorithm

1) Initialize Maximal Matching M as empty.
2) While there exists an Augmenting Path p
     Remove matching edges of p from M and add not-matching edges of p to M
     (This increases size of M by 1 as p starts and ends with a free vertex)
3) Return M. */

#define MAX 100001
#define NIL 0
#define INF (1<<28)

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i <= n; i++) {
        if(match[i] == 0) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[0] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=0) {
            for(i=0; i<G[u].size(); i++) {
                v = G[u][i];
                if(dist[match[v]] == INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[0]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=0) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]] == dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed 0 for all vertex in G
    while(bfs())
        for(i=1; i <= n; i++)
            if(match[i] == 0 && dfs(i))
                matching++;
    return matching;
}