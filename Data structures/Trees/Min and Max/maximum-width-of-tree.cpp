
void solve(Node *root, int level, map<int, int> mp) {
  if (!root) return;
  mp[level]++;
  solve(root->left, level + 1, mp);
  solve(root->right, level + 1, mp);
}

int getMaxWidth(Node *root) {
  map<int, int> mp;

  solve(root, 0, mp);

  return (*mp.rbegin()).second;
}

//////////////////////////////////////////////////////
// another way using queue

int getMaxWidth(Node *root) {
  queue<Node*> q;
  q.push(root);
  int ans = 0;

  while (q.size()) {
    int cnt = q.size();
    ans = max(ans, cnt);
    while (cnt--) {
      Node *par = q.front(); q.pop();
      if (par->left) q.push(par->left);
      if (par->right) q.push(par->right);
    }
  }

  return ans;
}
///////////////////////////////////////////////////
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
  return *max_element(arr, arr + h);
}

// A function that fills count array with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(struct node *root, int arr[], int level)
{
  if (root)
  {
    arr[level]++;
    getMaxWidthRecur(root->left, arr, level + 1);
    getMaxWidthRecur(root->right, arr, level + 1);
  }
}