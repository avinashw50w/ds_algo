/*Given an array, divide the array into two groups such that the difference between the sum of
the two groups is minimal. Return that difference

the idea is to find the subset sum K closest to S/2 where S is the sum of all the elements in the array,
then the ans will be S - 2*K */

int solve(vector<int> a) {
	int sum = 0, n = a.size(), ans = 0;
	for (int x : a) sum += x;

	for (int i = 0; i < 1 << n; ++i) {
		int s = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) s += a[j];
		}
		if (s <= sum / 2) ans = max(ans, s);
	}

	return sum - 2 * ans;
}