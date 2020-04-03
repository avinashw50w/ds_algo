/*Your code here*/
int count(Node *root) {
    if(root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

void arrayToBST(Node * root, int a[], int &i) {
	if (root == NULL) return;

	arrayToBST(root->left, a, i);
	root->data = a[i++];
	arrayToBST(root->right, a, i);
}

void getInorder(Node *root, int a[], int &i) {
	if (root == NULL) return;

	getInorder(root->left, a, i);
	a[i++] = root->data;
	getInorder(root->right, a, i);
}

Node* binaryTreeToBST(Node *root)
{
	int len = count(root);
	int *arr = new int[len];

    int i = 0;
	getInorder(root, arr, i);

	sort(arr, arr+len);

    i = 0;
	arrayToBST(root, arr, i);
	
	return root;
}
 