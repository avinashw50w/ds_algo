/*The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree. 
The diameter of a tree T is the largest of the following quantities:

* the diameter of the left subtree
* the diameter of the right subtree
* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)*/

/*The second parameter is to store the height of tree.
   Initially, we need to pass a pointer to a location with value
   as 0. So, function should be used as follows:
 
   int height = 0;
   struct node *root = SomeFunctionToMakeTree();
   int diameter = diameterOpt(root, &height); */

// diameter of a tree - maximum distance bw any two leaves
int solve(Node *root, int &res) {
    if (!root) return 0;

    int lh = solve(root->left, res);
    int rh = solve(root->right, res);

    res = max(res, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int diameter(Node *root) {
    int res = 0;
    solve(root, res);
    
    return res; 
}
