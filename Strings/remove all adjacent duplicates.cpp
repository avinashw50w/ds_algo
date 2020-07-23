/*remove all adjacent duplicate characters from string.
eg. bcaaadbbbbac => bcdac */

string solve(string s) {
	int i = 0;
	string res = "";
	while (s[i]) {
		if (s[i] != s[i + 1]) {
			res += s[i];
			i++;
		}

		if (s[i + 1] and s[i] == s[i + 1]) {
			while (s[i + 1] and s[i] == s[i + 1]) i++;
			i++;
		}
	}

	return res;
}