/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

NOTE: xor approach will not work for test case #3 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        int s = nums[0], f = nums[0];
        
        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);
        
        s = nums[0];
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }
        
        return s;
    }
};