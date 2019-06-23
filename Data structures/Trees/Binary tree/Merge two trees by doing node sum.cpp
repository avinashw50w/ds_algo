
Node *solve(Node *t1, Node *t2) {
	if(!t1) return t2;
	if (!t2) return t1;

	t1->data += t2->data;
	t1->left= solve(t1->left, t2->left);
	t1->right = solve(t1->right, t2->right);

	return t1;
}