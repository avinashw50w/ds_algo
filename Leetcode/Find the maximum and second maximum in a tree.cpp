void solve(TreeNode *root, int &first, int &second) {
    if (!root) return 0;
    if (root->val > first) second = first, first = root->val;
    else if (second < root->val and root->val < first) second = root->val;
    solve(root->left, first, second);
    solve(root->right, first, second);
}

pair<int, int> getMinimumDifference(TreeNode* root) {
    int first = root->val, second = INT_MIN;
    solve(root, root->val, INT_MIN);
    pair<int, int> p = {first, second};
    return p;
}