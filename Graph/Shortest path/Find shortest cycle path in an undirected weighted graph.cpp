// Using Dijkshta O(E(ElogV))
/*The idea is to use shortest path algorithm. We one by one remove every edge from graph, 
then we find shortest path between two corner vertices of it. We add an edge back before we process next edge.*/
struct Edge {
	int u;
	int v;
	int weight;
};

class Graph {
	typedef pair<int,int> pii;

	vector<pii> *G;
	vector<Edge> edges;
	int N;

public:
	Graph(int N) {
		this->N = N;
		G = new vector<pii> [N];
	}

	int shortestPath(int src, int dest) {
		vector<int> dist(maxn, INF);
		priority_queue<pii, vector<pii>, greater<pii>> Q;

		dist[src] = 0;
		Q.push({0, src});

		while(!Q.empty()) {
			auto top = Q.top(); Q.pop();
			int u = top.second;

			for (auto i: G[u]) {
				int v = i.first;
				int w = i.second;

				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					Q.push({dist[v], v});
				}
			}
		}

		return dist[dest];
	}

	int shortestCyclePathSum() {
		int ans = INT_MAX;

		for (Edge e: edges) {

			removeEdge(e);

			int dist = shortestPath(e.u, e.v);

			ans = min(ans, dist + e.weight);

			addEdge(e.u, e.v, e.weight);
		}
		
		return ans;
	}

	void addEdge(int u, int v, int w) {
		G[u].push_back({v, w});
		G[v].push_back({u, w});

		edges.push_back({u, v, w});
	}

	void removeEdge(Edge e) {
		int u = e[0], v = e[1], w = e[2];
		G[u].remove({v, w});
		G[v].remove({u, w});
	}
}



