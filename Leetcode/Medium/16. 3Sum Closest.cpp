/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, ans = 0;

        for (int i = 0; i < n-2; ++i) {
            int l = i + 1, r = n - 1;

            while (l < r) {

                int x = nums[i] + nums[l] + nums[r];

                if (abs(target - x) < abs(diff)) {
                    diff = target - x;
                    ans = x;
                }
                if (x > target) r--;
                else l++;
            }
        }
        return ans;
    }
};