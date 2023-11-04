/*Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] 
with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if 
B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

Example 1:

Input: [3,6,9,12]
Output: 4
Explanation: 
The whole array is an arithmetic sequence with steps of length = 3.
Example 2:

Input: [9,4,7,2,10]
Output: 3
Explanation: 
The longest arithmetic subsequence is [4,7,10].*/

class Solution {
public:
 
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if (n <= 1) return n;
        // dp[i][d] - the length of the longest arithmetic subsequence with difference d
        // which ends at a[i]
        // suppose the subsequence ends with a[j] a[i], which has common difference d
        // the dp[i][d] = max(dp[i][d], 1 + dp[j][d])
        map<int,int> dp[n];
        int ans = 2;
        
        for (int i = 1; i < n; ++i) {
            int x = A[i];
            for (int j = 0; j < i; ++j) {
                int y = A[j];
                
                int d = x-y;
                
                int len = dp[j].count(d) ? dp[j][d] + 1 : 2;
                
                dp[i][d] = max(dp[i][d], len);
                
                ans = max(ans, dp[i][d]);
            }
        }
        
        return ans;
    }
};