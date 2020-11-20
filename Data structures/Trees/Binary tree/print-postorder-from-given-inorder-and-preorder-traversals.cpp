/*Print Postorder traversal from given Inorder and Preorder traversals
Last Updated: 14-02-2020
Given Inorder and Preorder traversals of a binary tree, print Postorder traversal.

Example:

Input:
Inorder traversal in[] = {4, 2, 5, 1, 3, 6}
Preorder traversal pre[] = {1, 2, 4, 5, 3, 6}

Output:
Postorder traversal is {4, 5, 2, 6, 3, 1}
Trversals in the above example represents following tree

         1
      /    \
     2       3
   /   \      \
  4     5      6

  IDEA: recursively print the left subtree, then print the right subtree
   and then print the root
 */
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> in, int x, int l, int r) {
	for (int i = l; i <= r; ++i) if (in[i] == x) return i;
	return 0;
}

void solve(vector<int> in, vector<int> pre, int &i, int l, int r) {

	if (l > r) return;
	int idx = search(in, pre[i++], l, r);

	solve(in, pre, i, l, idx - 1);
	solve(in, pre, i, idx + 1, r);

	cout << in[idx] << " ";
}

void print(vector<int> inorder, vector<int> preorder) {
	int i = 0;
	solve(inorder, preorder, i, 0, inorder.size() - 1);
}

int main() {
	vector<int> in = { 4, 2, 5, 1, 3, 6 };
	vector<int> pre = { 1, 2, 4, 5, 3, 6 };
	print(in, pre);
}