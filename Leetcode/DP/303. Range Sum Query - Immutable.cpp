/*Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

q w e r t y u i o p     a s d f g h j k l   z x c v b n m   1 2 3 4 5 6 7 8 9 0
œ ∑ ´ ® † ¥ ¨ ˆ ø π     å ß ∂ ƒ © ˙ ∆ ˚ ¬   Ω ≈ ç √ ∫ ˜ µ   ¡ ™ £ ¢ ∞ § ¶ • ª º 
*/


class NumArray {
    vector<int> dp;
    
public:
    NumArray(vector<int>& nums) {
        
        dp = nums;
        for (int i = 1; i < nums.size(); ++i)
            dp[i] += dp[i-1];
    }
    
    int sumRange(int i, int j) {
        return dp[j] - (i > 0 ? dp[i-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */