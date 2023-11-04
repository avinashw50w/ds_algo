/*You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return 0;
        sort(a.begin(), a.end(), [](auto x, auto y) { 
            return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0];
        });
        
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i][0] > a[j][0] and a[i][1] > a[j][1] and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
    }
};