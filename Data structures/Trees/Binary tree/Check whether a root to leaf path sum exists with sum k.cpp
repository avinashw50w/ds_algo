/*Check whether any root to leaf path exists which sums to k. */

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