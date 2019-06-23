// Similar to trie, but each node contains 3 pointers instead of 26 pointers.
// Each node also contains 2 more info, the character and a boolean to mark end of a string.
// It is space efficient compared to tries


struct Node {
	char data;
	int endofstring;
	Node *left, *right, *eq;
};

Node* newNode(char c) {
	Node *tmp = new Node();
	tmp->data = c;
	tmp->endofstring = 0;
	tmp->left = tmp->right = tmp->eq = NULL;
	return tmp;
}

void insert(Node **root, char *word) {

	if (!(*root)) *root = newNode(c);

	if (*word < (*root)->data) insert((*root)->left, word);
	else if (*word > (*root)->data) insert((*root)->right, word);
	else {
		if (*(word+1)) insert((*root)->eq, word+1);
		else (*root)->endofstring = 1;
	}
}

void traverseTree(Node *root, char *buff, int depth) {
	if (root) {

		traverseTree(root->left, buff, depth);

		buff[depth] = root->data;
		
		if (root->endofstring == 1) {
			buff[depth+1] = '\0';
			printf("%s\n", buff);
		}

		traverseTree(root->eq, buff, depth + 1);
		traverseTree(root->right, buff, depth);
	}
}

bool searchTree(Node *root, char *word) {

	if (!root) return 0;

	if (*word < (*root)->data)
		return searchTree((*root)->left, word);
	else if (*word > (*root)->data)
		return searchTree((*root)->right, word);
	else {

		if (*(word+1) == '\0') return root->endofstring;
		return searchTree((*root)->eq, word+1);
	}
}