/*Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

If we notice carefully in the flattened tree, each node’s right child points to the next node of a pre-order traversal.

Now, if a node does not have left node, then our problem reduces to solving it for the node->right.
If it does, then the next element in the preorder traversal is the immediate left child. But if we make the immediate left child as the right child of the node,
then the right subtree will be lost. So we figure out where the right subtree should go. In the preorder traversal, the right subtree comes right after the
rightmost element in the left subtree.So we figure out the rightmost element in the left subtree, and attach the right subtree as its right child.
We make the left child as the right child now and move on to the next node.*/

/////////////////////////////////////

void flatten(Node *root) {

  if (!root) return;

  Node* node = root;
  while (node) {

    // Attatches the right sub-tree to the rightmost leaf of the left sub-tree:
    if (node->left) {

      Node *rightMost = node->left;
      while (rightMost->right) {

        rightMost = rightMost->right;
      }
      rightMost->right = node->right;

      // Makes the left sub-tree to the right sub-tree:
      node->right = node->left;
      node->left = NULL;
    }

    // Flatten the rest of the tree:
    node = node->right;
  }
}
///////////////////////////////////////////////////////////

void flatten(Node *root, Node *&last) {
  if (!root) return;
  Node *left = root->left;
  Node *right = root->right;

  if (root != last) {
    last->right = root;
    last->left = NULL;
    last = root;
  }

  flatten(left, last);
  flatten(right, last);

  if (!left and !right) last = root;
}

///////////////////////////////////////////////////////////

/*Simple solution is, perform pre-order traversal and add the elements that you get from the traversal to a new linked-list or binary tree which will
add the elements to right child always since the elements are in ascending order.*/