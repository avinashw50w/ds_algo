/*Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node. 
For example, consider the following BST.

              50
           /      \
         30        70
        /   \      /  \
      20    40    60   80 

The above tree should be modified to following 

              260
           /      \
         330        150
        /   \       /  \
      350   300    210   80

A simple method for solving this is to find sum of all greater values for every node. This method would take O(n^2) time.
We can do it using a single traversal. The idea is to use following BST property. If we do reverse Inorder traversal of BST, 
we get all nodes in decreasing order. We do reverse Inorder traversal and keep track of the sum of all nodes visited so far, 
we add this sum to every node.*/

// Recursive function to add all greater values in every node
void modifyBSTUtil(struct node *root, int &sum)
{
    // Base Case
    if (root == NULL)  return;
 
    // Recur for right subtree
    modifyBSTUtil(root->right, sum);
 
    // Now *sum has sum of nodes in right subtree, add
    // root->data to sum and update root->data
    sum = sum + root->data;
    root->data = sum;
 
    // Recur for left subtree
    modifyBSTUtil(root->left, sum);
}
 
// A wrapper over modifyBSTUtil()
void modifyBST(struct node *root)
{
    int sum = 0;
    modifyBSTUtil(root, sum);
}