/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Constraints:

1 <= n <= 20
1 <= k <= n
*/
class Solution {
    vector<vector<int>> ans;
public:
    void solve(int pos, int n, int k, vector<int> res) {
        if (k < 0 or pos > n) return;
        if (k == 0) {
            ans.push_back(res);
            return;
        }

        for (int i = pos; i <= n; ++i) {
            res.push_back(i);
            solve(i + 1, n, k-1, res);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1, n, k, {});
        return ans;
    }
};