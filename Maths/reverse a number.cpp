// reverse an integer

int solve(int n) {
	int res = 0;
	while (n) {
		res = res * 10 + (n % 10);
		n /= 10;
	}
	return res;
}

// another method
int solve(int n) {
	string s = to_string(n);
	for (int n = s.size(), i = 0; i < n / 2; ++i) {
		swap(s[i], s[n - 1 - i]);
	}
	return stoi(s);
}

