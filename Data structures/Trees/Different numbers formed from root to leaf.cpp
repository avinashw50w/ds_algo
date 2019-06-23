/*Sum of all the numbers that are formed from root to leaf paths
Given a binary tree, where every node value is a Digit from 1-9 .Find the sum of all the numbers which are formed from root to leaf paths.
For example consider the following Binary Tree.

                                          6
                                      /      \
                                    3          5
                                  /   \          \
                                 2     5          4  
                                      /   \
                                     7     4
  There are 4 leaves, hence 4 root to leaf paths:
   Path                    Number
  6->3->2                   632
  6->3->5->7               6357
  6->3->5->4               6354
  6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997 */

int solve(Node *root, int val) {
    if (!root) return 0;

    val = val*10 + root->data;

    if (!root->left and !root->right) return val;

    return solve(root->left, val) + solve(root->right, val);
}

int sum(Node *root) {
    if (!root) return 0;

    return solve(root, 0);
}