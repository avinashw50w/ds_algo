/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        set<vector<int>> res;
        vector<vector<int>> ret;
        sort(a.begin(), a.end());
        int n = a.size();
        
        for (int i = 0; i < n-2; ++i) {
            int l = i+1, r = n-1;
            
            while (l < r) {
                int sum = a[i] + a[l] + a[r];
            
                if (sum == 0) {
                    vector<int> ans{a[i], a[l], a[r]};
                    if (res.count(ans) == 0)
                        res.insert(ans);
                    l++; r--;
                }
                else if (sum > 0) r--;
                else l++;
            }
        }
        
        for (auto v: res)
            ret.push_back(v);
        return ret;
    }
};