/*Given a binary tree, we need to find maximum value we can get by subtracting value of node B from value of node A,
where A and B can be any two nodes of the binary tree where A is an ancestor of B. Expected time complexity is O(n).*/

// IDEA: find the minimum valued node (mn) in the left and right subtree of A,
// and calculate (A-mn). The ans will be the maximum of all such values for every node x.
int maxDiffUtil(Node* node, int &res)
{
    if (node == NULL)
        return INT_MAX;

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