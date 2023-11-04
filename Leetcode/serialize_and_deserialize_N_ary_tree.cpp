/*
                                    A
                                /   |   \
                               B    C    D
                             /   \      
                            E     F
                                  |
                                  K


 */

void solve(Node *root) {
    string s = "";

    serialize(root, s);

    Node *root2 = NULL;
    deserialize(root2, s, 0);
}

void serialize(Node *root, string &s) {
    if (!root) return;

    s += root->data;

    for (int i = 0; i < N and root->child[i]; ++i) {
        serialize(root->child[i], s);
    }

    s += '#';
}

int deserialize(Node *&root, int s, int &idx) {

    if (idx > s.size() or s[idx] == '#') return 1;

    root = newNode(s[idx++]);

    for (int i = 0; i < N; ++i) {
        if (deserialize(root->child[i], s, idx)) break;
    } 

    return 0;
}