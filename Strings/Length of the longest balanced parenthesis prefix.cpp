
int solve(string s) {
	int n = s.size();

	int sum = 0, mx = 0, pos = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') sum++;
		else {
			if (sum > 0) sum--;
			else break;
		}

		if (sum == 0) {
			pos = i;
			pos++;
		}
	}

	if (i != n and left == 0) pos = i;

	return pos;
}