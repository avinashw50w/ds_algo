/*Given an integer array nums and an integer k, return true if nums has a continuous subarray of 
size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a 
multiple of k.

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.*/

class Solution {
public:
    typedef long long ll;
    // simply find subarray of size atleast 2 which is divisible by k
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        if (n < 2) return false;
        map<ll, int> mp;
        ll sum = 0, ans = 0;

        for (int i = 0; i < n; ++i) {
            sum  = (sum + a[i] % k) % k;
            // subarray size should be atleast 2
            if (i >= 1) {
                ans += sum % k == 0;
            }
            if (mp.count(sum)) {
                ans += i - mp[sum] >= 2;
            }
            else mp[sum] = i;
        }
        
        return ans > 0;
    }
};