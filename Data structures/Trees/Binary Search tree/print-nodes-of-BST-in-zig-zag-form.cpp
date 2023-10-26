 
// Binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

vector<vector<Node>> printSpiral(Node *root) {
    deque<Node*> q;
    q.push_back(root);
    bool order = false;
    vector<vector<Node>> res;
    
    while (!q.empty()) {
        vector<Node> level;
        int cnt = q.size();
        
        while (cnt--) {
            if (!order) {
                Node *par = q.front(); q.pop_front();
                level.push_back(par);
                if (par->left) q.push(par->left);
                if (par->right) q.push(par->right);
            } else {
                Node *par = q.back(); q.pop_back();
                level.push_back(par);
                if (par->right) q.push(par->right);
                if (par->left) q.push(par->left);
            }
        }
        order ^= 1;
        res.push_back(level);
    }

    return res;
}

/////////////////////////////////////
/*Method 2 (Iterative)
We can print spiral order traversal in O(n) time and O(n) extra space. The idea is to use two stacks. We can use one stack for printing from left to right and 
other stack for printing from right to left. In every iteration, we have nodes of one level in one of the stacks. We print the nodes, and push nodes of next 
level in other stack.*/
 
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