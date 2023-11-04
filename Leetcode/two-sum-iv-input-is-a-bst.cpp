/*Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True*/
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
    void traverse(TreeNode *root, vector<int> &res) {
        if (!root) return;
        traverse(root->left, res);
        res.push_back(root->val);
        traverse(root->right, res);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        traverse(root, in);
        
        unordered_map<int,int> m;
        for (int i: in) {
            if (m.count(k-i)) return true;
            m[i] = 1;
        }
        
        return false;
    }
};