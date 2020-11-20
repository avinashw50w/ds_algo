/*Maximum Consecutive Increasing Path Length in Binary Tree
Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order. Every node is considered as a path of length 1.
Examples:

       10
      /    \
     /      \
    11        9
   / \        /\
  /   \      /  \
13    12    13   8
Maximum Consecutive Path Length is 3 (10, 11, 12)
Note: 10, 9 ,8 is NOT considered since
the nodes should be in increasing order.

      5
          /  \
         /    \
        8      11
        /        \
       /          \
       9    10
      /           /
     /           /
    6           15
Maximum Consecutive Path Length is 2 (8, 9).
We strongly recommend that you click here and code it yourself first, before moving on to the solution.

Every node in the Binary Tree can either become part of the path which is starting from one of its parent node or a new path can start from this node itself. The key is to recursively find the path length for the left and right sub tree and then return the maximum. Some cases need to be considered while traversing the tree which are discussed below.

prev : stores the value of the parent node. Initialize prev with one less than value of root node so that the path starting at root can be of length at least 1.
len : Stores the path length which ends at the parent of currently visited node.

Case 1: Value of Current Node is prev +1
In this case increase the path length by 1, and then recursively find the path length for the left and the right sub tree then return the maximum between two lengths.

Case 2: Value of Current Node is NOT prev+1
A new path can start from this node, so recursively find the path length for the left and the right sub tree. The path which ends at the parent node of current node might be greater than the path which starts from this node.So take the maximum of the path which starts from this node and which ends at previous node.*/

struct Node {
  int val;
  Node *left, *right;
  Node(int val) {
    this->val = val;
    left = right = NULL;
  }
};
// O(N)
void solve(Node *root, int len, int &res) {
  if (!root) return;

  res = max(res, len);

  if (root->left) {
    if (root->left->val - root->val == 1) solve(root->left, len + 1, res);
    else solve(root->left, 1, res);
  }

  if (root->right) {
    if (root->right->val - root->val == 1) solve(root->right, len + 1, res);
    else solve(root->right, 1, res);
  }
}

int maxConsecutivePathLength(Node *root) {
  // passing the root, prev val of root and len
  int res = 0;
  return solve(root, 1, res);
}

///////////////////////////////////////////////
// Returns the maximum consecutive Path Length
int maxPathLenUtil(Node *root, int prev_val, int prev_len)
{
  if (!root)
    return prev_len;

  // Get the value of Current Node
  // The value of the current node will be
  // prev Node for its left and right children
  int cur_val = root->val;

  // If current node has to be a part of the
  // consecutive path then it should be 1 greater
  // than the value of the previous node
  if (cur_val == prev_val + 1)
  {

    // a) Find the length of the Left Path
    // b) Find the length of the Right Path
    // Return the maximum of Left path and Right path
    return max(maxPathLenUtil(root->left, cur_val, prev_len + 1),
               maxPathLenUtil(root->right, cur_val, prev_len + 1));
  }

  // Find length of the maximum path under subtree rooted with this
  // node (The path may or may not include this node)
  int newPathLen = max(maxPathLenUtil(root->left, cur_val, 1),
                       maxPathLenUtil(root->right, cur_val, 1));

  // Take the maximum previous path and path under subtree rooted
  // with this node.
  return  max(prev_len, newPathLen);
}

// A wrapper over maxPathLenUtil().
int maxConsecutivePathLength(Node *root)
{
  // Return 0 if root is NULL
  if (root == NULL)
    return 0;

  // Else compute Maximum Consecutive Increasing Path
  // Length using maxPathLenUtil.
  return maxPathLenUtil(root, root->val - 1, 0);
}
