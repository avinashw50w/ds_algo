/*Method 1 (Uses Parent Pointer) 
In this method, we assume that every node has parent pointer.

The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

Input: node, root // node is the node whose Inorder successor is needed.
output: succ // succ is Inorder successor of node.

1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then succ is one of the ancestors. Do following.
Travel up using the parent pointer until you see a node which is left child of it’s parent. The parent of such a node is the succ.

Implementation
Note that the function to find InOrder Successor is highlighted (with gray background) in below code.
*/
struct node
{
    int data;
    node* left;
    node* right;
    node* parent;
};
 
node * minValue(node* node); 
 
node * inOrderSuccessor(node *root, node *n)
{
  // step 1 of the above algorithm 
  if( n->right)
    return minValue(n->right);
 
  // step 2 of the above algorithm
  node *p = n->parent;
  while(p && n == p->right)
  {
     n = p;
     p = p->parent;
  }
  return p;
}

///////////////////////////////////////////////////////////////////////////////////////////
/*Method 2 (Search from root) 
Parent pointer is NOT needed in this algorithm. The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.

Input: node, root // node is the node whose Inorder successor is needed.
output: succ // succ is Inorder successor of node.

1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then start from root and use search like technique. Do following.
Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise go to left side.*/

node * inOrderSuccessor(node *root, node *n)
{
    // step 1 of the above algorithm
    if( n->right)
        return minValue(n->right);
 
    node *succ = NULL;
 
    // Start from root and search for successor down the tree
    while (root)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
           break;
    }
 
    return succ;
}
 
/* Given a non-empty binary search tree, return the minimum data  
    value found in that tree. Note that the entire tree does not need
    to be searched. */
struct node * minValue(struct node* node) {
  struct node* current = node;
  
  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}
 
/* Helper function that allocates a new node with the given data and 
    NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data   = data;
  node->left   = NULL;
  node->right  = NULL;
  node->parent = NULL;
   
  return(node);
}
 