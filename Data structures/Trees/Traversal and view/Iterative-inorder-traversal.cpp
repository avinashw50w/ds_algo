/*Iterative inorder traversal*/

void inorder(Node *root) {
	stack<Node*> st;
	Node *curr = root;

	while (curr or !st.empty()) {
		while (curr) {
			st.push(curr);
			curr = curr->left;
		}

		curr = st.top(); st.pop();

		cout << curr->data << " ";

		curr = curr->right;
	}
}