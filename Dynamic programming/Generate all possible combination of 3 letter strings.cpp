/*generate all possible combinations of 3 letter strings. eg. aaa, aab, aac, ... dac, ..., zzz */

#include <bits/stdc++.h>
using namespace std;

void solve(int n, string s) {
	if (n == 0) {
		cout << s << endl;
		return;
	}
	// choose any one of the 26 letters as the first letter and recursively solve for the rest
	for (int i = 0; i < 26; ++i) {
		s += (i+'a');
		solve(n-1, s);
		s.pop_back();
	}
}

int main() {
	int n = 3;
	string s = "";
	solve(n, s);
}