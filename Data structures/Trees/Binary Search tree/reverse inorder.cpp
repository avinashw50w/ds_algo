/* reverse iorder of a BST traverses the nodes in descending order */

void reverse_inorder(node *root) {
	if(root == NULL) return;

	reverse_inorder(root->right);

	cout << root->data << " ";

	reverse_inorder(root->left);
}

/* This can also be used to find the kth largest element in a BST */
/*Time complexity: The code first traverses down to the rightmost node which takes O(h) time, 
then traverses k elements in O(k) time. Therefore overall time complexity is O(h + k).*/

int cnt = 0;
void reverse_inorder(node *root, int k) {
	if(root == NULL) return;

	reverse_inorder(root->right);

	cnt++;

	if(cnt == k) {
		cout << root->data << " ";
		return;
	}

	reverse_inorder(root->left);
}