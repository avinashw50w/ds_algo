/*Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input Tree:
         10
        /  \
       5    8
      / \
     2   20

In the above tree, nodes 20 and 8 must be swapped to fix the tree.
Following is the output tree
         10
        /  \
       5    20
      / \
     2   8

Approach 1: do inorder traversal and store all the nodes. Sort the array
and then again do inorder traversal and restore the elements back to the tree
T: O(nlogn), S: O(n), Time can be reduced if we find the two swapped values in the inorder
array and correct them. Then T will be O(n)

Approach 2:
case 1:The swapped nodes are not adjacent in the inorder traversal of the BST.
For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}.
The inorder traversal of the given tree is 3 25 7 8 10 15 20 5

case 2: The swapped nodes are adjacent in the inorder traversal of BST.
For example, Nodes 7 and 8 are swapped in {3 5 7 8 10 15 20 25}.
The inorder traversal of the given tree is 3 5 8 7 10 15 20 25

do an inorder traversal along with the previous visited node.
If for the first time current node value is less than the previous one, then store the
previous node in x. And if for the second time the current node value is less than the
previous node, then store the current node in z.
In case 2, z is null, and to swap we need the current node value so we will store that in y
Then if (x and y) swap(x, y)
else if (x and z) swap(x, z)
*/

void inorder(Node *root, Node *&x, Node *&y, Node *&z, Node *&prev) {
	if (!root) return;
	inorder(root->left, x, y, z, prev);

	if (prev and root->data < prev->data) {
		if (!x) {
			x = prev;
			y = root;
		}
		else
			z = root;
	}

	prev = root;
	inorder(root->right, x, y, z, prev);
}

void correctBST(Node *root) {
	Node *x, *y, *z, *prev;
	x = y = z = prev = NULL;

	inorder(root, x, y, z, prev);

	if (x and z) swap(x->data, z->data);
	else if (x and y) swap(x->data, y->data);
}