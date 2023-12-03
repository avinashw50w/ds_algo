/*Chandan is a horrendous murderer and he wants to kill Arjit just because he's lazy. Chandan is following the trail of Arjit's 
shoes. The trail is in the form of a k-ary tree. Arjit is lazy, sure, but he's smart. Initially, Arjit and Chandan are standing 
together, but Arjit magically moves away from Chandan as far as he can go.

Chandan doesn't know the way out, but he knows that Arjit has managed to travel the maximum distance he can. 
Help Chandan find out the maximum distance he would have to travel to find Arjit. And also tell him 
how much will he have to pay to travel so far. The travel rates are:

If maximum distance is <100, cost = 0.
If maximum distance is > 100, cost = 100.
If maximum distance is > 1000, cost = 1000.
If maximum distance is > 10000, cost = 10000.
Input format:
First line contains the total number of test cases. Then, the next line contains the number of nodes. 
The the next n-1 lines contain three integers - the first two denote an edge between a and b, 
the third integer denotes the weight of that edge.

Output format:
You've to print the money Chandan will pay and the maximum distance he will have to travel.

Constraints:
1 <= Test Cases <= 10
2 <= n <= 100000
1 <= a, b <= n
1 <= weight <= 100

SAMPLE INPUT 
1
5
1 2 4
3 2 3
2 5 2
4 1 1
SAMPLE OUTPUT 
0 8  */

/*Algo :    
Step 1: select a random node A  
Step 2: run bfs/dfs from A and find the farthest node say S  
Step 3: run bfs/dfs from S and find the farthest node say D  
Step 4: d(S, D) is the diameter of the tree*/

/*Here dist array also serves as vis array*/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
const int maxn = 1e5+5;

int dist[maxn];
vector<pair<int,int>> G[maxn];

void dfs(int u) {
	
	for(auto i: G[u]) {
		int next = i.first;
		int w = i.second;
		
		if(dist[next] == -1) {
			dist[next] = dist[u] + w;
			dfs(next);
		}
	}
}

int main() {
	int t; cin >> t;
	int N;
	
	while(t--) {
		cin >> N;
		rep(i,0,maxn) G[i].clear();
		
		rep(i,0,N-1) {
			int x, y, w;
			cin >> x >> y >> w;
			G[x].push_back({y, w});
			G[y].push_back({x, w});
		}
		
		memset(dist, -1, sizeof(dist));
		
		int start;
		
		rep(i, 0, N+1) {
			if(G[i].size()) {
				start = i;
				break;
			}
		}
		
		dist[start] = 0;
		
		dfs(start); 
		
		int maxx = INT_MIN, interm;
		rep(i, 0, N+1) {
			if(dist[i] > maxx) maxx = dist[i], interm = i; 
		}
		
		memset(dist, -1, sizeof(dist));
		
		dist[interm] = 0;
		dfs(interm);
		
		int ans = *max_element(dist, dist+N+1);
		int cost = 0;
		
		if(ans < 100) {
			cost = 0;
		} else if(100 <= ans and ans <= 1000) {
			cost = 100;
		} else if(1000 < ans and ans <= 10000) {
			cost = 1000;
		} else {
			cost = 10000;
		}
		
		cout << cost << " " << ans << endl;
	}
}