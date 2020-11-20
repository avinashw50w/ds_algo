/*
find the minimum height of a binary tree.
minimum height means the shortest path from root to any leaf
 */

void solve(Node *root, int level, int &ans) {
	if (!root) return;
	if (!root->left and !root->right) {
		ans = min(ans, level);
		return;
	}

	solve(root->left, level + 1, ans);
	solve(root->right, level + 1, ans);
}

int minimumHeight(Node *root) {
	int ans = INT_MAX;
	solve(root, 0, ans);
}