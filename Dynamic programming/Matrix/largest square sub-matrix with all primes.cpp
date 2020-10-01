/*find the largest square sub-matrix which contains only prime numbers*/

const int maxn = 1e5 + 5;
int p[maxn];
void seive() {
	int i;
	p[0] = p[1] = 1;
	for (i = 2; i * i < maxn; ++i) {
		if (!p[i]) {
			for (int j = i * i; j < maxn; ++j) p[j] = 1;
		}
	}
}

int solve(vector<vector<int>> mat) {
	int n = mat.size(), m = mat[0].size();
	vector<vector<int>> dp = vector<int> (n + 1, vector<int>(m + 1, 0));
	int ans = 0;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (p[mat[i - 1][j - 1]] == 0) {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
				ans = max(ans, dp[i][j]);
			}
		}
	}

	return ans;
}