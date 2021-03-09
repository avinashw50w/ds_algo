/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* src) {
        if (src == NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        q.push(src);

        Node *node = new Node(src->val);
        mp[src] = node;

        while (!q.empty()) {
            Node *u = q.front(); q.pop();

            for (auto v : u->neighbors) {
                if (mp[v] == NULL) {
                    node = new Node(v->val);
                    mp[v] = node;
                    q.push(v);
                }

                mp[u]->neighbors.push_back(mp[v]);
            }
        }

        return mp[src];
    }
};