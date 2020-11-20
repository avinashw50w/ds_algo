/*Sort the matrix row-wise and column-wise

Algo:
1. Sort each row of the matrix.
2. Get transpose of the matrix.
3. Again sort each row of the matrix.
4. Again get transpose of the matrix.
*/

for (int i = 0; i < n; ++i) {
	sort(mat[i].begin(), mat[i].end());
	transpose(mat);
	sor(mat[i].begin(), mat[i].end());
	transpose(mat);
}