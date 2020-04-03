/*Given a binary tree we need to check it has heap property or not, Binary tree need to fulfill following two conditions for being a heap –

It should be a complete tree (i.e. all levels except last should be full).
Every node’s value should be greater than or equal to its child node (considering max-heap).

We check each of the above condition separately, for checking completeness isComplete and for checking heap isHeapUtil function are written.
Detail about isComplete function can be found here.

isHeapUtil function is written considering following things –

Every Node can have 2 children, 0 child (last level nodes) or 1 child (there can be at most one such node).
If Node has No child then it’s a leaf node and return true (Base case)
If Node has one child (it must be left child because it is a complete tree) then we need to compare this node with its single child only.
If Node has both child then check heap property at Node at recur for both subtrees.
Complete code.*/

/*  Tree node structure */
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};
 
/* Helper function that allocates a new node */
struct Node *newNode(int k)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}
 
/* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
 
/* This function checks if the binary tree is complete or not */
bool isCompleteUtil (struct Node* root, unsigned int index,
                     unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (true);
 
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
 
    // Recur for left and right subtrees
    return (isCompleteUtil(root->left, 2*index + 1, number_nodes) &&
            isCompleteUtil(root->right, 2*index + 2, number_nodes));
}
 
// This Function checks the heap property in the tree.
bool isHeapUtil(struct Node* root)
{
    //  Base case : leaf node
    if (root->left == NULL && root->right == NULL)
        return (true);
 
    //  node will be in second last level
    if (root->right == NULL)
    {
        //  check heap property at Node
        //  No recursive call , because no need to check last level
        return (root->key >= root->left->key);
    }
    else
    {
        //  Check heap property at Node and
        //  Recursive check heap property at left and right subtree
        if (root->key >= root->left->key && root->key >= root->right->key)
            
            return ((isHeapUtil(root->left)) && (isHeapUtil(root->right)));
        
        else
            return (false);
    }
}
 
//  Function to check binary tree is a Heap or Not.
bool isHeap(struct Node* root)
{
    // These two are used in isCompleteUtil()
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
 
    if (isCompleteUtil(root, index, node_count) && isHeapUtil(root))
        return true;
    return false;
}