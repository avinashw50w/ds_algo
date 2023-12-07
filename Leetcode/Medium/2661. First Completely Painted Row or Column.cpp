/*You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain 
all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].*/
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), len = n*m;
        unordered_map<int, array<int,2>> pos;
        for (int i = 0; i<n; ++i) {
            for (int j=0; j<m; ++j) pos[mat[i][j]] = {i, j};
        }

    vector<int> rows(n, 0), col(m, 0);

    for (int k = 0; k<len; ++k) {
        int e = arr[k];
        int i = pos[e][0], j = pos[e][1];
        rows[i]++;
        col[j]++;
        if (rows[i] == m or col[j] == n) return k;
    }

    return 0;
}
};