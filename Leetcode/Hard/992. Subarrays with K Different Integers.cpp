/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]*/
class Solution {
public:
    // returns the no of subarrays with atmost k distinct elements
    int solve(vector<int> a, int k) {
        int n = a.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for (int st = 0, end = 0; end < n; ++end) {
            mp[a[end]]++;
            
            while (mp.size() > k) {
                mp[a[st]]--;
                if (mp[a[st]] == 0) mp.erase(a[st]);
                st++;
            }
            
            ans += end-st+1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& a, int k) {
        return solve(a, k) - solve(a, k-1);
    }
};