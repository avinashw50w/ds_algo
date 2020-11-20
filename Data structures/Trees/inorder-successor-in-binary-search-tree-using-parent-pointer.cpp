/*1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
Travel up using the parent pointer until you see a node which is left child of it’s parent. The parent of such a node is the succ.

        1
      /   \
     2     3
   /   \
  4     5
 the inorder successor of 5 is 1
 keep moving upward till the node is the right child of its parent
 and when the node becomes the left child of its parent then the parent is the inorder
 successor
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
  int data;
  node* left;
  node* right;
  node* parent;
};

node * minValue(struct node* node) {
  node *curr = node;
  while (curr->left) curr = curr->left;
  return curr;
}

node * inOrderSuccessor(node *root, node *n)
{
  if (n->right) return minValue(n->right);

  // step 2 of the above algorithm
  node *p = n->parent;
  while (p != NULL && n == p->right)
  {
    n = p;
    p = p->parent;
  }
  return p;
}