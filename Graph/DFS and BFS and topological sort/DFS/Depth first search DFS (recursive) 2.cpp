#include <bits/stdc++.h>
using namespace std;

class Graph{
	int N;
	vector<int> *G;
	int *vis;
public:
	Graph(int N) {
		this->N = N;
		vis = new int[N]();
		G = new vector<int>[N];
	}

	void addEdge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}

	void dfs(int u) {
		vis[u] = 1;
		cout << u << " ";
		for (auto v: G[u]) {
			if (!vis[v]) dfs(v);
		}
	}
};

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.dfs(2);
 
    return 0;
}
/*
Output:

Following is Depth First Traversal (starting from vertex 2)
2 0 1 3
*/
