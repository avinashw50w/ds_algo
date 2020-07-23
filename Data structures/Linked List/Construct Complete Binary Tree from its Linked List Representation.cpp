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
void convertList2Binary(ListNode *head, Node* &root) {

    if (head == NULL)
    {
        root = NULL; // Note that root is passed by reference
        return;
    }

    queue<Node *> q;
    root = newNode(head->data);
    head = head->next;
    q.push(root);

    // until the end of linked list is reached, do the following steps
    while (head)
    {
        // 2.a) take the parent node from the q and remove it from q
        Node* parent = q.front();
        q.pop();

        Node *leftChild = NULL, *rightChild = NULL;

        leftChild = newNode(head->data);
        head = head->next;
        q.push(leftChild);

        if (head)
        {
            rightChild = newNode(head->data);
            head = head->next;
            q.push(rightChild);
        }

        // 2.b) assign the left and right children of parent
        parent->left = leftChild;
        parent->right = rightChild;
    }
}

void inorderTraversal(BinaryTreeNode* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

int main()
{
    // create a linked list shown in above diagram
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    BinaryTreeNode *root;
    convertList2Binary(head, root);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////

/*
The structure of Link list node is as follows
struct node
{
    int data;
    struct node* next;
};

The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/
TreeNode *newNode(int val) {
    TreeNode *tmp = new TreeNode();
    tmp->data = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}
/*You are required to complete this method*/
void convert(node *head,TreeNode * &root)
{
    queue<TreeNode*> q;
    if(head == NULL) {
        root = NULL;
        return;
    }

    root = newNode(head->data);
    head = head->next;
    q.push(root);

    while(head) {
        TreeNode *parent = q.front();
        q.pop();

        TreeNode *lchild = NULL, *rchild = NULL;

        lchild = newNode(head->data);
        head = head->next;
        q.push(lchild);

        if(head) {
            rchild = newNode(head->data);
            head = head->next;
            q.push(rchild);
        }

        parent->left = lchild;
        parent->right = rchild;
    }

}
