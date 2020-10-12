#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int p = 29;

void solve(string txt, string pat) {

	int n = txt.length();
	int m = pat.length();

	ll hash = 0LL, pp = 1LL;

	for (int i = 0; i < m; ++i) {
		if (i < m - 1) pp = (pp * p) % mod;
		hash = (hash * p + (pat[i] - 'a' + 1));
		if (hash >= mod) hash -= mod;
	}

	ll hash2 = 0LL;

	for (int i = 0; i < m; ++i) {
		hash2 = (hash2 * p + (txt[i] - 'a' + 1));
		if (hash2 >= mod) hash2 -= mod;
	}

	for (int i = m; i < n; ++i) {
		if (hash == hash2)
			cout << i - m << endl;

		hash2 = (hash2 - pp * (txt[i - m] - 'a' + 1) + mod) % mod;
		hash2 = (hash2 * p + (txt[i] - 'a' + 1)) % mod;
	}
}

int main() {

	string txt = "dbafdhseaiofefjseal";
	string pat = "sea";

	solve(txt, pat);
}