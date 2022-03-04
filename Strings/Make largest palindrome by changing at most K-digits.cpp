/*Given a string containing all digits, we need to convert this string to a palindrome by changing at most K digits. If many solutions are possible then print lexicographically largest one.

Examples:

Input   : str = “43435”
          k = 3
Output  : "93939"
Lexicographically largest palindrome
after 3 changes is "93939" */

string solve(string s, int k) {
	int n = s.length();
	string palin = s;
	int l = 0, r = n - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			k--;
			palin[l] = palin[r] = max(s[l], s[r]);
		}
		++l;
		--r;
	}

	if (k < 0) return "-1";

	// use extra k's
	l = 0;
	r = n - 1;
	while (l <= r) {
		if (l == r) {
			if (k) palin[l] = '9', k--;
		}

		if (palin[l] != '9') {
			if (k >= 2 and palin[l] == s[l] and palin[r] == s[r]) {
				k -= 2;
				palin[l] = palin[r] = '9';
			}
			else if (k >= 1 and (palin[l] != s[l] or palin[r] != s[r])) {
				k--;
				palin[l] = palin[r] = '9';
			}
		}

		++l;
		--r;
	}

	return palin;
}