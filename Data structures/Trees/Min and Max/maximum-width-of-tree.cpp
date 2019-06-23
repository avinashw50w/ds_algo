 
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(struct node* root)
{
  int width;
  int h = height(root);
 
  // Create an array that will store count of nodes at each level
  int *arr = (int *)calloc(sizeof(int), h);
 
  int level = 0;
 
  // Fill the arr array using preorder traversal
  getMaxWidthRecur(root, arr, level);
 
  // Return the maximum value from count array
  return *max_element(arr, arr+h);
}
 
// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int arr[], int level)
{
  if(root)
  {
    arr[level]++;
    getMaxWidthRecur(root->left, arr, level+1);
    getMaxWidthRecur(root->right, arr, level+1);
  }
}