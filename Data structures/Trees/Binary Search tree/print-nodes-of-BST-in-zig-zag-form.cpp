/*Method 2 (Iterative)
We can print spiral order traversal in O(n) time and O(n) extra space. The idea is to use two stacks. We can use one stack for printing from left to right and 
other stack for printing from right to left. In every iteration, we have nodes of one level in one of the stacks. We print the nodes, and push nodes of next 
level in other stack.*/
 
// Binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

void printSpiral(Node *root) {
    queue<Node*> q;
    q.push(root);
    bool order = false;
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            Node *par = q.front(); q.pop();
            cout << par->data << " ";
            if (!order) {
                if (par->left) q.push(par->left);
                if (par->right) q.push(par->right);
            } else {
                if (par->right) q.push(par->right);
                if (par->left) q.push(par->left);
            }
        }
        order ^= 1;
        cout << endl;
    }
}

/////////////////////////////////////
 
void printSpiral(struct Node *root)
{
    if (root == NULL)  return;   // NULL check
 
    // Create two stacks to store alternate levels
    stack<struct Node*> s1;  // For levels to be printed from right to left
    stack<struct Node*> s2;  // For levels to be printed from left to right
 
    // Push first level to first stack 's1'
    s1.push(root);
 
    // Keep ptinting while any of the stacks has some Nodes
    while (!s1.empty() || !s2.empty())
    {
        // Print Nodes of current level from s1 and push Nodes of
        // next level to s2
        while (!s1.empty())
        {
            struct Node *temp = s1.top();
            s1.pop();
            cout << temp->data << " ";
 
            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
 
        // Print Nodes of current level from s2 and push Nodes of
        // next level to s1
        while (!s2.empty())
        {
            struct Node *temp = s2.top();
            s2.pop();
            cout << temp->data << " ";
 
            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}