/*Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

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