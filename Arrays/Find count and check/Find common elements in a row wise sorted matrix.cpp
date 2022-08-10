/*Find a common element in all rows of a given row-wise sorted matrix
Given a matrix where every row is sorted in increasing order. Write a function 
that finds and returns a common element in all rows. 
If there is no common element, then returns -1. 

Example:

Input: mat[4][5] = { {1, 2, 3, 4, 5},
                    {2, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };
Output: 5
*/

vector<int> solve(vector<vector<int>> mat) {
	unordered_map<int, int> mp;
	vector<int> res;
	int n = mat.size(), m = mat[0].size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[mat[i][j]] == i) {
				mp[mat[i][j]] = i + 1;
				if (i == n-1) res.push_back(mat[i][j]);
			}
		}
	}
	return res;
}

/*
A O(m*n*n) simple solution is to take every element of first row and search it in all other rows, till we find a common element. 
Time complexity of this solution is O(m*n*n) where m is number of rows and n is number of columns in given matrix. 
This can be improved to O(m*n*Logn) if we use Binary Search instead of linear search.

We can solve this problem in O(mn) time using the approach similar to merge of Merge Sort. The idea is to start from the 
last column of every row. If elements at all last columns are same, then we found the common element. Otherwise we find 
the minimum of all last columns. Once we find a minimum element, we know that all other elements in last columns cannot 
be a common element, so we reduce last column index for all rows except for the row which has minimum value. We keep 
repeating these steps till either all elements at current last column don’t become same, or a last column index reaches 0.*/

int findCommon(int mat[N][M]) {

	// to store the last visited column of every row
	int lastVisited[N];
	// since we are starting from the last column of every row, so initialize it with N-1
	REP(i, 0, N) lastVisited[i] = N-1;

	int min_row = 0;
	// 
	while(lastVisited[min_row] >= 0) {
		// find the min in the last visited column of every row
		REP(i, 0, N)
			if(mat[i][lastVisited[i]] < mat[min_row][lastVisited[min_row]])
				min_row = i;

		int cnt = 0;

// check the last last visited column of every row whether they are equal to the min element or not,
// if equal then increment the cnt, if greater then decrement the last visited column by 1
		REP(i, 0, N) {

			if(mat[i][lastVisited[i]] > mat[min_row][lastVisited[min_row]]) {

				if(lastVisited[i] == 0) return -1;

				lastVisited[i]--; 
			}
			// since the element can't be less than the element in the min_row, so it should be equal to it;
			else cnt++;
		}
		// if all the elements at the last visited column of every row are equal, 
		// then we have found the common elements
		if(cnt == M) return mat[min_row][lastVisited[min_row]];
	}

	return -1;
}