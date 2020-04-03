/*Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is visited from Right side.

Right view of following tree is 1 3 7 8

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
                  \
                   8

The Right view contains all nodes that are last nodes in their levels. A simple solution 
is to do level order traversal and print the last node in every level.

The problem can also be solved using simple recursive traversal. We can keep track of level of a node by 
passing a parameter to all recursive calls. The idea is to keep track of maximum level also. 
And traverse the tree in a manner that right subtree is visited before left subtree. 
Whenever we see a node whose level is more than maximum level so far, we print the node because this is the 
last node in its level (Note that we traverse the right subtree before left subtree).*/

// Recursive function to print right view of a binary tree.
void rightViewUtil(struct Node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the last Node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
////////////////////////////////////////////////////////////////////////
// left view //

void print(Node *root, int lvl, int& max_lvl) {
    if(root == NULL) return;
    
    if(max_lvl < lvl) {
        cout << root->data <<" ";
        max_lvl = lvl;
    }
    print(root->left, lvl+1, max_lvl);
    print(root->right, lvl+1, max_lvl);
}
// A wrapper over leftViewUtil()
void leftView(struct Node *root)
{
   int max_lvl = 0;
   print(root, 1, max_lvl);
}
