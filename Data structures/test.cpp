

Node* copyTree(Node *tree, map<Node*, Node*> *mp) {
	if(tree == NULL) return NULL;
	Node* cloneTree = newNode(tree->data);
	(*mp)[tree] = cloneTree;
	cloneTree->left = copyTree(tree->left, mp);
	cloneTree->right = copyTree(tree->right, mp);

	return cloneTree;
}

void copyRandom(Node* tree, Node* newTree, map<Node*, Node*> *mp) {
	if(newTree == NULL) return NULL;
	newTree->random = (*mp)[tree->random];
	copyRandom(tree->left, newTree->left, mp);
	copyRandom(tree->right, newTree->right, mp);
}

void clone(Node *tree) {
	if(tree == NULL) return;
	map<Node*, Node*> mp;
	Node* newTree = copyTree(tree, mp);
	copyRandom(tree, newTree, mp);
}