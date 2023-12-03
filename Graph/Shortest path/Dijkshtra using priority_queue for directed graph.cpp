//  only for directed graphs

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001
#define INF (1<<20)
#define arr array<int,2>
#define pb(x) push_back(x)

vector< pii > G[MAX];

int main() {
    int i, u, v, w, sz, nodes, edges, src;
    cin >> nodes >> edges;
    vector<array<int,2>> G(nodes);
    // create graph
    for(i=0; i<edges; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w}); // for undirected
    }
    cin >> src;

    // initialize distance vector
    vector<int> D(nodes, INF);
    D[starting] = 0;
    priority_queue< arr, vector<arr>, greater<arr> > Q;
    Q.push({0, src});

    // dijkstra
    while(!Q.empty()) {
        auto top = Q.top(); Q.pop();
        int u = top[1];
        for(auto e: G[u]) {
            int v = e[0];
            w = e[1];
            if(D[u]+w < D[v]) {
                D[v] = D[u] + w;
                Q.push({D[v], v});
            }
        }
    }

    // result
    for(i=1; i<=nodes; i++) printf("Node %d, min weight = %d\n", i, D[i]);
        return 0;
}
