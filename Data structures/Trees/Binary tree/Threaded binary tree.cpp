/*Inorder traversal of a Binary tree is either be done using recursion or with the use of a auxiliary stack. The idea of threaded binary trees 
is to make inorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child 
pointers that would normally be NULL point to the inorder successor of the node (if it exists).
There are two types of threaded binary trees.
Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists)
Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively. 
The predecessor threads are useful for reverse inorder traversal and postorder traversal.
The threads are also useful for fast accessing ancestors of a node.*/
struct node {
	int data;
	node *left, *right;
	bool rightThread;
}

node* leftmost(node *n) {
	if(n == NULL) return NULL;

	while(n->left != NULL) n = n->left;

	return n;
}

void inorder(node *n) {
	node *curr = leftmost(n);

	while(curr != NULL) {

		cout << curr->data << endl;

		if(curr->rightThread) 
			curr = curr->right;

		else curr = leftmost(curr->right);
	}
}
