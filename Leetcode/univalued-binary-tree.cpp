/*A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isUnivalTree(TreeNode* root) {
    bool l = (root->left == NULL or 
              (root->val == root->left->val and isUnivalTree(root->left)));
    bool r = (root->right == NULL or 
             (root->val == root->right->val and isUnivalTree(root->right)));
    
    return l and r;
}


class Solution {
public:
    
    bool check(TreeNode *root, int val) {
        if (!root) return true;
        
        if (root->val != val) return false;
        
        return (check(root->left, val) and check(root->right, val));
    }
    
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        int val = root->val;
        
        return check(root, val);
    }
};