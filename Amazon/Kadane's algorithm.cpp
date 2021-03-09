// maximum subarray problem also known as Kadane's algorithm //
// also handles the case when all nos are -ve
void kadane(vector<int> a) {
	int n = a.size(), sum = 0, ans = INT_MIN;

	for (int e : a) {
		sum = max(sum + e, e);
		ans = max(ans, sum);
	}

	return ans;
}
// maxSum is the sum of the elements of the maximum subarray //
// another dp way //
void maxSubarray(int a[], int n) {
	int dp[n] = {};
	dp[0] = a[0];
	for (int i = 1; i < n; ++i)
		dp[i] = max(a[i] , dp[i - 1] + a[i]);

	cout << *max_element(dp, dp + n);
}

// also return the start and end index of the subarray
pair<int, int> solve(vector<int> a) {
	int n = a.size(), sum = 0, start = 0, end = 0, idx = 0, maxsum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (sum > maxsum) {
			maxsum = sum;
			start = idx;
			end = i;
		}
		if (sum < 0) {
			sum = 0;
			idx = i + 1;
		}
	}

	return { start, end };
}

int main() {
	int a[] = {6, 2, -4, 3, 8, 1, -5, -6, -9, 0, 2, 4};
	int n = sizeof(a) / sizeof(a[0]);
	maxSubarray(a, n);
}
