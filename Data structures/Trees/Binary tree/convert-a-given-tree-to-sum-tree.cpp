/*Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

                  10
               /      \
             -2        6
           /   \      /  \
         8     -4    7    5
should be changed to

                 20(4-2+12+6)
                  /      \
             4(8-4)      12(7+5)
              /   \      /   \
             0     0    0     0*/

struct Node {
  int data;
  Node *left, *right;
  Node (int data) {
    this->data = data;
    left = right = NULL;
  }
};

int solve(Node *node) {
  if (!node) return 0;

  int ls = solve(node->left);
  int rs = solve(node->right);

  int node_data = node->data;
  node->data = ls + rs;

  return node_data + ls + rs;
}


////////////////////////////////////////////////
// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(struct node *node)
{
  // Base case
  if (node == NULL)
    return 0;

  // Store the old value
  int old_val = node->data;

  // Recursively call for left and right subtrees and store the sum as
  // new value of this node
  node->data = toSumTree(node->left) + toSumTree(node->right);

  // Return the sum of values of nodes in left and right subtrees and
  // old_value of this node
  return node->data + old_val;
}
// Note : to make the tree such that the node's value is equal to
// its current value + sum of the values of its left and right subrees, like this eg :
/*
          30(10+4-2+12+6)
                  /      \
             2(8-4-2)      18(7+5+6)
              /   \      /   \
             8    -4    7    5


then instread of returning node->data + old_val, return node->data += old_val.

*/
