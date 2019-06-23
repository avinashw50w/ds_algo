/*You are given a rooted tree with N nodes. The nodes are numbered from 1 to N, and the root is the node numbered 1. For each node X which is not a leaf, 
you must choose a node Y which is a child of X and mark the edge between X and Y as heavy (red in the picture below).

Once this has been done, we calculate the cost of each path from the root to a leaf. For this, we decompose the path into segments, where each segment has 
all light edges or all heavy edges, and each segment is maximal (ie. each segment is as long as possible). So, a path will start with a heavy segment or a 
light segment, but the segment types will alternate between heavy and light.

The length of a segment is the number of edges in it. The cost of a light segment with length L is L, and the cost of a heavy segment with length L is 
(ceiling[log2L]+1). The cost of a path from the root to a leaf will be the sum of costs of all the segments.

The decomposition into segments is done independently for each path.

For example:


The path 1 → 9 contains one heavy segment (1 → 2) with length 1 and one light segment (2 → 9) with length 2, so the cost is 
(ceiling[log21]+1) + 2 = (0 + 1) + 2 = 3.
The path 1 → 17 contains one light segment (1 → 3) with length 1 and one segment (3 → 17) with length 5, so the cost is 
1 + (ceiling[log25]+1) = 1 + (3 + 1) = 5.
The path 1 → 15 has cost 1 + (ceiling[log22]+1) + 1 = 1 + (1 + 1) + 1 = 4.
Consider all the paths from the root to leaves. The maximum cost among all these paths, is defined to be the 'cost' of the tree. 
Different ways of choosing heavy edges can lead to different ‘costs' of the tree.

Please find the minimum ‘cost' of the tree achievable.

Input
The first line contains one integer, T, the number of test cases. The description of each test case follows:
The first line of each test case contains one integer, N.
N-1 lines follow, each of which contains two integers a, b. This signifies that there is an edge between nodes a and b.
Output
The output should have only one integer in a new line, the minimum 'cost' achievable.

Constraints
1 ≤ T ≤ 10
2 ≤ N ≤ 105*/

#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100005;
 
int n;
int dp[N], pd[N][25];
vector <int> g[N];
 
int fx(int at, int par);
int gx(int at, int mx, int par);
 
int fx(int at, int par){
	if(dp[at] != -1) return dp[at];
	int ret = n, mx = -1, cnt = 0, ptr;
	for(auto u : g[at]){
		if(u == par) continue;
		if(fx(u, at) > mx) mx = fx(u, at), cnt = 1, ptr = u;
		else if(fx(u, at) == mx) ++cnt;
	}
	ret = mx + 1;
	if(cnt == 1 && gx(ptr, mx, at)) ret = mx;
	return dp[at] = ret;
}
 
int get(int val){
	if(val == 0) return 0;
	val = min(val - 1, 20);
	return 1 << val;
}
 
int gx(int at, int mx, int par){
	int id = mx - fx(at, par);
	if(id >= 20) return (1 << 20);
	if(pd[at][id] != -1) return pd[at][id];
	int ret = 0, xx = -1, cnt = 0, ptr;
	for(auto u : g[at]){
		if(u == par) continue;
		if(fx(u, at) > xx) xx = fx(u, at), ptr = u;
		++cnt;
	}
	if(cnt == 0) ret = get(mx);
	else{
		ret = gx(ptr, mx, at) - 1;
		for(auto u : g[at]){
			if(u == par || u == ptr) continue;
			int df = mx - (fx(u, at) + 1);
			ret = min(ret, get(df));
		}
	}
	return pd[at][id] = max(ret, 0);
}
 
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int u, v;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i) g[i].clear();
		for(int i = 2; i <= n; ++i){
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		memset(dp, -1, sizeof(dp));
		memset(pd, -1, sizeof(pd));
		printf("%d\n", fx(1, 0));
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 100005,maxm = 18;
 
vector<int> go[maxn];
int f[maxn][maxm],g[maxn],n;
 
void link(int u,int v)
{
	go[u].push_back(v);
}
 
void dfs(int now,int pre)
{
	int mx = -(1 << 30),elmx = -(1 << 30),hv = 0;
	for(auto p : go[now])
		if (p != pre)
		{
			dfs(p,now);
			if (g[p] > mx) elmx = mx,mx = g[p],hv = p; else
				if (g[p] > elmx) elmx = g[p];
		}
	if (mx < 0)
	{
		g[now] = 0;
		f[now][0] = 0;
		for(int i = 1;i < 18;i ++) f[now][i] = (1 << (i - 1));
	} else
	{
		++ elmx;
		if (f[hv][0]) g[now] = mx; else g[now] = mx + 1;
		g[now] = max(g[now],elmx);
		for(int i = 0;i < 18;i ++)
		{
			int v = g[now] + i;
			if (v <= elmx) f[now][i] = 0; else f[now][i] = (1 << min(20,v - elmx - 1));
			if (v - g[hv] < 18) f[now][i] = max(0,min(f[now][i],f[hv][v - g[hv]] - 1));
		}
	}
}
 
void work()
{
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) go[i].clear();
	for(int i = 1,u,v;i < n;i ++)
	{
		scanf("%d%d", &u, &v);
		link(u,v),link(v,u);
	}	
	dfs(1,0);
	printf("%d\n", g[1]);
}
 
int main()
{
	int t;
	scanf("%d", &t);
	for(;t;t --) work();
	return 0;
}
 