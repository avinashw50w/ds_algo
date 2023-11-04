/*Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        if (mp.count(nums[i]) and abs(i - mp[nums[i]]) <= k) return true;
        mp[nums[i]] = i;
    }

    return false;
}