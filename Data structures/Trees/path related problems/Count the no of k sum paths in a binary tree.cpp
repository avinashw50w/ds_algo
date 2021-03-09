/*Count all k-sum paths in a Binary Tree
Given a binary tree and an integer k. The task is to count the number of paths in the tree with
 the sum of the nodes equals to k.
A path can start from any node and end at any node and must be downward only, i.e.
they need not be root node and leaf node, and negative numbers can also be there in the tree.

Examples:

Input : k = 5
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6

Output : No of paths with sum equals to 5 are: 8
3 2
3 1 1
1 3 1
4 1
1 -1 4 1
-1 4 2
5
1 -1 5 */

void solve(Node *root, int k, int sum, int &ans, unordered_map<int, int> &mp) {
    if (!root) return;

    sum += root->val;

    ans += sum == k;
    ans += mp[sum - k];

    mp[sum]++;

    solve(root->left, k, sum, ans, mp);
    solve(root->right, k, sum, ans, mp);

    mp[sum]--;
}

int count(Node *root, int k) {
    unordered_map<int, int> mp;
    int ans = 0;
    solve(root, k, 0, ans, mp);

    return ans;
}