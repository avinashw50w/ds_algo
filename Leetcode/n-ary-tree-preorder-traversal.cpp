/*Given an n-ary tree, return the preorder traversal of its nodes' values.*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    void solve(Node *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        for (auto i: root->children) solve(i, res);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }
};