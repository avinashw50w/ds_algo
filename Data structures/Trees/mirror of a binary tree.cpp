void Mirror(node* root){
	if(root==NULL) return;
	Mirror(root->left);
	Mirror(root->right);
	swap(root->left,root->right);
}

