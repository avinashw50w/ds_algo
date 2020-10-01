/*given a matrix of letters and a dictionary of words. Find the set of words which can be found in the matrix by traversing in the
matrix in top, bottom, left, right and diagonally.*/

/*DP solution:
for a k letter word ending at pos (i,j), the (k-1)th letter must be in the 8 adjacent positions of (i,j)
let dp[k][i][j] = true, if a word of length k can be formed with the kth letter ending at pos (i,j)
*/
/*Time Complexity: O(W * R * C * L * 8)
where W and L are the size of the dictionary and max lenght of word in the dictionary
*/
int R, C;
vector<vector<string>> grid;
set<string> dict;

bool solve(string word) {
    int n = word.size();
    bool dp[n + 1][R][C];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (grid[i][j] == word[0]) dp[1][i][j] = true;

    for (int k = 2; k <= n; ++k) {
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (grid[i][j] == word[k - 1])
                    for (int x = i - 1; x <= i + 1; ++x)
                        for (int y = j - 1; y <= j + 1; ++y)
                            if (x >= 0 and y >= 0)
                                dp[k][i][j] |= dp[k - 1][x][y];

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (d[n][i][j]) return true;

        return false;
    }

    vector<string> findWords(vector<vector<string>> grid, set<string> dict) {

        R = grid.size();
        C = grid[0].size();
        vector<string> res;

        for (string word : dict) {
            if (solve(word)) res.push_back(word);
        }

        return res;
    }