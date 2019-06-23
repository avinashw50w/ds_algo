#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
const int inf = 1000000000;
int n, m;
vi *g;
vi vis;
vi dist;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis.assign(n+1,0);
    dist.assign(n+1,inf);
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
       
        vis[u] = 1;
        for(auto i: g[u]) {
            if(!vis[i]) {
                if(dist[u] != inf and dist[i] > dist[u] + 1) {
                    dist[i] = dist[u] + 1;
                    q.push(i);
                }
            }
        }
    }
    
    for(int i=1; i<=n; ++i) {
        if(i != s) 
            cout << ((dist[i] == inf)? -1 : 6*dist[i])<<" ";
    }
    cout << endl;
}

int main() {
    int t, u, v; cin>>t;
    while(t--) { 
        cin>>n>>m;
        g = new vi[n+1];
        for(int i=0; i<m; ++i) {
            cin>> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int s; cin>>s;
        bfs(s);
    }
}
