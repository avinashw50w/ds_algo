/*Iterative inorder traversal*/

void inorder(Node *root) {
	stack<Node*> st;
	Node *curr = root;

	while (curr and !st.empty()) {
		while (curr) {
			st.push(curr);
			curr = curr->left;
		}

		Node *top = st.top(); st.pop();

		cout << curr->data;

		curr = curr->right;
	}
}