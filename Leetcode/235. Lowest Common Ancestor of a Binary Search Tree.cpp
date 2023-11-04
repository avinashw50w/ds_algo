/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]*/

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (! root) return NULL;
    int rval = root->val;
    int pval = p->val;
    int qval = q->val;

    if (pval > rval and qval > rval)
        return lca(root->right, p, q);
    else if (pval < rval and qval < rval)
        return lca(root->left, p, q);
    else
        return root;
}