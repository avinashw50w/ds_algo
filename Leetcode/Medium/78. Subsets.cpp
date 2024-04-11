/*Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1<<n); ++i) {
            vector<int> t;
            for (int j = 0; j < n; ++j) {
                if (i>>j&1) t.push_back(a[j]);
            }
            res.push_back(t);
        }
        return res;
    }
};

////////////////////////////////////////////////////////////////
/// another way
class Solution {
    vector<int> a;
    vector<vector<int>> ans;
public:
    void solve(int pos, vector<int> res) {
        ans.push_back(res);
        for (int i = pos; i < a.size(); ++i) {
            res.push_back(a[i]);
            solve(i + 1, res);
            res.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        a = nums;
        solve(0, {});

        return ans;
    }
};