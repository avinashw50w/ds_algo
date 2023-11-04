/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    static const long long oo = 1e10;
    bool solve(TreeNode *root, long long mn, long long mx) {
        if (!root) return true;
        
       return (mn < root->val and root->val < mx and 
               solve(root->left, mn, root->val) and 
              solve(root->right, root->val, mx));
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, -oo, oo);
    }
};