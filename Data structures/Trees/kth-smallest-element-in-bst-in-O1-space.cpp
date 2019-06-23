/*K’th smallest element in BST using O(1) Extra Space
Given a Binary Search Tree (BST) and a positive integer k, find the k’th smallest element in the Binary Search Tree.
The idea is to use Morris Traversal. In this traversal, we first create links to Inorder successor and print the data 
using these links, and finally revert the changes to restore original tree. */
// A BST node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A function to find
int KSmallestUsingMorris(Node *root, int k)
{
    // Count to iterate over elements till we
    // get the kth smallest number
    int count = 0;
 
    int ksmall = INT_MIN; // store the Kth smallest
    Node *curr = root; // to store the current node
 
    while (curr != NULL)
    {
        // Like Morris traversal if current does
        // not have left child rather than printing
        // as we did in inorder, we will just
        // increment the count as the number will
        // be in an increasing order
        if (curr->left == NULL)
        {
            count++;
 
            // if count is equal to K then we found the
            // kth smallest, so store it in ksmall
            if (count==k)
                ksmall = curr->key;
 
            // go to current's right child
            curr = curr->right;
        }
        else
        {
            // we create links to Inorder Successor and
            // count using these links
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
 
            // building links
            if (pre->right==NULL)
            {
                //link made to Inorder Successor
                pre->right = curr;
                curr = curr->left;
            }
 
            // While breaking the links in so made temporary
            // threaded tree we will check for the K smallest
            // condition
            else
            {
                // Revert the changes made in if part (break link
                // from the Inorder Successor)
                pre->right = NULL;
 
                count++;
 
                // If count is equal to K then we found
                // the kth smallest and so store it in ksmall
                if (count==k)
                    ksmall = curr->key;
 
                curr = curr->right;
            }
        }
    }
    return ksmall; //return the found value
}
