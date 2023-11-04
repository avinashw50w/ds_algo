/* simply find the maximum sum such that no two consecutive elements are taken.
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.*/

// dp[i] = max(dp[i-1], dp[i-2] + A[i])
int rob(vector<int>& arr) {
    if (arr.empty()) return 0;
    int a = 0, b = arr[0], c = max(a, b);

    for (int i = 1; i < arr.size(); ++i) {
        c = max(b, a + arr[i]);
        a = b;
        b = c;
    }

    return c;
}