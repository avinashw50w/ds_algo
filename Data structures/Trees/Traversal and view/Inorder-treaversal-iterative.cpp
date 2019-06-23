
void inorderIterative(Node *root) {

	bool done = false;

	stack<Node*> s;

	Node *curr = root;

	while(!done) {

		if(curr != NULL) {
			s.push(curr);
			curr = curr->left;
		}

		else {
			
			if(!s.empty()) {
				cout << (s.top())->data << endl;
				s.pop();
				curr = curr->right;
			}

			else done = 1;
		}
	}
}