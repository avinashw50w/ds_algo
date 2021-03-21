/*Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
Note:

The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?*/
class Solution {
public:
    // O(n^2 * m^2)
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = mat[i][j];
                if (i) sum += dp[i-1][j];
                if (j) sum += + dp[i][j-1];
                if (i and j) sum -= dp[i-1][j-1];
                dp[i][j] = sum;
            }
        }

        int ans = -1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int p = i; p < n; ++p) {
                    for (int q = j; q < m; ++q) {
                        int sum = dp[p][q];
                        if (i) sum -= dp[i-1][q];
                        if (j) sum -= dp[p][j-1];
                        if (i and j) sum += dp[i-1][j-1];
                        
                        if (sum <= k) {
                            ans = max(ans, sum);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};

//////////////////////////////////////////////////////////////////
// Follow up: What if the number of rows is much larger than the number of columns?
// O(m^2 * nlogn) which more optimised than the above one
const int inf = 1e9;
// find the maximum subarray sum <= k
// prefixSum - x <= k
// x >= prefixSum - k
int solve(vector<int> a, int k) {
    int sum = 0, ans = -inf;
    set<int> st;
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i];
        if (sum <= k) ans = max(ans, sum);
        auto it = st.lower_bound(sum - k);
        if (it != st.end()) ans = max(ans, sum - *it);
        st.insert(sum);
    }

    return ans;
}

int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
    int n = mat.size(), m = mat[0].size();
    int ans = -inf;
    for (int left = 0; left < m; ++left) {
        vector<int> t(n);
        for (int right = left; right < m; ++right) {
            for (int i = 0; i < n; ++i) 
                t[i] += mat[i][right];

            ans = max(ans, solve(t, k));
        }
    }

    return ans;
}
