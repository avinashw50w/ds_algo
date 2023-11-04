/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/

class Solution {
public:
	bool solve(TreeNode *root, int target, int sum) {
		if (!root) return false;
		sum += root->val;
		if (!root->left and !root->right) return sum == target;

		return solve(root->left, target, sum)
		       || solve(root->right, target, sum);
	}

	bool hasPathSum(TreeNode* root, int sum) {
		return solve(root, sum, 0);
	}
};