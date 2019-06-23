/*eg. 1 2 3
      4 5 6
      7 8 9

will be printed as : 
1
4 2
7 5 3
8 6
9*/

void printDiagonals(vector<vector<int>> mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> res;

    for (int i = 0; i < n; ++i) {
        int r = i, c = 0;
        vector<int> tmp;
        while (r >= 0 and c < m) {
            tmp.push_back(mat[r][c]);
            --r; ++c;
        }
        res.push_back(tmp);
    }

    for (int i = 1; i < m; ++i) {
        int r = n-1, c = i;
        vector<int> tmp;
        while (r >= 0 and c < m) {
            tmp.push_back(mat[r][c]);
            --r; ++c;
        }
        res.push_back(tmp);
    }
    return res;
}