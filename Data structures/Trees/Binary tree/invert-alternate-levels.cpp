/*Invert alternate levels of a perfect binary tree*/
// store nodes in a queue and their values in a stack


void invert(Node *root) {
    if (!root) return;

    queue<Node*> q;
    queue<Node*> nodes;
    stack<int> values;

    int invert = false;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        while (n--) {
            Node *curr = q.front();
            q.pop();

            if (invert) {
                nodes.push(curr);
                values.push(curr->data);
            }

            if (n == 0) {
                invert ^= 1;

                while (!nodes.empty()) {
                    Node * tmp = nodes.front();
                    tmp->data = values.top();

                    nodes.pop();
                    values.pop();
                }
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }    
}

