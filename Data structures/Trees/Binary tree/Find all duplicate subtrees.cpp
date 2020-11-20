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

void serialise(Node *root, unordered_set<string> &st, vector<string> &res) {
    if (!root) return "$";
    string s = "";
    string l = serialise(root->left, st);
    string r = serialise(root->right, st);
    s += to_string(root->data) + l + r;

    if (st.count(s)) res.push_back(s);
    st.insert(s);
}

// another way to serialize
string serialise(Node *root, auto &st, auto &res) {
    if (!root) return "";
    string s = "(";
    s += serialise(root->left, st, res);
    s += to_string(root->data);
    s += serialise(root->right, st, res);
    s += ")";

    if (st.count(s)) res.push_back(s);
    st.insert(s);
    return s;
}

vector<string> solve(Node *root) {
    unordered_set<string> st;
    vector<string> res;
    serialise(root, st, res);
    for (string s : st) res.push_back(s);
    return res;
}