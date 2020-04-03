
int maxSum(Node *root) {
	if(root == NULL) return 0;

	int max_sum = _INT_MIN;
	Node *target_leaf;

	getTargetLeaf(root, max_sum, 0, &target_leaf);

	printPath(root, target_leaf);
}

void getTargetLeaf(Node *root, int &max_sum, int curr_sum, Node **target_leaf) {
	if(root == NULL) return;

	curr_sum += root->data;

	if(!root->left and !root->right) {
		if(curr_sum > max_sum) {
			max_sum = curr_sum;
			*target_leaf = root;
		}
	}

	getTargetLeaf(root->left, max_sum, curr_sum, target_leaf);
	getTargetLeaf(root->right, max_sum, curr_sum, target_leaf)
}

bool printPath(Node *root, Node *target_leaf) {
	if(!root) return false;

	if(root == target_leaf or printPath(root->left, target_leaf) or printPath(root->right, target_leaf)) {

		cout << root->data << " ";
		return;
	}

	return false;
}