/*Smallest submatrix with Kth maximum XOR
Difficulty Level : Hard
Last Updated : 29 Dec, 2020
Given a matrix m[][] of dimensions N × M and an integer K, calculate XOR(i, j) which is equal to 
the Bitwise Xor of all elements of submatrix from indices (1, 1) to (i, j)), for every index of 
the matrix. The task is to find the submatrix {(1, 1), …, (i, j)} having Kth maximum XOR(i, j) 
value. If multiple such submatrices exist, then print the smallest one. 

Note: Consider the starting index of the matrix from (1, 1).

Examples:

Input: m[][] = {{1, 2}, {2, 3}}, K = 2
Output: 1 2
Explanation:
XOR(1, 1) : m[1][1] = 1
XOR(1, 2): m[1][1] xor m[1][2] = 3
XOR(2, 1): m[1][1] xor m[2][1] = 3
XOR(2, 2): m[1][1] xor m[1][2] xor m[2][1] xor m[2][2] = 2
Hence, the 2nd maximum value is 3 at position [1, 2].*/

array<int,2> solve(vector<vector<int>> mat, int k) {
    int n = mat.size(), m = mat[0].size();
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    priority_queue<int, vector<int>, greater<int>> pq;
    map<int, array<int,2>> mp; // to store the coords(i,j) of the xor matrix sum upto (i,j)

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = mat[i][j];
            if (i) dp[i][j] ^= dp[i-1][j];
            if (j) dp[i][j] ^= dp[i][j-1];
            if (i and j) dp[i][j] ^= dp[i-1][j-1];

            pq.push(dp[i][j]);
            if (pq.size() > k) pq.pop();

            if (mp.count(dp[i][j]) == 0) mp[dp[i][j]] = { i, j };
        }
    }

    int kth_max = pq.top();

    return mp[kth_max];
}