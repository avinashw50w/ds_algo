/*Minimum edges to reverse to make path from a source to a destination
Given a directed graph and a source node and destination node, we need to find how many edges we need to reverse in order to make at least 1 path from source node to destination node.

This problem can be solved assuming a different version of the given graph. In this version we make a reverse edge corresponding to every edge and we assign that a weight 1 and assign a weight 0 to original edge. After this modification above graph looks something like below,
img: https://cdncontribute.geeksforgeeks.org/wp-content/uploads/modifiedGraph.png

Now we can see that we have modified the graph in such a way that, if we move towards original edge, no cost is incurred, but if we move toward reverse edge 1 cost is added. So if we apply Dijkstra’s shortest path on this modified graph from given source, then that will give us minimum cost to reach from source to destination i.e. minimum edge reversal from source to destination.*/

class Graph {
    int N;
    vector<pair<int,int>> *G;

    Graph(int N) {
        this->N = N;
        G = new vector<pair<int,int>> [N];
    }

    void addEdge(int u, int v, int w) {
        G[u].push_back({v, w});
    }

    vector<int> shortestPath() {
        set<pair<int,int>> Q;
        vector<int> dist(N, INT_MAX);

        Q.insert({0, src});

        while(!Q.empty()) {
            auto top = Q.begin();
            int u = top.second;
            Q.erase(top);

            for (auto next: g[u]) {
                int v = next.first, w = next.second;

                if (dist[v] > dist[u] + w) {
                    if (Q.find({dist[v], v}) != Q.end()) 
                        Q.erase(Q.find({dist[v], v}));

                    dist[v] = dist[u] + w;
                    Q.insert({dist[v], v});
                }
            }
        }

        return dist
    }
};

 Graph modelGraphWithWeight(vector<pair<int, int>> edges) {
    int N = edges.size();
    Graph g(N);

    for (auto i: edges) {
        g.addEdge(i.first, i.second, 0);
        g.addEdge(i.second, i.first, 1);
    }

    return g;
}

int getMinEdgeReversal(vector<pair<int,int>> edges, int src, int dest) {
    int N = edges.size();

    Graph g = modelGraphWithWeight(edges);

    vector<int> dist = g.shortestPath();

    return (dist[dest] != INT_MAX ? dist[dest] : -1);
}