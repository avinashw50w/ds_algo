/*print all the permutations of a string in lexicographical order. */
// NOTE: all the permutations will not be distinct if the input contains duplicate characters
vector<string> solve(string s) {
	vector<string> res;

	sort(s.begin(), s.end());

	do {
		res.push_back(s);
	} while (next_permuation(s.begin(), s.end()));

	return res;
}
///////////////////////////////////
// another approach, but the output will not necessarily be in lexicographic order
// output: 123 132 213 321
vector<string> res;

void permute(string s, int pos) {
    int N = s.length();
    if (pos == N) {
        res.push_back(s);
        return;
    }
    for (int i = pos; i < N; ++i) {
        swap(s[pos], s[i]);
        permute(s, pos + 1, N);
        swap(s[pos], s[i]);
    }
}

////////////////////////////////////////
// to get all distinct permutations
vector<string> res;
void solve(int pos, string &s) {
    int n = s.length();
    if (pos == n) {
        res.push_back(s);
        return;
    }

    for (int i = pos; i < n; ++i) {
        if (i > pos and (s[i] == s[pos] or s[i] == s[i-1])) continue;
        swap(s[pos], s[i]);
        solve(pos + 1, s);
        swap(s[pos], s[i]);
    }
}

int distinctPermutations(string s) {
    sort(s.begin(), s.end());
    solve(0, s);
}

// another way to get distinct permutations
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

/* Driver program to test above functions */
int main()
{
    string s = "123";
    int n = s.size();
    permute(s, 0, n - 1);
    return 0;
}
