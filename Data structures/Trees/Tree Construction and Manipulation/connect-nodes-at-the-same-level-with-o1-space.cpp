/*Connect nodes at same level using constant extra space
Write a function to connect all the adjacent nodes at the same level in a binary tree. Structure of the given Binary Tree node is like following.

struct node {
  int data;
  struct node* left;
  struct node* right;
  struct node* nextRight;
}
Run on IDE
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node. 
You can use only constant extra space.

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
   D-->E-->F-->NULL
We discussed two different approaches to do it in the previous post. The auxiliary space required in both of 
those approaches is not constant. Also, the method 2 discussed there only works for complete Binary Tree.

In this post, we will first modify the method 2 to make it work for all kind of trees. After that, we will 
remove recursion from this method so that the extra space becomes constant.

A Recursive Solution
In the method 2 of previous post, we traversed the nodes in pre order fashion. Instead of traversing in 
Pre Order fashion (root, left, right), if we traverse the nextRight node before the left and right children 
(root, nextRight, left), then we can make sure that all nodes at level i have the nextRight set, before the 
level i+1 nodes. Let us consider the following example (same example as previous post). The method 2 fails 
for right child of node 4. In this method, we make sure that all nodes at the 4’s level (level 2) have nextRight set, 
before we try to set the nextRight of 9. So when we set the nextRight of 9, we search for a nonleaf node on 
right side of node 4 (getNextRight() does this for us).

            1            -------------- Level 0
          /    \
        2        3       -------------- Level 1
       / \      /  \
      4   5    6    7    -------------- Level 2
     / \           / \
    8   9        10   11 -------------- Level 3*/
 
// Sets the nextRight of root and calls connectRecur() for other nodes
void connect (struct node *p)
{
    // Set the nextRight for root
    p->nextRight = NULL;
 
    // Set the next right for rest of the nodes (other than root)
    connectRecur(p);
}
 
/* Set next right of all descendents of p. This function makes sure that
nextRight of nodes ar level i is set before level i+1 nodes. */
void connectRecur(struct node* p)
{
    // Base case
    if (!p)
       return;
 
    /* Before setting nextRight of left and right children, set nextRight
    of children of other nodes at same level (because we can access 
    children of other nodes using p's nextRight only) */
    if (p->nextRight != NULL)
       connectRecur(p->nextRight);
 
    /* Set the nextRight pointer for p's left child */
    if (p->left)
    {
       if (p->right)
       {
           p->left->nextRight = p->right;
           p->right->nextRight = getNextRight(p);
       }
       else
           p->left->nextRight = getNextRight(p);
 
       /* Recursively call for next level nodes.  Note that we call only
       for left child. The call for left child will call for right child */
       connectRecur(p->left);
    }
 
    /* If left child is NULL then first node of next level will either be
      p->right or getNextRight(p) */
    else if (p->right)
    {
        p->right->nextRight = getNextRight(p);
        connectRecur(p->right);
    }
    else
       connectRecur(getNextRight(p));
}
 
/* This function returns the leftmost child of nodes at the same level as p.
   This function is used to getNExt right of p's right child
   If right child of p is NULL then this can also be used for the left child */
struct node *getNextRight(struct node *p)
{
    struct node *temp = p->nextRight;
 
    /* Traverse nodes at p's level and find and return
       the first node's first child */
    while(temp != NULL)
    {
        if(temp->left != NULL)
            return temp->left;
        if(temp->right != NULL)
            return temp->right;
        temp = temp->nextRight;
    }
 
    // If all the nodes at p's level are leaf nodes then return NULL
    return NULL;
}