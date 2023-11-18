/*Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
Return the maximum length of a subarray with positive product.

Example 1:
Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.

Example 2:
Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.
*/
class Solution {
public:
    int getMaxLen(vector<int>& a) {
        int posLen = 0; // max subrray length so far having +ve prod
        int negLen = 0; // max subarray length so far having -ve prod
        int ans = 0;

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > 0) {
                posLen++;
                negLen = negLen > 0 ? negLen + 1 : 0;
            } else if (a[i] < 0) {
                int t = posLen;
                posLen = negLen > 0 ? negLen + 1 : 0;
                negLen = t + 1;
            } else {
                posLen = negLen = 0;
            }
            ans = max(ans, posLen);
        }

        return ans;

    }
};