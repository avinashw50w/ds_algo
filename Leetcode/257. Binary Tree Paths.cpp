/*Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3*/

void solve(TreeNode *node, string s, vector<string> &res) {
    if (!node) return;

    if (!node->left and !node->right) {
        s += to_string(node->val);
        res.push_back(s);
        return;
    }

    s += to_string(node->val) + "->";

    solve(node->left, s, res);
    solve(node->right, s, res);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    solve(root, "", res);
    return res;
}