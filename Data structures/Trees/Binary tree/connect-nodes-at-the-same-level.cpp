/*Write a function to connect all the adjacent nodes at the same level in a binary tree. Structure of the given Binary Tree node is like following.

struct node{
  int data;
  struct node* left;
  struct node* right;
  struct node* nextRight;
}
Run on IDE
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

Example

Input Tree
       A
      / \
     B   C
    / \   \
   D   E   F


Output Tree
       A--->NULL
      / \
     B-->C-->NULL
    / \   \
   D-->E-->F-->NULL                 */

void connet(Node *root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int cnt = q.size();
        Node *prev = NULL, *curr = NULL;

        while (cnt--) {
            *curr = q.front(); q.pop();

            if (prev) prev->nextRight = curr;

            prev = curr;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        curr->nextRight = NULL;
    }
}

//////////////////////////////////////////////////////////////
/*Method 2 (Extend Pre Order Traversal)
This approach works only for Complete Binary Trees. In this method we set nextRight in Pre Order fashion to make sure
that the nextRight of parent is set before its children. When we are at node p, we set the nextRight of its left and
right children. Since the tree is complete tree, nextRight of p’s left child (p->left->nextRight) will always be p’s
right child, and nextRight of p’s right child (p->right->nextRight) will always be left child of p’s nextRight
(if p is not the rightmost node at its level). If p is the rightmost node, then nextRight of p’s right child will be NULL.*/

// Sets the nextRight of root and calls connectRecur() for other nodes
void connect (struct node *p)
{
    // Set the nextRight for root
    p->nextRight = NULL;

    // Set the next right for rest of the nodes (other than root)
    connectRecur(p);
}

/* Set next right of all descendents of p.
   Assumption:  p is a compete binary tree */
void connectRecur(struct node* p)
{
    // Base case
    if (!p)
        return;

    // Set the nextRight pointer for p's left child
    if (p->left)
        p->left->nextRight = p->right;

    // Set the nextRight pointer for p's right child
    // p->nextRight will be NULL if p is the right most child at its level
    if (p->right)
        p->right->nextRight = (p->nextRight) ? p->nextRight->left : NULL;

    // Set nextRight for other nodes in pre order fashion
    connectRecur(p->left);
    connectRecur(p->right);
}

/*Time Complexity: O(n)

Why doesn’t method 2 work for trees which are not Complete Binary Trees?
Let us consider following tree as an example. In Method 2, we set the nextRight pointer in pre order fashion.
When we are at node 4, we set the nextRight of its children which are 8 and 9 (the nextRight of 4 is already set as node 5).
nextRight of 8 will simply be set as 9, but nextRight of 9 will be set as NULL which is incorrect.
We can’t set the correct nextRight, because when we set nextRight of 9, we only have nextRight of
node 4 and ancestors of node 4, we don’t have nextRight of nodes in right subtree of root.

            1
          /    \
        2        3
       / \      /  \
      4   5    6    7
     / \           / \
    8   9        10   11

 */