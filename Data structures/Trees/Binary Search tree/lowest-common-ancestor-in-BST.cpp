
/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
// recursive
Node *lca(Node *root, int n1, int n2) {
  if (!root) return NULL;
  if (root->data > n1 and root->data > n2) return lca(root->left, n1, n2);
  if (root->data < n1 and root->data < n2) return lca(root->right, n1, n2);
  return root;
}

// iterative
struct node *lca(struct node* root, int n1, int n2)
{
  while (root != NULL)
  {
    // If both n1 and n2 are smaller than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
      root = root->left;

    // If both n1 and n2 are greater than root, then LCA lies in right
    else if (root->data < n1 && root->data < n2)
      root = root->right;

    // if value of node lies between n1 and n2
    // which means that the node is the parent of both n1 and n2 ,ie, its LCA
    else break;
  }
  return root;
}