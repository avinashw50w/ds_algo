Node *RemoveHalfNodes(Node *root)
{
    if (!root) return NULL;

    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);

    if (!root->left and !root->right) return root;

    if (!root->left) {
        Node *tmp = root;
        delete root;
        return tmp->right;
    }
    if (!root->right) {
        Node *tmp = root;
        delete root;
        return tmp->left;
    }
    return root;
}