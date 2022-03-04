/*Longest alternating (positive and negative) subarray starting at every indexA subarray is
called alternating if any two consecutive numbers in it have opposite signs (i.e. one of them
should be negative, whereas the other should be positive).

Given an array of n integers. For each index i, we need to find the length if the longest
alternating subarray starting at i.

Examples:

Input : a[] = {1, -5, 1, -5}
Output : For index 0, {1, -5, 1, -5} = 4
             index 1, {-5, 1, -5} = 3
             index 2, {1, -5} = 2
             index 3, {-5} = 1.*/

int solve(vector<int> a) {
    int n = a.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] * a[i + 1] < 0) dp[i] = 1 + dp[i + 1];
        ans = max(ans, dp[i]);
    }

    return ans;
}

///////////////////////////
dp[0] = 1;
for (int i = 1; i < n; ++i) {
    if (a[i] * a[i - 1] < 0) dp[i] = 1 + dp[i - 1];
}

////////////////////////////////
// without using dp array
int solve(vector<int> a) {
    int n = a.size(), cnt = 1, ans = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] * a[i-1] < 0) {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt = 1;
    }
    return cnt;
}