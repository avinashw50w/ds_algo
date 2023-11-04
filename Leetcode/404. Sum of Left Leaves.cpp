/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
means find the node which is the left child of its parent and also a leaf node.
*/

class Solution {
public:
    bool isLeaf(TreeNode *n) {
        return !n->left and !n->right;
    }

    void solve(TreeNode *n, int &ans) {
        if (!n) return;
        if (isLeaf(n)) return;
        if (n->left and isLeaf(n->left)) ans += n->left->val;
        solve(n->left, ans);
        solve(n->right, ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};