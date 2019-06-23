#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
const int p = 37;

void solve(string txt, string pat) {

	int n = txt.length();
	int m = pat.length();

	ll hash = 0LL, pp = 1LL;

	for(int i = 0; i < m; ++i) {
		hash += (pat[i]-'a'+1) * pp;
		pp *= (ll)p;
	}

	ll hash2 = 0LL;
	pp = 1LL;

	for(int i = 0; i < m; ++i) {
		hash2 += (txt[i]-'a'+1) * pp;
		pp *= (ll)p;
	}
	
	pp /= p;

	for(int i = m; i < n; ++i) {
		if(hash == hash2)
			cout << i - m << endl;

		hash2 -= (txt[i-m] - 'a' + 1);
		hash2 /= p;
		hash2 += (txt[i] - 'a' + 1) * pp;
	}
}

int main() {

	string txt = "dbafdhseaiofefjseal";
	string pat = "sea";

	solve(txt, pat);
}