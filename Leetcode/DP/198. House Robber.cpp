/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.*/

class Solution {
    typedef long long ll;
    const ll INF = 1e18;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n, -INF);
        
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

///////////////////////////////////////////////
class Solution {
    typedef long long ll;
    const ll INF = 1e18;
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        ll prev = nums[0];
        ll curr = max(nums[1], nums[0]);
        ll ans = curr;
        
        for (int i = 2; i < n; ++i) {
            ans = max(prev + nums[i], curr);
            prev = curr;
            curr = ans;
        }
        
        return ans;
    }
};