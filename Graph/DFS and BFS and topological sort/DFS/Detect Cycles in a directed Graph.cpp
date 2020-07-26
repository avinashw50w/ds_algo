#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY  1
#define BLACK 2

vector<int> *G;     // Graph
vector<int> vis;    // visited array
/*=======================================================*/
bool IsCyclic(int u) {
    vis[u] = GREY;
    for (int v : G[u]) {
        if ((vis[v] == WHITE and IsCyclic(v)) or vis[v] == GREY) return true;
    }

    vis[u] = BLACK;
    return false;
}
/*===========================================================*/
int main() {
    int N, M, u, v;
    cin >> N >> M;          // N and M are the no of nodes and edges respectively.
    G = new vi[N + 1];
    vis.assign(N, 0);

    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
    }
    bool cycle = false;
    for (int i = 0; i < N; ++i) {
        if (vis[i] == WHITE && IsCyclic(i)) {
            cycle = true;
            break;
        }
    }

    (cycle == true) ? puts("cycle exists") : puts("No cycle exists");

    return 0;
}
