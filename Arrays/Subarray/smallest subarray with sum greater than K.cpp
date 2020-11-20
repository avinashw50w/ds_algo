/*find the smallest length subarray whose sum is greater than K*/

int solve(vector<int> a, int K) {
	int n = a.size();
	int sum = 0, start = 0, end = 0;
	int min_len = n;
	while (end < n) {
		while (sum <= K and end < n) sum += a[end++];
		while (sum > K and start < n) {
			min_len = min(min_len, end - start);
			sum -= a[start++];
		}
	}

	return min_len;
}