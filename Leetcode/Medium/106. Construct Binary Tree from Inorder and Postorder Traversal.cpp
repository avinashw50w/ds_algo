/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]*/
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
    vector<int> post;
    unordered_map<int, int> pos;
public:
    TreeNode* solve(int l, int r, int &pi) {
        if (pi < 0 or l > r) return NULL;
        int e = post[pi];
        TreeNode *res = new TreeNode(e);
        int i = pos[e];
        pi--;
        // here order matters, first solve root->right, then root->left
        res->right = solve(i+1, r, pi);
        res->left = solve(l, i-1, pi);
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        int n = inorder.size();
        for (int i = 0; i < n; ++i) pos[inorder[i]] = i;
            int pi = n-1;
        return solve(0, n-1, pi);
    }
};