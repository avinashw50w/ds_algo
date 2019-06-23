
#include <bits/stdc++.h>
using namespace std;

const int N = 6;

bool BFS(int G[N][N], int s, int t, int par[])
{
	queue<int> Q;
	Q.push(s);
	par[s] = -2;

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for(int v = 0; v < N; ++v)
		{
			if(par[v] == -1 && RG[u][v] > 0)
			{
				q.push(v);
				par[v] = u;
			}
		}
	}

	return par[t] != -1;
}

// s and t are the source and sink respectiverly
int fordFulkerson(int G[N][N], int s, int t)
{
	int maxFlow = 0;

	int par[N];

	memset(par, -1, sizeof(par));

	int RG[N][N]; // residual graph

	// residual graph will be the same as of the original graph
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			RG[i][j] = G[i][j];

	// while there exists an augmenting path betweeen s and t
	while(BFS(RG, s, t, par))
	{
		int flow = INT_MAX;

		// find the min flow in the residual graph
		for(int v = t; v != s; v = par[v])
		{
			int u = par[v];
			flow = min(flow, RG[u][v]);
		}

		// update the residual graph
		for(int v = t; v != s; v = par[v])
		{
			int u = par[v];
			RG[u][v] -= flow;
			RG[v][u] += flow;
		}

		maxFlow += flow;
	}

	return maxFlow;
}

int main()
{
	int graph[N][N] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
 
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
 
    return 0;
}