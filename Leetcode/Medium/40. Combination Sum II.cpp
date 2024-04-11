/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique 
combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

IDEA: use backtracking
to generate only distinct combinations: 
- sort the array
- don't pick an element if the prev element == element, coz it has already been included in a combination*/
class Solution {
    vector<int> a;
    vector<vector<int>> ans;
public:
    void solve(int pos, vector<int> res, int sum) {
        if (pos >= a.size() or sum < 0) return;
        
        if (sum == 0) {
            ans.push_back(res);
            return;
        }

        for (int i = pos; i < a.size(); ++i) {
            if (i > pos and a[i] == a[i-1]) continue;
            res.push_back(a[i]);
            solve(i + 1, res, sum - a[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        a = candidates;
        sort(a.begin(), a.end());
        solve(0, {}, target);
        return ans;
    }
};