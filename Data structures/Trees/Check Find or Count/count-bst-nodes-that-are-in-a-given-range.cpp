/*The idea is to traverse the given binary search tree starting from root. For every node being visited, 
check if this node lies in range, if yes, then add 1 to result and recur for both of its children. 
If current node is smaller than low value of range, then recur for right child, else recur for left child.*/
int count(Node *root, int l, int r) {
	if(!root) return 0;
	// Special Optional case for improving efficiency
	if(root->data == l and root->data == r) return 1;
	// If current node is in range, then include it in count and
    // recur for left and right children of it
	if(l <= root->data and root->data <= r) 
		return 1 + count(root->left, l, r) + count(root->right, l, r);

	// If current node is smaller than low, then recur for right child
	if(root->data < l) 
		return count(root->right, l, r);
	// Else recur for left child
	else return count(root->left, l, r);
}

/*Time complexity of the above program is O(h + k) where h is height of BST and k is number of nodes in given range.*/