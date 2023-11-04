/*Given the root of a binary tree, return the maximum path sum of any path.*/
class Solution {
public:
    int solve(TreeNode *root, int &res) {
        if (!root) return 0;
        int ls = solve(root->left, res);
        int rs = solve(root->right, res);
        
        int ret = max(root->val, max(root->val + ls, root->val + rs));
        res = max(res, max(ret, root->val + ls + rs));
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        int res = -1e9;
        solve(root, res);
        return res;
    }
};