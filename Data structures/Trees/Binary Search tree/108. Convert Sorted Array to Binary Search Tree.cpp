/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	TreeNode *solve(vector<int> nums, int l, int r) {
		if (l > r) return NULL;
		int mid = (l + r) >> 1;
		TreeNode *par = new TreeNode(nums[mid]);
		par->left = solve(nums, l, mid - 1);
		par->right = solve(nums, mid + 1, r);
		return par;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return solve(nums, 0, nums.size() - 1);
	}
};