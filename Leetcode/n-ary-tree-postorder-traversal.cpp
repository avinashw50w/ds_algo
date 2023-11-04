/*Given an n-ary tree, return the postorder traversal of its nodes' values.*/
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
        
        for (auto i: root->children) solve(i, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }
};