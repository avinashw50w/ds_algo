/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/
class Solution {
    typedef long long ll;
public:
    int splitArray(vector<int>& a, int m) {
        // binary search the sum
        ll l = *max_element(a.begin(), a.end()), r = 1e18;
        while (l < r) {
            ll mid = l + ((r-l)>>1);
            int cnt = 0;
            ll sum = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (sum + a[i] > mid) {
                    sum = 0;
                    cnt++;
                }
                sum += a[i];
            }
            cnt++;
            if (cnt > m) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};