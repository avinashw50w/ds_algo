/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each 
column index starting from the leftmost column and ending on the rightmost column. There may be 
multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
eg.                 1
                2       3
            4       65     7
    here 6 and 5 are at the same row and column. So in the output sort them
    output: [[4], [2], [1,5,6], [3], [7]]

Return the vertical order traversal of the binary tree.*/
class Solution {
    map<int, vector<array<int, 2>>> mp;
public:

    void solve(TreeNode *root, int d, int level) {
        if (!root) return;
        mp[d].push_back({ level, root->val });
        solve(root->left, d-1, level + 1);
        solve(root->right, d+1, level + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        solve(root, 0, 0);
        
        for (auto &p: mp) {
            sort(p.second.begin(), p.second.end(), [](const auto &x, const auto &y) {
              return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];   
            });
            vector<int> v;
            for (auto e: p.second) v.push_back(e[1]);
            res.push_back(v);
        }
        return res;
    }
};