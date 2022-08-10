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

unordered_map<string> mp;

string check(Node *root) {
    if (!root) {
        return ""
    }

    string str = "(";
    str += check(root->left);
    str += to_string(root->data);
    str += check(root->right);
    str += ")";

    if (mp[str] == 1) {
        cout << root->data << " ";
    }

    mp[str]++;
    return str;
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