
// using bfs
// efficient
// T: O(V+E)
vector<int> shortestPath(vector<vector<int>> adj, int src) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            if (dist[v] == -1)
                dist[v] = dist[u] + 1;
        }
    }
    return dist;
}

// using dfs
// inefficient

const int inf = 1e9;
vector<int> dist, vis;
vector<vector<int>> adj;

void dsf(int u) {
    vis[u] = 1;
    for (int v: adj[u]) {
        if (dist[u] != inf)
            dist[v] = dist[u]+1;
    }
    vis[u] = 0;
}

vector<int> shortestPath(int src) {
    int n = adj.size();
    dist.assign(n, inf);
    vis.assign(n, 0);
    dist[src] = 0;
    dfs(src);
    return dist;
}