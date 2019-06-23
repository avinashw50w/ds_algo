/*Largest divisible pairs subset
Given an array of n distinct elements, find length of the largest subset such that every pair in the subset is such that 
the larger element of the pair is divisible by smaller element.

Examples:

Input : arr[] = {10, 5, 3, 15, 20} 
Output : 3 
Explanation: The largest subset is 10, 5, 20.
10 is divisible by 5, and 20 is divisible by 10.

Input : arr[] = {18, 1, 3, 6, 13, 17} 
Output : 4
Explanation: The largest subset is 18, 1, 3, 6,
In the subsequence, 3 is divisible by 1, 
6 by 3 and 18 by 6.
Recommended: Please try your approach on {IDE} first, before moving on to the solution.


This can be solved using Dynamic Programming. We first sort the array so that the largest element is at the end. Then we traverse the sorted array from end. For every element a[i], we compute dp[i] where dp[i] indicates size of largest divisible subset where a[i] is the smallest element. We can compute dp[i] in a sorted array using values from dp[i+1] to dp[n-1]. Finally we return maximum value from dp[].*/

int solve(int a[], int n) {

    int dp[n] = {0};
    sort(a, a+n);

    dp[n-1] = 1;

    for (int i = n-2; i >= 0; --i) {
        int mx = 0;
        for (int j = i+1; j < n; ++j) {
            if (a[j] % a[i] == 0) mx = max(mx, dp[j]);
        }

        dp[i] = 1 + mx;
    }

    return *max_element(dp, dp+n);
}