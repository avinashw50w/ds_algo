/*get all the nodes which are at a distance of K from the root. */

void solve(Node *node, int k, vector<int> &res) {
    if (!root) return;
    if (k == 0) {
        res.push_back(root->data);
        return;
    }

    solve(node->left, k - 1, res);
    solve(node->right, k - 1, res);
}

vector<int> getNodes(Node *root, int K) {
    vector<int> res;
    solve(root, K, res);
    return res;
}


/////////////////////////////////////
// for a general tree
vector<int> G[10001];

void solve(int u, int p = -1,  int K, vector<int> &res) {
    if (K == 0) {
        res.push_back(u);
    }

    for (int v : G[u]) {
        if (v == p) continue;
        solve(v, u, K - 1, res);
    }
}