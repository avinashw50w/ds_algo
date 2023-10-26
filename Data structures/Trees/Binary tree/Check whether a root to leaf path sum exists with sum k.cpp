/*Check whether any root to leaf path exists which sums to k. */

bool solve(Node *root, int sum) {
	if (!root) return false;
	sum -= root->data;
	if (!root->left and !root->right) {
		return sum == 0;
	}
	return solve(root->left, sum) or solve(root->right, sum);
}

// another
bool solve(Node* root, int sum) {
	if(root == NULL) return false;

	if(!root->left and !root->right) {
		if(root->data == sum)
			return true;
		else 
			return false;
	}

	if(solve(root->left, sum - root->data))
		return true;
	if(solve(root->right, sum - root->data))
		return true;

	return false;
}