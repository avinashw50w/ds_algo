/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position 
of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]*/
class Solution {
public:
    int findFirstPos(vector<int> a, int x) {
        int l = 0, r = a.size()-1, mid, ans = -1;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (x <= a[mid]) ans = mid, r = mid-1;
            else l = mid+1;
        }
        if (ans != -1 and a[ans] != x) return -1;
        return ans;
    }
    int findLastPos(vector<int> a, int x) {
        int l = 0, r = a.size()-1, mid, ans = -1;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (x >= a[mid]) ans = mid, l = mid+1;
            else r = mid-1;
        }
        if (ans != -1 and a[ans] != x) return -1;
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = findFirstPos(nums, target);
        int r = findLastPos(nums, target);

        return {l ,r};
    }
};