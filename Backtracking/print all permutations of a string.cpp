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
// for getting only distinct permutations, use the next_permutation func
// or implement the function if asked by the interviewer
void go(string s, int l, int N, vector<string> &res) {
	if (l == N) {
		res.push_back(s);
		return;
	}
	for (int i = l; i <= N; ++i) {
		swap(s[l], s[i]);
		go(s, l + 1, r, res);
		swap(s[l], s[i]);
	}
}
vector<string> solve(string s) {
	int n = s.length();
	vector<string> res;

	go(s, 0, n - 1, res);
	return res;
}

////////////////////////////////////////////////////////////////
unordered_map<char, int> f;

void go(string s, string t, vector<string> &res) {
	if (t.size() == s.size()) {
		cout << t << " ";
		res.push_back(t);
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
	vector<string> res;
	for (char c : s) f[c]++;
	go(s, "", res);
	return res;
}

void print(char s[], int n) {
	for (int i = 0; i < n; ++i) cout << s[i];
	cout << ", ";
}

void printPermutations(string s, char out[], int len) {

	if (len == s.size()) {
		print(out, len);
		return;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (f[s[i]] == 0) continue;

		out[len] = s[i];

		f[s[i]]--;

		printPermutations(s, out, len + 1);

		f[s[i]]++;
	}
}


int main() {

	string s; s = "AABC";

	for (int i = 0; i < s.size(); ++i) {
		f[s[i]]++;
	}

	char out[s.size()];

	printPermutations(s, out, 0);
}