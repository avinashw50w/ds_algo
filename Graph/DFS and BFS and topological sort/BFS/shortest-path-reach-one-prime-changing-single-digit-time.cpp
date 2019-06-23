/*Shortest path to reach one prime to other by changing single digit at a time
Given two four digit prime numbers, suppose 1033 and 8179, we need to find the shortest path 
from 1033 to 8179 by altering only single digit at a time such that every number that we get 
after changing a digit is prime. For example a solution is 1033, 1733, 3733, 3739, 3779, 8779, 8179

Examples:

Input : 1033 8179
Output :6*/

// Use BFS

class Graph {

	vector<int> *G;
	vector<int> dist;
	vector<int> primes;
	int N;

public:
	Graph(int N) {
		this->N = N;
		G = new vector<int> [N];
		dist.assign(N, -1);
	}

	void seive() {
		int i, j;
		vector<int> p(10000, 1);

		for (int i = 2; i*i <= 9999; ++i) {
			if (p[i]) {
				for (int j = i*i; j <= 9999; j += i) p[j] = 0;
			}
		}

		for (int i = 1000; i <= 9999; ++i)
			if (p[i]) primes.push_back(i);
	}

	void addEdge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int bfs(int p1, int p2) {
		queue<int> Q;
		Q.push(p1);
		dist[p1] = 0;

		while (!Q.empty()) {
			int top = Q.front();

			for (int v: G[top]) {
				if (dist[v] == -1) {
					dist[v] = dist[top] + 1;
					Q.push(v);
				}

				if (v == p2) return dist[v];
			}
		}

		return -1;
	}

	int solve(int p1, int p2) {
		int m = primes.size();
		for (int i = 0; i < m-1; ++i)
			for (int j = i+1; j < m; ++j)
				if (isAdjacent(primes[i], primes[j]))
					addEdge(primes[i], primes[j]);

		int dist = bfs(p1, p2);

		return dist;
	}
};