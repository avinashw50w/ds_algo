/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

class Solution {
public:
	// T: O(N)
	// S: O(N)
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mp;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			if (mp.count(target - nums[i])) {
				return { i, mp[target - nums[i]] };
			}
			mp[nums[i]] = i;
		}

		return res;
	}
};

/////////////////////////////////////////
// T: O(nlogn)
// S: O(1)
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	sort(nums.begin(), nums.end());
	int n = r.size(), l = 0, r = n-1;
	while (l < r) {
		int x = a[l] + a[r];
		if (x == target) return {l, r};
		if (x < target) l++;
		else r--;
	}
	return res;
}