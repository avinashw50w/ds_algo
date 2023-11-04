/*Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.*/
class Solution {
public:
    // # of subarrays with sum k
    int solve(vector<int> a, int k) {
        map<int, int> mp;
        int sum = 0, cnt = 0;
        for (int e: a) {
            sum += e;
            cnt += sum == k;
            cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();
        int ans = 0;
        for (int left = 0; left < m; ++left) {
            vector<int> t(n);
            for (int right = left; right < m; ++right) {
                for (int i = 0; i < n; ++i) {
                    t[i] += mat[i][right];
                }
                ans += solve(t, target);
            }
        }
        
        return ans;
    }
};