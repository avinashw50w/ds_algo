/*Given an array containing +ve and -ve elements(except 0). Find the longest subsequence which
has alternating +ve and -ve nos. Of all such subsequences, find the subsequence which has the
maximum sum.*/

bool sign(int n) { return n > 0; }

int solve(vector<int> a) {
	int n = a.size(), i = 0, ans = 0;

	while (i < n) {
		int j = i, mx = a[i];
		while (j < n and sign(a[i]) == sign(a[j])) {
			mx = max(mx, a[j]);
			++j;
		}
		ans += mx;

		i = j;
	}

	return ans;
}