/*Convert a given Binary Tree to Doubly Linked List | Set 4
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are 
to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder 
of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.

								10
							  /    \
							12     15
						  /  \     /
						 25  30   36

		25 <-> 12 <-> 30 <-> 10 <-> 36 <-> 15

In the following implementation, we traverse the tree in inorder fashion. 
We add nodes at the beginning of current linked list 
and update head of the list using pointer to head pointer. 
Since we insert at the beginning, we need to process leaves in reverse order. 
For reverse order, we first traverse the right subtree before the left subtree. i.e. do a reverse inorder traversal.
*/
// Structure for tree and linked list
struct Node
{
    int data;
    Node *left, *right;
};

void BToDLL(Node* root, Node** head_ref)
{
    if (root == NULL)
        return;

    BToDLL(root->right, head_ref);

    root->right = *head_ref;
 
    if (*head_ref != NULL)
        (*head_ref)->left = root;

    *head_ref = root;
 
    BToDLL(root->left, head_ref);
}
 
// Utility function for allocating node for Binary
// Tree.
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
int main()
{
    /* Constructing below tree
               5
             /   \
            3     6
           / \     \
          1   4     8
         / \       / \
        0   2     7   9  */
    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    root->right->right = newNode(8);
    root->left->left->left = newNode(0);
    root->left->left->right = newNode(2);
    root->right->right->left = newNode(7);
    root->right->right->right = newNode(9);
 
    Node* head = NULL;
    BToDLL(root, &head);
 
    printList(head);
 
    return 0;
}