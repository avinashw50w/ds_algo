// get all the nodes at a distance of K from the leaves.

void solve(Node *node, int k, vector<int> path, vector<int> &res) {
	if (!node) return;

	if (!node->left and !node->right and path.size() >= k) {
		res.push_back(path[path.size() - k]);
		return;
	}

	solve(node->left, k, path, res);
	solve(node->right, k, path, res);
}

void getNodes(Node *root, int K) {
	vector<int> res;
	vector<int> path;
	solve(root, K, path, res);
	return res;
}