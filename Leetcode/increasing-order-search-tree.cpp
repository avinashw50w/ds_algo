/*Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only 1 right child.

Example 1:
Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  */
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
    
    void solve(TreeNode *root, TreeNode **r) {
        if (!root) return;
        
        solve(root->right, r);
        
        root->right = *r;
        if (*r) (*r)->left = NULL;
        (*r) = root;

        solve(root->left, r);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return NULL;
        TreeNode *r = NULL;
        solve(root, &r);
        return r;
    }
};