/* https://leetcode.com/problems/cheapest-flights-within-k-stops/
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
*/

const int maxn = 111;
const int INF = 1e9;
class Solution {
public:
	vector<pair<int, int>> G[maxn];
	int vis[maxn];

	void dfs(int src, int dest, int totalCost, int K, int &ans) {
		if (K < -1) return;
		if (src == dest) {
			ans = min(ans, totalCost);
			return;
		}

		vis[src] = 1;

		for (auto e : G[src]) {
			int v = e.first;
			int w = e.second;
			if (!vis[v] and totalCost + w <= ans) {
				dfs(v, dest, totalCost + w, K - 1, ans);
			}
		}

		vis[src] = 0;
	}

	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int K) {
		int m = flights.size();

		for (auto e : flights) {
			G[e[0]].push_back({e[1], e[2]});
		}

		int ans = INF;
		dfs(src, dest, 0, K, ans);

		return ans == INF ? -1 : ans;
	}
};