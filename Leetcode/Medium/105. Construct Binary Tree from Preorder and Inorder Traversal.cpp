/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/
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
 

 IDEA: for each of the values in preorder, find its position i in inorder and 
 recursively construct left and right subtree where
 par = ith node
 left subtree = solve(l, i-1)
 right subtree = solve(i+1, r)
 */
class Solution {
    vector<int> pre, in;
    unordered_map<int, int> pos;
    int pi;
public:
    TreeNode* solve(int l, int r) {
        if(pi == pre.size() or l > r) return NULL;
        TreeNode *par = new TreeNode(pre[pi++]);
        if (l == r) return par;
        int i = pos[par->val];
        par->left = solve(l, i-1);
        par->right = solve(i+1, r);
        return par;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        int n = in.size();
        for (int i = 0; i<n; ++i) {
            pos[in[i]] = i;
        }
        pi = 0;
        return solve(0, n-1);
    }
};