/*Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example, given a 3-ary tree:*/

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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> v;
            while (cnt--) {
                Node *top = q.front();
                q.pop();
                int val = top->val;
                v.push_back(val);
                
                for (auto i: top->children) q.push(i);
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};