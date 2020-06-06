/* two nodes x and y are cousins if height[x] = height[y] and parent[x] != parent[y]. Given two nodes find whether they are cousins or not. */

bool checkForNode(Node *root, int x) {
    if (!root) return false;
    return root->data == x || checkForNode(root->left, x) || checkForNode(root->right, x);
}

bool check(Node *root, int x, int y) {
    int heightx = 0, parentx = -1;
    bool xexists = checkForNode(root, x, heightx, parentx);

    int heighty = 0, parenty = -1;
    bool yexists = checkForNode(root, y, heighty, parenty);

    return (xexists && yexists && heightx == heighty && parentx != parenty);
}