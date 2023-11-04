/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true. */
class Solution {
public:
    int solve(TreeNode *root) {
        if (!root) return 0;
        int lh = solve(root->left);
        int rh = solve(root->right);
        if (lh == -1 or rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {

        int h = solve(root);
        return h == -1 ? false : true;
    }
};