/*The Ruler of HackerLand believes that every citizen of the country should have access to a library. Unfortunately, 
HackerLand was hit by a tornado that destroyed all of its libraries and obstructed its roads! As you are the greatest 
programmer of HackerLand, the ruler wants your help to repair the roads and build some new libraries efficiently.

HackerLand has n cities numbered from 1 to n. The cities are connected by m bidirectional roads. A citizen has access 
to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.
The following figure is a sample map of HackerLand where the dotted lines denote obstructed roads:

image

The cost of repairing any road is cr dollars, and the cost to build a library in any city is Ccl dollars.

You are given q queries, where each query consists of a map of HackerLand and value of cl and cr.

For each query, find the minimum cost of making libraries accessible to all the citizens and print it on a new line.

Input Format

The first line contains a single integer, q, denoting the number of queries. The subsequent lines describe each query in the 
following format:

The first line contains four space-separated integers describing the respective values of  n(the number of cities),  
m(the number of roads),  cl(the cost to build a library), and  cr(the cost to repair a road).
Each line  of the  subsequent lines contains two space-separated integers, u and v, describing a bidirectional road 
connecting cities u and v.*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 1e5 + 5;

typedef long long ll;

int n, m, cr, cl;
vector<int> V, G[maxn];
ll cost1 = 0, cost2 = 0;

void init() {
    V.assign(n+1, 0);
    for(int i = 0; i < maxn; ++i) G[i].clear();
}

void dfs(int u, int &cnt) {
    cnt++;
    V[u] = 1;
    for(int v: G[u]) if(!V[v]) dfs(v, cnt);
}

int main() {
    int q; cin >> q;
    
    int u, v;
    
    while(q--) {
        cin >> n >> m >> cl >> cr;
        
        init();
        
        for(int i = 0; i < m; ++i) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        ll ans = 0;
        
        for(int i = 1; i <= n; ++i) {
            if(!V[i]) {
                int cnt = 0;
                cost1 = 0, cost2 = 0;
                cost1 += (ll)cl;
                
                dfs(i, cnt);
                
                cost1 += ((cnt - 1) * cr);
                cost2 += (cnt * cl);
                
                ans += min(cost1, cost2);
            }
        }
        
        cout << ans << endl;
    }
}