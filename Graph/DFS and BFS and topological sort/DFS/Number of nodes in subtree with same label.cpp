/*Given an tree, where each node has value btw [1, n] and a lable btw [a,z].
Return an array ans of size n where ans[i] is the # of nodes in the subtree i which has the same label
as i.
*/

vector<int> ans;
vector<int> cnt;

void dfs(string labels, int u = 0, int p = -1) {
    // store label cnt before entering the subtree u
    labelCnt = cnt[lables[u] - 'a']++;
    for (int v: adj[u]) {
        if (v != p)
            dfs(labels, v, u);
    }
    // ans for subtree u = current label cnt - the label count before entering the subtree u
    ans[u] = cnt[label[u] - 'a'] - labelCnt;
}

vector<int> solve(vector<vector<int>> tree, string labels) {
    // create adjacency list
    int n = tree.size();
    vector<vector<int>> adj(n);
    ans.resize(n, 0);
    cnt.resize(26, 0);

    for (auto e: tree) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(labels);
    return ans;
}