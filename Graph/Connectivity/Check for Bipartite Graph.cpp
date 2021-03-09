/* A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects
 a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to
 V and v to U. We can also say that there is no edge that connects vertices of same set.
  bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color.
  Note that it is possible to color a cycle graph with even no of vertices using two colors.

  Algorithm to check if a graph is Bipartite:
One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.
Following is a simple algorithm to find out whether a given graph is Birpartite or not using Breadth First Search (BFS).
1.	Assign RED(1) color to the source vertex (putting into set U).
2.	Color all the neighbors with BLUE(0) color (putting into set V).
3.	Color all neighbor’s neighbor with RED color (putting into set U).
4.	This way, assign color to all vertices such that it satisfies all the constraints of m way coloring problem where m = 2.
5. While assigning colors, if we find a neighbor which is colored with same color as current vertex, then the graph cannot be colored
	with 2 vertices (or graph is not Bipartite)*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int N;
vi color;
vi *G;

// using dfs
color.assign(N, -1);

bool IsBipartite(int u) {
	color[u] = 1;
	for (int v : G[u]) {
		if (color[v] == -1) {
			color[v] = !color[u];
			return isBipartite(v);
		}
		else if (color[v] == color[u]) return false;
	}

	return true;
}

// using bfs
bool IsBipartite(int s) {
	Color.assign(N, -1);
	queue<int> Q;
	Color[s] = 1;
	Q.push(s);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (auto i : G[u]) {
			if (Color[i] == -1) {
				Color[i] = !Color[u];
				Q.push(i);
			}
			else if (Color[i] == Color[u])
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N;
	G = new vi[N + 1];

}
