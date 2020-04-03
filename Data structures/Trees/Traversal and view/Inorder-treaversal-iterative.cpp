
void inorderIterative(Node *root) {

	bool done = false;

	stack<Node*> s;

	Node *curr = root;

	while(curr || !s.empty()) {

		while (curr) {
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top(); s.pop();
		cout << curr->data << " ";

		s.push(curr->right);
	}
}