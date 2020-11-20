/*Rotate a matrix by 45 degrees cloclwise.
Input: N = 6,
mat[][] = {{3, 4, 5, 1, 5, 9, 5},
               {6, 9, 8, 7, 2, 5, 2},
               {1, 5, 9, 7, 5, 3, 2},
               {4, 7, 8, 9, 3, 5, 2},
               {4, 5, 2, 9, 5, 6, 2},
               {4, 5, 7, 2, 9, 8, 3}}
Output:
        3
       6 4
      1 9 5
     4 5 8 1
    4 7 9 7 5
   4 5 8 7 2 9
    5 2 9 5 5
     7 9 3 3
      2 5 5
       9 6
        8
IDEA: there are two types of diagonals, one goes from left to right
and the other goes from right to left(\ and /)
\ diagonal - all elements lying on that diagonal have the same value of i - j
/ diagonal - all elements lying on that diagonal have the same value of i + j
*/

void rotate45(vector<vector<int>> mat) {
	int n = mat.size();
	map<int, vector<int>> mp;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			mp[i + j].push_back(mat[i][j]);
		}
	}

	for (auto e : mp) {
		for (int x : e.second) cout << x << " ";
		cout << endl;
	}
}