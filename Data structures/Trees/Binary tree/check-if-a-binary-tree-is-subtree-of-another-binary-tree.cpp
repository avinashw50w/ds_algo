/*Check if a binary tree is subtree of another binary tree | Set 1
Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S
consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire tree;
the subtree corresponding to any other node is called a proper subtree.

For example, in the following case, tree S is a subtree of tree T.

        Tree 2
          10
        /    \
      4       6
       \
        30


        Tree 1
              26
            /   \
          10     3
        /    \     \
      4       6      3
       \
        30
Solution: Traverse the tree T in preorder fashion. For every visited node in the traversal,
see if the subtree rooted with this node is identical to S.*/
// time: O(n^2)
bool areIdentical(struct node* root1, struct node* root2)
{
  /* base cases */
  if (root1 == NULL && root2 == NULL)
    return true;

  if (root1 == NULL || root2 == NULL)
    return false;

  /* Check if the data of both roots is same and data of left and right
     subtrees are also same */
  return (root1->data == root2->data   &&
          areIdentical(root1->left, root2->left) &&
          areIdentical(root1->right, root2->right) );
}


/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(struct node *T, struct node *S)
{
  /* base cases */
  if (S == NULL)
    return true;

  if (T == NULL)
    return false;

  /* Check the tree with root as current node */
  if (areIdentical(T, S))
    return true;

  /* If the tree with root as current node doesn't match then
     try left and right subtrees one by one */
  return isSubtree(T->left, S) ||
         isSubtree(T->right, S);
}

//////////////////////////////////////////////////////////////////////////////
// Time: O(n)
/*We have discussed a O(n2) solution for this problem. In this post a O(n) solution is discussed.
The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree.
Tree S is a subtree of T if both inorder and preorder traversals of S arew substrings of inorder and preorder traversals of T respectively.

Following are detailed steps.

1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].

2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].

3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.

We can also use postorder traversal in place of preorder in the above algorithm.

Let us consider the above example

Inorder and Preorder traversals of the big tree are.
inT[]   =  {a, c, x, b, z, e, k}
preT[]  =  {z, x, a, c, b, e, k}

Inorder and Preorder traversals of small tree are
inS[]  = {a, c, x, b}
preS[] = {x, a, c, b}

We can easily figure out that inS[] is a subarray of
inT[] and preS[] is a subarray of preT[]. */


bool isSubtree(Node *T, Node *S) {

  if (S == NULL) return true;
  if (T == NULL) return false;

  char inT[100], inS[100];

  int i = 0, j = 0;

  inorder(T, inT, i);
  inorder(S, inS, j);

  inT[i] = '\0';
  inS[j] = '\0';

  // Note that you have to use KMP instead of strstr to make the running time O(n)
  if (strstr(inT, inS) == NULL) return false;

  i = j = 0;
  char preT[100], preS[100];

  preoder(T, preT, i);
  preorder(S, preS, j);

  preT[i] = '\0';
  preS[j] = '\0';

  if (strstr(preT, preS) == NULL) return false;

  return true;
}

void inorder(Node *root, char a[], int &i) {
  if (root == NULL) return;
  inorder(root->left, a, i);
  a[i++] = root->data;
  inorder(root->right, a, i);
}

void preorder(Node *root, char a[], int &i) {
  if (root == NULL) return;
  a[i++] = root->data;
  preorder(root->left, a, i);
  preorder(root->right, a, i);
}

///////////////////////////////////////////////////////////////////
// using serialization
/*
            A        after serialization
          /   \     ====================>  AB$$C$$
         B     c
 */
string serialize(Node *root) {
  string s = "";
  if (!root) {
    s += "$";
    return s;
  }

  return s + to_string(root->data) + serialize(root->left) + serialize(root->right);
}

string check(Node *root, string str) {
  string s = "";
  if (!root) {
    s += "$";
    return s;
  }

  string left = check(root->left, str);
  if (left == "") return "";

  string right = check(root->right, str);
  if (right == "") return "";

  s += to_string(root->data) + left + right;

  if (s == str) return "";

  return s;
}

bool isSubtree(struct node *T, struct node *S)
{
  /* base cases */
  if (S == NULL)
    return true;

  if (T == NULL)
    return false;

  string subtree = serialize(S);
  string chk = check(T, subtree);
  if (chk == "") return true;
  return false;
}