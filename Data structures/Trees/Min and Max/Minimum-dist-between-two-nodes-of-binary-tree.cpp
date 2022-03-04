/*Find the minimum distance between two given keys of a Binary Tree
Find the distance between two keys in a binary tree, no parent pointers are given. Distance between two nodes 
is the minimum number of edges to be traversed to reach one node from other.

The distance between two nodes can be obtained in terms of lowest common ancestor. Following is the formula.

Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca) 
'n1' and 'n2' are the two given keys
'root' is root of given Binary Tree.
'lca' is lowest common ancestor of n1 and n2
Dist(n1, n2) is the distance between n1 and n2.*/


// Returns level of key k if it is present in tree, otherwise returns -1
int findLevel(Node *root, int k, int level) {
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->key == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}
 
Node *findDistUtil(Node* root, int n1, int n2, int &d1, int &d2, int &dist, int lvl)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1)
    {
         d1 = lvl;
         return root;
    }
    if (root->key == n2)
    {
         d2 = lvl;
         return root;
    }
 
    // Look for n1 and n2 in left and right subtrees
    Node *left_lca  = findDistUtil(root->left, n1, n2, d1, d2, dist, lvl+1);
    Node *right_lca = findDistUtil(root->right, n1, n2, d1, d2, dist, lvl+1);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)
    {
        dist = d1 + d2 - 2*lvl;
        return root;
    }
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
 
// The main function that returns distance between n1 and n2
// This function returns -1 if either n1 or n2 is not present in
// Binary Tree.
int findDistance(Node *root, int n1, int n2)
{
    // Initialize d1 (distance of n1 from root), d2 (distance of n2 
    // from root) and dist(distance between n1 and n2)
    int d1 = -1, d2 = -1, dist;
    Node *lca = findDistUtil(root, n1, n2, d1, d2, dist, 1);
 
    // If both n1 and n2 were present in Binary Tree, return dist
    if (d1 != -1 && d2 != -1)
        return dist;
 
    // If n1 is ancestor of n2, consider n1 as root and find level 
    // of n2 in subtree rooted with n1
    if (d2 == -1)
    {
        dist = findLevel(lca, n2, 0);
        return dist;
    }
 
    // If n2 is ancestor of n1, consider n2 as root and find level 
    // of n1 in subtree rooted with n2
    if (d1 == -1)
    {
        dist = findLevel(lca, n1, 0);
        return dist;
    }
 
    return -1;
}

/*Time Complexity: Time complexity of the above solution is O(n) as the method does a single tree traversal.*/