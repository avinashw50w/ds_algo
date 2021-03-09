/*Longest consecutive sequence in Binary tree
Given a Binary Tree find the length of the longest path which comprises of nodes with
consecutive values in increasing order. Every node is considered as a path of length 1.*/

void solve(Node *root, int len, int required, int &ans) {
	if (!root) return;

	if (root->data == required) len++;
	else len = 1;

	ans = max(ans, len);

	solve(root->left, len, root->data + 1, ans);
	solve(root->right, len, root->data + 1, ans);
}

int LCS(Node *root) {
	int ans = 0;
	solve(root, 0, root->data, ans);
	return ans;
}