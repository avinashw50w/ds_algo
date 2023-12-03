/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized 
that all houses in this place form a binary tree. It will automatically contact the police if two 
directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.*/
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
/*
array<int,2> for a node u represents pair {a, b} where
a = max coins collected in the subtree of u such that u is included
b = max coins collected in the subtree of u is not included
 */
class Solution {
public:
    array<int,2> dfs(TreeNode* root) {
        array<int,2> par = {root->val, 0};
        if (root->left) {
            array<int,2> ch = dfs(root->left);
            par[0] += ch[1];
            par[1] += max(ch[0], ch[1]);
        }
        if (root->right) {
            array<int,2> ch = dfs(root->right);
            par[0] += ch[1];
            par[1] += max(ch[0], ch[1]);
        }
        return par;
    }
    
    int rob(TreeNode* root) {
        array<int,2> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};

// another way to implement
array<int,2> dfs(TreeNode* root) {
    if (!root) return {0, 0};
    array<int,2> left = dfs(root->left);
    array<int,2> right = dfs(root->right);
    array<int,2> par = {root->val, 0};
    par[0] += left[1] + right[1];
    par[1] += max({left[0], left[1]});
    par[1] += max({right[0], right[1]});
    return par;

}