
/* find the kth largest element in a BST */

/* get the reverse inorder */
void rev_inorder(node* root) {
	if(root) {
		rev_inorder(root->right);
		
		cnt++;
		
		if(cnt == k) {
			cout << root->data << endl;
			break;
		}
		
		rev_inorder(root->left);
	}
}

//  O(h + k) , where h is the height of the tree //
