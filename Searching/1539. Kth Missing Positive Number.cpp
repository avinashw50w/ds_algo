/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.*/

class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        // missing numbers till index i = a[i]-1 - i;
        /*
        Find the first index i such that missing nos till index i >= k
        then 
        ans = a[i-1] + (k - missingCnt(i-1))
            = a[i-1] + k - (a[i-1] - 1 - i + 1) 
            = i + k
        */
        int n = a.size();
        auto missingCnt = [&](int i) { return a[i]-1-i; };
        if (a[0] > k) return k;
        if (a.back() <= a.size()) return a.size() + k;

        int l = 0, r = n-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (missingCnt(mid) < k) l = mid+1;
            else r = mid-1;
        }
        
        return l + k;
    }
};