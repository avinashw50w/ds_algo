/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

since array elements are distinct, it will generate unique permutations*/

// T: n!
// T(n) = n.T(n-1)
class Solution {
    vector<int> a;
    vector<vector<int>> ans;
public:
    void solve(int pos) {
        if (pos == a.size()) {
            ans.push_back(a);
            return;
        }

        for (int i = pos; i < a.size(); ++i) {
            swap(a[i], a[pos]);
            solve(pos + 1);
            swap(a[i], a[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        a = nums;
        solve(0);

        return ans;
    }
};