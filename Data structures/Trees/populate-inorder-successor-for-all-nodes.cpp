/*Given a Binary Tree where each node has following structure, write a function to populate next pointer for all nodes.
The next pointer for every node should be set to point to inorder successor.

struct node
{
  int data;
  struct node* left;
  struct node* right;
  struct node* next;
}
Run on IDE
Initially, all next pointers have NULL values. Your function should fill these next pointers so that they point to inorder successor.

Solution (Use Reverse Inorder Traversal)
Traverse the given tree in reverse inorder traversal and keep track of previously visited node. When a node is being visited,
assign previously visited node as next.*/

// A wrapper over populateNextRecur
void populateNext(struct node *root)
{
  // The first visited node will be the rightmost node
  // next of the rightmost node will be NULL
  struct node *next = NULL;

  populateNextRecur(root, &next);
}

/* Set next of all descendents of p by traversing them in reverse Inorder */
void populateNextRecur(struct node* p, struct node *&next_ref)
{
  if (p)
  {
    // First set the next pointer in right subtree
    populateNextRecur(p->right, next_ref);

    // Set the next as previously visited node in reverse Inorder
    p->next = next_ref;

    // Change the prev for subsequent node
    next_ref = p;

    // Finally, set the next pointer in right subtree
    populateNextRecur(p->left, next_ref);
  }
}