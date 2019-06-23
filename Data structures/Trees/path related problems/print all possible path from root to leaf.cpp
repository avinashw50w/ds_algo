void print(int a[], int n){
	for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;
}

void printPaths(node* root, int path[], int idx){
	if(root == NULL) return;
	path[idx++] = root->data;
	//  here we do pre Order traversal because we first want to 
	//print the parent and then print its left and right child
	if(root->left == NULL && root->right == NULL) { 
	    print(path, idx);
    }
	else{
		printPaths(root->left, path, idx);
		printPaths(root->right, path, idx);
	}
}
