/*find the smallest subrray length such that the sum of the subarray elements is
greater than K
IDEA: two pointer approach
*/

int solve(vector<int> a, int K) {
	int st = 0, end = 0, n = a.size();
	int sum = 0, len = n - 1;
	while (end < n) {
		while (sum > K and st < end) {
			len = min(len, end - st);
			sum -= a[st++];
		}

		while (sum <= K and end < n) {
			sum += a[end++];
		}
	}
}