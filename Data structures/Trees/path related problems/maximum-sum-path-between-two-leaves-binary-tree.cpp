/*Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

We can find the maximum sum using single traversal of binary tree. The idea is to maintain two values in recursive calls
1) Maximum root to leaf path sum for the subtree rooted under current node.
2) The maximum path sum between leaves (desired output).

For every visited node X, we find the maximum root to leaf sum in left and right subtrees of X. We add the two values with X->data, 
and compare the sum with maximum path sum found so far.

Following is the implementation of the above O(n) solution.*/

// maximum sum path bw two leaves in a tree

int solve(Node *root, int &res) {
    if (!root) return 0;
    if (!root->left and !root->right) return root->data;

    int ls = solve(root->left, res);
    int rs = solve(root->right, res);
    
    int ret = max(root->data, root->data + max(ls, rs));
    res = max(res, max(ret, root->data + ls + rs));

    return ret;
}

int maxSum(Node *root) {
    int res = 0;
    solve(root, res);

    return res;
}
