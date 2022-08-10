/*Find All Duplicate Subtrees
Given a binary tree, find all duplicate subtrees. For each duplicate subtrees, we only need to return the root node of any one of them. Two trees are duplicate if they have the same structure with same node values.

Examples:

Input :
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4

Output :
   2
  /    and    4
 4
Explanation: Above Trees are two duplicate subtrees.
Therefore, you need to return above trees root in the
form of a list.

IDEA: use serialization
*/

// another way to serialize
unordered_map<string, int> mp;
vector<string> res;

string serialise(Node *root) {
    if (!root) return "";
    string s = to_string(root->val) + "(" + serialise(root->left) + ")" + "(" + serialise(root->right) + ")";
    // push subtree only once if it's duplicate present
    // that's why used map here instead of set
    if(mp[s] == 1) res.push_back(root);
    mp[s]++;
    
    return s;
}

vector<Node*> solve(Node *root) {
    
    serialise(root);
    return res;
}