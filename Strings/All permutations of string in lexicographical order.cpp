/*print all the permutations of a string in lexicographical order. */

vector<string> solve(string s) {
	vector<string> res;

	sort(s.begin(), s.end());

	do {
		res.push_back(s);
	} while (nex_permuation(s.begin(), s.end()));

	return res;
}