/*radix sort
keep sorting the array first by their units digit, then by the tens digit and so on
Time complexity: O(N*k) where k is the no of digits in the largest no
*/

void sort(vector<int> &a, int e) {
	vector<int> res(a.size());

	int f[10] = {};
	for (int x : a)
		f[(x / e) % 10]++;

	for (int i = 1; i < 10; ++i)
		f[i] += f[i - 1];

	for (int i = a.size() - 1; i >= 0; --i) {
		res[f[(a[i] / e) % 10] - 1] = a[i];
		f[(a[i] / e) % 10]--;
	}

	a = res;
}

void radixSort(vector<int> &a) {
	int mx = *max_element(a.begin(), a.end());
	for (int i = 1; mx / i > 0; i *= 10) {
		sort(a, i);
	}
}