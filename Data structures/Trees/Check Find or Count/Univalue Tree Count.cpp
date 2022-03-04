/*A univalue tree is a tree where all nodes under it have the same value.

Given a binary tree root, return the number of univalue subtrees.

Constraints

1 ≤ n ≤ 100,000 where n is the number of nodes in root*/
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 bool go(Tree* root, int &ans) {
    if (!root) return true;

    int ls = go(root->left, ans);
    int rs = go(root->right, ans);

    int lval = root->left ? root->left->val : root->val;
    int rval = root->right ? root->right->val : root->val;
    if (ls and rs and root->val == lval and root->val == rval) {
        ans++;
        return true;
    }
    return false;
 }
int solve(Tree* root) {
    int ans = 0;
    go(root, ans);
    return ans;
    
}