int solve(Node *root, int &k) {
	if (root) {
		solve(root->left, k);
		k--;
		if (k == 0) return root->data;
		solve(root->right, k);
	}
	return -1;
}

////////////////////////////////////////////////////////////////
// O(1) extra space using Morris inorder traversal

void kthSmallest(Node *root, int k) {
	int cnt = 0, ans = -1;
	Node *curr = root;
	while (curr) {
		if (curr->left == NULL) {
			cnt++;
			if (cnt == k) {
				ans = root->data;
			}
			curr = curr->right;
		}
		else {
			Node *pre = curr->left;
			while (pre->right and pre->right != curr) pre = pre->right;

			if (pre->right == NULL) {
				pre->right = curr;
				curr = curr->left;
			}
			else {
				cnt++;
				if (cnt == k) {
					ans = root->data;
				}
				pre->right = NULL;
				curr = curr->right;
			}
		}
	}
	return ans;
}