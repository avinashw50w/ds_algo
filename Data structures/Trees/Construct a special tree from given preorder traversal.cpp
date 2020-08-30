/*Construct a special tree from given preorder traversal
Last Updated: 10-02-2020
Given an array ‘pre[]’ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children. One more array ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]’ indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node. Write a function to construct the tree from the given two arrays.

Example:

Input:  pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
Output: Root of following tree
          10
         /  \
        30   15
       /  \
      20   5
*/

Node *solve(vector<int> pre, vector<int> preLN, int &idx) {
    if (idx == pre.size()) return NULL;
    int i = idx;
    Node *node = newNode(pre[i]);
    idx++;

    if (preLN[i] == 'N') {
        node->left = solve(pre, preLN, idx);
        node->right = solve(pre, preLN, idx);
    }

    return node;
}

Node *construct(vector<int> pre, vector<int> preLN) {
    int i = 0;
    return solve(pre, preLN, i);
}