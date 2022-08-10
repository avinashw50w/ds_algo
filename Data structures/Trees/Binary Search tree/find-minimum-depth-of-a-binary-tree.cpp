int ans = INT_MAX;
void minDepth(Node *root, int d) {
    if (!root) {
         return;
    }
 
    if (!root->left and !root->right) {
      ans = min(ans, d);
      return;
    }
 
    // If left subtree is NULL, recur for right subtree
    minDepth(root->left, d + 1);
    minDepth(root->right, d + 1);
}

/*A Better Solution is to do Level Order Traversal. While doing traversal, returns depth of the first encountered leaf node.*/
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A queue item (Stores pointer to node and an integer)
struct qItem
{
   Node *node;
   int depth;
};
 
// Iterative method to find minimum depth of Bianry Tree
int minDepth(Node *root)
{
    // Corner Case
    if (root == NULL)
        return 0;
 
    // Create an empty queue for level order tarversal
    queue<qItem> q;
 
    // Enqueue Root and initialize depth as 1
    qItem qi = {root, 1};
    q.push(qi);
 
    // Do level order traversal
    while (q.empty() == false)
    {
       // Remove the front queue item
       qi = q.front();
       q.pop();
 
       // Get details of the remove item
       Node *node = qi.node;
       int depth = qi.depth;
 
       // If this  is the first leaf node seen so far
       // Then return its depth as answer
       if (node->left == NULL && node->right == NULL)
          return depth;
 
       // If left subtree is not NULL, add it to queue
       if (node->left != NULL)
       {
          qi.node  = node->left;
          qi.depth = depth + 1;
          q.push(qi);
       }
 
       // If right subtree is not NULL, add it to queue
       if (node->right != NULL)
       {
          qi.node  = node->right;
          qi.depth = depth+1;
          q.push(qi);
       }
    }
    return 0;
}