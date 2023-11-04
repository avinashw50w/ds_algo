/*Given an array of positive integers nums, remove the smallest subarray (possibly empty) such 
that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

*/
class Solution {
    typedef long long ll;
public:
    int minSubarray(vector<int>& a, int p) {
        /* ( totalSum - ∑(a[i]..a[j]) ) % p = 0 
            totalSum % p = ∑(a[i]..a[j]) % p
            => ∑(a[0]..a[j]) % p - ∑(a[0]..a[i-1]) % p = totalSum % p
            => ∑(a[0]..a[i-1]) % p = ∑(a[0]..a[j]) % p - totalSum % p
        */
        int n = a.size();
        ll total = 0;
        for (int e: a) total = (total + e) % p;
        if (total % p == 0) return 0;
        
        map<ll, ll> mp;
        ll sum = 0, ans = n;
        
        for (int i = 0; i < n; ++i) {
            sum = (sum + a[i]) % p;
            if (sum == total) ans = min(ans, (ll)i+1);
            if (mp.count((sum - total + p) % p)) 
                ans = min(ans, (ll)i - mp[(sum - total + p) % p]);
            mp[sum] = i;
        }
        
        return ans == n ? -1 : ans;
    }
};