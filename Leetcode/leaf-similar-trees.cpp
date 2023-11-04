/*Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.*/

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
    
    void solve(TreeNode *root, vector<int> &res) {
        if (!root) return;
        if (!root->left and !root->right) res.push_back(root->val);
        solve(root->left, res);
        solve(root->right, res);            
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> res1;
        solve(root1, res1);
        
        vector<int> res2;
        solve(root2, res2);
        
        if (res1.size() == res2.size()) {
            for (int i = 0; i < res1.size(); ++i) 
                if (res1[i] != res2[i]) return false;
            
            return true;
        }
        
        return false;
    }
};