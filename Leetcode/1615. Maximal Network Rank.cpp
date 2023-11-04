/*There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.

The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.

Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

IDEA: for any pair of nodes, find the sum of the edges connected to them, also an edge should
be counted only once.
*/
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_set<int> g[n+1];
        for (auto e: roads) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sub = 0;
                if (g[i].size() and g[i].count(j)) sub = 1;
                ans = max(ans, (int)g[i].size() + (int)g[j].size() - sub);
            }
        }
        return ans;
    }
};