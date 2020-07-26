
/*A cut edge is an edge that when removed (the vertices stay in place)
from a graph creates more components than previously in the graph.*/

const int MAXN = 1e5;
int par[MAXN], d[MAXN], l[MAXN];
int TIME = 0;


void dfs(int u) {
	d[u] = l[u] = ++TIME;

	for(int v: G[u])
	{
		if(!vis[v])
		{
			par[v] = u;
			dfs(v);

			l[u] = min(l[u], l[v]);

			if(d[u] < l[v])
				cout << u << " " << v << endl;

		}
		else if(v != par[u])
			l[u] = min(l[u], d[v]);
	}
}
