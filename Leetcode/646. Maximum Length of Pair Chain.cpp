/*You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].*/
// dp: O(N^2)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
        [](auto & a, auto & b) { return a[0] < b[0]; });

        int n = pairs.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0] and dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        return dp[n - 1];
    }
};

////////////////////////////////////////////////////
// Greedy : O(NlogN)
class Solution {
    const int INF = 1e9;
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // for getting the longest chain, sort according to the end of the chain
        sort(pairs.begin(), pairs.end(),
        [](auto & a, auto & b) { return a[1] < b[1]; });

        int n = pairs.size(), ans = 0, curr = -INF;

        for (auto p : pairs) if (curr < p[0]) {
                curr = p[1];
                ans++;
            }

        return ans;
    }
};