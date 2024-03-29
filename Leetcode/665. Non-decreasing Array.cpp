/*Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

 

Example 1:

Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        bool changed = false;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i-1]) {
                if (changed) return false;
                changed = true;
                if (i < 2 or nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1];
            }
        }
        
        return true;
    }
};