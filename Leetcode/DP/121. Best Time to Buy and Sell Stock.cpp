/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

exp: just find the maximum value of prices[j] - prices[i] such that j > i */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = INT_MAX;
        int ans = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        
        return ans >= 0 ? ans : 0;
    }
};