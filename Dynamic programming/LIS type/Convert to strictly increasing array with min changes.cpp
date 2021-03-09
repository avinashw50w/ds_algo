/*Given an array with n integers. Find the min no of changes in array
so that the array is strictly increasing.

Ans = size of array - Longest increasing subsequence of the array */

int solve(int a[], int n) {
    int dp[n + 1];
    fill(dp, dp + n, 1);

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++i)
            if (a[i] > a[j] and (i - j) <= (a[i] - a[j]))
                dp[i] = max(dp[i], dp[j] + 1);

    int lis = *max_element(dp, dp + n);
    return n - lis;
}