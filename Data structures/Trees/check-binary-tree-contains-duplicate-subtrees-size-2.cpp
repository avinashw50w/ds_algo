/*Check if a Binary Tree contains duplicate subtrees of size 2 or more
Given a Binary Tree, check whether the Binary tree contains a duplicate sub-tree of size 2 or more.
Note : Two same leaf nodes are not considered as subtree size of a leaf node is one.

Input :  Binary Tree
               A
             /    \
           B        C
         /   \       \
        D     E       B
                     /  \
                    D    E
Output : Yes */

// use tree serialization

unordered_set<string> st;

string check(Node *root) {
    string s = "";

    if (!root) {
        s += "$";
        return s;
    }

    string left = check(root->left);
    if (left == "") return "";

    string right = check(root->right);
    if (right == "") return "";

    s += root->data + left + right;

    if (st.size() > 3 and st.count(s)) return "";

    st.insert(s);
    return s;
}

/* these are the strings returned by the children to their parent, so if the subtree rooted at v already exists in the set, then
return empty string to the parent. SO whenever the parent recieves an empty string, then that means a duplicate subtree exists in the tree
D$$
E$$
BD$$E$$
D$$
E$$
BD$$E$$
 Yes

 */