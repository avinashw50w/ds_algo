/* given an NxM matrix which is row-wise sorted.
 find the index of the row having maximum no of 1's.
IDEA: start from top left corner,
if 1 is encountered then move left
otherwise move down
 */

int solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	int i = 0, j = m - 1, ans = -1;

	while (i < n and j >= 0) {
		if (mat[i][j] == 1) {
			ans = i;
			j--;
		}
		else i++;
	}
	return ans;
}