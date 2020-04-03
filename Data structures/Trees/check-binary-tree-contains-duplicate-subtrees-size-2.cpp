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

unordered_set<string> hash;

string check(Node *root) {
    string s = "";

    if (!root) {
        s += "$";
        return s;
    }

    string left = check(root->left);
    if (s == left) return s;

    string right = check(root->right);
    if (s == right) return s;

    s += root->data + left + right;

    if (hash.size() > 3 and hash.count(s)) return "";

    hash.insert(s);
    return s;
}

/* these are the strings returned by the children to their parent, so if the subtree rooted at v already exists in the hash, then 
return empty string to the parent. SO whenever the parent recieves an empty string, then that means a duplicate subtree exists in the tree
D$$
E$$
BD$$E$$
D$$
E$$
BD$$E$$
 Yes

 */