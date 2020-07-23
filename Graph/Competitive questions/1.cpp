/*check for each node whether it lies on the shortest path from src to desc*/

vector<int> Dijkstra(vector<vector<int>> G, int N, int source) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    vector<int> Dist(N, INF);
    Dist[source] = 0;
    Q.push({0, source});

    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        for (auto &c : G[u]) {
            int v = c.first;
            int w = c.second;
            if (Dist[v] > Dist[u] + w) {
                Dist[v] = Dist[u] + w;
                Q.push({Dist[v], v});
            }
        }
    }

    return Dist;
}

vector<string> classifyEdges(int N, vector<int> U, vector<int> V, vector<int> W) {

    vector<pair<int, int>> G[N];
    int M = V.size();
    for (int i = 0; i < M; ++i) {
        G[U[i] - 1].push_back({V[i] - 1, W[i]});
        G[V[i] - 1].push_back({U[i] - 1, W[i]});
    }
    for (auto i : G) {
        for (auto j : G[i]) cout << j.first << " ";
        cout << endl;
    }

    vector<int> dist1 = Dijkstra(G, N, 0);
    vector<int> dist2 = Dijkstra(G, N, N - 1);


    vector<string> ans(N);
    ans[0] = ans[N - 1] = "YES";
    for (int i = 1; i < N - 1; ++i) {
        if (dist1[i] + dist2[i] == dist1[N - 1]) ans[i] = "YES";
        else ans[i] = "NO";
    }

    return ans;
}