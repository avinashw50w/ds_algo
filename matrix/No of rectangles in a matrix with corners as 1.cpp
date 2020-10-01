/*Given a nxm matrix, find the no of rectangles having all four corners as 1*/

/**
 * scan each row one by one, and store all pairs of 1's in that row
 * if the pair appears again in the next row, then update the ans and increment that pair count
 */

int solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();

	unordered_map<pair<int, int>, int> mp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			for (int k = j + 1; k < m; ++k) {
				if (mat[i][j] == 1 and mat[i][k] == 1) {
					auto p = {i, j};
					if (mp.count(p)) ans += mp[p];
					mp[p]++;
				}
			}
		}
	}

	return ans;
}