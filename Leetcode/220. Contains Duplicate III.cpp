/*Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false*/
class Solution {
public:
    /* | a[i] - a[j] | <= t
        a[i] - a[j] <= t 
        or 
        a[i] - a[j] >= -t
        means a[i] <= a[j] + t
        or a[i] >= a[j] - t
        so find the closest value x which is >= a[j] - t
        then x - a[j] <= t
    */
    typedef long long ll;
    
    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        if (a.empty() or k == 0) return false;
        multiset<ll> mset;
        
        for (int i = 0; i < a.size(); ++i) {
            ll mn = (ll)a[i] - (ll)t;
            auto it = mset.lower_bound(mn);
            if (it != mset.end() and (ll)*it - (ll)a[i] <= t) return true;
            
            mset.insert(a[i]);
            if (mset.size() > k) 
                mset.erase(mset.find(a[i-k]));
        }
        
        return false;
    }
};