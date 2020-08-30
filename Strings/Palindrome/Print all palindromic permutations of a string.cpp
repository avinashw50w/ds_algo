
string reverse(string s) {
	string res = s;
	reverse(res.begin(), res.end());
	return res;
}

bool isPalindrome(string s, vector<int> &f) {
	for (char c : s) f[c - 'a']++;
	int odd = 0;
	for (int e : f) odd += e & 1;
	return ((s.size() & 1) and odd == 1) or ((s.size() & 1 == 0) and odd == 0);
}

void solve(string s) {
	vector<int> f(26, 0);

	if (!isPalindrome(s, f)) return;

	string half = "";
	char oddChar = '';
	for (int i = 0; i < 26; ++i) {
		if (f[i] & 1) oddChar = i + 'a';
		half += string(f[i] / 2, i + 'a');
	}

	string palind;

	do {
		palind = half;
		palind += oddChar;
		palind += reverse(half);

		cout << palind << endl;

	} while (next_permutation(half.begin(), half.end()));
}

