/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28

to reach the bottom right corner we need m-1 down and n-1 right moves.
So the # of distinct ways to reach bottom right is the distinct combinations of m-1 down and n-1 right moves,
which is (m-1+n-1)!/(m-1)!(n-1)! = m+n-2Cm-1 or m+n-2Cn-1
*/

class Solution {
public:
    int nCr(int n, int r) {
        r = min(n-r, r);
        vector<int> c(n+1, 0);
        c[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, r); j > 0; --j) c[j] += c[j-1];
        }
    return c[r];
}

int uniquePaths(int m, int n) {
    return nCr(m+n-2, n-1);
}
};