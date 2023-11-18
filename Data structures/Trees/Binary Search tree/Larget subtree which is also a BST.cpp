struct Data {
    int ans;
    int min;
    int max;
    int size;
    int valid;
};

Data dfs(Node *root) {
    Data par = {0, root->val, root->val, 1, 1};
    
    if (root->left) {
        Data left = dfs(root->left);
        par.ans = max(par.ans, left.ans);
        par.size += left.size;
        if (left.max >= par.min or !left.valid) {
            par.valid = 0;
        }
        par.min = left.min;
    }
    
    if (root->right) {
        Data right = dfs(root->right);
        par.ans = max(par.ans, right.ans);
        par.size += right.size;
        if (right.min >= par.max or !right.valid) {
            par.valid = 0;
        }
        par.max = right.max;
    }

    if (par.valid) {
        par.ans = max(par.ans, par.size);
    }

    return par;
}

int MaxSizeBST(Node *root) {
    return dfs(root).ans;
}

