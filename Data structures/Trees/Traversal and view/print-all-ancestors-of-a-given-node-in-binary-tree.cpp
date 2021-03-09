/*Print Ancestors of a given node in Binary Tree
Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree.

For example, if the given tree is following Binary Tree and key is 7, then your function should print 4, 2 and 1.


              1
            /   \
          2      3
        /  \
      4     5
     /
    7
*/


bool solve(Node *root, int target) {
  if (root) {
    if (root->data == target or solve(root->left, target) or solve(root->right, target)) {
      cout << root->data << " ";
      return true;
    }
  }
  return false;
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                      malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

/* Driver program to test above functions*/
int main()
{

  /* Construct the following binary tree
              1
            /   \
          2      3
        /  \
      4     5
     /
    7
  */
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5);
  root->left->left->left  = newnode(7);

  solve(root, 7);

  getchar();
  return 0;
}
/*
Output:
4 2 1

Time Complexity: O(n) where n is the number of nodes in the given Binary Tree.*/