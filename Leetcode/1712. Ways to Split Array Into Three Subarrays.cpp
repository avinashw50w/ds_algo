/*A split of an integer array is good if:

The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.*/
class Solution {
    typedef long long ll;
    const int mod = 1e9 + 7;
public:
    int waysToSplit(vector<int>& a) {
        int n = a.size();
        vector<ll> pre(n+1, 0);
        for (int i = 0; i < n; ++i) 
            pre[i+1] = pre[i] + a[i];
        
        int j = 0, k = 0;
        ll ans = 0;
        
        for (int i = 1; i < n-1; ++i) {
            int left = pre[i];
            int mid = (pre[n] - pre[i]) / 2;
            if (left > mid) break;
            // find min j such that left <= mid
            while (j <= i or (j < n and pre[j] - left < left)) j++;
            // find min k such that left <= mid and  mid > right
            while (k < j or (k < n and pre[k] - left <= pre[n] - pre[k])) k++;
            
            ans += k - j;
            ans %= mod;
        }
        
        return ans;
    }
};