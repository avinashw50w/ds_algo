//  only for directed graphs

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
 
#define MAX 100001
#define INF (1<<20)
#define pii pair< int, int >
#define pb(x) push_back(x)
 
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};
 
priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int D[MAX];
bool visited[MAX];
 
int main() {
    int i, u, v, w, sz, nodes, edges, starting;
 
    // create graph
    scanf("%d %d", &nodes, &edges);
    for(i=0; i<edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].pb(pii(v, w));
        G[v].pb(pii(u, w)); // for undirected
    }
    scanf("%d", &starting);
 
    // initialize distance vector
    for(i=1; i<=nodes; i++) D[i] = INF;
    D[starting] = 0;
    Q.push(pii(starting, 0));
 
    // dijkstra
    while(!Q.empty()) {
        u = Q.top().first;
        Q.pop();
        if(visited[u]) continue;
        sz = G[u].size();
        for(i=0; i<sz; i++) {
            v = G[u][i].first;
            w = G[u][i].second;
            if(!visited[v] && D[u]+w < D[v]) {
                D[v] = D[u] + w;
                Q.push(pii(v, D[v]));
            }
        }
        visited[u] = 1; // done with u
    }
 
    // result
    for(i=1; i<=nodes; i++) printf("Node %d, min weight = %d\n", i, D[i]);
    return 0;
}
