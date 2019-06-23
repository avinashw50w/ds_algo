/*1) Create an empty stack nodeStack and push root node to stack.
2) Do following while nodeStack is not empty.
….a) Pop an item from stack and print it.
….b) Push right child of popped item to stack
….c) Push left child of popped item to stack  */

void preorder(Node *root) {
	if(root == NULL) return;

	stack<Node *> s;
	s.push(root);

	while(!s.empty()) {
		Node *tmp = s.top();
		s.pop();

		cout << tmp->data << " ";

		if(tmp->right) s.push(tmp->right);
		if(tmp->left) s.push(tmp->left);
	}
}