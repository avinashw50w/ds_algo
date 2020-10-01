/*Find all the centroids in a tree.
A centroid is the vertex, on removal of which divides the tree into components and each component
has number of nodes <= n/2
There can be atmost 2 centroids in a tree, and if there are 2 centroids then there is
an edge connecting the two centroids
*/

const int maxn = 1e5;
vector<int> centroids, G[maxn];
int sub[maxn]; // sub[i]: no of nodes in the subtree rooted at i
int N; // total nodes

void dfs(int u, int p = -1) {
	sub[u] = 1;
	bool is_centroid = true;
	for (int v : G[u]) {
		if (v != p) {
			dfs(v, u);
			sub[u] += sub[v];
			if (sub[v] > N / 2) is_centroid = false;
		}
	}
	if (N - sub[u] > N / 2) is_centroid = false;
	if (is_centroid) centroids.push_back(u);
}