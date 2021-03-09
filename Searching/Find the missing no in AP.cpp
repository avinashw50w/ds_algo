/*Find the missing number in an Arithmetic progression.
eg. 2 4 8 10 12,
output: 6
*/


int solve(vector<int> a, int diff) {
	int n = a.size();
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (m - 1 >= l and a[m] - a[m - 1] > diff)
			return a[m - 1] + diff;
		if (m + 1 <= r and a[m + 1] - a[m] > diff)
			return a[m] + diff;

		if (a[m] == a[0] + m * diff) l = m + 1;
		else r = m - 1;
	}

	return -1;
}

int findMissingNo(vector<int> a) {
	int n = a.size();
	// a[n-1] = a[0] + n*diff
	// diff = (a[n-1] - a[0]) / n
	int diff = (a[n - 1] - a[0]) / n;

	return solve(a, diff);
}