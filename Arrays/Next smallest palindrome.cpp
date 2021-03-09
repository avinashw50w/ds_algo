
void solve(vector<int> &a) {
	int n = a.size();
	bool leftSmaller = false;
	int mid = n / 2;
	int i = mid - 1;
	int j = n & 1 ? m + 1 : mid;
	while (i >= 0 and j < n and a[i] == a[j]) i--, j++;

	if (i < 0 or a[i] < a[j]) leftSmaller = true;

	while (i >= 0) {
		a[i] = a[j];
		i--;
		j++;
	}

	if (leftSmaller) {
		int carry = 1;
		i = mid - 1;
		if (n & 1) {
			j = mid + 1;
			a[mid] += carry;
			carry = a[mid] / 10;
			a[mid] %= 10;
		}
		else j = mid;

		while (i >= 0) {
			a[i] += carry;
			carry = a[i] / 10;
			a[i] %= 10;
			a[j] = a[i];
			i--;
			j++;
		}
	}
}

void nextSmallestPalin(vector<int> &a) {
	int n = a.size();
	if (allAre9(a)) {
		for (int &e : a) e = 0;
		a[n - 1] = 1;
		a.insert(a.begin(), 1);
	}

	solve(a);
}