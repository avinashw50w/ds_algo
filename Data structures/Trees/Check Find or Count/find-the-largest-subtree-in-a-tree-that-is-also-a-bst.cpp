/*Method 1 (Simple but inefficient)
Start from root and do an inorder traversal of the tree. For each node N, check whether the subtree rooted with N is BST or not.
If BST, then return size of the subtree rooted with N. Else, recur down the left and right subtrees and return the maximum of
values returned by left and right subtrees.*/

int largestBST(struct node *root)
{
  if (isBST(root))
    return size(root);
  else
    return maximum(largestBST(root->left), largestBST(root->right));
}

/*Time Complexity: The worst case time complexity of this method will be O(n^2).*/

/*Method 2 (Tricky and Efficient)
In method 1, we traverse the tree in top down manner and do BST test for every node. If we traverse the tree in bottom up manner,
then we can pass information about subtrees to the parent. The passed information can be used by the parent to do BST test (for parent node)
only in constant time (or O(1) time). A left subtree need to tell the parent whether it is BST or not and also need to pass maximum value in it.
So that we can compare the maximum value with the parent’s data to check the BST property. Similarly, the right subtree need to pass the
minimum value up the tree. The subtrees need to pass the following information up the tree for the finding the largest BST.
1) Whether the subtree itself is BST or not (In the following code, is_bst is used for this purpose)
2) If the subtree is left subtree of its parent, then maximum value in it. And if it is right subtree then minimum value in it.
3) Size of this subtree if this subtree is BST (In the following code, return value of largestBSTtil() is used for this purpose)

maxx is used for passing the maximum value up the tree and min_ptr is used for passing minimum value up the tree.*/

int largetBST(Node *root) {
  int mn = INT_MAX, mx = INT_MIN;
  int maxsize = 0, isBST = 0;

  solve(root, mn, mx, maxsize, isBST);

  return maxsize;
}

int solve(Node *node, int &mn, int &mx, int &maxsize, int &isBST) {
  if (!node) {
    isBST = 1;
    return 0;
  }

  bool left = false, right = false;

  mx = INT_MIN;
  int ls = solve(node->left, mn, mx, maxsize, isBST);
  // if left subtree is a bst and root data > maximum in its left subtree
  if (isBST and root->data > mx) left = true;

  int mini = mn;
  mn = INT_MAX;

  int rs = solve(node->right, mn, mx, maxsize, isBST);
  // if right subtree is a BST and root data < minimum in its right subtree
  if (isBST and root->data < mn) right = true;

  mn = min(mn, mini);
  mn = min(mn, root->data);
  mx = max(mx, root->data);
  /* If both left and right subtrees are BST. And left and right
     subtree properties hold for this node, then this tree is BST.
     So return the size of this tree */
  if (left and right) {
    maxsize = max(maxsize, ls + rs + 1);
    return ls + rs + 1;
  }
  else {
    isBST = 0;
    return 0;
  }
}

