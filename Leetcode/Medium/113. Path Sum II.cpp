/*Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum 
of the node values in the path equals targetSum. Each path should be returned as a list of the node 
values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<int>> res;
public:
    void solve(TreeNode* root, int sum, vector<int> path) {
        if (!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left and !root->right) {
            if (sum == 0) res.push_back(path);
            return;
        }
        solve(root->left, sum, path);
        solve(root->right, sum, path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, {});
        return res;
    }
};