
/*A cut edge is an edge that when removed (the vertices stay in place) 
from a graph creates more components than previously in the graph.*/

const int MAXN = 1e5;
int par[MAXN], d[MAXN], h[MAXN], vis[MAXN];
int TIME = 0;


void dfs(int u) {
	d[u] = h[u] = ++TIME;
	vis[u] = 1;

	for(int v: G[u])
	{
		if(!vis[v])
		{		
			par[v] = u;
			dfs(v);

			d[u] = min(d[u], d[v]);

			if(h[u] < d[v])
				cout << u << " " << v << endl;

			else if(v != par[u])
				d[u] = min(d[u], h[v]);
		}
	}
}