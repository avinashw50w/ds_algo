/*Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get
nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i.
After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167*/

class Solution {
    vector<vector<int>> dp;
public:
    int solve(vector<int> a, int l, int r) {
        if (l > r) return 0;
        int &res = dp[l][r];
        if (res != 0) return res;
        int ans = INT_MIN;
        // burst the ith balloon
        for (int i = l; i <= r; ++i) {
            int cost = a[l - 1] * a[i] * a[r + 1];
            ans = max(ans, solve(a, l, i - 1) + solve(a, i + 1, r) + cost);
        }

        return res = ans;
    }

    int maxCoins(vector<int>& a) {
        a.insert(a.begin(), 1);
        a.push_back(1);
        int n = a.size();
        dp.resize(n, vector<int>(n, 0));
        return solve(a, 1, n - 2);
    }
};


////////////////////////////////////////
// bottom up
/*Suppose we want to burst all the ballons within range [l, r] (both inclusive)
before bursting ballon l - 1 and r + 1, and note f[l][r] as the maximum coins we can collect in this process.
If i is the last ballon we want to burst within range [l, r], we can get:

    f[l][r] = ln * nums[i] * rn + f[l][i - 1] + f[i + 1][r]
where ln and rn are the left/right neighbors to [l, r]. Remember by definition we always burst [l, r] before bursting l - 1 and r + 1, we can easily get the neighbors to be:

    int ln = l > 0 ? nums[l - 1] : 1;
    int rn = r + 1 < n ? nums[r + 1] : 1;
If we start with small ranges and build the dynamic programming table by iterating all the possible is (last burst ballon), we can get the full code in bottom-up approach: */

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l <= n - len; ++l) {
            int r = l + len - 1;
            int ln = l > 0 ? nums[l - 1] : 1;
            int rn = r + 1 < n ? nums[r + 1] : 1;
            for (int i = l; i <= r; ++i) {
                int temp = ln * nums[i] * rn
                           + (i ? f[l][i - 1] : 0)
                           + (i + 1 <= r ? f[i + 1][r] : 0);
                f[l][r] = max(f[l][r], temp);
            }
        }
    }
    return f[0][n - 1];
}