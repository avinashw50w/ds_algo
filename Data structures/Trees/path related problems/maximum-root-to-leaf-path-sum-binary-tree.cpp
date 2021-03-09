
int maxSum(Node *root) {
	if (root == NULL) return 0;

	int max_sum = INT_MIN;
	Node *target_leaf;

	getTargetLeaf(root, max_sum, 0, &target_leaf);

	printPath(root, target_leaf);
}

void getTargetLeaf(Node *root, int &maxsum, int sum, Node *&target_leaf) {
	if (root == NULL) return;

	sum += root->data;

	if (!root->left and !root->right) {
		if (sum > maxsum) {
			maxsum = sum;
			target_leaf = root;
		}
	}

	getTargetLeaf(root->left, maxsum, sum, target_leaf);
	getTargetLeaf(root->right, maxsum, sum, target_leaf);
}

bool printPath(Node *root, Node *target_leaf) {
	if (!root) return false;

	if (root == target_leaf or printPath(root->left, target_leaf) or printPath(root->right, target_leaf)) {

		cout << root->data << " ";
		return true;
	}

	return false;
}