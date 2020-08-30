/*find the longest prefix of a string s which is a palindrome
eg. s = abad , then ans = aba
idea:
concatenate s with the reverse of s having a non english character at the middle
eg. abad#daba
find the lps (longest proper prefix which is also a proper suffix) of the concatenated string.
ans = s.substr(0, lps);
*/

int lps(string s) {
	int n = s.size();
	int ret = 0, j = 0;
	vector<int> f(n, 0);
	for (int i = 1; i < n; ++i) {
		while (j >= 0 and s[i] != s[j]) {
			if (j >= 1) j = f[j - 1];
			else j = -1;
		}
		++j;
		f[i] = j;
		ret = max(ret, f[i]);
	}

	return ret;
}

string solve(string s) {
	string s2 = s;
	reverse(s2.begin(), s2.end());
	s += '#' + s2;

	int l = lps(s);

	return s.substr(0, l);
}

int main() {
	cout << solve("abacabad");
}