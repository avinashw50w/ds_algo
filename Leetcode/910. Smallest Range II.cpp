/*Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.
Example 3:

Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3]
*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // sort the array, then divide into two subarrays
        // [0..i-1] [i..n-1]
        //    +K      -K
        // means we add K to the all the elements int the range [0..i-1]
        // and subtract K to the elements in the range [i..n-1]
        //  after such operation the maximum possible no can be either a[i-1] + K or a[n-1] - K
        //  and the minimum possible value can be either a[0] + K or a[i] - K
        sort(A.begin(), A.end());
        int n = A.size(), ans = A[n-1] - A[0];
        for (int i = 1; i < n; ++i) {
            int h = max(A[i-1] + K, A[n-1] - K) - min(A[0] + K, A[i] - K);
            ans = min(ans, h);
        }
        return ans == 1e9 ? 0 : ans;
    }
};