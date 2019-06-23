/*Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

Output:
Print the answer to each test case in a new line.

Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 104
1 ≤ M ≤ 105
1 ≤ X, Y ≤ N

SAMPLE INPUT 
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT 
2
2 */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)

const int maxn = 1e4+2;
const int oo = 1e9;
int N, M;
vector<int> G[maxn];
int vis[maxn], dist[maxn];

int main() {
    int T; cin >> T;
    
    while(T--) {
        rep(i,0,maxn) G[i].clear();
        memset(vis, 0, sizeof(vis));
        fill(dist, dist+maxn, oo);
        cin >> N >> M;
        int X, Y;
        
        while(M--) {
            cin >> X >> Y;
            G[X].push_back(Y);
            G[Y].push_back(X);
        }
    
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            
            if(vis[u]) continue;
            vis[u] = 1;
            
            for(int v: G[u]) {
                if(!vis[v]) q.push(v), dist[v] = min(dist[v], dist[u] + 1);    
            }
        }
        
        cout << dist[N] << endl;
    }
}

/////////////////////////////////////////////
// simple one

int dist[maxn], vis[maxn];

void dfs(int u) {
    vis[u] = 1;
    for (auto v: G[u]) {
        if (!vis[v]) {
            dist[v] = dist[u] + 1;
            dfs(v);
        }
    }
}

int solve() {
    dfs(1);
    return dist[N];
}