/*given a sorted matrix such that each row is sorted in ascending order and the first element of a row
is greater than the last element of the previous row.
eg.   	1  2  3  4
		5  6  7  8
		9 10 11 12

IDEA: Let's write the elements of matrix in in 1d array: 1 2 3 4 5 6 7 8 9 10 11 12
if R and C are the no of rows and columns of the matrix respectively then
for any index x of the above array, what is the position of the element at index x in the matrix
it will be at row x/C and column x%C (both 0 indexed)
*/

pair<int, int> search(vector<vector<int>> matrix, int target) {
	int R = matrix.size(), C = matrix[0].size();
	int l = 0, r = R * C - 1, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		int i = mid / C, j = mid % C;
		if (A[i][j] == target) return {i, j};
		if (A[i][j] > target) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}