/*Largest Independent Set Problem
Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.
For example, consider the following binary tree. The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.

IDEA: let f(n) = the largest independent set such for the subtree rooted at node n
so f(n) = max(
			1 + f(grand children of n) // if n is not included in the set
			f(children of n) // if n is included in the set
		)
*/

int solve(Node *root) {
	if (!root) return 0;

	int exc = solve(root->left) + solve(root->right);

	int inc = 1;
	if (root->left) inc += solve(root->left->left) + solve(root->left->right);
	if (root->right) inc += solve(root->right->left) + solve(root->right->right);

	return max(inc, exc);
}