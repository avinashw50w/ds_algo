/*Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2


return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).*/

class Solution {
public:
    void solve(TreeNode *root, unordered_map<int, int> &f) {
        if (!root) return;
        f[root->val]++;
        solve(root->left, f);
        solve(root->right, f);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> f;
        vector<int> ans;
        solve(root, f);
        int mx = INT_MIN;
        for (auto x : f) mx = max(mx, x.second);
        for (auto x : f) if (x.second == mx) ans.push_back(x.first);
        return ans;
    }
};