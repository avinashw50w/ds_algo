/*Count sub-matrices having sum divisible ‘k’
Given a n x n matrix of integers and a positive integer k. The problem is to count all sub-matrices having sum divisible by the given value k.*/

// returns the no of subarrays with sum divisible by K
int count(vector<int> a, int K) {
	int n = a.size();
	vector<int> m(k, 0);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		while (sum < 0) sum += K;
		ans += sum % K == 0;
		ans += mp[sum % K];
		m[sum % K]++;
	}

	return ans;
}

int solve(vector<vector<int>> mat, int K) {
	int n = mat.size(), m = mat[0].size();

	int ans = 0;
	for (int l = 0; l < m; ++l) { // column start
		vector<int> a(n, 0);
		for (int r = l; r < m; ++r) { // column end
			for (int i = 0; i < n; ++i) {
				a[i] += mat[i][r];
				ans += count(a, K);
			}
		}
	}

	return ans;
}