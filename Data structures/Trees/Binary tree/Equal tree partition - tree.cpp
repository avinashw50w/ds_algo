/* Given a binary tree with n nodes, your task is to check if it's possible to partition the tree into two trees 
which have the equal sum of values after removing exactly one edge from the original tree. 

Solution: store the sum of each subtree. If the total sum of the tree is S, we just need to check whether the subtree with sum S/2 exists or not. */

bool check(Node *root) {
	if(root == NULL) return true;

	map<int, int> m;

	int sum = getSum(root, m);

	if(sum == 0) return true;

	return !(sum & 1) && (m.find(sum>>1) != m.end());
}

int getSum(Node *root, map<int,int> m) {
	if(root == NULL) return 0;

	int sum = root->val + getSum(root->left) + getSum(root->right);
	m[sum] = 1;
	return sum;
}