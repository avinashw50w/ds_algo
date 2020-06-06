#include <bits/stdc++.h>
using namespace std;

string kmp(string s) {
	int n = s.size();
	vector<int> f(n, 0);
	for (int i = 1; i < n; ++i) {
		int j = f[i - 1];
		while (j > 0 and s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) j++;
		f[i] = j;
	}

	return s.substr(0, f[n - 1])
}

void solve(string s) {
	int n = s.size(), i = 0, j, l = 0;
	string pre, suff;
	while (i < n / 2) {
		if (s[i] != s[n - i - 1]) { l = i; break; }
	}

	string a = s.substr(l, n - 2 * l);
	string b = a;
	reverse(b.begin(), b.end());
	string x = kmp(a + '#' + b);
	string y = kmp(b + '#' + a);

	if (x.size() > y.size()) swap(x, y);

	string ans = s.substr(0, l) + x + s.substr(n - l, l);

	return ans << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;

		solve(s);
	}
}