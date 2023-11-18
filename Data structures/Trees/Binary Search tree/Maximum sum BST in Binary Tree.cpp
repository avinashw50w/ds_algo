/*Given a binary tree. Find the sum of the subtree which is a BST and has the maximum sum.*/

struct Data {
    int ans;
    int sum;
    int min;
    int max;
    int valid;
};

Data dfs(Node *root) {
    Data par = {0, root->val, root->val, root->val, 1};
    if (root->left) {
        Data left = dfs(root->left);
        par.ans = max(par.ans, left.ans);
        par.sum += left.sum;
        if (left.max >= par.min or !left.valid)
            par.valid = 0;
        par.min = left.min;
    }
    if (root->right) {
        Data right = dfs(root->right);
        par.ans = max(par.ans, right.ans);
        par.sum += right.sum;
        if (right.min >= par.max or !right.valid)
            par.valid = 0;
        par.max = right.max;
    }

    if (par.valid) {
        par.ans = max(par.ans, par.sum);
    }
    return par;
}

int solve(Node *root) {
    return dfs(root).ans;
}