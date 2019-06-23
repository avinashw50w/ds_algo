/*Given Inorder Traversal of a Special Binary Tree in which key of every node is greater 
than keys in left and right children, construct the Binary Tree and return root.

Examples:

Input: inorder[] = {5, 10, 40, 30, 28}
Output: root of following tree
         40
       /   \
      10     30
     /         \
    5          28 

Input: inorder[] = {1, 5, 10, 40, 30, 
                    15, 28, 20}
Output: root of following tree
          40
        /   \
       10     30
      /         \
     5          28
    /          /  \
   1         15    20
The idea used in Construction of Tree from given Inorder and Preorder traversals can be used here. 
Let the given array is {1, 5, 10, 40, 30, 15, 28, 20}. The maximum element in given array must be root. 
The elements on left side of the maximum element are in left subtree and elements on right side are in right subtree.

         40
      /       \  
   {1,5,10}   {30,15,28,20}
We recursively follow above step for left and right subtrees, and finally get the following tree.

          40
        /   \
       10     30
      /         \
     5          28
    /          /  \
   1         15    20
Algorithm: buildTree()
1) Find index of the maximum element in array. The maximum element must be root of Binary Tree.
2) Create a new tree node ‘root’ with the data as the maximum value found in step 1.
3) Call buildTree for elements before the maximum element and make the built tree as left subtree of ‘root’.
5) Call buildTree for elements after the maximum element and make the built tree as right subtree of ‘root’.
6) return ‘root’.*/
 
/* Recursive function to construct binary of size len from
   Inorder traversal inorder[]. Initial values of start and end
   should be 0 and len -1.  */
struct node* buildTree (int inorder[], int start, int end)
{
    if (start > end)
        return NULL;
 
    /* Find index of the maximum element from Binary Tree */
    int i = max (inorder, start, end);
 
    /* Pick the maximum value and make it root */
    struct node *root = newNode(inorder[i]);
 
    /* If this is the only element in inorder[start..end],
       then return it */
    if (start == end)
        return root;
 
    /* Using index in Inorder traversal, construct left and
       right subtress */
    root->left  = buildTree (inorder, start, i-1);
    root->right = buildTree (inorder, i+1, end);
 
    return root;
}
 
/* UTILITY FUNCTIONS */
/* Function to find index of the maximum value in arr[start...end] */
int max (int arr[], int strt, int end)
{
    int i, max = arr[strt], maxind = strt;
    for(i = strt+1; i <= end; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}