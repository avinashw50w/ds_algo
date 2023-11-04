/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

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
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


//////////////////////////////////////////
int searchInsert(vector<int>& a, int x) {
    int n = a.size();
    if (n == 0) return 0;
    if (x < a[0]) return 0;
    if (x > a[n - 1]) return n;
    int l = 0, r = n - 1, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (x <= a[mid]) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    return ans;
}