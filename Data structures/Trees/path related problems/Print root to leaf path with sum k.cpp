/*Root to leaf path sum equal to a given number k
Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding up all
the values along the path equals the given number k. Return false if no such path can be found.*/

bool printPath(Node *root, int sum, vector<int> path) {
	if (!root) return (sum == 0);

	path.push_back(root->data);

	if (sum == root->data and (!root->left and !root->right)) {
		print(path);
		return 1;
	}

	bool ans = 0;

	if (root->left) ans |= printPath(root->left, sum - root->data, path);

	if (root->right) ans |= printPath(root->right, sum - root->data, path);

	path.pop_back();

	return ans;
}


////////////////////////////////////////////////////////////////////////

void solve(node *root, int K, int sum, vector<int>path, vector<vector<int>> &res) {
	if (!root) return;

	sum += root->data;
	path.push_back(root->data);

	if (!root->left and !root->right and sum == K) {
		res.push_back(path);
	}

	solve(root->left, k, sum, path, res);
	solve(root->right, k, sum, path, res);

	path.pop_back();
}

int hasPathSum(node *root, int K) {
	vector<int> path;
	vector<vector<int>> res;
	solve(root, K, 0, path, res);

	if (res.size()) {
		for (auto i : res) {
			for (int j : i) cout << j << " ";
			cout << endl;
		}

		return true;
	}
	return false;
}