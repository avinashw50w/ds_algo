/*Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        if (a.empty()) return 0;
        int cnt = 0, ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 1) cnt++, ans = max(ans, cnt);
            else {
                cnt = 0;
            }
        }

        return ans;
    }
};