/*Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input:
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.

NOTE: root will always have the minimum value, because only the minimum leaf node values
propagates upwards.
*/

class Solution {
    typedef long long ll;
    const ll INF = 1e12;
public:
    void solve(TreeNode *root, ll &first, ll &second) {
        if (!root) return;
        if (root->val < first) {
            second = first;
            first = root->val;
        }
        else if (first < root->val and root->val < second) second = root->val;
        solve(root->left, first, second);
        solve(root->right, first, second);
    }

    int findSecondMinimumValue(TreeNode* root) {
        ll first = INF, second = INF;
        solve(root, first, second);
        return second == INF ? -1 : (int)second;
    }
};