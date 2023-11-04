/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.*/
class Solution {
    const int inf = 1e9;
    int ans = inf;
public:
    void dfs(TreeNode *root, int d) {
        if (!root) return;
        if (!root->left and !root->right) ans = min(ans, d);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }

    int minDepth(TreeNode* root) {
        dfs(root, 1);
        return ans == inf ? 0 : ans;
    }
};