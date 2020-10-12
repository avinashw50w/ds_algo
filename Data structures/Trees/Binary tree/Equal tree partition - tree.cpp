/* Given a binary tree with n nodes, your task is to check if it's possible to partition the tree into two trees
which have the equal sum of values after removing exactly one edge from the original tree.

Solution: store the sum of each subtree. If the total sum of the tree is S, we just need to check whether the subtree with sum S/2 exists or not. */

bool check(Node *root) {
    if (root == NULL) return true;

    unordered_set<int> st;

    int sum = getSum(root, st);

    if (sum == 0) return true;

    return (sum & 1 ^ 1) && (st.count(sum >> 1));
}

int getSum(Node *root, unordered_set<int> st) {
    if (root == NULL) return 0;

    int sum = root->val + getSum(root->left) + getSum(root->right);
    st.insert(sum);

    return sum;
}