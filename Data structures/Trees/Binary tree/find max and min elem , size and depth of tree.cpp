int findMin(node* root){        // find the min element in the tree
	if(root==NULL) return -1;
	node* curr=root;
	while(curr->left!=NULL) curr=curr->left;
	return curr->data;
}

int findMax(node* root){
	if(root==NULL) return -1;
	node* curr=root;
	while(curr->right!=NULL) curr=curr->right;
	return curr->data;
}

// finding size of a tree.  Size of a tree is the number of elements present in the tree. 
int size(node* root){
	if(root==NULL) return 0;
	else return size(root->left) + 1 + size(root->right);
}

int maxDepth(node* root){
	if(root==NULL) return 0;
	return max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

int leafNodes(node *root){
	if(root==NULL) return 0;
	if(root->left==NULL && root->right==NULL) return 1;
	return leafNode(root->left) + leafNodes(root->right);
}
