/*Common elements in all rows of a given matrix
Given an m x n matrix, find all common elements present in all rows
in O(mn) time and one traversal of matrix.

Example:

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output:
1 8 or 8 1
8 and 1 are present in all rows.*/

vector<int> solve(vector<vector<int>> mat) {

    int N = mat.size();
    int M = mat[0].size();
    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {

            if (mp[mat[i][j]] == i) {
                mp[mat[i][j]] = i + 1;

                if (i == N) res.push_back(mat[i][j]);
            }
        }
    }

    return res;
}