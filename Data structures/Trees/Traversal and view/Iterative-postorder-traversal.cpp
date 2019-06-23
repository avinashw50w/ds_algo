
void postorder(Node *root) {
	if(root == NULL) return;

	stack<Node*> s;

	do {

		while (root) {
			if (root->right) s.push(root->right);
			s.push(root);

			root = root->left;
		}

		root = s.top(); s.pop();

		if(root->right and s.top == root->right) {
			s.pop();
			s.push(root);
			root = root->right;
		}

		else {
			cout << root->data << " ";
			root = NULL;
		}
		
	} while(!s.empty());
}