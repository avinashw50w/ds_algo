/* How to determine if a binary tree is height-balanced?
A tree where no leaf is much farther away from the root than any other leaf. Different balancing schemes allow different definitions of “much farther”
and different amounts of work to keep them balanced.

Consider a height-balancing scheme where following conditions should be checked to determine if a binary tree is balanced.
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.  */


// time: O(n)
struct Node
{
    int data;
    Node *left, *right;
};

//main function
bool isBalanced(Node *n)
{
    if (balancedHeight(n) > -1) return true;

    return false;
}

// returns the height of the subtree rooted at n if the subtree is balanced otherwise returns -1
int balancedHeight(Node *n)
{
    if (n == NULL) return 0;

    int h1 = balancedHeight(n -> left);
    int h2 = balancedHeight(n -> right);

    if (h1 == -1 or h2 == -1) return -1;

    if (abs(h1 - h2) > 1) return -1;

    return 1 + max(h1, h2);
}

////////////////////////////////////////////////////////////////////////////////////////////////

bool isBalanced(struct Node *root, int &height) {
    int lh = 0, rh = 0;
    int l = 0, r = 0;

    if (root == NULL) {
        height = 0;
        return 1;
    }

    l = isBalanced(root->left, lh); // check if left subtree is balanced
    r = isBalanced(root->right, rh); // check if right subtree is balanced

    height = 1 + max(lh, rh);

    if (abs(lh - rh) > 1) return 0;

    return l && r;
}

//////////////////////////////////////////////////////////////////////////////

/* Returns true if binary tree with root as root is height-balanced */
// O(n^2)
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(struct node *root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return true;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if ( abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    /* If we reach here then tree is not height-balanced */
    return false;
}


