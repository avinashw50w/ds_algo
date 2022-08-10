
// it is just like doing inorder traversal //

void printRange(node *root, int k1, int k2)
{
	if(root == NULL) return;

	if(k1 > root->data) printRange(root->right, k1, k2);

	if(k1 <= root->data and root->data <= k2) cout << root->data;

	if(k2 < root->data) printRange(root->left, k1, k2);
}