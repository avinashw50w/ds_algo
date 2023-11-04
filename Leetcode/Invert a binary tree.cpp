/*Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / 
1   3 6   
Output:

     4
   /   \
  7     2
   \   / \
    6 3   1*/

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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->left, root->right);
        return root;
    }
};