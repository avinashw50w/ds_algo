/*Given a string s, remove the adjacent duplicate characters*/
/*1st type: abbcdddef => abcdef */
int solve(string &s) {
	int n = s.length(), k = 0, i = 0;
	while (i < n) {
		s[k++] = s[i];
		int len = 1;
		while (i + len < n and s[i + len] == s[i]) len++;
		i += len;
	}
	return k;
}

int main() {
	string s = "abbcdddef";
	cout << s.substr(0, solve(s));
}

/*2nd type: abbcdddef => acef */
int solve(string &s) {
	int n = s.length(), k = 0, i = 0;
	while (i < n) {
		while (i + len < n and s[i + len] == s[i]) len++;
		if (len == 1) s[k++] = s[i];
		i += len;
	}
	return k;
}

/*recursively remove adjacent duplicate characters */

string solve(string s) {
	int n = s.length(), i = 0;

	while (i < n) {
		int len = 1;
		while (i + len < n and s[i + len] == s[i]) len++;
		if (len > 1) {
			s = s.substr(0, i) + s.substr(i + len);
			return solve(s);
		}
		i += len;
	}

	return s;
}

