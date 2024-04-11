struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        this->data = val;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> inorder, vector<int> preorder) {
    int n = inorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[inorder[i]] = i;
    int preIndex = 0;
    solve(inorder, preorder, mp, preIndex, 0, n - 1);
}

Node *solve(vector<int> in, vector<int> pre, unordered_map<int> mp, int &pi, int l, int r) {
    if (l > r) return NULL;
    Node *node = new Node(pre[pi++]);
    if (l == r) return node;

    int inIndex = mp[node->data];

    node->left = solve(in, pre, mp, pi, l, inIndex - 1);
    node->right = solve(in, pre, mp, pi, inIndex + 1, r);

    return node;
}

/*Let us consider the below traversals:

Inorder sequence: D B E A F C
Preorder sequence: A B D E C F

In a Preorder sequence, leftmost element is the root of the tree. So we know ‘A’ is root for given sequences. By searching ‘A’ in Inorder sequence,
we can find out all elements on left side of ‘A’ are in left subtree and elements on right are in right subtree. So we know below structure now.

                 A
               /   \
             /       \
           D B E     F C
We recursively follow above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
Algorithm: buildTree()
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call.
2) Create a new tree node tNode with the data as picked element.
3) Find the picked element’s index in Inorder. Let the index be inIndex.
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6) return tNode.
*/
