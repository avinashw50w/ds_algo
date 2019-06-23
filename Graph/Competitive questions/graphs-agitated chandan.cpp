#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int maxn = 100000+1;
int vis[maxn];
vector<pii> g[maxn];

int bfs(int s) {
	queue<pii> q;
	q.push(make_pair(s,0));

	int sum = 0;
	while(!q.empty()) {
		pii it = q.front(); q.pop();
		int u = it.first;
		int w = it.second;

		if (vis[u]) continue;
		vis[u] = 1;

		sum += w;

		for(auto i: g[u]) {
			if(!vis[i.first]) {
				
				q.push(make_pair(i.first, i.second)); 
			}
		}
	}
	return sum;
}


int main() {
	int t; cin>>t;
	while(t--) {
		int n, u, v, w;

		cin>>n;

		for(int i=0;i<n;++i) {
			cin>>u>>v>>w;
			g[u].push_back(make_pair(v, w));
			g[v].push_back(make_pair(u, w));
		}
		int ans = 0, sum, cost = 0;
		for(int i=0;i<n;++i){
			memset(vis, 0, sizeof(vis));
			sum = bfs(i);
			ans = max(ans, sum);
		}
			if(ans < 100) cost = 0;
			else if( ans > 100 && ans < 1000 ) cost = 100;
			else if( ans > 1000 && ans < 10000 ) cost = 1000;
			else cost = 10000;
			

		cout << cost << " " << ans << endl;


	}
	
}