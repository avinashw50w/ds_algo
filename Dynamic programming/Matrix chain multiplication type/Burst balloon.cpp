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