/*Given a binary tree, such that each node contains a number. Find the maximum possible sum in going from one leaf node to another.

just a slight variation to finding the diameter of a tree*/

int solve(Node *root, int &res) {
	if (!root) return 0;
	int ls = solve(root->left, res);
	int rs = solve(root->right, res);

	res = max(res, 1 + ls + rs);

	return root->data + max(ls, rs);
}