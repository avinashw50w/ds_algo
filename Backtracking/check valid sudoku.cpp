/*Check if given Sudoku board configuration is valid or not
Last Updated: 02-04-2019
Given a Sudoku Board configuration, check whether it is valid or not.

Examples:

Input:
    [5 3 - - 7 - - - -]
    [6 - - 1 9 5 - - -]
    [- 9 8 - - - - 6 -]
    [8 - - - 6 - - - 3]
    [4 - - 8 - 3 - - 1]
    [7 - - - 2 - - - 6]
    [- 6 - - - - 2 8 -]
    [- - - 4 1 9 - - 5]
    [- - - - 8 - - 7 9]

Output: True
*/
bool noDuplicatedInRow(vector<vector<char>> grid, int r) {
    set<char> st;
    for (int c = 0; c < grid[0].size(); ++c) {
        if (st.count(grid[r][c])) return false;
        if (grid[r][c] != '.') st.insert(grid[r][c]);
    }
    return true;
}

bool noDuplicatedInCol(vector<vector<char>> grid, int c) {
    set<char> st;
    for (int r = 0; r < grid.size(); ++r) {
        if (st.count(grid[r][c])) return false;
        if (grid[r][c] != '.') st.insert(grid[r][c]);
    }
    return true;
}

bool noDuplicatedInBox(vector<vector<char>> grid, int boxStartRow, int boxStartCol) {
    set<char> st;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            int curr = grid[r + boxStartRow][c + boxStartCol];
            if (st.count(curr)) return false;
            if (curr != '.') st.insert(curr);
        }
    }
    return true;
}

bool isValid(vector<vector<char>> grid, int r, int c) {
    return noDuplicatedInRow(grid, r)
           && noDuplicatedInCol(grid, c)
           && noDuplicatedInBox(grid, r - r % 3, c - c % 3);
}

bool isValidConfig(vector<vector<char>> grid, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!isValid(grid, i, j)) return false;
        }
    }

    return true;
}

int main() {
    vector<vector<char>> grid = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    cout << (isValidConfig(grid, 9) ? "YES\n" : "NO\n");
}