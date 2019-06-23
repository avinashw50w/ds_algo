void countSort(int arr[], int n, int place) {
	int i, freq[10], output[n];

	for (i = 0; i < n; ++i)
		freq[(arr[i]/place) % 10]++;

	for (i = 1; i < 10; ++i)
		freq[i] += freq[i-1];

	for (i = n-1; i >= 0; --i) {
		int pos = (arr[i]/place) % 10;
		output[freq[pos]- 1] = arr[i];
		freq[pos]--;
	}

	for (i = 0; i < n; ++i)
		arr[i] = output[i];
}

void radixSort(int arr[], int n) {
	int maxx = *max_element(arr, arr+n);

	for (int mul = 1; maxx/mul > 0; mul *= 10)
		countSort(arr, n, mul);
}