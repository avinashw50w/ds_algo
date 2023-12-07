/*Given a rooted tree with root 0. Each node has some value. Given an array value where 
value[i] is the value of the ith node. Let mn be the minimum value of a node in a path from root to leaf.
Find the sum of all such values for all the paths from root to leaf.*/

vector<vector<int>> adj;
vector<int> values;

int dfs(int u = 0, int p = -1) {
    // if leaf then return it's value
    if (adj[u].size() == 0 and u != 0) return values[u];
    // otherwise get the sum of the min of all the paths from u to any leaf in subtree of u
    int sum = 0;
    for (int v: adj[u]) {
        if (v == p) continue;
        sum += dfs(v, u);
    }
    return min(values[u], sum);
}