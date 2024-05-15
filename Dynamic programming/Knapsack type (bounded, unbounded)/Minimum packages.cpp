/*Given a list of weights of items. We have to ship the items in packages where no package weight
should exceed maxWeight. Find the minimum no. of such packages

IDEA: 
dp[i][w] = min # of such packages such that items upto i are picked and the weight of current package is w
*/

int solve(vector<int> weights, int maxWeight) {
    int n = weights.size();

    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, INT_MAX));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= maxWeight; ++w) {
            if (weights[i-1] <= w) {
                dp[i][w] = min(
                    1 + dp[i-1][w - weights[i-1]], // create a new group with the current item of weight i
                    dp[i-1][w] // include the item the current group
                    );
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][maxWeight];
}

////////////////////////////////////////////////////////////////

int solve(vector<int> weights, int maxWeight) {
    int n = weights.size();
    vector<int> dp(maxWeight+1, INT_MAX); // dp[i] = min packages required for items of total weight i
    dp[0] = 0; // 0 packages are needed no items

    for (int i = 0; i < n; ++i) {
        for (int j = maxWeight; j >= weights[i]; --j) {
            if (dp[j] != INT_MAX) 
                dp[j] = min(dp[j], 1 + dp[j - weights[i]]);
        }
    }

    return dp[maxWeight];
}