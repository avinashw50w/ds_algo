/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) nums[k++] = nums[i];
        }
        
        while (k < n) nums[k] = 0, k++;
    }
};