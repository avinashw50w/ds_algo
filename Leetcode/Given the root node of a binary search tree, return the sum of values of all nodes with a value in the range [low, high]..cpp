/*Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].*/
class Solution {
    int ans = 0;
public:
    void solve(TreeNode *root, int low, int high) {
        if (!root) return;
        if (low <= root->val and root->val <= high) ans += root->val;
        solve(root->left, low, high);
        solve(root->right, low, high);   
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root, low, high);
        return ans;
    }
};