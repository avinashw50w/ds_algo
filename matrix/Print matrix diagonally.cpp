#include <bits/stdc++.h>
using namespace std;

/* Input:
1, 2, 3, 4, 5
6, 7, 8, 9, 10
11, 12, 13, 14, 15
16, 17, 18, 19, 2
Output :
1
6 2
11 7 3
16 12 8 4
17 13 9 5
18 14 10
19 15
20

*/

void printDiagonal(vector<vector<int>> mat) {
	int R = mat.size();
	int C = mat[0].size();
	int row, col, i;

	for (i = 0; i < R; ++i) {
		for (row = i, col = 0; row >= 0 and col < C; --row, ++col)
			cout << mat[row][col] << " ";
		cout << endl;
	}

	for (i = 1; i < C; ++i) {
		for (row = R - 1, col = i; row >= 0 and col < C; --row, ++col)
			cout << mat[row][col] << " ";
		cout << endl;
	}
}
///////////////////////////////////
// return the result too
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
		int r = n - 1, c = i;
		vector<int> tmp;
		while (r >= 0 and c < m) {
			tmp.push_back(mat[r][c]);
			--r; ++c;
		}
		res.push_back(tmp);
	}
	return res;
}

int main() {

	vector<vector<int>> mat = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20}
	};

	printDiagonal(mat);
}

