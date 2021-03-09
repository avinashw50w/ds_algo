/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
// bottom up
class Solution {
public:
    int maxProfit(int K, vector<int>& price) {
        int n = price.size();
        if (K >= n) {
            int ans = 0;
            for (int i = 1; i < n; ++i) {
                if (price[i] > price[i - 1]) ans += price[i] - price[i - 1];
            }

            return ans;
        }

        vector<int> buy(K + 1, -1e9), sell(K + 1);

        for (int p : price) {
            for (int i = 1; i <= K; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - p);
                sell[i] = max(sell[i], buy[i] + p);
            }
        }

        return sell[K];
    }
};

//////////////////////////////////////
// top down
class Solution {
    static const int maxn = 1e3;
    int dp[maxn][maxn][2];
public:

    int solve(vector<int> p, int i, int own, int k) {
        if (i == p.size() or k == 0) return 0;
        int &res = dp[i][k][own];
        if (res != -1) return res;

        if (own) {
            // sell
            int op1 = p[i] + solve(p, i + 1, !own, k - 1);
            int op2 = solve(p, i + 1, own, k);
            return res = max(op1, op2);
        }
        else {
            // buy
            // here we do not decrease k by 1 because one transaction completes after a buy and
            // the sell
            int op1 = -p[i] + solve(p, i + 1, !own, k);
            int op2 = solve(p, i + 1, own, k);
            return res = max(op1, op2);
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size()) {
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            }

            return ans;
        }
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 0, k);
    }
};