

void check(node *root1, node *root2) {
	if (!root1 and !root2) return true;

	if (!root1 or !root2) return false;

	return (root1->val == root2->val
	        and
	        check(root1->left, root2->right)
	        and
	        check(root1->right, root2->left))

}