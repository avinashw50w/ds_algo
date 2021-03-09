void postorder(Node *root) {
	Node *curr = root;
	stack<Node*> st;

	while (curr or st.size()) {
		// while left child exists push it to stack
		if (curr) {
			st.push(curr);
			curr = curr->left;
		}
		// if left child doesn't exists, then check if it has a right child
		else {
			Node *top = st.top();
			// if no right child, means it is a left node, so print it
			if (top->right == NULL) {
				st.pop();
				cout << top->val << " ";
				// while the curr node is the right child of its parent,
				// then print the node. There is no need to check for left child
				// because all the left children so far have already been printed
				while (st.size() and top == st.top()->right) {
					top = st.top(); st.pop();
					cout << top->val << " ";
				}
			}
			// if right child exists then set curr to its right child
			else {
				curr = top->right;
			}
		}
	}
}
