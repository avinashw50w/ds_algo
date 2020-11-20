/*find the transpose of a matrix
simple swap a[i][j] with a[j][i], if i < j
*/

for (int i = 0; i < n ; ++i) {
	for (int j = 0; j < m; ++j) if (i < j) swap(a[i][j], a[j][i]);
}