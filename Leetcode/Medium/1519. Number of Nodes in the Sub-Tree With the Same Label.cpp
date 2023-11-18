/*You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes
numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of 
the tree has a label which is a lower-case character given in the string labels (i.e. The node with the 
number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai 
and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have 
the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.*/
class Solution {
    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> cnt;
    string l;
public:

    void dfs(int u = 0, int p = -1) {
        // store label cnt before entering the subtree u
        int lc = cnt[l[u] - 'a']++;
        for (int v: adj[u]) {
            if (v != p) dfs(v, u);
        }
        // subtract the label count of outer tree
        ans[u] = cnt[l[u] - 'a'] - lc;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        l = labels;
        ans.resize(n, 0);
        cnt.resize(26, 0);
        adj = vector<vector<int>>(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs();
        return ans;
    }
};