/*Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?*/

class Solution {
public:
    void reverse(vector<int> &a, int l, int r) {
        while (l < r) swap(a[l++], a[r--]);
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        k = n - k;
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        reverse(nums, 0, n - 1);
    }
};