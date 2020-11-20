// get all the nodes at a distance of K from the leaves.

void solve(Node *node, int k, vector<int> path, vector<int> &res) {
	if (!node) return;

	path.push_back(node->data);

	if (!node->left and !node->right and path.size() >= k) {
		res.push_back(path[path.size() - k]);
		return;
	}

	solve(node->left, k, path, res);
	solve(node->right, k, path, res);

	path.pop_back();
}

void getNodes(Node *root, int K) {
	vector<int> res;
	vector<int> path;
	solve(root, K, path, res);
	return res;
}