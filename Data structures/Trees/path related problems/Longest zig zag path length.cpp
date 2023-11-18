/*Given a binary tree, find the longest zig zag path length.
NOTE: the path should either be in the left or right subtree and should not span across.

eg.        1
          /  \
              2
             / \
             3
            / \
               4 
ans : 3, 2->3->4
*/
// array<int,3> 
// {answer for the subtree, longest zigzag in the left subtree, longest zigzag in the right subtree}
array<int,3> dfs(Node *root) {
    array<int,3> par = {0, 0, 0};
    if (root->left) {
        array<int,3> left = solve(root->left);
        par[1] = max(par[1], left[2] + 1);
        par[0] = max(par[0], left[0]);
    }
    if (root->right) {
        array<int,3> left = solve(root->right);
        par[2] = max(par[2], left[1] + 1);
        par[0] = max(par[0], left[0]);
    }

    par[0] = max({par[0], par[1], par[2]});
    return par;
}

int solve(Node *root) {
    return dfs(root)[0];
}