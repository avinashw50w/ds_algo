/*Given a binary tree, write a function that returns true if the tree satisfies below property.

For every node, data value must be equal to sum of data values in left and right children.
Consider data value as 0 for NULL children.

Simply do preorder traversal and in place of visiting the node, check if the node's data is equal to the sum of the data of
its left and right child  */

bool check(Node *root) {
    if (!root or (!root->left and !root->right)) return true;
    int ld = 0, rd = 0;
    if (root->left) ld = root->left->data;
    if (root->right) rd = root->right->data;

    return root->data == ld + rd and check(root->left) and check(root->right);
}
int check(Node *root) {

    if (!root || (!root->left and !root->right)) return 1;

    int left_data = 0, right_data = 0;

    if (root->left) left_data = root->left->data;

    if (root->right) right_data = root->right->data;

    if ( (root->data == left_data + right_data) and check(root->left) and check(root->right) )
        return 1;

    else return 0;
}

/*Time Complexity: O(n), we are doing a complete traversal of the tree.*/