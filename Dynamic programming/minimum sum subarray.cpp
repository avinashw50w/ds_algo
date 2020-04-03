
void minSumSubarray(int a[], int n) {
	int sum = a[0], mn = a[0];
	for (int i = 1; i < n; ++i) {
		sum += a[i];

		if (sum > 0) sum = a[i];
		mn = min(mn, sum);
	}

	return mn;
}