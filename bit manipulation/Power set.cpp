/*Given a string S find all possible substrings of the string in lexicographically-sorted order.
IDEA: simply generate all possible subsets, and return the sorted order
*/
// note that it also returns the "" set too, to remove that iterate i from 1
vector<string> solve(string s) {
	int n = s.size();
	vector<string> res;

	for (int i = 0; i < 1 << n; ++i) {
		string t = "";
		for (int j = 0; j < n; ++j) {
			if (i >> j & 1) t += s[j];
		}

		res.push_back(t);
	}

	sort(res.begin(), res.end());
	return res;
}