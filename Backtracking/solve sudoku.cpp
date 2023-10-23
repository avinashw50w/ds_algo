/*Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.*/

// Time: O(9^(n*n))
// space: O(n*n)
#define UNASSIGNED = 0;

bool findUnassignedLocation(vector<vector<int>> grid, int &r, int &c) {
	for (r = 0; r < grid.size(); ++r)
		for (c = 0; c < grid[0].size(); ++c)
			if (grid[r][c] == UNASSIGNED) return true;
	return false;
}

bool usedInRow(vector<vector<int>> grid, int r, int x) {
	for (int c = 0; c < grid[r].size(); ++c) if (grid[r][c] == x) return true;
	return false;
}

bool usedInCol(vector<vector<int>> grid, int c, int x) {
	for (int r = 0; r < grid.size(); ++r) if (grid[r][c] == x) return true;
	return false;
}

bool usedInBox(vector<vector<int>> grid, int boxStartRow, int boxStartCol, int x) {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (grid[i + boxStartRow][j + boxStartCol] == x) return true;
		}

	return false;
}

bool isSafe(vector<vector<int>> grid, int r, int c, int x) {
	return !usedInRow(grid, r, x)
	       && !usedInCol(grid, c, x)
	       && !usedInBox(grid, r - r % 3, c - c % 3, x);
}

bool solveSudoku(vector<vector<int>> grid) {
	int r, c;
	if (!findUnassignedLocation(grid, r, c)) return true;

	for (int i = 1; i < 10; ++i) {
		if (isSafe(grid, r, c, i)) {
			grid[r][c] = i;
			if (solveSudoku(grid)) return true;
			grid[r][c] = UNASSIGNED;
		}
	}
	return false;
}

int main() {
	vector < vector<int> grid = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
		{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
		{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
		{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
		{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
		{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
		{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
	};

	if (solveSudoku(grid)) {
		printGrid(grid);
	}
	else cout << "Solution does not exist";
}