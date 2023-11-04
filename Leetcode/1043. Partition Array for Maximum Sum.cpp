/*Given an integer array arr, you should partition the array into (contiguous) subarrays of 
length at most k. After partitioning, each subarray has their values changed to become the 
maximum value of that subarray.

Return the largest sum of the given array after partitioning.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

IDEA: let dp[j] be the maximum sum after partitioning j elements from start.
suppose the partition be [0..i-1] [i...], if we know the answer upto index i,
then dp[j+1] = min(dp[j+1], dp[i] + (j-i+1) * mx), where i <= j < n and mx is the maximum 
element from index i to j
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        // using push dp
        vector<int> dp(n + 1, INT_MIN);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            int mx = a[i];
                // partition at i
            for (int j = i; j < n and j-i+1 <= k; ++j) {
                mx = max(mx, a[j]);
                dp[j+1] = max(dp[j+1], dp[i] + (j-i+1) * mx);
            }
        }
        return dp[n];
    }
};
/////////////////////////////////////////////////////////////////
// using pull dp
int maxSumAfterPartitioning(vector<int>& a, int k) {
    int n = a.size();
    vector<int> dp(n, INT_MIN);
    for (int i = 0; i < n; ++i) {
        int mx = a[i];
        for (int j = i; j < n and j-i+1 <= k; ++j) {
            mx = max(mx, a[j]);
            dp[j] = max(dp[j], (i-1 >= 0 ? dp[i-1] : 0) + (j-i+1) * mx);
        }
    }
    return dp[n-1];
}