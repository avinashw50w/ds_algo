/*Find postorder traversal of BST from preorder traversal
Given an array representing preorder traversal of BST, print its postorder traversal.

Examples:

Input : 40 30 35 80 100
Output : 35 30 100 80 40

Input : 40 30 32 35 80 90 100 120
Output : 35 32 30 120 100 90 80 40

*/

void solve(vector<int> pre, int mn, int mx, int &i) {
    if (i == pre.size()) return;

    if (pre[i] < mn or pre[i] > mx) return;

    int val = pre[i++];
    solve(pre, mn, val, i);
    solve(pre, val, mx, i);

    cout << val << " ";
}

void print(vector<int> preorder) {
    int i = 0;
    solve(preorder, INT_MIN, INT_MAX, i);
}