/*There is an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node.

You start with a score of 0. In one operation, you can:

Pick any node i.
Add values[i] to your score.
Set values[i] to 0.
A tree is healthy if the sum of values on the path from the root to any leaf node is different than zero.

Return the maximum score you can obtain after performing these operations on the tree any number of times so that it remains healthy.

IDEA: 
let totalsum be the sum of all the node values.
let sum be the sum of the minimum value node among all the paths from root to leaf.
Then ans = totalsum - sum
*/
class Solution {
    typedef long long ll;
    vector<vector<int>> adj;
    vector<int> values;
public:

    ll dfs(int u = 0, int p = -1) {
        if (adj[u].size() == 1 and u != 0) return values[u];
        ll sum = 0;
        for (int v: adj[u]) {
            if (v == p) continue;
            sum += dfs(v, u);
        }
        return min(sum, (ll)values[u]);
    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        this->values = values;
        int n = values.size();
        adj = vector<vector<int>>(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        ll totalsum = 0;
        for (int v: values) totalsum += v;

            ll minpathsum = dfs();
        return totalsum - minpathsum;
    }
};