/*given an array, find the longest subarray which forms an AP (arithmetic progression)*/

int solve(vector<int> a) {
	int n = a.size();
	if (n <= 2) return n;

	vector<int> diff(n - 1);
	for (int i = 0; i + 1 < n; ++i) diff[i] = a[i + 1] - a[i];

	int ans = 1, cnt = 1;
	for (int i = 1; i < diff.size(); ++i) {
		if (diff[i] == diff[i - 1]) {
			cnt++;
			ans = max(ans, cnt);
		}
		else cnt = 1;
	}
	// 1 is added coz : if there are 2 consecutive similar differences d d then there are 3 array elements
	// a1 a2 a3 such that a2 - a1 = a3 - a2
	return ans + 1;
}