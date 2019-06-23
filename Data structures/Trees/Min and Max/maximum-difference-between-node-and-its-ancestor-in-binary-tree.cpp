/*Given a binary tree, we need to find maximum value we can get by subtracting value of node B from value of node A, 
where A and B are two nodes of the binary tree and A is an ancestor of B. Expected time complexity is O(n).
As we are given a binary tree, there is no relationship between node values so we need to traverse whole binary tree 
to get max difference and we can obtain the result in one traversal only by following below steps :
If we are at leaf node then just return its value because it can’t be ancestor of any node. Then at each internal node 
we will try to get minimum value from left subtree and right subtree and calculate the difference between node value 
and this minimum value and according to that we will update the result.
As we are calculating minimum value while retuning in recurrence we will check all optimal possibilities (checking 
node value with minimum subtree value only) of differences and hence calculate the result in one traversal only.*/

int maxDiffUtil(Node* node, int &res)
{
    /* Returning Maximum int value if node is not
       there (one child case)  */
    if (node == NULL)
        return INT_MAX;
 
    /* If leaf node then just return node's value  */
    if (node->left == NULL && node->right == NULL)
        return node->data;
 
    /* Recursively calling left and right subtree
       for minimum value  */
    int val = min(maxDiffUtil(node->left, res),
                  maxDiffUtil(node->right, res));
 
    /* Updating res if (node value - minimum value
       from subtree) is bigger than res  */
    res = max(res, node->data - val);
 
    /* Returning minimum value got so far */
    return min(val, node->data);
}
 
/* This function mainly calls maxDiffUtil() */
int maxDiff(Node *root)
{
    // Initialising result with minimum int value
    int res = INT_MIN;
 
    maxDiffUtil(root, &res);
 
    return res;
}