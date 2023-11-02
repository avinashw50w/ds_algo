/*Given Linked List Representation of Complete Binary Tree, construct the Binary tree. A complete binary tree can be represented in an array in the following approach.
eg, 		10 -> 12 -> 15 -> 25 -> 30 -> 36

							10
						   /   \
						  12    15
						/  \    /
					   25  30  36

If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2 respectively.

1. Create an empty queue.
2. Make the first node of the list as root, and enqueue it to the queue.
3. Until we reach the end of the list, do the following.
………a. Dequeue one node from the queue. This is the current parent.
………b. Traverse two nodes in the list, add them as children of the current parent.
………c. Enqueue the two nodes into the queue.

*/

// converts a given linked list representing a complete binary tree into the
// linked representation of binary tree.


/*
The structure of Link list node is as follows 
struct node
{
    int data;
    struct node* next;
};

The structure of TreeNode is as follows

*/
/*TreeNode *newNode(int val) {
    TreeNode *tmp = new TreeNode();
    tmp->data = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}*/
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};

/*You are required to complete this method*/
void convert(node *head,TreeNode * &root)
{
    queue<TreeNode*> q;
    if(head == NULL) {
        root = NULL;
        return;
    }
  
    root = new TreeNode(head->data);
    head = head->next;
    q.push(root);
    
    while(head) {
        TreeNode *parent = q.front();
        q.pop();
        
        TreeNode *lchild = NULL, *rchild = NULL;
        
        lchild = new TreeNode(head->data);
        q.push(lchild);
        head = head->next;
        
        if(head) {
            rchild = new TreeNode(head->data);
            q.push(rchild);
            head = head->next;
        }
        
        parent->left = lchild;
        parent->right = rchild;
    }

}


