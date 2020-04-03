/*The second largest element is second last element in inorder traversal and second element in reverse inorder traversal. 
We traverse given Binary Search Tree in reverse inorder and keep track of counts of nodes visited. Once the count becomes 2, we print the node.*/

void secondLargest(Node *root, int &c) {
	if(root == NULL or c >= 2) return;

	secondLargest(root->right, c);

	c++;

	if(c == 2) {
		cout << root->data << endl;
		return;
	}

	secondLargest(root->left, c);
}