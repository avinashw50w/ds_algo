
/* find the kth largest element in a BST */

/* get the reverse inorder */
void rev_inorder(node* root, int &k) {
	if (root) {
		rev_inorder(root->right);

		k--;
		if (k == 0) {
			cout << root->data;
			return;
		}

		rev_inorder(root->left);
	}
}

//  O(h + k) , where h is the height of the tree //
/////////////////////////////////////
// in O(1) extra space
Node* KthLargestUsingMorrisTraversal(Node* root, int k)
{
	Node* curr = root;
	Node* Klargest = NULL;

	// count variable to keep count of visited Nodes
	int count = 0;

	while (curr != NULL) {
		// if right child is NULL
		if (curr->right == NULL) {

			// first increment count and check if count = k
			if (++count == k)
				Klargest = curr;

			// otherwise move to the left child
			curr = curr->left;
		}

		else {

			// find inorder successor of current Node
			Node* succ = curr->right;

			while (succ->left != NULL && succ->left != curr)
				succ = succ->left;

			if (succ->left == NULL) {

				// set left child of successor to the
				// current Node
				succ->left = curr;

				// move current to its right
				curr = curr->right;
			}

			// restoring the tree back to original binary
			//  search tree removing threaded links
			else {

				succ->left = NULL;

				if (++count == k)
					Klargest = curr;

				// move current to its left child
				curr = curr->left;
			}
		}
	}

	return Klargest;
}
