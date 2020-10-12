/*Given a Binary Tree where every node has following structure.

struct node {
    int key;
    struct node *left,*right,*random;
}
The random pointer points to any random node of the binary tree and can even point to NULL, clone the given binary tree.

Method 1 (Use Hashing)
The idea is to store mapping from given tree nodes to clone tre node in hashtable. Following are detailed steps.

1) Recursively traverse the given Binary and copy key value, left pointer and right pointer to clone tree. While copying, store the mapping
from given tree node to clone tree node in a hashtable. In the following pseudo code, ‘cloneNode’ is currently visited node of clone tree and
‘treeNode’ is currently visited node of given tree.

   cloneNode->key  = treeNode->key
   cloneNode->left = treeNode->left
   cloneNode->right = treeNode->right
   map[treeNode] = cloneNode
2) Recursively traverse both trees and set random pointers using entries from hash table.

   cloneNode->random = map[treeNode->random] */


// This function creates clone by copying key and left and right pointers
// This function also stores mapping from given tree node to clone.
Node *cloneTree(Node *treeNode, unordered_map<Node*, Node*> &mp) {
    if (!treeNode) return NULL;
    Node *cloneNode = new Node(treeNode->data);
    mp[treeNode] = cloneNode;
    cloneNode->left = cloneTree(treeNode->left, mp);
    cloneNode->right = cloneTree(treeNode->right, mp);
    return cloneNode;
}

// This function copies random node by using the hashmap built by
// copyLeftRightNode()
void cloneRandom(Node *treeNode, Node *cloneNode, unordered_map<Node*, Node*> mp) {
    if (!cloneNode) return;
    cloneNode->random = mp[treeNode->random];
    cloneRandom(treeNode->left, cloneNode->left, mp);
    cloneRandom(treeNode->right, cloneNode->right, mp);
}

// This function makes the clone of given tree. It mainly uses
// copyLeftRightNode() and copyRandom()
Node *clone(Node *tree) {
    if (!tree) return NULL;
    unordered_map<Node*, Node*> mp;
    Node *cloneTree = cloneNodes(tree, mp);
    cloneRandom(tree, cloneTree, mp);
    return cloneTree;
}

