
struct node {
	int data;
	node *left, *right;
	bool rightThread;
}

queue<node> Q;

void inorder(node *n) {
	if(n == NULL) return;

	inorder(n->left);

	Q.push(n);

	inorder(n->right);
}

void createThreadedTree(node *root) {
	if(root == NULL) return;

	if(root->left) createThreadedTree(root->left);

	Q.pop();

	if(root->right) createThreadedTree(root->right);
	else {
		root->right = Q.front();
		root->rightThread = true;
	}
}