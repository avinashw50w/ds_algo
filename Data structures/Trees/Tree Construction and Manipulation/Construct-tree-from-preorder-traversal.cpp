/*Given preorder traversal of a binary search tree, construct the BST.

For example, if the given traversal is {10, 5, 1, 7, 40, 50}, then the output should be root of following tree.

     10
   /   \
  5     40
 /  \      \
1    7      50
O(n) recursive solutions.*/

Node *solve(vector<int> pre, int &i, int l, int r) {
    if (i >= pre.size()) return NULL;
    Node *root = NULL;

    if (l < pre[i] and pre[i] < r) {
        root = new Node(pre[i++]);

        root->left = solve(pre, i, l, root->data);
        root->right = solve(pre, i, root->data, r);
    }
}

Node *construct(vector<int> preorder) {
    int i = 0;
    return solve(preorder, i, INT_MIN, INT_MAX);
}


/* O(n) stack based iterative solution //
1. Create an empty stack.

2. Make the first value as root. Push it to the stack.

3. Keep on popping while the stack is not empty and the next value is greater than stack’s top value. Make this value as the right child
of the last popped node. Push the new node to the stack.

4. If the next value is less than the stack’s top value, make this value as the left child of the stack’s top node. Push the new node to the stack.

5. Repeat steps 2 and 3 until there are items remaining in pre[].*/

struct node {
    int data;
    struct node *left, *right;
};

node* ConstructTree(int pre[], int n) {

    stack<node*> s;

    s.push(pre[0]);

    node* tmp, *root = newNode(pre[0]);

    for (int i = 1; i < n; ++i) {

        tmp = NULL;

        /* Keep on popping while the next value is greater than
           stack's top value. */
        while (!s.empty() and s.top() < pre[i]) {
            tmp = s.top();
            s.pop();
        }

        // Make this greater value as the right child and push it to the stack
        if (tmp != NULL) {
            tmp->right = newNode(pre[i]);
            s.push(tmp->right);
        }

        // If the next value is less than the stack's top value, make this value
        // as the left child of the stack's top node. Push the new node to stack
        else {
            (s.top())->left = newNode(pre[i]);
            s.push((s.top())->left);
        }
    }

    return root;
}

//////////////////////////////////////////////////////////////////////////////////////////
// time : O(n^2)
// A recursive function to construct Full from pre[]. preIndex is used
// to keep track of index in pre[].
struct node* constructTreeUtil (int pre[], int* preIndex,
                                int low, int high, int size)
{
    // Base case
    if (*preIndex >= size || low > high)
        return NULL;

    // The first node in preorder traversal is root. So take the node at
    // preIndex from pre[] and make it root, and increment preIndex
    struct node* root = newNode ( pre[*preIndex] );
    *preIndex = *preIndex + 1;

    // If the current subarry has only one element, no need to recur
    if (low == high)
        return root;

    // Search for the first element greater than root
    int i;
    for ( i = low; i <= high; ++i )
        if ( pre[ i ] > root->data )
            break;

    // Use the index of element found in preorder to divide preorder array in
    // two parts. Left subtree and right subtree
    root->left = constructTreeUtil ( pre, preIndex, *preIndex, i - 1, size );
    root->right = constructTreeUtil ( pre, preIndex, i, high, size );

    return root;
}

// The main function to construct BST from given preorder traversal.
// This function mainly uses constructTreeUtil()
struct node *constructTree (int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, &preIndex, 0, size - 1, size);
}

