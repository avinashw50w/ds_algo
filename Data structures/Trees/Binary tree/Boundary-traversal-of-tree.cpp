/*Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root. 
For example, boundary traversal of the following tree is “20 8 4 10 14 25 22″

							20
						  /    \
						 8     22
					   /  \      \
					  4   12     25
					     /  \
					    10  14


We break the problem in 3 parts:
1. Print the left boundary in top-down manner.
2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts:
…..2.1 Print all leaf nodes of left sub-tree from left to right.
…..2.2 Print all leaf nodes of right subtree from left to right.
3. Print the right boundary in bottom-up manner.*/

void printBoundaryLeft(Node *root) {
	if (root) {

		if (root->left) {
			cout << root->data << " ";
			printBoundaryLeft(root->left);
		}

		else if (root->right) {
			cout << root->data << " ";
			printBoundaryLeft(root->right);
		}
	}
}

void printBoundaryRight(Node *root) {
	if (root) {

		if (root->right) {
			printBoundaryRight(root->right);
			cout << root->data << " ";
		}

		else if (root->left) {
			printBoundaryRight(root->left);
			cout << root->data << " ";
		}
	}
}

void printLeaves(Node *root) {
	if (root) {

		printLeaves(root->left);

		if (!root->left and !root->right) cout << root->data << " ";

		printLeaves(root->right);
	}
}

void boundaryTraversal(Node *root) {
	if (root) {

		cout << root->data << " ";

		printBoundaryLeft(root->left);

		printLeaves(root->left);
		printLeaves(root->right);

		printBoundaryRight(root->right);
	}
}

