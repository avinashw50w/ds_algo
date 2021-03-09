/*Given a string, partition it into as many substrings as possible such that each substring
contains the characters only appearing in that substring and not in other substrings,
eg. abcbceacbadegfgedghijjhij
abcbceacba degfgedg hijjhij
the first substring contains  a, b and c
the second substring contains d, e, f and g
the third substring contains h, i and j
*/
// IDEA: store the index of the last occurence of each character

vector<string> solve(string s) {
	int n = s.size();
	vector<string> res;
	vector<int> last(26, -1);

	for (int i = n - 1; i >= 0; --i) {
		char c = s[i];
		if (last[c - 'a'] == -1)
			last[c - 'a'] = i;
	}

	int maxp = -1;
	string str = "";
	for (int i = 0; i < n; ++i) {
		lp = last[s[i] - 'a'];
		maxp = max(maxp, lp);

		if (i == maxp) {
			str += s[i];
			res.push_back(str);
			maxp = -1;
			str = "";
		}
		else str += s[i];
	}

	return res;
}