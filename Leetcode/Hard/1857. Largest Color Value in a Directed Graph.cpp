/* https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the 
ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] 
indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a 
directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes 
that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
*/
// using dfs
class Solution {
    vector<vector<int>> adj, cnt;
    vector<int> vis;
    string cl;
    bool hasCycle = false;
    int ans = 0;
public:

    void dfs(int u) {
        vis[u] = 1;
        for (int v: adj[u]) {
            if (vis[v] == 1) hasCycle = true;
            else if (vis[v] == 0) dfs(v);
            
            for (int i=0; i<26; ++i) {
                cnt[u][i] = max(cnt[u][i], cnt[v][i]);
            }
        }

        vis[u] = 2;

        cnt[u][cl[u]-'a']++;
        ans = max(ans, cnt[u][cl[u]-'a']);
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        cl = colors;
        adj = vector<vector<int>>(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
        }

        vis.assign(n, 0);
        cnt = vector<vector<int>>(n, vector<int>(26, 0));
        
        for (int i=0; i<n; ++i) {
            if (vis[i] == 0) dfs(i);
        }
        return hasCycle ? -1 : ans;
    }
};

// using kahn's algo
class Solution {   
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
            cnt[i][colors[i]-'a']++;
        }

        int ans = 0, vis = 0;
        
        while (!q.empty()) {
            vis++;
            int u = q.front(); q.pop();
            for (int v: adj[u]) {
                for (int i = 0; i<26; ++i) {
                    int inc = i == colors[v] - 'a';
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + inc);
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }

            ans = max(ans, cnt[u][colors[u]-'a']);
        }

        return vis == n ? ans : -1;
    }
};