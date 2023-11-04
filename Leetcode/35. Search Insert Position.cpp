/*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
*/

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	}
};