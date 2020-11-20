/*Replace each node in binary tree with the sum of its inorder predecessor and successor
Last Updated: 23-10-2019
Given a binary tree containing n nodes. The problem is to replace each node in the binary tree with the sum of its inorder predecessor and inorder successor.

Examples:

Input :          1
               /   \
              2     3
            /  \  /  \
           4   5  6   7

Output :        11
              /    \
             9      13
            / \    /  \
           2   3   4   3

For 1:
Inorder predecessor = 5
Inorder successor  = 6
Sum = 11

For 4:
Inorder predecessor = 0
(as inorder predecessor is not present)
Inorder successor  = 2
Sum = 2

For 7:
Inorder predecessor = 3
Inorder successor  = 0
(as inorder successor is not present)
Sum = 3*/

void inorder(Node *root, vector<int> &a) {
	if (!root) return;
	inorder(root->left);
	a.push_back(root->data);
	inorder(root->right);
}

void replace(Node *root, vector<int> a, int &i) {
	if (!root) return;
	replace(root->left);
	root->data = a[i - 1] + a[i + 1];
	replace(root->right);
}

void solve(Node *root) {
	vector<int> a;

	a.push_back(0);
	inorder(root, a);
	a.push_back(0);

	replace(root, a, i);
}