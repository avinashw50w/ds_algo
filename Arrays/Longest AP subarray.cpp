/*given an array, find the longest subarray which forms an AP (arithmetic progression)*/

int solve(vector<int> a) {
	int n = a.size();
	if (n <= 2) return n;

	vector<int> diff(n - 1);
	for (int i = 0; i + 1 < n; ++i) diff[i] = a[i + 1] - a[i];

	int ans = 1, cnt = 1;
	for (int i = 1; i < n - 1; ++i) {
		if (diff[i] == diff[i - 1]) {
			cnt++;
			ans = max(ans, cnt);
		}
		else cnt = 1;
	}

	return ans + 1;
}