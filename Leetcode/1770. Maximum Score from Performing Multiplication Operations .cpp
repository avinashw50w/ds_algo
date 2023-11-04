/*You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.*/
class Solution {
    int dp[1000][1000];
public:
    
    int solve(vector<int> &a, vector<int> &mul, int l, int r, int i, int m) {
        if (m == 0) return 0;
        if (l > r) return 0;
        if (dp[l][i] != -1) return dp[l][i];
        
        int op1 = a[l] * mul[i] + solve(a, mul, l+1, r, i+1, m-1);
        int op2 = a[r] * mul[i] + solve(a, mul, l, r-1, i+1, m-1);
        
        return dp[l][i] = max(op1, op2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, multipliers, 0, n-1, 0, m);
    }
};

////////////////////////////////////////////////////////////////
// Bottom up, O(N) space
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int diff = nums.size() - multipliers.size();
    vector<int> dp(multipliers.size());
    for(int k = 0; k < multipliers.size(); k++) {
        vector<int> current(multipliers.size());
        for(int i = 0; i < nums.size() - k - diff; i++) {
            int j = i + k;
            current[j] = max(
                (k == 0 ? 0 : dp[j]) + nums[i] * multipliers[multipliers.size() - 1 - k], 
                (k == 0 ? 0 : dp[j - 1]) + nums[j + diff] * multipliers[multipliers.size() - 1 - k]); 
        }
        dp = current;
    }
    return dp[multipliers.size() - 1];
}