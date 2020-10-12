/* given an NxM matrix, find the no of submatices whose sum is equal to k. */
/*precalculate prefix sums of all the columns in the presum
where presum[i][j] = sum(mat[0][j] ... mat[i][j])

Now fix the border rows:rowstart and rowend, and then keep calculating the sum from column 0 to m.
if the seen before then add the no of times the sum appeard before. Then update the sum*/

int solve(vector<vector<int>> mat, int K) {
	int n = mat.size(), m = mat[0].size();
	if (n == 0 or m == 0) return 0;

	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j)
			mat[i][j] += mat[i][j - 1];

	unordered_map<int, int> mp;
	int ans = 0;

	for (int colStart = 0; colStart < m; ++colStart) {
		for (int colEnd = colStart; colEnd < m; ++colEnd) {
			mp.clear();
			int sum = 0;
			for (int row = 0; row < n; ++row) {
				sum += mat[row][colEnd] - (colstart - 1 >= 0 ? mat[row][colStart - 1] : 0);
				ans += sum == K;
				ans += mp[K - sum];
				mp[sum]++;
			}
		}
	}

	return ans;
}

/////////////////////////////////////////
// doing the same thing above, but in row-wise manner
int solve(vector<vector<int>> mat, int k) {
	if (mat.size() == 0 or mat[0].size() == 0) return 0;
	int n = mat.size(), m = mat.size();

	int presum[n + 1][m];
	memset(presum, 0, sizeof(presum));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			presum[i + 1][j] = presum[i][j] + mat[i][j];

	unordered_map<int, int> mp;
	int ans = 0;

	for (int rowstart = 0; rowstart < n; ++rowstart) {
		for (int rowend = rowstart; rowend < n; ++rowend) {
			int sum = 0;
			mp.clear();
			for (int j = 0; j < m; ++j) {
				sum += presum[rowend + 1][j] - presum[rowstart][j];
				ans += sum == k;
				ans += mp[k - sum];

				mp[sum]++;
			}
		}
	}

	return ans;
}