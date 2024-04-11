/*Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n 
nodes of unique values from 1 to n. Return the answer in any order.*/
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
public:

    vector<TreeNode*> solve(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }

        for (int i = l; i <= r; ++i){
            vector<TreeNode*> left = solve(l, i-1);
            vector<TreeNode*> right = solve(i+1, r);

            for (int li = 0; li < left.size(); ++li) {
                for (int ri = 0; ri < right.size(); ++ri) {
                    TreeNode* par = new TreeNode(i);
                    par->left = left[li];
                    par->right = right[ri];
                    res.push_back(par);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {

        return solve(1, n);
    }
};