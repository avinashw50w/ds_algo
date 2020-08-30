void Mirror(node* root) {
    if (root == NULL) return;
    Mirror(root->left);
    Mirror(root->right);
    swap(root->left, root->right);
}

/////////////////////////////////
// another method
Node *solve(Node *n) {
    if (!n) return NULL;
    Node *l = n->left;
    Node *r = n->right;
    n->left = solve(r);
    n->right = solve(l);
    return n;
}


//////////////////////////////////

// check if two trees a and b are similar or not
bool sameTree(node* a, node* b) {
    if (!a and !b) return true;
    if (!a or !b) return false;

    return (a->data == b->data and sameTree(a->left, b->left) and sameTree(a->right, b->right));
}
