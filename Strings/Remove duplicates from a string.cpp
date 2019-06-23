// abaacd => bcd
string solve(string s) {

	int k = 0, f[26] = {0};

	for (int i = 0; i < s.size(); ++i) f[s[i]-'a']++;

	for (int i = 0; i < s.size(); ++i)
		if (f[s[i]-'a'] == 1) s[k++] = s[i];

	s.resize(k);
	return s;
}

// abaacd => abcd

string solve(string s) {

	int k = 0, n = s.size(), f[26] = {0};

	for (int i = 0; i < n; ++i) {
		f[s[i]-'a']++;

		if (f[s[i]-'a'] == 1) s[k++] = s[i];
	}

	s.resize(k);
	return s;
}

/// O(1) space : use bit manipulation

string solve(string s) {

	int k = 0, n = s.size();

	int mask = 0;

	for (int i = 0; i < n; ++i) {
		int x = s[i] - 'a';

		if ((mask & (1 << x)) == 0) {

			s[k++] = s[i];

			mask |= (1 << x);
		}
	}

	s.resize(k);
	return s;
}