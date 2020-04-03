#include <bits/stdc++.h>
using namespace std;

void printDiagonal(vector<vector<int>> mat) {
	int R = mat.size();
	int C = mat[0].size();
	int row, col, i;

	for(i = 0; i < R; ++i) {
		for(row = i, col = 0; row >= 0 and col < C; --row, ++col)
			cout << mat[row][col] <<" ";
		cout << endl;
	}

	for(i = 1; i < C; ++i) {
		for(row = R-1, col = i; row >= 0 and col < C; --row, ++col)
			cout << mat[row][col] <<" ";
		cout << endl;
	}
}

int main() {

	vector<vector<int>> mat = {{1,2,3,4,5},
					 		   {6,7,8,9,10},
					 		   {11,12,13,14,15},
					 		   {16,17,18,19,20}};

	printDiagonal(mat);
}

/*Output :
1 
6 2 
11 7 3 
16 12 8 4 
17 13 9 5 
18 14 10 
19 15 
20 

*/