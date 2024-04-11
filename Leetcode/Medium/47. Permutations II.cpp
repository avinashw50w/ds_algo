/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique 
permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/
class Solution {
    vector<int> a;
    set<vector<int>> st;
public:
    void solve(int pos) {
        if (pos == a.size()) {
            st.insert(a);
            return;
        }

        for (int i = pos; i < a.size(); ++i) {
            // this extra check improves the run time
            if (i > pos and (a[i] == a[i-1] or a[i] == a[pos])) continue;
            swap(a[i], a[pos]);
            solve(pos + 1);
            swap(a[i], a[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        a = nums;
        sort(a.begin(), a.end());
        solve(0);
        vector<vector<int>> ans;
        for (auto e: st) ans.push_back(e);
            return ans;
    }
};