/* Calculate the "DepthSum" which is the sum of depths of all the nodes of a binary tree with respect to root. Root is at depth 0 
eg.           1
            /   \
           2     3
         /  \   /  \
        4    5  6   7
      /  \
     8    9 

Answer = 16
*/

struct Node {
    int val;
    Node *left, *right;
};

int ans = 0;

void solve(Node *root, int depth) {
    if (!root) return 0;
    ans += depth;
    solve(root->left, depth + 1);
    solve(root->right, depth + 1);
}

int sumDepths(Node *root) {
    solve(root, 0);
    return ans;
}

///////////////////////////////////////////////
// Follow up: Find the DepthSum of all the subtrees, ie calculate DepthSum(1) + DepthSum(2) + ... DepthSum(9)
// Answer = 26 , for the above example tree
// For any node n:
// p.first = the DepthSum of the subtree rooted at n
// p.second = the no of nodes in the subtree rooted at n
// eg. DepthSum(1) = (DepthSum(2) + no of nodes in subtree rooted at 2) + (DepthSum(3) + no of nodes in subtree rooted at 3)


int ans = 0;

pair<int,int> solve(Node *root) {
    pair<int,int> p = {0, 1};

    if (root->left) {
        pair<int,int> pchild = solve(root->left);
        p.first += pchild.first + pchild.second;
        p.second += pchild.second;
    }

    if (root->right) {
        pair<int,int> pchild = solve(root->right);
        p.first += pchild.first + pchild.second;
        p.second += pchild.second;
    }

    ans += p.second;
    return p;
}

///////////////////////////////////////////////////
//Follow up: Given a target node x, find the sumDepth of the tree where x is treated as the root.
// sumDepth(u) = sumDepth(par[u]) - (no of nodes in the subtree rooted at x) + (no of nodes outside the subtree rooted at x)
// eg. in the example tree, if 2 is the root then sumDepth(2) = sumDepth(1) - (no of nodes in the subtree rooted at 2) + (no of nodes outside the subtree rooted at 2)
// because when 2 is the root, all the nodes in the subtree of 2 will have their depths decreased by 1, and all the nodes outside the subtree
// will have their depths increased by 1.

// p.first = the DepthSum of the subtree rooted at n
// p.second = the no of nodes in the subtree rooted at n
int ans = 0;
int totalSize = 0;

struct Node {
    int data;
    Node *left, *right;
    int size;
}

pair<int,int> dfs(Node *root) {
    if (!root) return {0,0};
    pair<int,int> p = {0,1};

    pair<int,int> lchild = dfs(root->left);
    pair<int,int> rchild = dfs(root->right);

    p.first += (lchild.first + lchild.second) + (rchild.first + rchild.second);
    p.second += (lchild.second + rchild.second);
    root->size = p.second;
    return p;
}

void dfs2(Node *root, Node *target, int sumDepth) {
    if (root == target) {
        ans = sumDepth;
        return;
    }

    if (root->left) {
        int newSumDepth = sumDepth - root->left->size + (totalSize - root->left->size);
        dfs2(root->left, target, newSumDepth);
    }

    if (root->right) {
        int newSumDepth = sumDepth - root->right->size + (totalSize - root->right->size);
        dfs2(root->right, target, newSumDepth);
    }
}

int solve(Node *root, Node *target) {
    pair<int,int> p = dfs(root);

    int sumDepth = p.first;
    totalSize = p.second;

    dfs2(root, target, sumDepth);

    return ans;
}