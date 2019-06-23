// given an array, find for each element a[i] in the array the number of element that are greater than a[i]
// and lies on the right side of it.
//eg input : 2 7 5 3 0 8 1
//output   : 4 1 1 1 2 0 0

#include <bits/stdc++.h>
using namespace std;

void solve1(int a[], int N) {
    int res[N];
    memset(res, 0, sizeof(res));

    multiset<int> s;
    s.insert(a[N-1]);

    for (int i = N-2; i >= 0; --i) {
        res[i] = s.size() - distance(s.begin(), s.lower_bound(a[i]));
        s.insert(a[i]);
    }

    for (int i = 0; i < N; ++i) 
        cout << res[i] <<" ";
}

////////////////////////////////////////
// using AVL tree

struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
    int size; // size of the tree rooted with this node
};
   
int max(int a, int b) {
       return a>b?a:b;
} 

// A utility function to get height of the tree rooted with N
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
    
// A utility function to size of the tree of rooted with N
int size(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->size;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    node->size = 1;
    return(node);
}

// A utility function to right rotate subtree rooted with y
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Update sizes
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Update sizes
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// Inserts a new key to the tree rotted with node. Also, updates *count
// to contain count of smaller elements for the new key
struct node* insert(struct node* node, int key, int &count)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key) {
        node->left  = insert(node->left, key, count);
         // UPDATE COUNT OF SMALLER ELEMENTS FOR KEY
        count = count + size(node->right) + 1;
    }
    else
    {
        node->right = insert(node->right, key, count);
    }
 
 
    /* 2. Update height and size of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
    node->size   = size(node->left) + size(node->right) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}
 

 void solve(int a[], int N){
      
    int i;
    struct node *root = NULL;
    int res[N];
    
    memset(res, 0, sizeof(res));
 
    // Starting from rightmost element, insert all elements one by one in
    // an AVL tree and get the count of smaller elements
    for (i = N-1; i >= 0; i--)
     root = insert(root, a[i], res[i]);
  
  
    for (int i = 0; i < N; ++i) 
        cout << res[i] << " ";
}

 
int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    solve1(a, N);

    return 0;
}
