/*On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.*/

class Solution {
    typedef long long ll;
    const ll INF = 1e18;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<ll> dp(n+1, INF);
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 0; i < n; ++i) {
            for (int j: {i+1, i+2}) {
                if (j < n)
                    dp[j] = min(dp[j], (ll)cost[j] + dp[i]);
            }
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};