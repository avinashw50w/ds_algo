// count all possible paths from source to destination in a DIRECTED graph.
int paths = 0;

void count(int src, int dest) {
    if (src == dest) paths++;
    else {
        for (auto v : G[src]) {
            count(v, dest);
        }
    }
}

// for undirected graph
vector<int> vis(maxn);
int paths = 0;
void dfs(int u, int dest) {
    vis[u] = 1;
    paths += u == dest;
    for (auto v : G[u]) {
        if (!vis[v]) dfs(v, dest);
    }
    // backtrack
    vis[u] = 0;
}