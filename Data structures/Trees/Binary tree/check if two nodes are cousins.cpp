/* two nodes x and y are cousins if height[x] = height[y] and parent[x] != parent[y]. Given two nodes find whether they are cousins or not. */

bool checkForNode(Node *root, int x, int h, int p, int &height, int &parent) {
    if (!root) return false;
    if (root->data == x) {
        height = h;
        parent = p;
        return true;
    }
    return checkForNode(root->left, x, h + 1, root->data, height, parent)
           || checkForNode(root->right, x, h + 1, root->data, height, parent);
}


bool check(Node *root, int x, int y) {
    int heightx = 0, parentx = -1;
    bool xexists = checkForNode(root, x, 0, -1, heightx, parentx);

    heighty = 0, parenty = -1;
    bool yexists = checkForNode(root, y, 0, -1, heighty, parenty);

    return (xexists && yexists && heightx == heighty && parentx != parenty);
}