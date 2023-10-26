
bool isBST(node *root, int minval, int maxval) { //  set min= -oo  and max= +oo
    if (root == NULL) return true;
    return (minVal < root->data and root->data < maxVal)
        && isBST(root->left, minVal, root->data)
        && isBST(root->right, root->data, maxVal);
   
}

isBST(root, INT_MIN, INT_MAX);

/*METHOD 4(Using In-Order Traversal)
Thanks to LJW489 for suggesting this method.
1) Do In-Order Traversal of the given tree and store the result in a temp array.
3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.

Time Complexity: O(n)

We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node.
If the value of the currently visited node is less than the previous value, then tree is not BST. Thanks to ygos for this space optimization.*/
bool isBST(struct node* root)
{
    static struct node *prev = NULL;

    // traverse the tree in inorder fashion and keep track of prev node
    if (root)
    {
        if (!isBST(root->left))
            return false;

        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}
