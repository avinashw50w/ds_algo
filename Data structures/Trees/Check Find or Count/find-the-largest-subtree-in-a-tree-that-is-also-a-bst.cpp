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
 
/* Returns size of the largest BST subtree in a Binary Tree
  (efficient version). */
int largestBST(Node* node)
{
  // Set the initial values for calling largestBSTUtil()
  int mini = INT_MAX;  // For minimum value in right subtree
  int maxx = INT_MIN;  // For maximum value in left subtree
 
  int maxSize = 0;  // For size of the largest BST
  bool is_bst = 0;
 
  largestBSTUtil(node, mini, maxx, maxSize, is_bst);
 
  return maxSize;
}

int largestBSTUtil(Node* node, int &mini, int &maxx,
                            int &maxSize, bool &is_bst)
{
 
  /* Base Case */
  if (node == NULL)
  {
     is_bst = 1; // An empty tree is BST
     return 0;    // Size of the BST is 0
  }
 
  int minimum = INT_MAX;
 
  /* A flag variable for left subtree property
     i.e., maximum(root->left) < root->data */
  bool left_flag = false;
 
  /* A flag variable for right subtree property
     i.e., minimum(root->right) > root->data */
  bool right_flag = false;
 
  int ls, rs; // To store sizes of left and right subtrees
 
  /* Following tasks are done by recursive call for left subtree
    a) Get the maximum value in left subtree (Stored in *maxx)
    b) Check whether Left Subtree is BST or not (Stored in *is_bst)
    c) Get the size of maximum size BST in left subtree (updates *maxSize) */
  maxx = INT_MIN;
  ls = largestBSTUtil(node->left, mini, maxx, maxSize, is_bst);
  if (is_bst == 1 && node->data > maxx)
     left_flag = true;
 
  /* Before updating *mini, store the minimum value in left subtree. So that we
     have the correct minimum value for this subtree */
  minimum = mini;
 

  mini =  INT_MAX;
  rs = largestBSTUtil(node->right, mini, maxx, maxSize, is_bst);
  if (is_bst == 1 && node->data < mini)
     right_flag = true;
 
  // Update minimum and maximum values for the parent recursive calls
  if (minimum < mini)
     mini = minimum;
  if (node->data < mini) // For leaf nodes
     mini = node->data;
  if (node->data > maxx)
     maxx = node->data;
 
  /* If both left and right subtrees are BST. And left and right
     subtree properties hold for this node, then this tree is BST.
     So return the size of this tree */
  if(left_flag && right_flag)
  {
     if (ls + rs + 1 > maxSize)
         maxSize = ls + rs + 1;
     return ls + rs + 1;
  }
  else
  {
    //Since this subtree is not BST, set is_bst flag for parent calls
     is_bst = 0; 
     return 0;
  }
}
 