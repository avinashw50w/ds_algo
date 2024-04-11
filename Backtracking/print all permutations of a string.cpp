/*Print all possible permutations of a string.
eg. AABC:  AABC AACB ABAC ABCA ACAB ACBA BAAC BACA BCAA CAAB CABA CBAA */
// implement next_permutation if asked by the interviewer
// easy way
vector<string> solve(string s) {
	vector<string> res;
	sort(s.begin(), s.end());
	do {
		res.push_back(s);
	} while (next_permutation(s.begin(), s.end()));
	return res;
}

/////////////////////////////
// another way using backtracking
// swap the ith charcter by any char after i, and then solve for substring (i + 1, n)
// revert back the swapping
// NOTE: all the permutations will not be distinct if the input contains duplicate characters
// for getting only distinct permutations, use the next func
void go(string s, int pos, vector<string> &res) {
	int N = s.length();
	if (pos == N) {
		res.push_back(s);
		return;
	}
	for (int i = pos; i < N; ++i) {
		swap(s[pos], s[i]);
		go(s, pos + 1, res);
		swap(s[pos], s[i]);
	}
}
vector<string> solve(string s) {
	int n = s.length();
	vector<string> res;

	go(s, 0, res);
	return res;
}

////////////////////////////////////////////////////////////////
// get only distinct permutations, if string contains duplicate characters
vector<string> res;
set<string> st;

void solve(int pos, string &s) {
	int n = s.length();
	if (pos == n) {
		st.insert(s);
		return;
	}

	for (int i = pos; i < n; ++i) {
		if (i > pos and (s[i] == s[pos] or s[i] == s[i-1])) continue;
		swap(s[pos], s[i]);
		solve(pos + 1, s);
		swap(s[pos], s[i]);
	}
}

vector<string> distinctPermutations(string s) {
	sort(s.begin(), s.end());
	solve(0, s);
	vector<string> ans;
	for(string per: st) {
		ans.push_back(per);
	}
	return ans;
}

////////////////////////////////////////////////////////////////
// another way to get distinct permutations
unordered_map<char, int> f;
set<string> st;

void go(string s, string t, vector<string> &res) {
	if (t.size() == s.size()) {
		cout << t << " ";
		st.insert(t);
		return;
	}
	for (int i = 0; i < s.size(); ++i) {
		if (f[s[i]] == 0) continue;
		t += s[i];
		f[s[i]]--;
		go(s, t, res);
		f[s[i]]++;

	}
}

vector<string> solve(string s) {
	for (char c : s) f[c]++;
		go(s, "", res);
	vector<string> ans;
	for(string per: st) {
		ans.push_back(per);
	}
	return ans;
}
